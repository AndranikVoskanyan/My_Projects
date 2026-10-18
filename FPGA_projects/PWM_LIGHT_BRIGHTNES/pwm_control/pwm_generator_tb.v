`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:25:11 09/29/2026
// Design Name:   pwm_generator
// Module Name:   /home/ise/Desktop/PWM_LIGHT_BRIGHTNES/pwm_control/pwm_generator_tb.v
// Project Name:  pwm_control
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: pwm_generator
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module pwm_generator_tb;

	localparam  PWM_WIDTH = 8;
	reg clk,reset;
   reg [PWM_WIDTH-1:0] duty_cycle;
	wire pwm_out;
	// Instantiate the Unit Under Test (UUT)
	pwm_generator #(PWM_WIDTH) uut (
	.clk(clk), 
	.reset(reset),
	.duty_cycle(duty_cycle),
	.pwm_out(pwm_out)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		duty_cycle = 0;
		// Wait 100 ns for global reset to finish
		#40; duty_cycle = 0;reset = 0;
		#1000000; duty_cycle = 64;
		#1000000;	duty_cycle = 128;
		#1000000;	duty_cycle = 192;
		#1000000;	duty_cycle = 255;
        
		// Add stimulus here

	end
      initial begin 
			forever begin
				#10 clk = ~clk;
			end
		end
endmodule

