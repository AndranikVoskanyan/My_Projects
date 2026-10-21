	`timescale 1ns / 1ps
	//////////////////////////////////////////////////////////////////////////////////
	// Company: 
	// Engineer: 
	// 
	// Create Date:    21:39:51 10/15/2026 
	// Design Name: 
	// Module Name:    instruction_decoder 
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
	module instruction_decoder(
		input [31:0] instruction,
		output [6:0] opcode,
		output [4:0] rd,rs1,rs2,
		output [2:0] funct3,
		output [6:0] funct7
		 );
		 
	assign funct7	= instruction[31:25];
	assign rs2 		= instruction[24:20];
	assign rs1 		= instruction[19:15];
	assign funct3 	= instruction[14:12];
	assign rd 		= instruction[11:7];
	assign opcode 	= instruction[6:0];	


	endmodule
