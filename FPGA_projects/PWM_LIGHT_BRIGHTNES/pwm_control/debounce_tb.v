`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:02:43 09/29/2026
// Design Name:   debounce
// Module Name:   /home/ise/Desktop/PWM_LIGHT_BRIGHTNES/pwm_control/debounce_tb.v
// Project Name:  pwm_control
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
	reg reset;
	reg button_sync;

	// Outputs
	wire debounced_button;

	// Instantiate the Unit Under Test (UUT)
	debounce uut (
		.clk(clk), 
		.reset(reset), 
		.button_sync(button_sync), 
		.debounced_button(debounced_button)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		button_sync = 0;
		#30 reset = 0;
		// Wait 100 ns for global reset to finish
		#100; button_sync = 1; #40 button_sync = 0;
      #40; button_sync = 1; 
		// Add stimulus here

	end
      initial begin
			forever begin 
				#10; clk = ~clk;
			end
		end
endmodule

