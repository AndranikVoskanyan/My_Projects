function [best_a, best_b, best_GBLA, best_na, best_nb] = ...
    tls_bla_aic(G, na_max, nb_max, w_exc, fs)

G     = G(:);
w_exc = w_exc(:);

K  = length(G);
Ts = 1/fs;

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

best_AIC  = inf;
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
        J        = [-G_mat .* Zden_cur,Znum_cur];

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
        G_hat = B_z ./ A_z;

        e      = G - G_hat;
        RSS    = sum(abs(e).^2);
        sigma2 = RSS / K;
        if sigma2 < realmin
            sigma2 = realmin;
        end

        p   = nA + nB;
        AIC = 2*p + K * log(sigma2);

        if AIC < best_AIC
            best_AIC  = AIC;
            best_a    = a_norm.';
            best_b    = b_norm.';
            best_GBLA = G_hat;
            best_na   = na_ord;
            best_nb   = nb_ord;
        end
    end
end