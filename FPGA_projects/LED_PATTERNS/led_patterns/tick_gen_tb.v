`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:26:17 09/29/2026
// Design Name:   tick_generator
// Module Name:   /home/ise/Desktop/LED_PATTERNS/led_patterns/tick_gen_tb.v
// Project Name:  led_patterns
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: tick_generator
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module tick_gen_tb;

	// Inputs
	reg clk;
	reg reset_n;

	// Outputs
	wire tick;

	// Instantiate the Unit Under Test (UUT)
	tick_generator uut (
		.clk(clk), 
		.reset_n(reset_n), 
		.tick(tick)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset_n = 0;
		
		// Wait 100 ns for global reset to finish
		#50;
        reset_n = 1;
		// Add stimulus here

	end
   initial begin 
	 forever begin
	 #10; clk = ~clk;
	 end
	end
endmodule

