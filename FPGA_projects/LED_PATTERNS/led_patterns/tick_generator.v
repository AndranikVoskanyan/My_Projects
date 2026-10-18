`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:01:35 09/28/2026 
// Design Name: 
// Module Name:    tick_generator 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module tick_generator #(
    parameter COUNT_MAX = 10,
	 parameter COUNTER_BITS = 4
)(
    input  wire clk,
    input  wire reset_n,
    output wire tick
);

reg [COUNTER_BITS-1:0] counter;
reg slower_clock;

always @(posedge clk or negedge reset_n) begin
	if(!reset_n) begin
		counter <= 0;
		slower_clock <=0;
	end
	else begin
		if(counter == COUNT_MAX - 1) begin
			slower_clock <= 1;
			counter <=0;
		end
		else begin
			counter <= counter+1;
			slower_clock <=0;
		end
	end
	
end

assign tick = slower_clock;
endmodule
