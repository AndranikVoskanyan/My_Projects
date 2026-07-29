function out = interpolate(rx_sig,index )
    % Simple linear interpolation
    index_round = floor(index);
    diff = index - index_round;
    if index_round >= 1 && index_round < length(rx_sig)
        out = (1 - diff) * rx_sig(index_round) + diff * rx_sig(index_round + 1);
    else
        out = 0;
    end
    
end