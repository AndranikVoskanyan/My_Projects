# FPGA Projects

Digital design projects written in VHDL and Verilog. They range from a basic LED pattern generator to a UART link that crosses clock domains, and an AES-128 encryption core.

Four of the projects target a Xilinx **Spartan-6 XC6SLX9** (TQG144 package) and are built with **Xilinx ISE** (ISim for simulation). Each of them contains an ISE project file (`.xise`) and a pin constraints file (`pinout.ucf`). The two AES projects contain VHDL sources only.

| Folder | Language | What it is | Main concepts |
|---|---|---|---|
| [`AES_128_enc_VHDL`](#1-aes-128-encryption--sequential-version) | VHDL | AES-128 encryption, sequential FSM version | FSM, S-box, ShiftRows, MixColumns, key expansion, 7-segment display |
| [`AES_128_enc_VHDL_pipelined`](#2-aes-128-encryption--column-wise-version) | VHDL | AES-128 encryption, reworked column-wise datapath | Handshaked stages (`start`/`done`/`ready`), 4-byte datapath |
| [`DSP_FIR`](#3-dsp_fir--4-tap-fir-filter) | Verilog | 4-tap fixed-point FIR filter | Pipelining, signed arithmetic, valid-signal propagation |
| [`LED_PATTERNS`](#4-led_patterns--button-controlled-led-patterns) | Verilog | Button-selectable LED animations | Synchronizer, debounce, edge detection, FSM, parameterised modules |
| [`PWM_LIGHT_BRIGHTNES`](#5-pwm_light_brightnes--pwm-led-dimmer) | Verilog | LED dimmer with up/down buttons | PWM, saturating counter, reuse of the button chain |
| [`uart_cdc_2`](#6-uart_cdc_2--uart-link-with-clock-domain-crossing) | Verilog | UART TX/RX with async FIFOs and a self-checking loopback | Clock domain crossing, Gray-code FIFO, UART, on-chip clocking IP |

> Each project folder also contains the files ISE generated during synthesis, place & route and simulation (`.ncd`, `.ngc`, `.bit`, `.wdb`, logs and so on). The design sources are the `.v` / `.vhd` files, the testbenches (`*_tb.v`) and `pinout.ucf`.

---

## 1. AES_128_enc_VHDL — sequential version

An AES-128 encryption core in VHDL, developed as a team project with Zinar Zeynep for the *Digital Architecture and Design* course.

**How it works**

- `encoder.vhd` is the top level. A four-state FSM (`add_k` → `s_box_s` → `col_shift` → `mat_multiple`) steps through the AES rounds on the full 128-bit state.
- The stages are separate entities:
  - `key.vhd`: round key generation and AddRoundKey
  - `S_box.vhd`: SubBytes
  - `col_shift.vhd`: ShiftRows
  - `mat_mul.vhd`: MixColumns
  - `LUT_mul2.vhd`, `LUT_mul3.vhd`: lookup tables for the ×2 and ×3 multiplications in GF(2⁸) used by MixColumns
- The cipher key is the AES example key `2b7e151628aed2a6abf7158809cf4f3c`, and the design holds four plaintext blocks (`6BC1BEE2…`, `AE2D8A57…`, `30C81C46…`, `F69F2445…`), which are the standard NIST SP 800-38A example blocks.
- The result is shown on a **4-digit 7-segment display** (`anod`, `led_seg0`), driven by time-multiplexing the digits. Three inputs control the demo:
  - `push_start` runs an encryption (each new start takes the next of the four plaintext blocks).
  - `out_switch` selects the display: with it on, the ciphertext is shown in hex; with it off, the display shows "AES".
  - `next_values` steps the display to the next four hex digits (16 bits) of the 128-bit result.

**Scope:** encryption only. `decoder.vhd` is an empty placeholder entity.

## 2. AES_128_enc_VHDL_pipelined — column-wise version

A second implementation of the same AES-128 encryption function with a different architecture.

- The data moves between stages as **4-byte columns** (`arr_0 … arr_3`) instead of as one 128-bit word.
- Each stage (key, S-box, ShiftRows, MixColumns) has `start`, `done` and `ready` handshake signals, and the encoder keeps the state as a 4×4 byte matrix.
- The stage entities have an `en_de` (encrypt/decrypt) input, but the encoder ties it to encryption (`'0'`), so this version also encrypts only.
- Same key, same test blocks and the same 7-segment output interface as version 1.

---

## 3. DSP_FIR — 4-tap FIR filter

A three-stage pipelined 4-tap FIR filter on signed 8-bit samples (Verilog).

```
sample_in ─► fir_delay_line ─► coef_mul ─► accum_stage ─► fir_out (18-bit signed)
sample_valid ─────────── valid ──────────── valid ────────► output_valid
```

- **`fir_delay_line`**: shift register holding the last four samples; advances only when `sample_valid` is high.
- **`coef_mul`**: four parallel signed multiplications by the coefficients `5, 59, 59, 5` (parameters, 16-bit products).
- **`accum_stage`**: sign-extends and sums the products, then shifts right by 7 (÷128). The coefficients sum to 128, so the filter has unity gain at DC. They are symmetric, which gives a linear-phase low-pass response.
- A valid flag travels with the data, so `output_valid` is asserted three clock cycles after the corresponding `sample_valid`.

**Testbench (`fir_top_tb.v`):** applies an impulse of amplitude 64. The output is the scaled impulse response `2, 29, 29, 2`, then `0`.

---

## 4. LED_PATTERNS — button-controlled LED patterns

Eight LEDs show one of four animations, and a push button cycles through them.

**Signal chain**

```
button ─► button_sync ─► debounce ─► edge_detector ─► control_fsm ──► mode (2 bit) ─┐
                                                                                    ├─► led_pattern ─► 8 LEDs
clk ─► tick_generator ─► step_counter (3 bit) ──────────────────────────► step ─────┘
```

- **`button_sync`**: two-flip-flop synchronizer for the asynchronous button input.
- **`debounce`**: counter-based debouncer (parameters `COUNT_MAX`, `COUNTER_BITS`).
- **`edge_detector`**: produces one-cycle rising/falling edge pulses.
- **`contorl_fsm`**: a 2-bit mode counter, advanced by each button press.
- **`tick_generator`** and **`step_counter`**: the tick generator divides the clock down to the step rate (`TICK_COUNT = 25_000_000` cycles per step), and the step counter counts steps 0–7.
- **`led_pattern`** (combinational):

| Mode | Pattern |
|---|---|
| `00` | one LED moving 0 → 7 |
| `01` | one LED moving 7 → 0 |
| `10` | bar that fills up from LED 0 |
| `11` | alternating `01010101` / `10101010` |

- **Reset:** asynchronous assertion with synchronized release (two flip-flops) in `everything.v`, which is the top level. The LEDs are active-low, so the output is inverted.
- **Testbenches** for each block: `button_sync_tb`, `debounce_tb`, `edge_detector_tb`, `counter_test`, `step_counter_tb`, `tick_gen_tb`, `led_pattern_tb` and the full design `everything_tb`.

---

## 5. PWM_LIGHT_BRIGHTNES — PWM LED dimmer

An LED brightness control with an **increase** and a **decrease** button and a reset button.

```
increase_button ─► button_control ─┐
                                   ├─► brightness_control ─► duty_cycle ─► pwm_generator ─► pwm_out
decrease_button ─► button_control ─┘
```

- **`button_control`** wraps the same chain as the LED project (`button_sync` → `debounce` → `edge_detector`). One instance serves each button.
- **`brightness_control`**: holds the 8-bit duty cycle and changes it by `STEP = 32` on each press, saturating at 0% and 100%. The levels are `0, 32, 64, …, 224, 255`.
- **`pwm_generator`**: a free-running 8-bit counter compared with the duty cycle (PWM frequency = clock / 256). A duty of 255 holds the output permanently on.
- The top level is `everything.v`, fully parameterised (`PWM_WIDTH`, `STEP`, `COUNT_MAX`, `COUNTER_BITS`). The output is inverted for the active-low LED.
- **Testbenches** for each module plus the full design.

---

## 6. uart_cdc_2 — UART link with clock-domain crossing

A hardware self-test of a UART link in which two parts of the design run on **different clocks** and exchange data through asynchronous FIFOs.

**Clocks:** a Xilinx Clocking Wizard IP (`ipcore_dir/clk_div`) generates **25 MHz** (control and buttons) and **10 MHz** (UART) from the board clock.

```
write button ─► [25 MHz] test-pattern generator ─► TX async FIFO ─► [10 MHz] TX controller ─► uart_tx ─► TX pin
                                                                                                            │ jumper
check button ─► [25 MHz] checker FSM ◄─ RX async FIFO ◄─ [10 MHz] uart_rx ◄─ 2-FF sync ◄──────────── RX pin ◄┘
```

- **`async_fifo`**: dual-clock FIFO with Gray-coded read and write pointers, two-flip-flop pointer synchronizers and registered `full` / `empty` flags (16 entries × 8 bits by default).
- **`uart_tx`** / **`uart_rx`**: FSM-based UART at 115200 baud, 8 data bits. The receiver samples in the middle of each bit.
- **`fifo_uart_tx_controller`**: FSM that reads the TX FIFO and hands bytes to `uart_tx` with a start/busy handshake.
- **`everything2.v`** (top): each press of the *write* button sends the next of eight test bytes (`11 22 33 44 55 AA A5 5A`). Each press of the *check* button reads one received byte from the RX FIFO and compares it with the expected value. An RX-overflow flag is carried back into the 25 MHz domain through a synchronizer.
- **Board test:** TX (P111) is jumpered to RX (P112), so every byte sent should come back unchanged. The LEDs show:

| LED | Meaning |
|---|---|
| 1 | PASS |
| 2 | ERROR |
| 3 | TX FIFO full |
| 4 | TX FIFO empty |
| 5 | TX busy |
| 6 | RX FIFO full |
| 7 | RX FIFO empty |
| 8 | clock locked |

(All LEDs are active-low.)

- **Simulation:** `uart_tx_tb.v` covers the transmitter.

---

## Building

For the four Spartan-6 projects, open the `.xise` file in Xilinx ISE (`DSP_FIR.xise`, `led_patterns.xise`, `pwm_control.xise` or `uart_cdc_2.xise`) and run Synthesize → Implement → Generate Programming File. `pinout.ucf` holds the pin assignments. For simulation, run the testbenches (`*_tb.v`) in ISim.

The AES folders contain VHDL sources only and can be added to any Xilinx or generic VHDL simulation project. The top entity is `encoder`.
