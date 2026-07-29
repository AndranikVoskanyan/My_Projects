clear all;close all; clc;
%% ------------------- Parameters ------------------- %%
while true
M = 4;                           % Bits per symbol (BPSK=1, QPSK=2, 16QAM=4, 64QAM=6)
f_cutoff = 1e6;                              % Nyquist filter cutoff frequency
rollofffactor = 0.2;                % Roll-off factor

upsampling_factor =10;                          % Upsampling factor (samples per symbol)

filter_taps = 16 * upsampling_factor + 1;        % Number of taps (must be odd)
Ns = 2000;
Tsymbol = 1 / (2 * f_cutoff);           % Symbol period
fsymbol = 1 / Tsymbol;                 % Symbol rate
fs = fsymbol * upsampling_factor;            % Sampling frequency
total_bits = Ns*M;            % Total number of bits
fc = 600e6;                            % Carrier frequency (Hz)
                                         % Carrier frequency offset (Hz)

K = 3/30;                             % Gardner algorithm gain
num_iteration = 1;                              % Number of averaging iterations

Toa = 20;                            % Time of arrival (pilot start index)
pilot_size = [Ns*30/100];                    % Different pilot sizes
average_window_size = 128;                         % Averaging window size



block_size = 128;
num_blocks = total_bits / block_size;
encoded_bits = [];

H0 = generate_ldpc(128, 256, 0, 1, 3);






