function [best_a, best_b, best_GBLA, best_na, best_nb] = ...
    tls_bla_sigma(G, sigma_G2, na_max, nb_max, w_exc, fs)

G     = G(:);
w_exc = w_exc(:);

K  = length(G);
Ts = 1/fs;

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

w_d = w_exc*Ts;
z   = exp(1j * w_d);

Z_num = zeros(K, nb_max+1);
for j = 1:(nb_max+1)
    Z_num(:, j) = z.^(-(j-1));
end

Z_den = zeros(K, na_max+1);
for j = 1:(na_max+1)
    Z_den(:, j) = z.^(-(j-1));
end

best_cost = inf;
best_a    = [];
best_b    = [];
best_GBLA = [];
best_na   = 0;
best_nb   = 0;

for nb_ord = 0:nb_max
    nB       = nb_ord + 1;
    Znum_cur = Z_num(:,1:nB);

    for na_ord = max(1,nb_ord):na_max
        nA       = na_ord + 1;
        Zden_cur = Z_den(:,1:nA);
        G_mat    = repmat(G,1,nA);

        J = [-G_mat .* Zden_cur, Znum_cur];

        [~,~,V] = svd(J,'econ');
        v       = V(:,end);

        b_all = v(nA+1:end);
        a_all = v(1:nA);

        scale = a_all(1);
        if abs(scale) < 1e-12
            a_norm = a_all;
            b_norm = b_all;
        else
            a_norm = a_all / scale;
            b_norm = b_all / scale;
        end

        A_z   = Zden_cur * a_norm;
        B_z   = Znum_cur * b_norm;

        if any(abs(A_z) < 1e-14)
            continue; 
        end

        G_hat = B_z ./ A_z;

        e  = G - G_hat;
        Jw = sum( (abs(e).^2) ./ sigma_G2 );

        if isfinite(Jw) && (Jw < best_cost)
            best_cost = Jw;
            best_a    = a_norm.'; 
            best_b    = b_norm.';
            best_GBLA = G_hat;
            best_na   = na_ord;
            best_nb   = nb_ord;
        end
    end
end

if isempty(best_GBLA)
    error('TLS: no valid model found (check na_max/nb_max / sigma_G2).');
end

end