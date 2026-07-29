function [recovered_symbols, timing_errors, sample_positions] = gardner_function(rx_sig, K, sps)
%GARDNER_FUNCTION Gardner timing recovery for real or complex signals.
%
% INPUTS:
%   rx_sig - Matched-filtered received samples
%   K      - Timing-loop gain
%   sps    - Samples per symbol; use 2 in your project
%
% OUTPUTS:
%   recovered_symbols - One corrected sample per symbol
%   timing_errors      - Gardner timing error for each symbol
%   sample_positions   - Fractional sample positions selected

validateattributes(rx_sig, {'numeric'}, ...
    {'vector', 'nonempty', 'finite'});
validateattributes(K, {'numeric'}, ...
    {'scalar', 'real', 'finite'});
validateattributes(sps, {'numeric'}, ...
    {'scalar', 'real', 'finite', '>', 1});

inputWasColumn = iscolumn(rx_sig);
rx = rx_sig(:).';

maximumSymbols = floor((length(rx) - 2) / sps);

recovered_symbols = complex(zeros(1, maximumSymbols));
timing_errors = zeros(1, maximumSymbols);
sample_positions = zeros(1, maximumSymbols);

currentTime = 1 + sps;
symbolIndex = 0;

while currentTime + 1 <= length(rx)

    previousTime = currentTime - sps;
    midpointTime = currentTime - sps / 2;

    previousSample = linear_interpolate(rx, previousTime);
    midpointSample = linear_interpolate(rx, midpointTime);
    currentSample = linear_interpolate(rx, currentTime);

    % Gardner timing error
    timingError = real( ...
        (currentSample - previousSample) * conj(midpointSample));

    symbolIndex = symbolIndex + 1;

    recovered_symbols(symbolIndex) = currentSample;
    timing_errors(symbolIndex) = timingError;
    sample_positions(symbolIndex) = currentTime;

    % Move the next sampling instant according to the error
    currentTime = currentTime + sps - K * timingError;
end

recovered_symbols = recovered_symbols(1:symbolIndex);
timing_errors = timing_errors(1:symbolIndex);
sample_positions = sample_positions(1:symbolIndex);

if inputWasColumn
    recovered_symbols = recovered_symbols.';
    timing_errors = timing_errors.';
    sample_positions = sample_positions.';
end
end


function value = linear_interpolate(signal, position)

lowerIndex = floor(position);
fraction = position - lowerIndex;

if lowerIndex < 1 || lowerIndex >= length(signal)
    value = 0;
    return;
end

value = (1 - fraction) * signal(lowerIndex) ...
    + fraction * signal(lowerIndex + 1);
end