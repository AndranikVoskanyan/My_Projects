`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:00:39 09/28/2026 
// Design Name: 
// Module Name:    debounce 
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
module debounce #(
	parameter  COUNT_MAX = 4,
	parameter  COUNTER_BITS = 16
)(
	input wire clk, reset,button_sync,
	output wire debounced_button
    );
	 
	reg debounced_but_reg;
	reg [COUNTER_BITS-1:0] counter;
	always @(posedge clk) begin
		if(reset) begin
				debounced_but_reg <= 0;
				counter <= 0;
		end
		else begin
			if(debounced_but_reg == button_sync) begin
				counter<=0;
			end
			else begin
				if(counter == COUNT_MAX - 1) begin
					debounced_but_reg <= button_sync;
				end
				else begin
					counter <= counter + 1'b1;
				end
			end
		end
	end
	assign debounced_button = debounced_but_reg; 
endmodule
