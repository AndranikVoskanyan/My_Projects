`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:23:43 09/29/2026 
// Design Name: 
// Module Name:    pwm_generator 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module pwm_generator#(
    parameter PWM_WIDTH = 8
)(
    input  wire                 clk,
    input  wire                 reset,
    input  wire [PWM_WIDTH-1:0] duty_cycle,
    output wire                 pwm_out
);

reg [PWM_WIDTH-1:0] counter;

always @(posedge clk) begin
    if (reset)
        counter <= {PWM_WIDTH{1'b0}};
    else
        counter <= counter + 1'b1;
end

assign pwm_out = (duty_cycle == {PWM_WIDTH{1'b1}}) ? 1'b1 :
                 (counter < duty_cycle)            ? 1'b1 :
                                                     1'b0;


endmodule

