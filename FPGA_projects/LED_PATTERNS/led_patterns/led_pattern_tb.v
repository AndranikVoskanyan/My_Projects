`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:25:36 09/28/2026
// Design Name:   led_pattern
// Module Name:   /home/ise/Desktop/LED_PATTERNS/led_patterns/led_pattern_tb.v
// Project Name:  led_patterns
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: led_pattern
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module led_pattern_tb;

	// Inputs
	reg [1:0] mode;
	reg [2:0] step;

	// Outputs
	wire [7:0] led;

	// Instantiate the Unit Under Test (UUT)
	led_pattern uut (
		.mode(mode), 
		.step(step), 
		.led(led)
	);

	initial begin
		// Initialize Inputs
		mode = 2'b11;
		step = 3'b000;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
	initial begin
      forever begin
			#10; step = step+1;
			
		end
	end
endmodule

