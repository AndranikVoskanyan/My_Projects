# C\_Codes

Embedded C projects, mostly for the ESP32. The code talks to the hardware **directly through registers** (addresses and bit fields from the ESP32 Technical Reference Manual) instead of calling driver functions, so that I learn what the chip really does.

Part of my [My\_Projects](../README.md) portfolio.

## Projects

|Folder|Description|Status|
|-|-|-|
|[`ESP\_BUZZER\_SINGER`](ESP_BUZZER_SINGER)|Button-triggered melody player: debounced button, SR-flip-flop style flag, note table, LED indicator. Direct IO\_MUX, GPIO and Timer Group 0 register access.|Done|

More folders will be added here as I go.

## How the code is written

* Registers are `volatile uint32\_t \*` pointers to fixed addresses.
* One helper, `bit\_operation(reg, mask, start\_index, op)`, does every set, clear and toggle with a mask.
* GPIO outputs use the `W1TS` and `W1TC` registers ("write 1 to set" and "write 1 to clear").
* Timing comes from a hardware timer running at 1 MHz (one tick = 1 microsecond).
* Programs never block: they compare the clock with a deadline, using differences of unsigned counters so that counter wrap-around is handled correctly.
* Deadlines move forward by exactly one period instead of restarting from "now", so timing does not drift.

## Building and flashing (ESP32 projects)

Requires [ESP-IDF](https://docs.espressif.com/projects/esp-idf/) and an ESP32 dev board (ESP-WROOM-32 / NodeMCU).

1. Create an ESP-IDF project (for example from the `hello\_world` example).
2. Copy the project's `.c` and `.h` files into its `main/` folder.
3. List the `.c` file in `main/CMakeLists.txt`.
4. Build and flash:

```
idf.py set-target esp32
idf.py build
idf.py -p <PORT> flash monitor
```

Each project folder has its own README with the wiring and details.

Tested with ESP-IDF version: *fill in the output of `idf.py --version`*.

## Planned

* `struct` register maps (a group of registers as one named structure)
* Timer alarm and interrupt for a fixed 5 ms tick
* PWM and encoder counting through registers
* I2C driver for the MPU6050 IMU
* Self-balancing two-wheeled robot with the ESP32 as its controller

## Notes

Always check register addresses and bit positions against your own copy of the **ESP32 Technical Reference Manual** before writing to a register. Some pins are special (for example GPIO12 is a strapping pin, and GPIO6 to 11 are connected to the flash chip).

## Author

Andranik Voskanyan

