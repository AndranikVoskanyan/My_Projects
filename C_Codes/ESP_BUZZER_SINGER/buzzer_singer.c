#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "melody.h"      // note_t {freq_hz, duration_ms}, melody[], MELODY_LENGTH, NOTE_GAP_MS


// ===========================================================================
// GPIO AND IO_MUX REGISTERS
// ===========================================================================
#define IO_MUX_GPIO12_REG  0x3FF49034u
#define IO_MUX_GPIO13_REG  0x3FF49038u
#define IO_MUX_GPIO14_REG  0x3FF49030u

#define GPIO_OUT_BASE      0x3FF44000u
#define GPIO_OUT_W1TS_REG  (GPIO_OUT_BASE + 0x08u)
#define GPIO_OUT_W1TC_REG  (GPIO_OUT_BASE + 0x0Cu)
#define GPIO_ENABLE_REG    (GPIO_OUT_BASE + 0x20u)
#define GPIO_IN_REG        (GPIO_OUT_BASE + 0x3Cu)

// ===========================================================================
// TIMER REGISTERS
// ===========================================================================
#define TIMG0_BASE         0x3FF5F000u
#define T0CONFIG_REG       (TIMG0_BASE + 0x00u)
#define T0LO_REG           (TIMG0_BASE + 0x04u)
#define T0UPDATE_REG       (TIMG0_BASE + 0x0Cu)
#define T0LOADLO_REG       (TIMG0_BASE + 0x18u)
#define T0LOADHI_REG       (TIMG0_BASE + 0x1Cu)
#define T0LOAD_REG         (TIMG0_BASE + 0x20u)


#define TIMGn_WDTCONFIG0_REG (TIMG0_BASE + 0x48u)
#define TIMG0_WDTWPROTECT_REG (TIMG0_BASE + 0x64u)
#define TIMG0_WDTWPROTECT_REG_KEY 0x050D83AA1u




#define LED_PIN            13u
#define BUZZER_PIN         12u
#define BUTTON_PIN         14u

// APB clock 80 MHz / divider 80 = 1 MHz timer, so one tick = 1 us
#define CLK_DIVIDER        80u
#define TIMER_HZ           (80000000u / CLK_DIVIDER)
#define US_PER_MS          1000u
#define DEBOUNCE_US        30000u


enum operations {
    BIT_SET,
    BIT_CLEAN,
    BIT_TOGGLE,
    REG_CLEAN
};

void bit_operation(volatile uint32_t *reg, uint32_t mask, uint8_t start_index, enum operations op)
{
    if (op == REG_CLEAN) {
        *reg = 0;
        return;
    }
    if (start_index > 31 || ((mask << start_index) >> start_index) != mask) {
        printf("Wrong mask. Register remains unchanged.\n");
        return;
    }
    uint32_t reg_mask = mask << start_index;
    switch (op) {
        case BIT_SET:    *reg |= reg_mask;  return;
        case BIT_CLEAN:  *reg &= ~reg_mask; return;
        case BIT_TOGGLE: *reg ^= reg_mask;  return;
        default:         return;
    }
}


// ===========================================================================
// TIMER
// ===========================================================================
static volatile uint32_t *t0config = (volatile uint32_t *)T0CONFIG_REG;
static volatile uint32_t *t0lo     = (volatile uint32_t *)T0LO_REG;
static volatile uint32_t *t0update = (volatile uint32_t *)T0UPDATE_REG;
static volatile uint32_t *t0loadlo = (volatile uint32_t *)T0LOADLO_REG;
static volatile uint32_t *t0loadhi = (volatile uint32_t *)T0LOADHI_REG;
static volatile uint32_t *t0load   = (volatile uint32_t *)T0LOAD_REG;
static volatile uint32_t *t0watchdog = (volatile uint32_t *)TIMGn_WDTCONFIG0_REG;
static volatile uint32_t *t0watchdogprotect = (volatile uint32_t *)TIMG0_WDTWPROTECT_REG;

void timer_init(void)
{
    printf("T0CONFIG before: 0x%08X\n", (unsigned)*t0config);

    *t0watchdogprotect = TIMG0_WDTWPROTECT_REG_KEY;
    bit_operation(t0watchdog,1,31,BIT_CLEAN);
    
    bit_operation(t0config, 1, 31, BIT_CLEAN);        // EN = 0: stop while we configure
    bit_operation(t0config, 0xFFFF, 13, BIT_CLEAN);   // clear DIVIDER field (bits 28:13)
    bit_operation(t0config, CLK_DIVIDER, 13, BIT_SET);// DIVIDER = 80
    bit_operation(t0config, 1, 30, BIT_SET);          // INCREASE = 1: count up
    bit_operation(t0config, 1, 29, BIT_CLEAN);        // AUTORELOAD = 0
    bit_operation(t0config, 1, 10, BIT_CLEAN);        // ALARM_EN = 0
    bit_operation(t0config, 1, 31, BIT_SET);          // EN = 1: start counting

    printf("T0CONFIG after:  0x%08X\n", (unsigned)*t0config);
}

