# ESP_BUZZER_SINGER

A melody player for the ESP32, written with **direct register access**. Press a button, and a passive buzzer plays a song from a note table while an LED shows that the song is running. IO_MUX, GPIO and the hardware timer are all handled through their registers, and the program never blocks: it only compares the timer with the next deadline.

## What it does

1. The button is read and **debounced**.
2. A clean press **sets** a flag (`play_flag`, like an SR flip-flop).
3. While the flag is high, the melody player runs and the LED is on.
4. When the last note ends, the melody **resets** the flag, and the player is ready for the next press.

```
 button --> debounce --> SET --> [ play_flag ] --> melody_update()
                                      ^                 |
                                      +--- RESET <------+  (melody finished)
```

- A press while the song is playing is ignored, because the flag is already high.
- If the button is held down at power-up, nothing plays until it is released and pressed again.

## Hardware

| Part | Pin | Notes |
|---|---|---|
| ESP32 dev board (ESP-WROOM-32) | | |
| Passive buzzer | GPIO12 to GND | Must be **passive**. An active buzzer always plays one fixed pitch. |
| LED | GPIO13 | With a series resistor. |
| Push button | GPIO14 | Button to 3.3 V, with an external 5.1 kOhm pull-down to GND. Pressed reads 1. |

Pin notes:
- GPIO12 is a **strapping pin**. If the buzzer circuit holds it high at reset, the chip can fail to boot.
- GPIO12, 13 and 14 start as JTAG pins, so the code first selects the GPIO function in their IO_MUX registers.

## Files

| File | Purpose |
|---|---|
| `buzzer_singer.c` | Main program: register setup, timer, debouncer, melody player, main loop |
| `melody.h` | The song: note frequencies, durations, tempo (included by `buzzer_singer.c`) |

## Registers used

Addresses are from the ESP32 Technical Reference Manual.

| Block | Register | Address | Use |
|---|---|---|---|
| IO_MUX | GPIO12 pad (MTDI) | `0x3FF49034` | `MCU_SEL` = 2, GPIO function |
| IO_MUX | GPIO13 pad (MTCK) | `0x3FF49038` | `MCU_SEL` = 2, GPIO function |
| IO_MUX | GPIO14 pad (MTMS) | `0x3FF49030` | `MCU_SEL` = 2, input enable (`FUN_IE`), pull-ups off |
| GPIO | `GPIO_OUT_W1TS` | `0x3FF44008` | set output pins |
| GPIO | `GPIO_OUT_W1TC` | `0x3FF4400C` | clear output pins |
| GPIO | `GPIO_ENABLE` | `0x3FF44020` | enable outputs |
| GPIO | `GPIO_IN` | `0x3FF4403C` | read input pins |
| Timer Group 0 | `T0CONFIG` | `0x3FF5F000` | enable, divider, count direction |
| Timer Group 0 | `T0LO`, `T0UPDATE` | `0x3FF5F004`, `0x3FF5F00C` | latch and read the counter |
| Timer Group 0 | `T0LOADLO`, `T0LOADHI`, `T0LOAD` | `0x3FF5F018`, `0x3FF5F01C`, `0x3FF5F020` | reset the counter |
| Timer Group 0 | `WDTCONFIG0` | `0x3FF5F048` | watchdog enable bit (bit 31) |
| Timer Group 0 | `WDTWPROTECT` | `0x3FF5F064` | write-protect key `0x50D83AA1` |

The timer counts the 80 MHz APB clock divided by 80, so **one tick is exactly 1 microsecond**.

## How it works

- **Debouncer** (`debounce_rising_edge`): the pin must stay unchanged for 30 ms before the new level is accepted. It returns 1 exactly once per press.
- **Melody player** (`melody_update`): called over and over, it never waits. It flips the buzzer when a half period has passed, and moves from note to gap to next note when the deadline is reached.
- **Square wave:** a note of frequency `f` flips the pin every `1 000 000 / (2 f)` microseconds.
- **No drift:** each deadline moves forward from the previous deadline, not from "now", so pitch and tempo stay accurate.
- **Wrap-safe timing:** time comparisons use differences of 32-bit values, so they stay correct when the counter wraps around.
- **Watchdog:** the main loop never yields to FreeRTOS, so the program unlocks the Timer Group 0 watchdog with its key and clears its enable bit at start-up, to avoid watchdog warnings. The write protection is not locked again afterwards.

## Changing the song

Edit the table in `melody.h`:

```c
#define BEAT_MS 400                      // tempo: smaller = faster

static const note_t melody[] = {
    {NOTE_E4, BEAT_MS},
    {NOTE_F4, BEAT_MS},
    {NOTE_G4, 2 * BEAT_MS},              // held for two beats
    {NOTE_REST, BEAT_MS},                // silence
};
```

Notes are defined as `NOTE_C4` to `NOTE_B5` (`S` means sharp, for example `NOTE_FS4`). `NOTE_GAP_MS` is the short silence after every note.

## Build and flash

1. Create an ESP-IDF project (for example from the `hello_world` example).
2. Copy `buzzer_singer.c` and `melody.h` into its `main/` folder.
3. In `main/CMakeLists.txt`, use `idf_component_register(SRCS "buzzer_singer.c" INCLUDE_DIRS ".")`.
4. Build and flash:

```
idf.py set-target esp32
idf.py build
idf.py -p <PORT> flash monitor
```

The monitor prints `Melody player ready`, then `Button pressed. Playing.` and `Melody finished.`

## Testing

- Press once: the LED and the song start together. Press again during the song: nothing happens.
- When the song ends, the LED goes off and a new press plays it again.
- Hold the button at power-up: nothing plays until you release and press again.
- Check the pitch with a phone tuner app. E4 should read about 330 Hz.

## Known limitations

- Frequencies are whole hertz, and the timing is polled, so very high notes (above a few kHz) become less accurate.
- Printing inside the loop while a note plays would disturb the pitch, so only start and end events are printed.
- With the watchdog disabled, a program stuck in the loop will not reset the chip. Re-enable it when the polling loop is replaced by an interrupt-driven design.
- It needs a **passive** buzzer.

## Next steps

- Replace the polling loop with a timer alarm and an interrupt.
- Generate the tone with the PWM peripheral (LEDC) so the CPU stays free.
- Play recorded sound samples through the ESP32 DAC.
- Read the melody from a file instead of a table in the source code.
