`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:15:43 09/29/2026
// Design Name:   edge_detector
// Module Name:   /home/ise/Desktop/LED_PATTERNS/led_patterns/edge_detector_tb.v
// Project Name:  led_patterns
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: edge_detector
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module edge_detector_tb;

	// Inputs
	reg clk;
	reg reset_n;
	reg debounced_button;

	// Outputs
	wire rising_edge,falling_edge;

	// Instantiate the Unit Under Test (UUT)
	edge_detector uut (
		.clk(clk), 
		.reset_n(reset_n), 
		.debounced_button(debounced_button), 
		.rising_edge(rising_edge),
		.falling_edge(falling_edge)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset_n = 0;
		debounced_button = 0;
		#40 reset_n = 1;
		// Wait 100 ns for global reset to finish
		#90;
      debounced_button = 1;
				#80;
      debounced_button = 0;
		// Add stimulus here

	end
	initial begin
		forever begin
			#10 clk = ~clk;
		end
	end
      
endmodule

