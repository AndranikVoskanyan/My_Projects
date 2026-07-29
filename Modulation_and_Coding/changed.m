clear all;close all; clc;
%% ------------------- Parameters ------------------- %%
for time_shift = 20:10:20                           % Time shift (samples)
clearvars -except time_shift 
for ppm = [2 4 8]

Ns = 1000;

for window_size = [Ns/7.8125]
M = 8;                           % Bits per symbol (BPSK=1, QPSK=2, 16QAM=4, 64QAM=6)
f_cutoff = 1e6;                              % Nyquist filter cutoff frequency
rollofffactor = 0.2;                                  % Roll-off factor
upsampling_factor = 40 ;                          % Upsampling factor (samples per symbol)
filter_taps = 16 * upsampling_factor + 1;        % Number of taps (must be odd)
Eb_N0_in_dB = 0:1:25;                               % Eb/N0 range in dB
Tsymbol = 1 / (2 * f_cutoff);           % Symbol period
fsymbol = 1 / Tsymbol;                 % Symbol rate
fs = fsymbol * upsampling_factor;            % Sampling frequency
total_bits = Ns*M;            % Total number of bits
fc = 600e6;                            % Carrier frequency (Hz)
t = (0:(Ns*upsampling_factor)-1)./fs;
cfo = ppm * fc * 1e-6;                 % Carrier frequency offset (Hz)

cfo_Exp=exp(1j*cfo*2*pi*t);
phase_offset_deg = ppm/10;          
phase_offset_rad = phase_offset_deg * pi / 180;  % Phase offset (radians)
K = 5/300;                             % Gardner algorithm gain
num_iteration = 1;                              % Number of averaging iterations

Toa = 40;

% Time of arrival (pilot start index)
pilot_size = [Ns*30/100];                    % Different pilot sizes
average_window_size = window_size;                         % Averaging window size

average_time_error = zeros(num_iteration, length(Eb_N0_in_dB), length(pilot_size));
average_freq_error = zeros(num_iteration, length(Eb_N0_in_dB), length(pilot_size));


block_size = 128;
num_blocks = total_bits / block_size;
encoded_bits = [];

H0 = generate_ldpc(128, 256, 0, 1, 3);






