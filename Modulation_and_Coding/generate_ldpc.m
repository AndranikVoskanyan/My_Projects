function H = generate_ldpc(K, N, seed, make_sparse, column_weight)
%GENERATE_LDPC Generate a systematic LDPC parity-check matrix.
%
% Example:
%   H0 = generate_ldpc(128, 256, 0, 1, 3);
%
% Inputs:
%   K             - Number of information bits
%   N             - Total codeword length
%   seed          - Random seed
%   make_sparse   - 1 for sparse matrix, 0 for full matrix
%   column_weight - Number of ones in each information-bit column
%
% Output:
%   H - Binary parity-check matrix with form:
%
%       H = [A I]
%
% Matrix size:
%   (N-K) x N

if nargin < 3 || isempty(seed)
    seed = 0;
end

if nargin < 4 || isempty(make_sparse)
    make_sparse = 1;
end

if nargin < 5 || isempty(column_weight)
    column_weight = 3;
end

if N <= K
    error('N must be larger than K.');
end

M = N - K;

if column_weight > M
    error('column_weight cannot be larger than N-K.');
end

rng(seed);

% Information part of parity-check matrix
A = zeros(M, K);

% Track the number of ones in every row
row_weights = zeros(M, 1);

for col = 1:K

    % Random value used when several rows have equal weight
    random_values = rand(M, 1);

    % Prefer rows with the smallest current weight
    [~, row_order] = sortrows( ...
        [row_weights, random_values], [1 2]);

    selected_rows = row_order(1:column_weight);

    A(selected_rows, col) = 1;

    row_weights(selected_rows) = ...
        row_weights(selected_rows) + 1;
end

% Ensure that no parity-check row is empty
empty_rows = find(sum(A, 2) == 0);

for i = 1:length(empty_rows)
    selected_column = randi(K);
    A(empty_rows(i), selected_column) = 1;
end

% Systematic parity-check matrix H = [A I]
H = [A eye(M)];

% Convert to binary values
H = mod(H, 2);

if make_sparse == 1
    H = sparse(H);
end
end