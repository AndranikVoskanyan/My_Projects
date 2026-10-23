# My Projects

A portfolio of my university and personal engineering projects, spanning control systems, digital design, embedded systems, analog/mixed-signal electronics, signal processing, and machine learning.

Some projects were completed individually, others as group work during my studies (B.Sc. Automation at the National Polytechnic University of Armenia; M.Sc. Electrical Engineering at Vrije Universiteit Brussel). I am grateful to my teammates for their contributions to the group projects. Where applicable, my specific role is described in the README of the corresponding project folder.

## Contents

| Area | Project | Folder |
|---|---|---|
| Digital design / FPGA | RISC-V processor in Verilog, tested on FPGA; AES-128 encryption in VHDL, UART, CDC, Async FIFO and other  (design, simulation, implementation on FPGA board) | [`FPGA_projects`](FPGA_projects) |
| Control / Robotics | Model predictive control (MPC) implemented from scratch for a highly flexible robotic manipulator | [`Handmade_MPC_for_highly_flexible_robotic_manipulator`](Handmade_MPC_for_highly_flexible_robotic_manipulator) |
| Control | Inverted pendulum controller stabilising the upper equilibrium point | [`Inverted_pendulum`](Inverted_pendulum) |
| System identification | Nonlinear system identification: multisine excitation, output measurement, best linear approximation with minimal error | [`Non_linear_system_identification`](Non_linear_system_identification) |
| Industrial automation | PLC project in Siemens TIA Portal: traffic and pedestrian lights at a street crossing | [`PLC_project_working/Andranik_voskanyan_PLC_project`](PLC_project_working/Andranik_voskanyan_PLC_project) |
| Image processing / ML | Document scanner: hand-written Canny edge detector and Hough transform, with a UI for cropping and sharpening | [`Doc_scanner`](Doc_scanner) |
| Analog / mixed-signal | Oscillator design through to a PWM generator with a reference frequency (LTspice) | [`from_oscilator_to_PWM`](from_oscilator_to_PWM) |
| Analog | Two-stage amplifier | [`2_stage_amp`](2_stage_amp) |
| Embedded | Arduino alarm/timer project with assembly | [`Arduino_with_assembly_ALARM/proj_timer`](Arduino_with_assembly_ALARM/proj_timer) |
| Communications | Modulation and coding | [`Modulation_and_Coding`](Modulation_and_Coding) |

## Highlights

- **RISC-V on FPGA:** a processor written in Verilog, with datapath and control unit, verified on real hardware running a small program (`program.mem`).
- **MPC for a flexible manipulator:** ties into my master's thesis, *MPC of a Parameter-Estimated Flexible Manipulator*, completed in the Robotics & Multibody Mechanics group at VUB.
- **Document scanner:** core algorithms (Canny, Hough transform) implemented by hand rather than taken from a library.

## Tools and technologies

Verilog, VHDL, SystemVerilog, Python, MATLAB/Simulink, LTspice, Siemens TIA Portal, Arduino and assembly, Xilinx ISE, Git, Linux/Bash.

## Repository structure

Each folder is self-contained and holds the available source code, documentation, simulations, or other project materials. See the README inside a folder (where present) for build and run instructions.

```
My_Projects/
├── 2_stage_amp/
├── Arduino_with_assembly_ALARM/
├── Doc_scanner/
├── FPGA_projects/
├── Handmade_MPC_for_highly_flexible_robotic_manipulator/
├── Inverted_pendulum/
├── Modulation_and_Coding/
├── Non_linear_system_identification/
├── PLC_project_working/
└── from_oscilator_to_PWM/
```

## About me

I'm Andranik Voskanyan, an electrical engineer based in Brussels, with experience in design verification (SystemVerilog/UVM at Microchip Technology) and robotics.

GitHub: [AndranikVoskanyan](https://github.com/AndranikVoskanyan)

## License

Released under the [Apache License 2.0](LICENSE).
