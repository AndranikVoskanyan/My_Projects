`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:00:23 09/28/2026 
// Design Name: 
// Module Name:    button_sync 
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
module button_sync(
		input wire clk, reset_n, button_async,
		output wire button_sync
    );

reg button_sync_ff1, button_sync_ff2;

always @(posedge clk ) begin
	if(reset_n) begin
		button_sync_ff1 <= 1'b0;
		button_sync_ff2 <= 1'b0;
	end
	else begin
		button_sync_ff1 <= button_async;
		button_sync_ff2 <= button_sync_ff1;
	end
end

assign button_sync = button_sync_ff2;

endmodule