%% ------------------- Simulation Loop ------------------- %%
for avg_idx = 1:num_iteration
    
     %%%%% igf you want to use encoder (decoder part is not there eos don't
     %%%%% use) after line 62 end change every tx_bits_o with encoded_bits 
    % Generate random bit sequence
    tx_bits_o = randi([0, 1], 1, total_bits);
    for blk = 1:num_blocks
        infobits = tx_bits_o((blk-1)*block_size + 1 : blk*block_size).';
        [paritybits, ~] = encode_ldpc(infobits, H0, 0);
        encoded_block = [infobits; paritybits].';
        encoded_bits = [encoded_bits encoded_block];
    end
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
    cfo_Exp=exp(1j*cfo*2*pi*t);
    % Nyquist (RRC) filter (TX)
    rrc_filter =  root_cos_fil_gen(rollofffactor, fc/(1+rollofffactor), upsampling_factor, filter_taps,0);
    tx_filtered = conv(upsampled_signal, rrc_filter);

    % Add noise for each Eb/N0
    signal_energy = trapz(abs(tx_filtered).^2) * (1 / fs);
    eb = signal_energy / (2 * total_bits);
    n0 = eb ./ (10.^(Eb_N0_in_dB / 10));
    noise_power = 2 * n0 * fs;

    rx_signals = zeros(length(Eb_N0_in_dB), length(tx_filtered));
    for snr_idx = 1:length(Eb_N0_in_dB)
        noise = sqrt(noise_power(snr_idx) / 2) .* ((randn(1, length(tx_filtered)) + 1i * randn(1, length(tx_filtered))));
        rx_signals(snr_idx, :) = tx_filtered + noise;
    end

    % Nyquist (RRC) filter (RX)
    rx_filtered = zeros(size(rx_signals, 1), size(rx_signals, 2) + length(rrc_filter) - 1);
    for snr_idx = 1:size(rx_signals, 1)
        rx_filtered(snr_idx, :) = conv(rx_signals(snr_idx, :), fliplr(rrc_filter));
    end

    % Apply time shift and crop
    cropped_signals = zeros(size(rx_signals, 1), length(tx_symbols) * upsampling_factor);
    for snr_idx = 1:size(rx_signals, 1)
        shifted_signal = circshift(rx_filtered(snr_idx, :), time_shift);
        cropped_signals(snr_idx, :) = shifted_signal(filter_taps : end - (filter_taps - 1));
        cfo_rx_filtered(snr_idx, :) = cropped_signals(snr_idx, :).*cfo_Exp.*exp(1j*phase_offset_rad);

    end

    % % Gardner timing recovery
    for last_chance = 0:1
     if last_chance ==1 

        downsample_ratio = upsampling_factor / 2;
        recovered_signals = zeros(size(rx_signals, 1), length(tx_symbols));
        timing_errors = zeros(size(rx_signals, 1), length(tx_symbols));
        for snr_idx = 1:size(rx_signals, 1)
           % cfo_rx_filtered(snr_idx, :)= cfo_rx_filtered(snr_idx, :).*exp(-1j*2*pi*cfo*t);

            recover_no_cfo_signal(snr_idx,:) = cfo_rx_filtered(snr_idx, :).*exp(-1j*2*pi*t*(cfo_est));
             % recover_no_cfo_signal(snr_idx,:) = circshift( recover_no_cfo_signal(snr_idx,:),-(estimated_toa));

            partially_downsampled = downsample(recover_no_cfo_signal(snr_idx, :), downsample_ratio);
            [recovered_signals(snr_idx, :), timing_errors(snr_idx, :)] = gardner_function(partially_downsampled, K, upsampling_factor / downsample_ratio);
            % recovered_signals(snr_idx,:) = circshift( recovered_signals(snr_idx,:),-(estimated_toa-Toa));
            pilot_len = pilot_size(1);  % assuming you use pilot_size(1)
            rx_pilot = recovered_signals(snr_idx, Toa:Toa+pilot_len-1);
            tx_pilot = pilots{1};  % original known pilots
        
            % Estimate residual phase offset
            phi_est = abs(angle(sum((rx_pilot .* conj(tx_pilot)))));
            recover_no_cfo_signal(snr_idx,:) = recover_no_cfo_signal(snr_idx,:) * exp(1j * -phi_est);

        end
        
     else
        downsample_ratio = upsampling_factor / 2;
        recovered_signals = zeros(size(rx_signals, 1), length(tx_symbols));
        timing_errors = zeros(size(rx_signals, 1), length(tx_symbols));
        for snr_idx = 1:size(rx_signals, 1)
           % cfo_rx_filtered(snr_idx, :)= cfo_rx_filtered(snr_idx, :).*exp(-1j*2*pi*cfo*t);
    
            partially_downsampled = downsample(cfo_rx_filtered(snr_idx, :), downsample_ratio);
            [recovered_signals(snr_idx, :), timing_errors(snr_idx, :)] = gardner_function(partially_downsampled, K, upsampling_factor / downsample_ratio);
        end
    
        
        % Downsample
        
        % downsampled_signal_rx = zeros(length(eb_n0_dB),length(tx_symbols));
        % for i = 1:length(e`b_n0_dB)
        %     downsampled_signal_rx(i,:) = downsample(cfo_rx_filtered(i,:),upsampling_factor);
        % end
        
    
        % Data acquisition (estimate ToA)
        for snr_idx = 1:length(Eb_N0_in_dB)
            for pilot_idx = 1:length(pilot_size)
                [estimated_toa, cfo_est] = dataAcquisition(recovered_signals(snr_idx, :), pilots{pilot_idx}, average_window_size, Tsymbol);
                % recovered_signals(snr_idx,:) = circshift( recovered_signals(snr_idx,:),-estimated_toa + time_of_arrival);
                % recover_no_cfo_signal(snr_idx,:) = recovered_signals(snr_idx, :).*exp(-1j*2*pi*(0:(Ns-1))*(cfo_est));
                average_time_error(avg_idx, snr_idx, pilot_idx) = abs(estimated_toa - Toa);
                average_freq_error(avg_idx, snr_idx, pilot_idx) = abs(cfo_est - cfo);

            end
        end

     end
    end
 for snr_idx = 1:length(Eb_N0_in_dB)
        if M > 1
            rx_bits = demapping(recovered_signals(snr_idx, :).', M, 'qam').';
        else
            rx_bits = demapping(recovered_signals(snr_idx, :).', M, 'pam').';
        end

        bit_errors = sum(rx_bits ~= tx_bits_o);
        BER(avg_idx, snr_idx) = bit_errors / total_bits;

        if avg_idx == 1
            IQ_symbols{snr_idx} = recovered_signals(snr_idx, :);
        end
end
end

%% ------------------- Results ------------------- %%
variance_time_error = squeeze(std(average_time_error, 0, 1));
variance_freq_error = squeeze(std(average_freq_error, 0, 1));


BER_mean = mean(BER,1);

figure(time_shift+1); hold on; 
plot(real(IQ_symbols{end}), imag(IQ_symbols{end}),"o", 'MarkerSize', 5, 'LineWidth', 2); 
xline(0, 'k', 'LineWidth', 1); % Bold black X=0 line
yline(0, 'k', 'LineWidth', 1); % Bold black Y=0 line
xlabel('In-Phase (I)');
ylabel('Quadrature (Q)');
title(sprintf('Received QAM Constellation with different CFO samplle shift = %.2f',time_shift));
legend("ppm = 2 ","ppm = 4",'ppm = 6');
axis equal;

figure(1001*(time_shift+1));
if ppm == 2

semilogy(Eb_N0_in_dB, berawgn(Eb_N0_in_dB,'qam',2^M)); hold on;
end
semilogy(Eb_N0_in_dB, BER_mean, 'LineWidth', 1.5); hold on;

ylim([10^-5 1])

xlabel('Eb/N0');
ylabel('BER');
title(sprintf('BER with different CFO samplle shift = %.2f',time_shift));
legend('theoretical',"ppm = 2 ","ppm = 4",'ppm = 6');


end
end
end
switch M
    case 1, mod_name = 'BPSK';
    case 2, mod_name = 'QPSK';
    case 4, mod_name = '16QAM';
    otherwise, mod_name = '64QAM';
end
% title([mod_name, ' (Modulation Order = ', num2str(modulation_order), ')']);