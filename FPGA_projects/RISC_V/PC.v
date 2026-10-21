`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:18:06 10/15/2026 
// Design Name: 
// Module Name:    PC 
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
module PC(
	input wire clk,rst,stall,
	input wire [31:0] next_pc,
	output reg [31:0] pc
    );

	always @(posedge clk) begin
		if(rst) begin
			pc <= 0;
		end
		else begin
			if (!stall) begin
				pc <= next_pc;
			end
		end
	end
endmodule
