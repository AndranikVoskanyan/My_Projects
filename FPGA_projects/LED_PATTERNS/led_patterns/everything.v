`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:48:16 09/29/2026 
// Design Name: 
// Module Name:    top 
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
module everything(
    input  wire       clk,
    input  wire       reset_n,
    input  wire       button,
    output wire [7:0] led
);




reg reset_syncff1,reset_syncff2;
wire reset_n_sync;
always @(posedge clk or negedge reset_n)begin 
	if(!reset_n) begin
		reset_syncff1 <= 0;
		reset_syncff2 <= 0;
	end
	else begin
		reset_syncff1 <= 1;
		reset_syncff2 <= reset_syncff1;
	end
end

/////////////////////////////////////////
// module instances 
wire button_synced;
wire button_debounced;
wire button_fliped;
wire rising_edge;
wire falling_edge;

wire [1:0] mode;

wire tick;
wire [2:0] step;

wire [7:0] led_pattern_out;

parameter DEBOUNCE_COUNT        = 4;
parameter DEBOUNCE_COUNTER_BITS = 4;

parameter TICK_COUNT            = 25_000_000;
parameter TICK_COUNTER_BITS     = 25;

assign reset_n_sync = reset_syncff2;
assign button_fliped = ~button;
button_sync u_button_sync (
    .clk          (clk),
    .reset_n      (reset_n_sync),
    .button_async (button_fliped),
    .button_sync  (button_synced)
);

debounce #(
    .COUNT_MAX    (DEBOUNCE_COUNT),
    .COUNTER_BITS (DEBOUNCE_COUNTER_BITS)
) u_debounce (
    .clk              (clk),
    .reset_n          (reset_n_sync),
    .button_sync      (button_synced),
    .debounced_button (button_debounced)
);


edge_detector u_edge_detector (
    .clk              (clk),
    .reset_n          (reset_n_sync),
    .debounced_button (button_debounced),
    .rising_edge      (rising_edge),
    .falling_edge     (falling_edge)
);

contorl_fsm u_mode_control (
    .clk            (clk),
    .reset_n        (reset_n_sync),
    .button_pressed (rising_edge),
    .mode           (mode)
);

tick_generator #(
    .COUNT_MAX    (TICK_COUNT),
    .COUNTER_BITS (TICK_COUNTER_BITS)
) u_tick_generator (
    .clk     (clk),
    .reset_n (reset_n_sync),
    .tick    (tick)
);

step_counter u_step_counter (
    .clk     (clk),
    .reset_n (reset_n_sync),
    .tick    (tick),
    .step    (step)
);

led_pattern u_led_pattern (
    .mode (mode),
    .step (step),
    .led  (led_pattern_out)
);

assign led = ~led_pattern_out;
endmodule
