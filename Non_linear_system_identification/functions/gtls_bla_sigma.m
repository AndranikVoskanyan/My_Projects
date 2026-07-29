function [best_a, best_b, best_GBLA, best_na, best_nb, best_cost] = ...
         gtls_bla_sigma(G, sigma_G2, na_max, nb_max, w_exc, fs)
%GTLS_BLA_WVAR_A0FREE_Z  GTLS (z^-1 domain) with free a0, model order chosen
% by variance-weighted FRF error (no AIC).
%
% Model:
%   G(z) = B(z^-1) / A(z^-1)
%   A(z^-1) = a0 + a1 z^-1 + ... + a_na z^-na   (a0 is estimated, NOT forced to 1)
%   B(z^-1) = b0 + b1 z^-1 + ... + b_{nb-1} z^{-(nb-1)}
%
% Homogeneous equation at each excited line k:
%   G_k*A(z_k^-1) - B(z_k^-1) = 0
% => Phi * theta ≈ 0, with theta = [a0..a_na, b0..b_{nb-1}]^T
%
% GTLS solves (via GSVD):
%   min ||Phi*theta||_2   s.t.  || C^(1/2) * theta ||_2 = 1
% where C is column covariance of Phi induced by uncertainty in G_k:
%   Var(G_k) = sigma_G2(k)
%
% Model order selection criterion (variance-linked):
%   Jw = sum_k |G(k) - G_model(k)|^2 / sigma_G2(k)
%
% Inputs:
%   G        : Kx1 complex FRF on excited lines (e.g. G_ML_excited)
%   sigma_G2 : Kx1 variance of FRF at excited lines (e.g. sigma_ML2_excited)
%   na_max   : maximum denominator order (highest power in z^-1), includes a0..a_na
%   nb_max   : maximum numerator order (number of b's), b0..b_{nb-1}
%   w_exc    : Kx1 rad/s (excited lines)
%   fs       : sampling rate (Hz)
%
% Outputs:
%   best_a     : 1x(na+1)  [a0 a1 ... a_na]
%   best_b     : 1x(nb)    [b0 ... b_{nb-1}]
%   best_GBLA  : Kx1 fitted FRF on excited lines
%   best_na, best_nb
%   best_cost  : best variance-weighted cost Jw

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

% avoid division by zero in weights
sigma_G2 = max(sigma_G2, 1e-30);

Ts   = 1/fs;
zinv = exp(-1j*w_exc*Ts);   % z^-1 points on unit circle

best_cost  = inf;
best_theta = [];
best_na    = 0;
best_nb    = 0;

for nb_cur = 1:nb_max
    for na_cur = nb_cur:na_max   % keep your na>=nb rule (optional)

        % ---------- Build basis in z^-1
        % Denominator basis includes i=0..na (a0..a_na)
        Z_den = zeros(K, na_cur+1);
        for i = 0:na_cur
            Z_den(:, i+1) = zinv.^i;     % z^-i
        end

        % Numerator basis includes j=0..nb-1 (b0..b_{nb-1})
        Z_num = zeros(K, nb_cur);
        for j = 0:nb_cur-1
            Z_num(:, j+1) = zinv.^j;     % z^-j
        end

        % Homogeneous regression:  [ G*Z_den , -Z_num ] * theta ≈ 0
        Phi = [ (G .* Z_den),  (-Z_num) ];     % K x L
        L   = size(Phi,2);                      % L = (na+1) + nb

        % ---------- Column covariance Cphi = E{ dPhi^H dPhi }
        % Only the (G*Z_den) part depends on G. For row k:
        % dPhi_k = dG_k * [ z^0 .. z^-na , 0..0 ]
        Cphi = zeros(L,L);
        for k = 1:K
            v = [ (zinv(k).^(0:na_cur)), zeros(1,nb_cur) ];  % 1 x L
            Cphi = Cphi + sigma_G2(k) * (v') * v;
        end
        Cphi = (Cphi + Cphi')/2;

        % Regularize for numerical stability
        reg = 1e-12 * trace(Cphi)/max(1,L);
        if ~(isfinite(reg) && reg > 0), reg = 1e-12; end
        Cphi = Cphi + reg*eye(L);

        % C = sqrt(Cphi)
        [V,D] = eig(Cphi);
        d = real(diag(D)); d(d<0)=0;
        C = V*diag(sqrt(d))*V';

        % ---------- GTLS solve via GSVD(Phi, C)
        try
            [~,~,X,Cg,Sg] = gsvd(Phi, C);
        catch
            continue;
        end

        c = diag(Cg);  s = diag(Sg);
        ratio = inf(size(c));
        ok = abs(s) > 0;
        ratio(ok) = abs(c(ok))./abs(s(ok));

        [~, idx] = min(ratio);
        e = zeros(length(ratio),1); e(idx)=1;

        theta = (X') \ e;   % generalized right singular vector

        % ---------- Build model FRF and compute variance-weighted cost
        a_part = theta(1:na_cur+1);                 % a0..a_na
        b_part = theta(na_cur+2 : na_cur+1+nb_cur); % b0..b_{nb-1}

        A = zeros(K,1);
        for i = 0:na_cur
            A = A + a_part(i+1) * (zinv.^i);
        end

        B = zeros(K,1);
        for j = 0:nb_cur-1
            B = B + b_part(j+1) * (zinv.^j);
        end

        if any(abs(A) < 1e-14)
            continue; % avoid blow-up
        end

        G_model = B ./ A;
        err = G - G_model;

        Jw = sum( (abs(err).^2) ./ sigma_G2 );

        if isfinite(Jw) && (Jw < best_cost)
            best_cost  = Jw;
            best_theta = theta;
            best_na    = na_cur;
            best_nb    = nb_cur;
        end
    end
end

if isempty(best_theta)
    error('GTLS: no valid model found (check orders / sigma_G2).');
end

% ---------- Return best coefficients
a_part = best_theta(1:best_na+1);
b_part = best_theta(best_na+2 : best_na+1+best_nb);

best_a = a_part.';    % [a0 a1 ... a_na]
best_b = b_part.';    % [b0 ... b_{nb-1}]

% ---------- Best fitted FRF
A = zeros(K,1);
for i = 0:best_na
    A = A + a_part(i+1) * (zinv.^i);
end

B = zeros(K,1);
for j = 0:best_nb-1
    B = B + b_part(j+1) * (zinv.^j);
end

best_GBLA = B ./ A;
end
