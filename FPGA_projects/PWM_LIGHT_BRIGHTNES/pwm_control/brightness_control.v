`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:10:08 09/29/2026 
// Design Name: 
// Module Name:    brightness_control 
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
module brightness_control #(
    parameter PWM_WIDTH = 8,
    parameter STEP      = 32
)(
    input  wire                 clk,
    input  wire                 reset,
    input  wire                 increase,
    input  wire                 decrease,
    output reg  [PWM_WIDTH-1:0] duty_cycle
);

wire [1:0] inc_dec;
assign inc_dec[0] = decrease;
assign inc_dec[1] = increase;
always @(posedge clk) begin
	if(reset) begin
		duty_cycle <= {PWM_WIDTH{1'b0}};
	end
	else begin
		case(inc_dec)
			2'b00:	duty_cycle <= duty_cycle;
			2'b01:	duty_cycle <= (duty_cycle <= STEP)
										  ? {PWM_WIDTH{1'b0}} 
										  :(duty_cycle == {PWM_WIDTH{1'b1}})
										  ? duty_cycle - STEP + 1'b1
										  :duty_cycle - STEP;
			2'b10:	duty_cycle <= (duty_cycle <= {PWM_WIDTH{1'b1}} - STEP)? duty_cycle + STEP : {PWM_WIDTH{1'b1}};
			2'b11: 	duty_cycle <= duty_cycle;
			default: duty_cycle <= duty_cycle;
		endcase
	end
end

endmodule
