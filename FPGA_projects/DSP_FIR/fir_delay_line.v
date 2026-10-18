`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:56:18 10/08/2026 
// Design Name: 
// Module Name:    fir_delay_line 
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
module fir_delay_line (
    input  wire clk,
    input  wire rst,
    input  wire sample_valid,
    input  wire signed [7:0] sample_in,

    output reg signed [7:0] x0,
    output reg signed [7:0] x1,
    output reg signed [7:0] x2,
    output reg signed [7:0] x3,
	 output reg val_for_mul
);


always @(posedge clk) begin
	if(rst) begin
		x0 <= 0;
		x1 <= 0;
		x2 <= 0;
		x3 <= 0;
		val_for_mul <= 1'b0;
	end
	else begin
		val_for_mul <= sample_valid;
		if(sample_valid) begin
			x0 <= sample_in;
			x1 <= x0;
			x2 <= x1;
			x3 <= x2;
		end
	end
end



endmodule 