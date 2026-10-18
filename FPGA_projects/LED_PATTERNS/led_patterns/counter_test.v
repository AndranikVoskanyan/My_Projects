`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:32:24 09/28/2026
// Design Name:   counter
// Module Name:   /home/ise/Desktop/LED_PATTERNS/led_patterns/counter_test.v
// Project Name:  led_patterns
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: counter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module counter_test;

	// Inputs
	reg clk;
	reg reset;

	// Outputs
	wire [15:0] counter;

	// Instantiate the Unit Under Test (UUT)
	counter uut (
		.clk(clk), 
		.reset_n(reset), 
		.counter(counter)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
      #20;reset = 0;
		// Wait 100 ns for global reset to finish
		#100; reset = 1'b1;
		
		// Add stimulus here

	end
	initial begin
    forever begin
		 #10	clk = ~clk;
		end  
		end
endmodule

