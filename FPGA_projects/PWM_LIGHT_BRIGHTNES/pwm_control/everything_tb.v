`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:49:35 09/29/2026
// Design Name:   everything
// Module Name:   /home/ise/Desktop/PWM_LIGHT_BRIGHTNES/pwm_control/everything_tb.v
// Project Name:  pwm_control
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: everything
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module everything_tb;

reg clk;
reg reset_button;
reg increase_button;
reg decrease_button;

wire pwm_out;

everything #(
    .PWM_WIDTH(8),
    .STEP(32),
    .COUNT_MAX(4),
    .COUNTER_BITS(16)
) uut (
    .clk(clk),
    .reset_button(reset_button),
    .increase_button(increase_button),
    .decrease_button(decrease_button),
    .pwm_out(pwm_out)
);
initial begin
    clk = 1'b0;
    forever #10 clk = ~clk;
end

initial begin

    reset_button    = 1'b0;
    increase_button = 1'b0;
    decrease_button = 1'b0;

    #500;

    reset_button = 1'b1;
    #500;
    reset_button = 1'b0;

    #1000;

    increase_button = 1'b1;
	     #200;
    increase_button = 1'b0;
    #200;
    increase_button = 1'b1;
    #200;
    increase_button = 1'b0;
    #200;
    increase_button = 1'b1;

    #2000;

    increase_button = 1'b0;
    #200;
    increase_button = 1'b1;
    #200;
    increase_button = 1'b0;

 #2000;

    increase_button = 1'b1;
    #2000;
    increase_button = 1'b0;

    #2000;

    increase_button = 1'b1;
    #2000;
    increase_button = 1'b0;

    #2000;

    decrease_button = 1'b1;
    #2000;
    decrease_button = 1'b0;

    #2000;
	 
	     increase_button = 1'b1;
    decrease_button = 1'b1;

    #2000;

    increase_button = 1'b0;
    decrease_button = 1'b0;

    #2000;

    increase_button = 1'b1;
    #2000;
    increase_button = 1'b0;
    #2000;

    increase_button = 1'b1;
    #2000;
    increase_button = 1'b0;
    #2000;

    increase_button = 1'b1;
    #2000;
	 
	  increase_button = 1'b0;
    #2000;

    increase_button = 1'b1;
    #2000;
    increase_button = 1'b0;
    #2000;

    increase_button = 1'b1;
    #2000;
    increase_button = 1'b0;
    #2000;

    increase_button = 1'b1;
    #2000;
    increase_button = 1'b0;
    #2000;

    increase_button = 1'b1;
    #2000;
    increase_button = 1'b0;

    #2000;
	  decrease_button = 1'b1;
    #2000;
    decrease_button = 1'b0;

    #2000;



    #3000;

   

end

endmodule