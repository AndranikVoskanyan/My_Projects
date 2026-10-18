`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:58:53 09/29/2026
// Design Name:   contorl_fsm
// Module Name:   /home/ise/Desktop/LED_PATTERNS/led_patterns/control_fsm.v
// Project Name:  led_patterns
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: contorl_fsm
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module control_fsm;

	// Inputs
	reg clk;
	reg reset_n;
	reg button_pressed;

	// Outputs
	wire [1:0] mode;

	// Instantiate the Unit Under Test (UUT)
	contorl_fsm uut (
		.clk(clk), 
		.reset_n(reset_n), 
		.button_pressed(button_pressed), 
		.mode(mode)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset_n = 0;
		button_pressed = 0;
		#30; reset_n = 1;
		// Wait 100 ns for global reset to finish
		#80; button_pressed = 1;
		#20; button_pressed = 0;
      #20; button_pressed = 1;
		#20; button_pressed = 0;  
      #20; button_pressed = 1;
		#20; button_pressed = 0;  
		      #20; button_pressed = 1;
		#20; button_pressed = 0;  
		// Add stimulus here

	end
   initial begin
		forever begin
			#10; clk = ~clk;
		end
	end
	
endmodule

