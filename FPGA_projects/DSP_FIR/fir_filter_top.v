`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:49:48 10/08/2026 
// Design Name: 
// Module Name:    fir_filter_top 
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
module fir_filter_top  (input  wire clk,
    input  wire rst,
    input  wire sample_valid,
    input  wire signed [7:0] sample_in,

    output wire signed [17:0] fir_out,
    output wire output_valid
);


	localparam signed [7:0] coeff0 = 8'sd5;
	localparam signed [7:0] coeff1 = 8'sd59;
	localparam signed [7:0] coeff2 = 8'sd59;
	localparam signed [7:0] coeff3 = 8'sd5;	
    wire signed [7:0] x0, x1, x2, x3;

    wire signed [15:0] p0x0;
    wire signed [15:0] p1x1;
    wire signed [15:0] p2x2;
    wire signed [15:0] p3x3;

    wire val_for_mul;
    wire val_for_accum;

    fir_delay_line delay_inst (
        .clk(clk),
        .rst(rst),
        .sample_valid(sample_valid),
        .sample_in(sample_in),

        .x0(x0),
        .x1(x1),
        .x2(x2),
        .x3(x3),
        .val_for_mul(val_for_mul)
    );

    coef_mul #(.coeff0(coeff0),
					.coeff1(coeff1),
					.coeff2(coeff2),
					.coeff3(coeff3)) mul_inst (
        .clk(clk),
        .rst(rst),
        .valid_mul(val_for_mul),

        .x0(x0),
        .x1(x1),
        .x2(x2),
        .x3(x3),

        .p0x0(p0x0),
        .p1x1(p1x1),
        .p2x2(p2x2),
        .p3x3(p3x3),

        .valid_accum(val_for_accum)
    );


   accum_stage accum_inst (
        .clk(clk),
        .rst(rst),
        .valid_accum(val_for_accum),

        .p0x0(p0x0),
        .p1x1(p1x1),
        .p2x2(p2x2),
        .p3x3(p3x3),

        .accum_val(fir_out),
        .valid_next_stage(output_valid)
    );
	 
endmodule
