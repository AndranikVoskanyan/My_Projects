function [best_a, best_b, best_GBLA, best_na, best_nb] = ...
         gtls_bla_aic(G, sigma_G2, na_max, nb_max, w_exc, fs)

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

Ts   = 1/fs;
zinv = exp(-1j*w_exc*Ts);  

best_AIC   = inf;
best_theta = [];
best_na    = 0;
best_nb    = 0;

for nb_cur = 1:nb_max
    for na_cur = nb_cur:na_max   

     
        Z_den = zeros(K, na_cur+1);
        for i = 0:na_cur
            Z_den(:, i+1) = zinv.^i;  
        end

     
        Z_num = zeros(K, nb_cur);
        for j = 0:nb_cur-1
            Z_num(:, j+1) = zinv.^j;    
        end

        
        Phi = [ (G .* Z_den),  (-Z_num) ];     
        L   = size(Phi,2);                     

 
        Cphi = zeros(L,L);
        for k = 1:K
            v = [ (zinv(k).^(0:na_cur)), zeros(1,nb_cur) ];  
            Cphi = Cphi + sigma_G2(k) * (v') * v;
        end
        Cphi = (Cphi + Cphi')/2;

        reg = 1e-12 * trace(Cphi)/max(1,L);
        if ~(isfinite(reg) && reg > 0), reg = 1e-12; end
        Cphi = Cphi + reg*eye(L);

        [V,D] = eig(Cphi);
        d = real(diag(D)); d(d<0)=0;
        C = V*diag(sqrt(d))*V';

        
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

        p = (X') \ e;      
        theta = p;       

        r   = Phi*theta;
        SSE = sum(abs(r).^2);

        npar = (na_cur+1) + nb_cur;  
        if ~(isfinite(SSE) && SSE > 0)
            continue;
        end
        AIC = 2*npar + K*log(SSE/K);

        if AIC < best_AIC
            best_AIC   = AIC;
            best_theta = theta;
            best_na    = na_cur;
            best_nb    = nb_cur;
        end
    end
end

if isempty(best_theta)
    error('GTLS: no valid model found (check orders / sigma_G2).');
end

a_part = best_theta(1:best_na+1);              
b_part = best_theta(best_na+2 : best_na+1+best_nb);

best_a = a_part.';    
best_b = b_part.';   

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