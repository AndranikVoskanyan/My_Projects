`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:28:04 10/15/2026 
// Design Name: 
// Module Name:    register_file 
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


module register_file(
	input clk, rd_we,
	input [4:0] rs1_addr,rs2_addr,rd_addr,
	input [31:0] rd_data,
	output reg [31:0] rs1_data,
	output reg [31:0] rs2_data
    );

reg [31:0] mem [0:31];

always @(posedge clk) begin
	if(rd_we && rd_addr != 0) begin
		mem[rd_addr] <= rd_data;
	end
end

always @(*) begin
	 rs1_data = (rs1_addr == 0) ? 32'b0 : mem[rs1_addr];
	 rs2_data = (rs2_addr == 0) ? 32'b0 : mem[rs2_addr];
end


endmodule
