`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:06:47 09/29/2026
// Design Name:   everything
// Module Name:   /home/ise/Desktop/LED_PATTERNS/led_patterns/everything_tb.v
// Project Name:  led_patterns
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: everything
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module everything_tb;

	// Inputs
	reg clk;
	reg reset_n;
	reg button;

	// Outputs
	wire [7:0] led;

	// Instantiate the Unit Under Test (UUT)
	everything uut (
		.clk(clk), 
		.reset_n(reset_n), 
		.button(button), 
		.led(led)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset_n = 0;
		button = 0;
		
		// Wait 100 ns for global reset to finish
		#80; reset_n = 1;
		// Add stimulus here
		#110; button = 1;
		#30; button = 0;
		#10; button = 1;
		#200; button = 0;
		#100; button = 1;
	end
   initial begin
		forever begin
			#10; clk = ~clk;
		end
	
	end
endmodule

