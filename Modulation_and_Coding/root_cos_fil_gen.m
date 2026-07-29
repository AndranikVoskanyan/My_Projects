function normalized_Hrrc = root_cos_fil_gen(betta, B, OFS, RRCT,plot_img)
T = 1/B;
Fs = B*OFS;

stepOffset = (1/RRCT)*Fs;
highestFreq = stepOffset*(RRCT-1)/2;
Gridfreq = linspace(-highestFreq,highestFreq,RRCT);
Delta_t = 1/Fs;
t = (-(RRCT-1)/2:(RRCT-1)/2)*Delta_t;
RRC = zeros(1,RRCT);

for i = 1:RRCT
    if  abs(Gridfreq(i)) <= (1-betta)/(2*T)
        RRC(i) = T;
    elseif abs(Gridfreq(i)) <= (1+betta)/(2*T)
        RRC(i) = T/2 * (1+cos((pi*T/betta)*(abs(Gridfreq(i))-((1-betta)/(2*T)))));
    end
end
Hrrc = sqrt(RRC);
hrc_time_domain = real(ifft(ifftshift(RRC)));
hrc_time_domain_shift = fftshift(hrc_time_domain);
normalized_RRC = hrc_time_domain_shift / norm(hrc_time_domain_shift);

% Find closest indices to sampling points (multiples of T)
sample_times = -ceil(t(end)/T)*T : T : ceil(t(end)/T)*T;
[~, sample_indices] = min(abs(t' - sample_times), [], 1);
%normalize
normalized_RRC_dev = norm(hrc_time_domain_shift);
% max_abs_value = max((hrc_time_domain_shift));
normalized_RRC = hrc_time_domain_shift / normalized_RRC_dev;

hrrc_time_domain = (ifft(ifftshift(Hrrc)));
hrrc_time_domain_shift = fftshift(hrrc_time_domain);

normalized_Hrrc_dev = norm(hrrc_time_domain_shift);

normalized_Hrrc = hrrc_time_domain_shift / normalized_Hrrc_dev;


if plot_img == 1
figure;
    %% plots
subplot(2,1,1);
plot(Gridfreq,RRC);
grid on;
xlabel('Hz');
ylabel('RRC');
title('filter in frequency domain');

% %plot in time domain
subplot(2,1,2);
plot(t, normalized_RRC, 'b', 'LineWidth', 1.2); hold on;
plot(t(sample_indices), normalized_RRC(sample_indices), 'ro', 'MarkerSize', 6, 'LineWidth', 1.5);
grid on;
xlabel('Time (s)');
ylabel('Normalized RRC');
title('RRC Filter in Time Domain');
legend('RRC', 'Sample Points');

end

end