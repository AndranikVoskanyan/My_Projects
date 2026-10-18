`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:14:59 10/08/2026 
// Design Name: 
// Module Name:    accum_stage 
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
module accum_stage(
	input wire clk,rst,valid_accum,
	input wire signed [15:0] p0x0,p1x1,p2x2,p3x3,
	output reg signed[17:0] accum_val,
	output reg valid_next_stage
    );
	wire signed [17:0] p0_ext;
	wire signed [17:0] p1_ext;
	wire signed [17:0] p2_ext;
	wire signed [17:0] p3_ext;

	assign p0_ext = {{2{p0x0[15]}}, p0x0};
	assign p1_ext = {{2{p1x1[15]}}, p1x1};
	assign p2_ext = {{2{p2x2[15]}}, p2x2};
	assign p3_ext = {{2{p3x3[15]}}, p3x3};
	 always @(posedge clk) begin
		if(rst) begin
			accum_val <= 0;
			valid_next_stage <= 0;
		end
		else begin
		   valid_next_stage <= valid_accum;
			if(valid_accum) begin
				accum_val <= (	p0_ext + p1_ext + p2_ext + p3_ext) >>>7;
			end
		end
	 end


endmodule
