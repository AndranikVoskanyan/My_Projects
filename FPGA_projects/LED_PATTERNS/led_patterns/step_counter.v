`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:34:32 09/29/2026 
// Design Name: 
// Module Name:    step_counter 
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
module step_counter(
	input wire clk,reset_n,tick,
	output wire [2:0] step
    );

reg [2:0] step_counter;
always @(posedge clk or negedge reset_n) begin
	if(!reset_n) begin
		step_counter <= 0;
	end
	else if (tick) begin
		step_counter <= step_counter + 1'b1;
	end
end
assign step = step_counter;
endmodule
