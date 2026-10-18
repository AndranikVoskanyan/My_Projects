`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:14:23 09/28/2026 
// Design Name: 
// Module Name:    counter 
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
module counter #( 
	parameter N = 16
)
(
	input wire clk, reset_n,
	output wire [N-1:0] counter
);

reg [N-1:0] counter_reg;


always @(posedge clk or negedge reset_n) begin
	if(!reset_n) begin
		counter_reg <= 0;
	end
	else begin
		counter_reg <= counter_reg +1'b1;
	end
end

assign counter = counter_reg;

endmodule
