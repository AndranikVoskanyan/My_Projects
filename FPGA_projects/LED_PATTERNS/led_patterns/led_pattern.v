`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:01:45 09/28/2026 
// Design Name: 
// Module Name:    led_pattern 
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
module led_pattern(
	input [1:0] mode,
	input [2:0] step,
	output [7:0] led
    );
reg [7:0] led_reg;

always @(*) begin
	led_reg = 8'b00000000;
	case(mode) 
		2'b00: led_reg[step] = 1'b1;
		2'b01: led_reg[7-step] = 1'b1;
		2'b10: begin
					led_reg[step] = 1'b1;
					led_reg = ((led_reg - 1'b1)<< 1)+1'b1;
				 end
		2'b11: begin
					led_reg = (step[0]) ? 8'b01010101 : 8'b10101010;
				 end
		default: begin
						led_reg = 0;
					end
	endcase
end
assign led = led_reg;
endmodule
