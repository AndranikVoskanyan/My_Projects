`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:57:17 10/08/2026
// Design Name:   fir_filter_top
// Module Name:   /home/ise/Desktop/DSP_FIR/fir_top_tb.v
// Project Name:  DSP_FIR
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: fir_filter_top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module fir_top_tb;

	// Inputs
	reg clk;
	reg rst;
	reg sample_valid;
	reg [7:0] sample_in;

	// Outputs
	wire [17:0] fir_out;
	wire output_valid;

	// Instantiate the Unit Under Test (UUT)
	fir_filter_top uut (
		.clk(clk), 
		.rst(rst), 
		.sample_valid(sample_valid), 
		.sample_in(sample_in), 
		.fir_out(fir_out), 
		.output_valid(output_valid)
	);
	
	always #5 clk = ~clk;
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		sample_valid = 0;
		sample_in = 0;
		#30; rst = 0;
		// Wait 100 ns for global reset to finish
		#105; sample_in = 'sd64; sample_valid = 1;
		#10; sample_in = 'sd0; sample_valid = 1;
      #10; sample_in = 'sd0; sample_valid = 1;
      #10; sample_in = 'sd0; sample_valid = 1;
		// Add stimulus here

	end
      
endmodule

