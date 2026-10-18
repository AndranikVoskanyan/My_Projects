`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:37:21 09/29/2026
// Design Name:   step_counter
// Module Name:   /home/ise/Desktop/LED_PATTERNS/led_patterns/step_counter_tb.v
// Project Name:  led_patterns
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: step_counter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module step_counter_tb;

	// Inputs
	reg clk;
	reg reset_n;
	reg tick;

	// Outputs
	wire [2:0] step;

	// Instantiate the Unit Under Test (UUT)
	step_counter uut (
		.clk(clk), 
		.reset_n(reset_n), 
		.tick(tick), 
		.step(step)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset_n = 0;
		tick = 0;

		// Wait 100 ns for global reset to finish
		#50; reset_n = 1;
		// Add stimulus here
		forever begin
		#40; tick = ~tick;
		#10; tick = ~tick;
		#10;
		
		end
	end
      initial begin
		
			forever begin
			
				#10; clk = ~clk;
			end
		end
endmodule