%% ------------------- Simulation Loop ------------------- %%
% for avg_idx = 1:num_iteration


    % Generate random bit sequence
    tx_bits_o = randi([0, 1], 1, total_bits);
    % for blk = 1:num_blocks
    %     infobits = tx_bits_o((blk-1)*block_size + 1 : blk*block_size).';
    %     [paritybits, ~] = encode_ldpc(infobits, H0, 0);
    %     encoded_block = [infobits; paritybits].';
    %     encoded_bits = [encoded_bits encoded_block];
    % end
    pilots_bits = tx_bits_o(M*Toa : M*(Toa + pilot_size(1)) - 1);
    new_tx_bits_o = [tx_bits_o(1:M*Toa-1) pilots_bits tx_bits_o(M*(Toa + pilot_size(1)):end) ];
    tx_bits_o = new_tx_bits_o;
    % Map bits to symbols
    if M > 1
        tx_symbols = mapping(tx_bits_o.', M, 'qam').';
    else
        tx_symbols = mapping(tx_bits_o.', M, 'pam').';
    end

    % Extract pilots and data
    pilots = cell(1, length(pilot_size));
    data_symbols = cell(1, length(pilot_size));
    for k = 1:length(pilot_size)
        pilots{k} = tx_symbols(Toa : Toa + pilot_size(k) - 1);
        data_symbols{k} = tx_symbols(Toa + pilot_size(k) : end);
    end

    % Upsample signal
    upsampled_signal = upsample(tx_symbols, upsampling_factor);
    t = (0:length(upsampled_signal)-1)./fs;    

    % t = (0:length(upsampled_signal)-1)./fs;    
    % cfo_Exp=exp(1j*cfo*2*pi*t);
    % Nyquist (RRC) filter (TX)
    rrc_filter =  root_cos_fil_gen(rollofffactor, fc/(1+rollofffactor), upsampling_factor, filter_taps,0);
    tx_filtered = conv(upsampled_signal, rrc_filter);
    % cropped_signals_tx = zeros(size(tx_filtered, 1), length(tx_symbols) * upsampling_factor);
    cropped_signals_tx = tx_filtered(filter_taps : end - (filter_taps - 1));

    txPluto = sdrtx('Pluto',...
    'RadioID', 'usb:0',...
    'Gain', -25,... % -90 to 0 dB
    'CenterFrequency', fc,... % 335e6 to 3.8e9 [Hz]
    'BasebandSampleRate', fs); % 60e3 to 60e6 [Hz]

    txPluto.transmitRepeat(cropped_signals_tx')



     rxPluto = sdrrx('Pluto', ...
    'RadioID', 'usb:0', ...
    'CenterFrequency', fc, ...             % fc = 600e6 (your carrier frequency)
    'GainSource', 'Manual', ...
    'Gain', 25, ...                        % Adjust as needed
    'BasebandSampleRate', fs, ...          % fs = symbol_rate * upsampling_factor
    'EnableBurstMode', true, ...
    'NumFramesInBurst', 1, ...
    'SamplesPerFrame', Ns*upsampling_factor, ...
    'OutputDataType', 'double');

    [rx_signals,datavalid,overflow] = rxPluto();
    if (overflow)
        disp('Samples dropped');
    end
 

    %%%%%%rx_signal from pluto 
    % Nyquist (RRC) filter (RX)
    rx_filtered = conv(rx_signals, fliplr(rrc_filter));

    % Apply time shift and crop
    cropped_signals = zeros(size(rx_signals, 1), length(tx_symbols) * upsampling_factor);
    cropped_rx_signals = rx_filtered(filter_taps : end - (filter_taps - 1));

    

    % % Gardner timing recovery


    for last_chance = 0:1
     if last_chance ==1 

            downsample_ratio = upsampling_factor / 2;
            recovered_signals = zeros(size(cropped_rx_signals, 1), length(tx_symbols));
            t = ((0:length(cropped_rx_signals)-1)./fs)';    

            recover_no_cfo_signal = cropped_rx_signals.*exp(-1j*2*pi*t*(cfo_est));

            partially_downsampled = downsample(recover_no_cfo_signal, downsample_ratio);
            [recovered_signals, timing_errors] = gardner_function(partially_downsampled, K, upsampling_factor / downsample_ratio);
            pilot_len = pilot_size(1);  % assuming you use pilot_size(1)
            rx_pilot = recovered_signals(estimated_toa:estimated_toa+pilot_len-1);
            tx_pilot = pilots{1};  % original known pilots
        
            % Estimate residual phase offset
            phi_est = angle((sum((rx_pilot .* conj(tx_pilot)'))));
            recover_no_cfo_signal = recovered_signals * exp(-1j * phi_est);
            % recover_no_cfo_signal = recovered_signals;

     else
            downsample_ratio = upsampling_factor / 2;
            recovered_signals = zeros(size(cropped_rx_signals, 1), length(tx_symbols));
            timing_errors = zeros(size(cropped_rx_signals, 1), length(tx_symbols));
            
            partially_downsampled = downsample(cropped_rx_signals, downsample_ratio);
            [recovered_signals, timing_errors] = gardner_function(partially_downsampled, K, upsampling_factor / downsample_ratio);
        
            for pilot_idx = 1:length(pilot_size)
                [estimated_toa, cfo_est] = dataAcquisition(recovered_signals', pilots{pilot_idx}, average_window_size, Tsymbol);

            end

     end
    end
        if M > 1
            rx_bits = demapping(recover_no_cfo_signal, M, 'qam').';
        else
            rx_bits = demapping(recover_no_cfo_signal, M, 'pam').';
        end

        IQ_symbols = recover_no_cfo_signal;
% end

%% ------------------- Results ------------------- %%



figure(1); 
plot(real(IQ_symbols), imag(IQ_symbols),"o", 'MarkerSize', 8, 'LineWidth', 1); 
xline(0, 'k', 'LineWidth', 1); % Bold black X=0 line
yline(0, 'k', 'LineWidth', 1); % Bold black Y=0 line
xlabel('In-Phase (I)');
ylabel('Quadrature (Q)');
title(('Received QAM Constellation'));
% legend("ppm = 0 ","ppm = 2",'ppm = 10');
axis equal;

% figure(1001*(time_shift+1));
% if ppm == 0

% semilogy(Eb_N0_in_dB, berawgn(Eb_N0_in_dB,'qam',2^M)); hold on;
% % end
% semilogy(Eb_N0_in_dB, BER_mean, 'LineWidth', 1.5); hold on;
% 
% ylim([10^-5 1])
% 
% xlabel('Eb/N0');
% ylabel('BER');
% title(sprintf('BER with different CFO samplle shift = %.2f',time_shift));
% legend('theoretical',"ppm = 0 ","ppm = 2",'ppm = 10');



% title([mod_name, ' (Modulation Order = ', num2str(modulation_order),
% ')']);
pause(1)
end