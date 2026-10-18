`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:27:08 10/03/2026 
// Design Name: 
// Module Name:    clk_devider 
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
module clk_devider#(
	parameter CLK_DEV_IND = 2
)(
	input wire clk,rst,
	output reg clk_devided
    );

 function integer clog2;
		 input integer value;
		 integer i;
		 if  (value == 1) begin
			clog2 =	1;
		 end
		 else begin
			 
				  value = value - 1;

				  for (i = 0; value > 0; i = i + 1)
						value = value >> 1;

				  clog2 = i;
			 end
			
endfunction
localparam HALF_COUNTER = CLK_DEV_IND / 2;
localparam COUNTER_BITS = clog2(HALF_COUNTER);
reg [COUNTER_BITS-1:0]counter;
always @(posedge clk) begin
	if(rst) begin
		counter <= 0;
		clk_devided <= 0;
	end
	else begin
		if(counter <= HALF_COUNTER - 1  ) begin
			counter <= 0;
			clk_devided <= ~clk_devided;
			
		end
		else begin
			counter <= counter + 1'b1;
		end
	end
end

endmodule
