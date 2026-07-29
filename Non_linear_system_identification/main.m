clear all;close all;clc;


for i = [1]
[G_best,a_best,b_best,excited_bins] = robust_method_parametric_non_parametric( 2,"LTI2",i,1);
fs = 60000;
Ts = 1/fs;
N = 4000;
frez = fs/N;
N_Period    = 30;          
Tg_cut      = 5;           
M   = 15;        
P   = N_Period - Tg_cut + 1;  % # periods used per realization

K = length(excited_bins);
G_mp_exc_all = zeros(K, P, M);

R_idx       = 0:M-1;        
freq = (0:N-1).' * (frez);
f_exc = freq(excited_bins+1);      
w_exc = 2*pi*f_exc; 
w_d   = w_exc * Ts;
z_exc = exp(1j * w_d);
compare_plots_index = i;

%%

G_ML = G_best("G_ML");
figure(5+compare_plots_index);
subplot(2,1,1);
plot(f_exc, db(abs(G_ML(excited_bins+1))), 'LineWidth', 1.5,'DisplayName', 'G_{ML}'); hold on;
grid on;
xlabel('Frequency [Hz]');
ylabel('Magnitude [dB]');
legend show;
title('Magnitude');

subplot(2,1,2);
plot(f_exc, unwrap(angle(abs(G_ML(excited_bins+1))))*180/pi, 'LineWidth', 1.5,'DisplayName', 'G_{ML}'); hold on;
grid on;
xlabel('Frequency [Hz]');
ylabel('Phase [deg]');
legend show;
title('Phase');
try
  best_a_lls = a_best("LLS");
  best_b_lls = b_best("LLS");
  sys_tf_lls = tf(best_b_lls,best_a_lls,Ts,'variable','z^-1');
  sys_tf_lls_s = d2c(sys_tf_lls);
  % sys_tf_lls_s = tf(best_b_lls(end:-1:1),best_a_lls(end:-1:1));
  % sys_tf_lls = c2d(sys_tf_lls_s,Ts); 
  figure(5+compare_plots_index);
  subplot(2,1,1)
  plot(f_exc, db(abs(G_best("G_LLS"))),    'LineWidth', 1.5,'DisplayName', sprintf('G_{LLS} na = %d nb = %d',numel(best_a_lls)-1,numel(best_b_lls)-1));hold on;
  subplot(2,1,2)
  plot(f_exc, unwrap(angle(G_best("G_LLS")))*180/pi,    'LineWidth', 1.5,'DisplayName', sprintf('G_{LLS} na = %d nb = %d',numel(best_a_lls)-1,numel(best_b_lls)-1));hold on;


  figure(6+compare_plots_index);
  subplot(2,2,1);step(sys_tf_lls);
  title('LLS Z domain Step Response');
  subplot(2,2,2);pzmap(sys_tf_lls);
  title('LLS Z domain PZMAP');
  subplot(2,2,3);step(sys_tf_lls_s);
  title('LLS S domain Step Response');
  subplot(2,2,4);pzmap(sys_tf_lls_s);   
  title('LLS S domain PZMAP');

catch exception
    disp("LLS is not choosen");
end

try
    best_a_tls = a_best("TLS");
    best_b_tls = b_best("TLS");
    sys_tf_tls = tf(best_b_tls,best_a_tls,Ts,'variable','z^-1');
    sys_tf_tls_s = d2c(sys_tf_tls);
    % sys_tf_tls_s = tf(best_b_tls(end:-1:1),best_a_tls(end:-1:1));
    % sys_tf_tls = c2d(sys_tf_tls_s,Ts); 
    figure(5+compare_plots_index);
    subplot(2,1,1)
    plot(f_exc, db(abs(G_best("G_TLS"))),    'LineWidth', 1.5,'DisplayName', sprintf('G_{TLS} na = %d nb = %d',numel(best_a_tls)-1,numel(best_b_tls)-1));hold on;
    subplot(2,1,2)
    plot(f_exc, unwrap(angle(G_best("G_TLS")))*180/pi,    'LineWidth', 1.5,'DisplayName', sprintf('G_{TLS} na = %d nb = %d',numel(best_a_tls)-1,numel(best_b_tls)-1));hold on;


    figure(7+compare_plots_index);
    subplot(2,2,1);step(sys_tf_tls);
    title('TLS Z domain Step Response');
    subplot(2,2,2);pzmap(sys_tf_tls);
    title('TLS Z domain PZMAP');
    subplot(2,2,3);step(sys_tf_tls_s);
    title('TLS S domain Step Response');
    subplot(2,2,4);pzmap(sys_tf_tls_s);  
    title('TLS S domain PZMAP');



catch exception
    disp("TLS is not choosen");
end


try


    best_a_gtls = a_best("GTLS");
    best_b_gtls = b_best("GTLS");
    sys_tf_gtls = tf(best_b_gtls,best_a_gtls,Ts,'variable','z^-1');
    sys_tf_gtls_s = d2c(sys_tf_gtls);
    % sys_tf_gtls_s = tf(best_b_gtls(end:-1:1),best_a_gtls(end:-1:1));
    % sys_tf_gtls = c2d(sys_tf_gtls_s,Ts); 
    figure(5+compare_plots_index);
    subplot(2,1,1)
    
    plot(f_exc, db(abs(G_best("G_GTLS"))), 'LineWidth', 1.5, ...
                'DisplayName', sprintf('G_{GTLS} na=%d nb=%d',numel(best_a_gtls)-1,numel(best_b_gtls)-1)); hold on;    subplot(2,1,2)
    plot(f_exc, unwrap(angle(G_best("G_GTLS")))*180/pi, 'LineWidth', 1.5, ...
    'DisplayName', sprintf('G_{GTLS} na=%d nb=%d',numel(best_a_gtls)-1,numel(best_b_gtls)-1)); hold on;


    figure(8+compare_plots_index);

    subplot(2,2,1);step(sys_tf_gtls);
    title('GTLS Z Domain Step Response');
    subplot(2,2,2);pzmap(sys_tf_gtls);
    title('GTLS Z Domain PZMAP');
    subplot(2,2,3);step(sys_tf_gtls_s);
    title('GTLS S Domain Step Response');
    subplot(2,2,4);pzmap(sys_tf_gtls_s);  
    title('GTLS S Domain PZMAP');


catch exception
    disp("GTLS is not choosen");
end



end