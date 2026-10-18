`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:23:55 09/29/2026
// Design Name:   button_control
// Module Name:   /home/ise/Desktop/PWM_LIGHT_BRIGHTNES/pwm_control/button_control_tb.v
// Project Name:  pwm_control
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: button_control
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module button_control_tb;

	// Inputs
	reg clk;
	reg reset;
	reg button_signal;

	// Outputs
	wire rising_edge;
	wire falling_edge;

	// Instantiate the Unit Under Test (UUT)
	button_control uut (
		.clk(clk), 
		.reset(reset), 
		.button_signal(button_signal), 
		.rising_edge(rising_edge), 
		.falling_edge(falling_edge)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		button_signal = 0;
		#30; reset = 0;
		// Wait 100 ns for global reset to finish
		#110; button_signal = 1; #50; button_signal = 0;
      #70; button_signal = 1; #200; button_signal = 0;
		// Add stimulus here

	end
      initial begin
			forever begin
				#10;clk = ~clk;
			end
		end
endmodule

