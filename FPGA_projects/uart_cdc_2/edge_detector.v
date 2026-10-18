`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:01:01 09/28/2026 
// Design Name: 
// Module Name:    edge_detector 
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
module edge_detector(
	 input  wire clk, reset_n, debounced_button,
    output wire rising_edge,falling_edge
    );



reg prev_debounced;
reg rising_edge_detection,falling_edge_detection;



always @(posedge clk )begin
	if(reset_n) begin
			prev_debounced <= 0 ;
			rising_edge_detection <= 0 ;
			falling_edge_detection <= 0;
	end
	
	else begin
		prev_debounced <= debounced_button;
		rising_edge_detection <= ~prev_debounced & debounced_button;
		falling_edge_detection <= prev_debounced & ~debounced_button;
	end

end
assign rising_edge = rising_edge_detection;
assign falling_edge = falling_edge_detection;
endmodule