void timer_reset(void)
{
    bit_operation(t0config, 1, 31, BIT_CLEAN);  // EN = 0: stop timer
    *t0loadlo = 0;
    *t0loadhi = 0;
    *t0load   = 1;                              // trigger counter loading
    bit_operation(t0config, 1, 31, BIT_SET);    // EN = 1: restart timer
}

uint32_t timer_now_us(void)
{
    *t0update = 1;        // latch the running counter into T0LO
    return *t0lo;
}

// wrap-safe "has this moment already passed?"
uint8_t time_reached(uint32_t now, uint32_t deadline)
{
    return ((int32_t)(now - deadline) >= 0);
}

// sanity check only: expect roughly 90000..100000 (FreeRTOS ticks are 10 ms long)
void timer_self_test(void)
{
    uint32_t a = timer_now_us();
    vTaskDelay(pdMS_TO_TICKS(100));
    uint32_t b = timer_now_us();
    printf("self test: 100 ms of FreeRTOS delay = %u us on the timer\n", (unsigned)(b - a));
}


// ===========================================================================
// PINS: one write function and one read function for every pin
// ===========================================================================
static volatile uint32_t *gpio_out_w1ts_reg = (volatile uint32_t *)GPIO_OUT_W1TS_REG;
static volatile uint32_t *gpio_out_w1tc_reg = (volatile uint32_t *)GPIO_OUT_W1TC_REG;
static volatile uint32_t *gpio_enable_reg   = (volatile uint32_t *)GPIO_ENABLE_REG;
static volatile uint32_t *gpio_in_reg       = (volatile uint32_t *)GPIO_IN_REG;

void pin_write(uint8_t pin, uint8_t level)
{
    if (level) bit_operation(gpio_out_w1ts_reg, 1u, pin, BIT_SET);   // W1TS: set the pin
    else       bit_operation(gpio_out_w1tc_reg, 1u, pin, BIT_SET);   // W1TC: clear the pin
}

uint8_t pin_read(uint8_t pin)
{
    return (uint8_t)((*gpio_in_reg >> pin) & 1u);
}


// ===========================================================================
// BUTTON DEBOUNCER
// The input must stay unchanged for DEBOUNCE_US before it is accepted.
// ===========================================================================
typedef struct {
    uint8_t  raw;           // last level seen on the pin
    uint8_t  stable;        // last level that was accepted as clean
    uint32_t changed_at;    // when 'raw' last changed
} debounce_t;

void debounce_init(debounce_t *d, uint8_t level, uint32_t now)
{
    d->raw = level;
    d->stable = level;
    d->changed_at = now;
}

// Returns 1 exactly once per press: when the clean level goes 0 -> 1.
uint8_t debounce_rising_edge(debounce_t *d, uint8_t raw_level, uint32_t now)
{
    if (raw_level != d->raw) {                  // pin moved: restart the stability timer
        d->raw = raw_level;
        d->changed_at = now;
    }

    if (d->raw != d->stable && (uint32_t)(now - d->changed_at) >= DEBOUNCE_US) {
        d->stable = d->raw;                     // stayed the same long enough: accept it
        return d->stable;                       // 1 only if it just became 1 (a press)
    }
    return 0;
}


// ===========================================================================
// MELODY PLAYER
// Walks through melody[]: each note sounds for duration_ms, then a short gap.
// Called over and over; it only looks at the clock and flips the buzzer when due.
// ===========================================================================
typedef struct {
    size_t   index;         // which note of the table
    uint8_t  in_gap;        // 0 = note sounding, 1 = silent gap after it
    uint8_t  level;         // current buzzer level
    uint32_t phase_end;     // when the current note (or gap) ends
    uint32_t next_toggle;   // when the buzzer must flip next
    uint32_t half_period;   // ticks per half period of the current note
} melody_t;

static melody_t player;

