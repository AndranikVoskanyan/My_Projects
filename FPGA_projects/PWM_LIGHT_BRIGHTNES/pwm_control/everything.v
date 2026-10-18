`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:44:41 09/29/2026 
// Design Name: 
// Module Name:    everything 
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

module everything #(
    parameter PWM_WIDTH    = 8,
    parameter STEP         = 32,
    parameter COUNT_MAX    = 500_000,
    parameter COUNTER_BITS = 19
)(
    input  wire clk,
    input  wire reset_button,
    input  wire increase_button,
    input  wire decrease_button,

    output wire pwm_out
);
wire increase_inve, decrease_inv,reset_button_inv;

wire increase_pulse;
wire decrease_pulse;
assign increase_inve = ~increase_button;
assign decrease_inv = ~decrease_button;

wire [PWM_WIDTH-1:0] duty_cycle;

wire pwm_inv;
reg reset_ff1;
reg reset_ff2;
wire reset_inv;
wire reset;
assign resset_inv = ~reset_button;
always @(posedge clk or posedge resset_inv) begin
    if (resset_inv) begin
        reset_ff1 <= 1'b1;
        reset_ff2 <= 1'b1;
    end
    else begin
        reset_ff1 <= 1'b0;
        reset_ff2 <= reset_ff1;
    end
end

assign reset = reset_ff2;

button_control #(
    .COUNT_MAX(COUNT_MAX),
    .COUNTER_BITS(COUNTER_BITS)
) increase_button_inst (
    .clk(clk),
    .reset(reset),
    .button_signal(increase_inve),
    .rising_edge(increase_pulse),
    .falling_edge()
);

button_control #(
    .COUNT_MAX(COUNT_MAX),
    .COUNTER_BITS(COUNTER_BITS)
) decrease_button_inst (
    .clk(clk),
    .reset(reset),
    .button_signal(decrease_inv),
    .rising_edge(decrease_pulse),
    .falling_edge()
);

brightness_control #(
    .PWM_WIDTH(PWM_WIDTH),
    .STEP(STEP)
) brightness_control_inst (
    .clk(clk),
    .reset(reset),
    .increase(increase_pulse),
    .decrease(decrease_pulse),
    .duty_cycle(duty_cycle)
);

pwm_generator #(
    .PWM_WIDTH(PWM_WIDTH)
) pwm_generator_inst (
    .clk(clk),
    .reset(reset),
    .duty_cycle(duty_cycle),
    .pwm_out(pwm_inv)
);
assign pwm_out = ~pwm_inv;
endmodule 