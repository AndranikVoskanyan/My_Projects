function [paritybits, codeword] = encode_ldpc(infobits, H, verbose)
%ENCODE_LDPC Systematic LDPC encoder for H = [A I].
%
% Example:
%   H0 = generate_ldpc(128, 256, 0, 1, 3);
%   [paritybits, codeword] = encode_ldpc(infobits, H0, 0);
%
% Inputs:
%   infobits - Column or row vector containing the information bits
%   H        - LDPC parity-check matrix in systematic form H = [A I]
%   verbose  - 1 to display encoding information, otherwise 0
%
% Outputs:
%   paritybits - Calculated parity bits as a column vector
%   codeword   - Complete systematic codeword [infobits; paritybits]
%
% The encoded codeword satisfies:
%   mod(H * codeword, 2) = 0

if nargin < 3
    verbose = 0;
end

% Convert information bits to a binary column vector
infobits = mod(double(infobits(:)), 2);

[number_of_checks, codeword_length] = size(H);

number_of_information_bits = ...
    codeword_length - number_of_checks;

if length(infobits) ~= number_of_information_bits
    error(['The number of information bits must be ', ...
        num2str(number_of_information_bits), '.']);
end

% Divide H into information and parity sections
A = H(:, 1:number_of_information_bits);
P = H(:, number_of_information_bits + 1:end);

% This encoder expects the parity section to be an identity matrix
if ~isequal(full(mod(P, 2)), eye(number_of_checks))
    error('The parity-check matrix must have the form H = [A I].');
end

% From H*[u;p] = 0:
%
% A*u + p = 0  over GF(2)
%
% Therefore:
% p = A*u mod 2
paritybits = mod(A * infobits, 2);
paritybits = full(paritybits);

% Complete systematic codeword
codeword = [infobits; paritybits];

% Verify that the codeword satisfies all parity checks
syndrome = mod(H * codeword, 2);

if any(syndrome ~= 0)
    error('Encoding failed: the generated codeword is invalid.');
end

if verbose == 1
    fprintf('Information bits: %d\n', length(infobits));
    fprintf('Parity bits:      %d\n', length(paritybits));
    fprintf('Codeword length:  %d\n', length(codeword));
    fprintf('Parity checks passed.\n');
end
end