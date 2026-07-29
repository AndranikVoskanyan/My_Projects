function [toa, cfo] = dataAcquisition(sig, a, K, Tsymb)

    N = length(a);
    D = zeros(length(K),length(sig));

    sumK=zeros(1,length(sig));
    y = [sig zeros(1,N)]; %zero pad the signal otherwise exceed index error

    for k = 1:K
        %compute Dk for each n
        for n = 1:length(sig)-N+1
            sumDk = 0;
            for L = k:N-1
                sumDk = sumDk + (conj(y(n+L))*a(L+1)) * conj((conj(y(n+L-k))*a(L-k+1)));
            end
            D(k,n) = (1/(N-k))*sumDk; %Differential cross correlation
        end
        %update sum to maximaze in order to find n_estimate 
        sumK = sumK + abs(D(k,:));
    end

    [~, toa] = max(sumK);
  
    
    sumDeltaF = 0;
    for k = 1:K
        sumDeltaF = sumDeltaF + ( angle(D(k,toa))/(2*pi*k*Tsymb) );
    end
    cfo = -(1/K)*sumDeltaF;

end