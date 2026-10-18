`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:44:18 09/29/2026
// Design Name:   button_sync
// Module Name:   /home/ise/Desktop/PWM_LIGHT_BRIGHTNES/pwm_control/button_sync_tb.v
// Project Name:  pwm_control
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
	reg reset;
	reg button_async;

	// Outputs
	wire button_sync;

	// Instantiate the Unit Under Test (UUT)
	button_sync uut (
		.clk(clk), 
		.reset(reset), 
		.button_async(button_async), 
		.button_sync(button_sync)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		button_async = 0;
		#30; reset = 0;
		// Wait 100 ns for global reset to finish
		#110; button_async = 1;
		#70; button_async = 0;
		// Add stimulus here

	end
      initial begin 
			 forever begin
				#10; clk = ~clk;
			 end
		end
endmodule

