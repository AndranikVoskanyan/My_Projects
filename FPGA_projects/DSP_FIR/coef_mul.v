`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:00:08 10/08/2026 
// Design Name: 
// Module Name:    coef_mul 
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
module coef_mul#(
	parameter signed [7:0] coeff0 = 8'sh20, 
	parameter signed [7:0] coeff1 = 8'sh20, 
	parameter signed [7:0] coeff2 = 8'sh20,
	parameter signed [7:0] coeff3 = 8'sh20
)(
	input wire clk,rst,valid_mul,
	input wire signed [7:0] x0,x1,x2,x3,
	output reg signed [15:0] p0x0,p1x1,p2x2,p3x3,
	output reg valid_accum
    );

always @(posedge clk) begin
	if(rst) begin
		p0x0 <= 0;
		p1x1 <= 0;
		p2x2 <= 0;
		p3x3 <= 0;
		valid_accum <= 0;
	end
	else begin
	   valid_accum <= valid_mul;

		if(valid_mul) begin
			p0x0 <= x0*coeff0;
			p1x1 <= x1*coeff1;
			p2x2 <= x2*coeff2;
			p3x3 <= x3*coeff3;
		end
	end
end

endmodule
