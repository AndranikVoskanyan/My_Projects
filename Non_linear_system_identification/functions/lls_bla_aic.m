function [best_a, best_b, best_GBLA, best_na, best_nb] = ...
         lls_bla_aic(G, na_max, nb_max, w_exc, fs)

G     = G(:);
w_exc = w_exc(:);

K  = length(G);
Ts = 1/fs;
w_d = w_exc*Ts;
z   = exp(1j * w_d);
Z_num = zeros(K, nb_max);
for j = 1:nb_max
    Z_num(:, j) = z.^(-(j-1));
end

Z_den = zeros(K, na_max);
for i = 1:na_max
    Z_den(:, i) = z.^(-i);
end

G_mat = repmat(G, 1, na_max);
Phi_den_full = -G_mat .* Z_den;

best_AIC        = inf;
best_a_internal = [];
best_b          = [];
best_GBLA       = [];
best_na         = 0;
best_nb         = 0;

for nb_cur = 1:nb_max
    for na_cur = nb_cur:na_max

        Phi_num = Z_num(:, 1:nb_cur);
        Phi_den = Phi_den_full(:, 1:na_cur);
        Phi     = [Phi_den Phi_num ];

        theta = Phi \ G;

        b_hat = theta(na_cur+1:end);
        a_hat = theta(1:na_cur);

        A_z = 1 + Z_den(:,1:na_cur) * a_hat;
        B_z = Z_num(:,1:nb_cur)   * b_hat;
        G_hat = B_z ./ A_z;

        e     = G - G_hat;
        RSS   = sum(abs(e).^2);
        sigma2 = RSS / K;
        if sigma2 < realmin
            sigma2 = realmin;
        end

        p   = na_cur + nb_cur;
        AIC = 2*p + K * log(sigma2);

        if AIC < best_AIC
            best_AIC        = AIC;
            best_a_internal = a_hat(:).';
            best_b          = b_hat(:).';
            best_GBLA       = G_hat;
            best_na         = na_cur;
            best_nb         = nb_cur;
        end
    end
end

best_a = [1 best_a_internal];
best_na = length(best_a) - 1;
best_nb = length(best_b);