// 'start' is the exact moment the note begins (end of the previous gap), so the tempo never drifts
static void melody_begin_note(melody_t *m, uint32_t start)
{
    const note_t *n = &melody[m->index]; // typedef note_t and  melody is included from melody.h

    m->in_gap = 0;
    m->level = 0;
    pin_write(BUZZER_PIN, 0);

    m->phase_end = start + (uint32_t)n->duration_ms * US_PER_MS;

    if (n->freq_hz != NOTE_REST) {
        m->half_period = TIMER_HZ / (2u * n->freq_hz);
        m->next_toggle = start + m->half_period;
    }
}

void melody_start(melody_t *m, uint32_t now)
{
    m->index = 0;
    melody_begin_note(m, now);
}

// Returns 1 while the melody is still playing, 0 when it has finished.
uint8_t melody_update(melody_t *m, uint32_t now)
{
    if (m->index >= MELODY_LENGTH) {
        pin_write(BUZZER_PIN, 0);
        return 0;
    }

    if (time_reached(now, m->phase_end)) {          // current note or gap is over
        if (!m->in_gap) {                           // note over -> silent gap
            m->in_gap = 1;
            m->level = 0;
            pin_write(BUZZER_PIN, 0);
            m->phase_end += (uint32_t)NOTE_GAP_MS * US_PER_MS;
        } else {                                    // gap over -> next note
            m->index++;
            if (m->index >= MELODY_LENGTH) {
                pin_write(BUZZER_PIN, 0);
                return 0;                           // song finished
            }
            melody_begin_note(m, m->phase_end);
        }
        return 1;
    }

    // inside a sounding note: flip the buzzer at every half period
    if (!m->in_gap && melody[m->index].freq_hz != NOTE_REST &&
        time_reached(now, m->next_toggle)) {
        m->level ^= 1u;
        pin_write(BUZZER_PIN, m->level);
        m->next_toggle += m->half_period;           // from the previous deadline: no drift
    }
    return 1;
}


void app_main(void)
{
    volatile uint32_t *io_mux_12 = (volatile uint32_t *)IO_MUX_GPIO12_REG;
    volatile uint32_t *io_mux_13 = (volatile uint32_t *)IO_MUX_GPIO13_REG;
    volatile uint32_t *io_mux_14 = (volatile uint32_t *)IO_MUX_GPIO14_REG;

    // pads 12, 13, 14 start as JTAG pins: MCU_SEL = 2 makes them GPIO
    bit_operation(io_mux_12, 0x7u, 12, BIT_CLEAN);
    bit_operation(io_mux_12, 0x2u, 12, BIT_SET);
    bit_operation(io_mux_13, 0x7u, 12, BIT_CLEAN);
    bit_operation(io_mux_13, 0x2u, 12, BIT_SET);
    bit_operation(io_mux_14, 0x7u, 12, BIT_CLEAN);
    bit_operation(io_mux_14, 0x2u, 12, BIT_SET);

    // button pad: input enable on, internal pull-up/pull-down off (external 5.1 kOhm pull-down)
    bit_operation(io_mux_14, 1u, 9, BIT_SET);       // FUN_IE = 1
    bit_operation(io_mux_14, 1u, 8, BIT_CLEAN);     // FUN_WPU = 0
    bit_operation(io_mux_14, 1u, 7, BIT_CLEAN);     // FUN_WPD = 0

    // outputs: GPIO12 (buzzer) and GPIO13 (LED) are neighbours, so mask 0x3 at bit 12 enables both
    bit_operation(gpio_enable_reg, 3u, BUZZER_PIN, BIT_SET);
    pin_write(BUZZER_PIN, 0);
    pin_write(LED_PIN, 0);

    timer_init();
    timer_self_test();
    timer_reset();

    debounce_t button;
    debounce_init(&button, pin_read(BUTTON_PIN), timer_now_us());

    // The flip-flop: SET by a clean button press, RESET when the melody ends.
    uint8_t play_flag = 0;

    printf("\nMelody player ready. Press the button on GPIO14.\n");

    while (1) {
        uint32_t now = timer_now_us();

        // SET: a debounced press raises the flag (ignored while it is already high)
        if (debounce_rising_edge(&button, pin_read(BUTTON_PIN), now) && !play_flag) {
            play_flag = 1;
            pin_write(LED_PIN, 1);              // LED shows the flag
            melody_start(&player, now);
            printf("Button pressed. Playing.\n");
        }

        // the melody runs only while the flag is high
        if (play_flag) {
            uint8_t still_playing = melody_update(&player, now);

            // RESET: the end of the melody drops the flag
            if (!still_playing) {
                play_flag = 0;
                pin_write(LED_PIN, 0);
                printf("Melody finished.\n");
            }
        }
    }

}
