function [G_best,a_best,b_best,excited_bins] = robust_method_parametric_non_parametric( power_level,model_type,is_sigma,is_plot)
    if nargin<4
        is_plot = inf;
    end
    load('OSE_Sig_E0_S0.mat')
    load('OSE_Sel_E0_S0.mat')
    file_pattern = 'ACQ_R%d_P%d_E0_M0_F0.mat';
    excited_bins = OSE_Sel_E0_S0(:,1);
    excited_signal = OSE_Sig_E0_S0(:,1);
    
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
    % ---------------------------------------
    
    
    G_hat_m_all   = [];   % N x M    (G^[m])
    sigma_on2_all = [];   % N x M    (sigma_on^2[m])
    
    
    for k = 1:M
    
        m = R_idx(k);
        fname = sprintf(file_pattern, m,power_level);
        fprintf('Processing realization %d: %s\n', m, fname);
    
        S = load(fname,'YR0','YR1','YR6','YR7', 'YR1_Time');

        switch upper(strtrim(model_type))
        
            case 'LTI1'
                    u = S.YR0;
                    y = S.YR6;
        
            case 'LTI2'
                    u = S.YR7;
                    y = S.YR1;
        
            case 'NL'
                    u = S.YR6;
                    y = S.YR7;
        
            case 'OVERALL'
                    u = S.YR0;
                    y = S.YR1;
        
            otherwise
                error('Unknown model_type. Use: LTI1, LTI2, NL, or OVERALL');
        end
       
        u_mat = reshape(u, N, N_Period); 
        y_mat = reshape(y, N, N_Period); 
        u_keep = u_mat(:, Tg_cut:end);    
        y_keep = y_mat(:, Tg_cut:end);    
    
        U_fft = fft(u_keep, [], 1);       
        Y_fft = fft(y_keep, [], 1);       
        % U_fft = zeros(N,P);
        % Y_fft = zeros(N,P);
        % for i = 1:P
        %     U_fft(:,i) = fft(u_keep(:,i));
        %     Y_fft(:,i) = fft(y_keep(:,i));
        % end
    
       
        S_YU_mp = Y_fft .* conj(U_fft);   % N x P
        S_UU_mp = U_fft .* conj(U_fft);   % N x P
    
        G_mp = zeros(N, P);
        
        for index = 1:P
              G_mp(:,index) = S_YU_mp(:,index) ./ S_UU_mp(:,index);   
            % G_mp(:,index) = Y_fft(:,index) ./ U_fft(:,index);
        end
    
        G_hat_m = mean(G_mp, 2);         
        G_mp_exc_all(:,:,k) = G_mp(excited_bins+1, :);
        diff_horizontal = zeros(N,1);
        for p = 1:P
            diff_per_periods = abs(G_mp(:,p)-G_hat_m);
            diff_horizontal = diff_horizontal + diff_per_periods.^2;
        end
    
        sigma_on2_m =  diff_horizontal/(P*(P-1));  
       
        G_hat_m_all(:,k)   = G_hat_m;
        sigma_on2_all(:,k) = sigma_on2_m;    
    end
    
    
    G_ML = mean(G_hat_m_all, 2);   
    diff_horizontal = zeros(N,1);
    for m = 1:M
        diff_per_realization = abs(G_hat_m_all(:,m) - G_ML);
    
        diff_horizontal = diff_horizontal + diff_per_realization.^2;
    
    end
    
    sigma_ML2 =  diff_horizontal/(M*(M-1));  
    
    
    
    G_hat_m_excited         = G_hat_m_all(excited_bins+1, :);    
    sigma_on2_excited       = sigma_on2_all(excited_bins+1, :);  
    G_ML_excited            = G_ML(excited_bins+1);              
    sigma_ML2_excited       = sigma_ML2(excited_bins+1);         
    sigma_on2_mean_excited  = mean(sigma_on2_all, 2);  
    sigma_on2_mean_excited  = sigma_on2_mean_excited(excited_bins+1);
    
    
    
    
    sigma_on2_noise_variance = (1/(M^2))*sum(sigma_on2_all,2) ;   
    sigma_on2_noise_variance_excited = sigma_on2_noise_variance(excited_bins+1);
    sigma_nl2 = M*(sigma_ML2 - sigma_on2_noise_variance/(M*P*excited_signal.^2));
    sigma_nl2_excited = sigma_nl2(excited_bins+1);
    
    
    
    
    fprintf('Non parametric  part finished \n');   
    
    
    
    
    %%%%%%%%%%%%%%%% PARAMETRIC
    
    G_best = containers.Map;
    G_best('G_ML') = G_ML;
    a_best = containers.Map;
    b_best = containers.Map;


    fprintf("Please answer to following questions carefully to start Parametric Identification process\n")
    LLS = lower(input("Activate LLS method (true/false)"));
    TLS = lower(input("Activate TLS method (true/false)"));
    GTLS = lower(input("Activate GLS method (true/false)"));
    
    na_max = input("Please determine maximum order for denuminator (integer number)");      
    
    if na_max ~= round(na_max)
        error("order need to be integer")
    end
    
    nb_max = input("Please determine maximum order for numinator (round number smaller or equal then denuminator)");     
    
    if nb_max ~= round(nb_max)
        error("order need to be integer")
    end
    
    if na_max < nb_max
        error('Order of numinator need to be smaller then order of denuminator');
    end
    
   
    if LLS == true
        if is_sigma ~= 1
            [best_a, best_b, best_GBLA, best_na, best_nb] = ...
             lls_bla_aic(G_ML_excited, na_max, nb_max, w_exc, fs);
        else

            [best_a, best_b, best_GBLA, best_na, best_nb] = ...
                 lls_bla_sigma(G_ML_excited,sigma_ML2_excited, na_max, nb_max, w_exc, fs);
        end

        G_best('G_LLS') = best_GBLA;
        a_best('LLS') = best_a;
        b_best('LLS') = best_b;


    end
    
    if TLS == true
        if is_sigma ~=1
    [best_a_tls, best_b_tls, best_GBLA_tls, na_tls, nb_tls] = ...
        tls_bla_aic(G_ML_excited, na_max, nb_max, w_exc, fs);
        else
            [best_a_tls, best_b_tls, best_GBLA_tls, na_tls, nb_tls] = ...
                tls_bla_sigma(G_ML_excited, sigma_ML2_excited,na_max, nb_max, w_exc, fs);
            
        end
       
        G_best('G_TLS') = best_GBLA_tls;
        a_best('TLS') = best_a_tls;
        b_best('TLS') = best_b_tls;


    end
    
    if GTLS == true
        if is_sigma ~= 1
        [best_a_gtls, best_b_gtls, best_GBLA_gtls, na_gtls, nb_gtls] = ...
            gtls_bla_aic(G_ML_excited, sigma_ML2_excited, na_max, nb_max, w_exc, fs);
        else
            [best_a_gtls, best_b_gtls, best_GBLA_gtls, na_gtls, nb_gtls] = ...
                gtls_bla_sigma(G_ML_excited, sigma_ML2_excited, na_max, nb_max, w_exc, fs);
        end
        G_best('G_GTLS') = best_GBLA_gtls;
        a_best('GTLS')   = best_a_gtls;
        b_best('GTLS')   = best_b_gtls;
   
    end
        
   
    
    
    
    %%%%%%%% EXTRA PLOTS
    if is_plot ~= inf
        figure;
        subplot(2,1,1);
        plot(f_exc, db(abs(G_ML_excited)), 'LineWidth', 1.5);
        grid on;
        xlabel('Frequency [Hz]');
        ylabel('Magnitude [dB]');
        title('Robust BLA G_{ML} (magnitude, excited lines)');
        
        subplot(2,1,2);
        plot(f_exc, unwrap(angle(G_ML_excited))*180/pi, 'LineWidth', 1.5);
        grid on;
        xlabel('Frequency [Hz]');
        ylabel('Phase [deg]');
        title('Robust BLA G_{ML} (phase, excited lines)');
        
        figure;
        G_mag_real = abs(G_hat_m_excited);   
        plot(excited_bins, db(G_mag_real), 'LineWidth', 0.5); 
        hold on;
        plot(excited_bins, db(abs(G_ML_excited)), 'LineWidth', 2);
        grid on;
        xlabel('Frequency [Hz]');
        ylabel('Magnitude [dB]');
        title('Per-realization FRFs and ML BLA (magnitude)');
        legend('Realizations','G_{ML}','Location','Best');
        
        
        figure;
        subplot(3,1,1);
        plot(excited_bins, db(sigma_on2_mean_excited), 'LineWidth', 1.5);
        grid on;
        xlabel('Frequency [Hz]');
        ylabel('\sigma_{o_n}^2');
        title('Mean noise variance over periods (\sigma_{o_n}^2), excited lines');
        
        subplot(3,1,2);
        plot(excited_bins, db(sigma_on2_all(excited_bins+1,4)), 'LineWidth', 1.5);
        grid on;
        xlabel('Frequency [Hz]');
        ylabel('\sigma_{o_4}^2');
        title(' noise variance of 4th period (\sigma_{o_n}^2), excited lines');
        
        subplot(3,1,3);
        plot(excited_bins, db(sigma_ML2_excited), 'LineWidth', 1.5);
        grid on;
        xlabel('Frequency [Hz]');
        ylabel('\sigma_{ML}^2');
        title('Variance of FRF mean over realizations (\sigma_{ML}^2), excited lines');
        
     
        figure;
        
        subplot(3,1,1);
        plot(f_exc, db(sqrt(sigma_on2_noise_variance_excited)), 'LineWidth', 1.5);
        grid on;
        xlabel('Frequency [Hz]');
        ylabel('dB');
        title('\sigma^2_{noise} (excited bins)');
        
        subplot(3,1,2);
        plot(f_exc, db(sqrt(sigma_nl2_excited)), 'LineWidth', 1.5);
        grid on;
        xlabel('Frequency [Hz]');
        ylabel('dB');
        title('\sigma^2_{NL} (excited bins)');
        
        subplot(3,1,3);
        plot(f_exc, db(sqrt(sigma_ML2_excited)), 'LineWidth', 1.5);
        grid on;
        xlabel('Frequency [Hz]');
        ylabel('dB');
        title('\sigma^2_{ML} (excited bins)');
    end
end