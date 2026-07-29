function [best_a, best_b, best_GBLA, best_na, best_nb] = ...
    lls_bla_sigma(G, sigma_G2, na_max, nb_max, w_exc, fs)


G     = G(:);
w_exc = w_exc(:);
K     = length(G);

if nargin < 2 || isempty(sigma_G2)
    sigma_G2 = ones(K,1);
else
    sigma_G2 = real(sigma_G2(:));
    if numel(sigma_G2) == 1
        sigma_G2 = sigma_G2 * ones(K,1);
    end
end
if length(sigma_G2) ~= K
    error('sigma_G2 must be length K (same as G).');
end
sigma_G2 = max(sigma_G2, 1e-30); 

Ts  = 1/fs;
z   = exp(1j * w_exc*Ts);

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

best_cost       = inf;
best_a_internal = [];
best_b          = [];
best_GBLA       = [];
best_na         = 0;
best_nb         = 0;

for nb_cur = 1:nb_max
    for na_cur = nb_cur:na_max

        Phi_num = Z_num(:, 1:nb_cur);
        Phi_den = Phi_den_full(:, 1:na_cur);
        Phi     = [Phi_den Phi_num];

        theta = Phi \ G;

        b_hat = theta(na_cur+1:end);
        a_hat = theta(1:na_cur);

        A_z  = 1 + Z_den(:,1:na_cur) * a_hat;
        B_z  = Z_num(:,1:nb_cur)     * b_hat;

        if any(abs(A_z) < 1e-14)
            continue; 
        end

        G_hat = B_z ./ A_z;

    
        e  = G - G_hat;
        Jw = sum( (abs(e).^2) ./ sigma_G2 );
        Jw_K =  Jw/K;
        Jw = 2*(na_cur+nb_cur) + K*log(Jw_K);
        if isfinite(Jw) && (Jw < best_cost)
            best_cost       = Jw;
            best_a_internal = a_hat(:).';
            best_b          = b_hat(:).';
            best_GBLA       = G_hat;
            best_na         = na_cur;
            best_nb         = nb_cur;
        end
    end
end

if isempty(best_GBLA)
    error('LLS: no valid model found (check na_max/nb_max / sigma_G2).');
end

best_a  = [1 best_a_internal];    
best_na = length(best_a) - 1;
best_nb = length(best_b);
end