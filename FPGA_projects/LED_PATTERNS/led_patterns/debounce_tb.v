`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:47:36 09/28/2026
// Design Name:   debounce
// Module Name:   /home/ise/Desktop/LED_PATTERNS/led_patterns/debounce_tb.v
// Project Name:  led_patterns
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: debounce
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module debounce_tb;

	// Inputs
	reg clk;
	reg reset_n;
	reg button_sync;

	// Outputs
	wire debounced_button;

	// Instantiate the Unit Under Test (UUT)
	debounce #(4,3) uut (
		.clk(clk), 
		.reset_n(reset_n), 
		.button_sync(button_sync), 
		.debounced_button(debounced_button)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset_n = 0;
		button_sync = 0;
		
		#10; reset_n = 0;
		// Wait 100 ns for global reset to finish
		#100;
		reset_n = 1;
		#40; button_sync = 1;
		// Add stimulus here
		#30; button_sync = 0;
		#90; button_sync = 1;
	   #130; button_sync = 0;
	
	end
      
	initial begin
			forever begin
				#10; clk = ~clk;
			end
			
	end
	
endmodule

