`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:02:06 09/28/2026 
// Design Name: 
// Module Name:    contorl_fsm 
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
module contorl_fsm(
	 input  wire       clk,
    input  wire       reset_n,
    input  wire       button_pressed,
    output wire [1:0] mode
    );

reg [1:0] button_counter;

always @(posedge clk or negedge reset_n) begin
	if(!reset_n) begin
		button_counter <= 0;
	end
	else begin
		if(button_pressed)
			button_counter <= button_counter + 1'b1;
	end
end
assign mode = button_counter;


endmodule
