`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:21:17 09/28/2026
// Design Name:   button_sync
// Module Name:   /home/ise/Desktop/LED_PATTERNS/led_patterns/button_sync_tb.v
// Project Name:  led_patterns
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: button_sync
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module button_sync_tb;

	// Inputs
	reg clk;
	reg reset_n;
	reg button_async;

	// Outputs
	wire button_sync;

	// Instantiate the Unit Under Test (UUT)
	button_sync uut (
		.clk(clk), 
		.reset_n(reset_n), 
		.button_async(button_async), 
		.button_sync(button_sync)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset_n = 1;
		button_async = 0;
		
		#10; reset_n = 0;
		// Wait 100 ns for global reset to finish
		#100;
		reset_n = 1;
      button_async = 1;
		// Add stimulus here

	end
   initial begin
			forever begin
				#10; clk = ~clk;
			end
			
	end
	initial begin
			forever begin
				#25; button_async = ~button_async;
			end
			
	end
endmodule

