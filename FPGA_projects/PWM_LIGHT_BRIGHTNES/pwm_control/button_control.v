`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:10:19 09/29/2026 
// Design Name: 
// Module Name:    button_control 
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
module button_control #(
	parameter COUNT_MAX = 4,
	parameter COUNTER_BITS = 16)(
	input wire clk, reset, button_signal,
	output wire rising_edge, falling_edge
    );


wire button_sync;
wire debounced_button;
wire rising_edge_reg, falling_edge_reg;


button_sync button_sync_uut(.clk(clk), 
									 .reset(reset), 
									 .button_async(button_signal),
									 .button_sync(button_sync));

debounce #(.COUNT_MAX(COUNT_MAX),
			  .COUNTER_BITS(COUNTER_BITS)) debounce_uut(
								    .clk(clk), 
								    .reset(reset),
								    .button_sync(button_sync),
								    .debounced_button(debounced_button));
	 
edge_detector edge_detector(.clk(clk), 
									 .reset(reset), 
									 .debounced_button(debounced_button),
								    .rising_edge(rising_edge_reg),
									 .falling_edge(falling_edge_reg));
assign rising_edge = rising_edge_reg;
assign falling_edge = falling_edge_reg;
endmodule
