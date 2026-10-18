`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:07:59 09/29/2026
// Design Name:   brightness_control
// Module Name:   /home/ise/Desktop/PWM_LIGHT_BRIGHTNES/pwm_control/brightness_control_tb.v
// Project Name:  pwm_control
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: brightness_control
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module brightness_control_tb;

	// Inputs
	reg clk;
	reg reset;
	reg increase;
	reg decrease;

	// Outputs
	wire [7:0] duty_cycle;

	// Instantiate the Unit Under Test (UUT)
	brightness_control uut (
		.clk(clk), 
		.reset(reset), 
		.increase(increase), 
		.decrease(decrease), 
		.duty_cycle(duty_cycle)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		increase = 0;
		decrease = 0;
		#30; reset = 0;
		// Wait 100 ns for global reset to finish
		#100; increase = 1; #20; increase = 0;
      #40; increase = 1;  #20; increase = 0;
		#40; increase = 1;  #20; increase = 0;
		#40; increase = 1;  #20; increase = 0;
		#40; increase = 1;  #20; increase = 0;
		#40; increase = 1;  #20; increase = 0;
		#40; increase = 1;  #20; increase = 0;
		#40; increase = 1;  #20; increase = 0;
			#40; increase = 1;  #20; increase = 0;
		#40; increase = 1;  #20; increase = 0;
		#40; decrease = 1;  #20; decrease = 0;
		#40; decrease = 1;  #20; decrease = 0;
		#40; decrease = 1;  #20; decrease = 0;
		#40; decrease = 1;  #20; decrease = 0;
		#40; decrease = 1;  #20; decrease = 0;
		#40; decrease = 1;  #20; decrease = 0;
		#40; decrease = 1;  #20; decrease = 0;
				#40; decrease = 1;  #20; decrease = 0;
		#40; decrease = 1;  #20; decrease = 0;
		#40; decrease = 1;  #20; decrease = 0;
		#40; decrease = 1;  #20; decrease = 0;
		// Add stimulus here

	end
	initial begin
		forever begin
			#10; clk=~clk;
		end
	end
endmodule

