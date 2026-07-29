Communication Flow
Random bit generation
        ↓
PAM/QAM symbol mapping
        ↓
Pilot insertion
        ↓
Upsampling
        ↓
Root Raised Cosine transmit filter
        ↓
ADALM-Pluto transmitter
        ↓
Real wireless channel
        ↓
ADALM-Pluto receiver
        ↓
Root Raised Cosine receive filter
        ↓
Gardner timing recovery
        ↓
Time-of-arrival and CFO estimation
        ↓
Frequency and phase correction
        ↓
Symbol demapping
        ↓
Recovered bit sequence
Project Files
for_pluto.m

The main hardware implementation of the communication system.

This script:

Generates random data bits
Maps bits into QAM or PAM symbols
Inserts known pilot symbols
Upsamples and pulse-shapes the transmitted signal
Configures the ADALM-Pluto transmitter
Continuously transmits the generated waveform
Configures the ADALM-Pluto receiver
Captures real received samples
Applies matched filtering
Performs Gardner timing recovery
Estimates time of arrival and carrier-frequency offset
Corrects frequency and phase errors
Demaps the received symbols
Displays the recovered QAM constellation
changed.m

An additional MATLAB testing script used to evaluate the synchronization and communication algorithms under controlled conditions.

It can test different:

Carrier-frequency offsets
Time shifts
Signal-to-noise ratios
Modulation parameters

It also calculates BER and displays constellation and BER plots.

mapping.m

Converts the input bit sequence into normalized PAM or QAM symbols using Gray coding.

demapping.m

Detects the received PAM or QAM symbols and converts them back into bits.

dataAcquisition.m

Uses differential cross-correlation with the known pilot sequence to estimate:

Time of arrival
Carrier-frequency offset
root_cos_fil_gen.m

Generates a normalized Root Raised Cosine filter.

The filter is created in the frequency domain and converted into the time domain using the inverse FFT.

interpolate.m

Performs linear interpolation between received signal samples. It can be used by the timing-recovery algorithm when the required sampling position is between two available samples.

Modulation Configuration

The modulation is selected using the number of bits per symbol:

M = 1; % BPSK
M = 2; % QPSK
M = 4; % 16-QAM
M = 6; % 64-QAM

The current Pluto implementation uses:

M = 4;

Therefore, the current configuration uses 16-QAM modulation.

Pluto SDR Configuration

The transmitter is configured using:

txPluto = sdrtx('Pluto', ...
    'RadioID', 'usb:0', ...
    'Gain', -25, ...
    'CenterFrequency', fc, ...
    'BasebandSampleRate', fs);

The receiver is configured using:

rxPluto = sdrrx('Pluto', ...
    'RadioID', 'usb:0', ...
    'CenterFrequency', fc, ...
    'GainSource', 'Manual', ...
    'Gain', 25, ...
    'BasebandSampleRate', fs);

The current center frequency is:

fc = 600e6;

This corresponds to a carrier frequency of 600 MHz.

The radio ID, transmitter gain, receiver gain and center frequency may need to be changed depending on the connected device and experimental setup.

Requirements
MATLAB
Communications Toolbox
Signal Processing Toolbox
Communications Toolbox Support Package for Analog Devices ADALM-Pluto Radio
ADALM-Pluto SDR device

The following additional functions must also be available:

gardner_function
generate_ldpc
encode_ldpc
Running the Project
Connect the ADALM-Pluto SDR to the computer.
Make sure that MATLAB detects the device.
Place all MATLAB files in the same project folder.
Check the Pluto radio ID and communication parameters.
Run:
for_pluto

The script continuously transmits and receives the waveform and displays the recovered signal constellation.

Notes

The main script runs inside a continuous loop:

while true

Stop the execution manually from MATLAB when the experiment is complete.

The quality of the recovered constellation depends on factors such as:

Transmitter and receiver gain
Antenna placement
Distance between transmitter and receiver
Carrier-frequency mismatch
Timing synchronization
Environmental interference