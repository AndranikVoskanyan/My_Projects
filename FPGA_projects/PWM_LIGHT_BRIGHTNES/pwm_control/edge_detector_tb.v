`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:06:37 09/29/2026
// Design Name:   edge_detector
// Module Name:   /home/ise/Desktop/PWM_LIGHT_BRIGHTNES/pwm_control/edge_detector_tb.v
// Project Name:  pwm_control
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
	reg reset;
	reg debounced_button;

	// Outputs
	wire rising_edge;
	wire falling_edge;

	// Instantiate the Unit Under Test (UUT)
	edge_detector uut (
		.clk(clk), 
		.reset(reset), 
		.debounced_button(debounced_button), 
		.rising_edge(rising_edge), 
		.falling_edge(falling_edge)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		debounced_button = 0;
		#30; reset = 0;
		// Wait 100 ns for global reset to finish
		#100; debounced_button = 1; #40 debounced_button = 0;
        
		// Add stimulus here

	end
     initial begin 
		forever begin
			#10; clk = ~clk;
		end
	  end
endmodule

