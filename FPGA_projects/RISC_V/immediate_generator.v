`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:51:38 10/15/2026 
// Design Name: 
// Module Name:    immediate_generator 
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
module immediate_generator(
	input wire [31:0] instruction,
	input wire [2:0] imm_sel,
	output reg [31:0] immidiate
    );
localparam I = 3'b000;
localparam S = 3'b001;
localparam B = 3'b010;
localparam U = 3'b011;
localparam J = 3'b100;

always @(*) begin
immidiate = 0;
	case(imm_sel) 
		I: begin
			immidiate = {{20{instruction[31]}},instruction[31:20]};
		end
		S: begin
			immidiate = {{20{instruction[31]}},instruction[31:25],instruction[11:7]};
		end
		B: begin
			immidiate[31:13] = {19{instruction[31]}};
			immidiate[12] = instruction[31];
			immidiate[11] = instruction[7];
			immidiate[10:5] = instruction[30:25];
			immidiate[4:1] = instruction[11:8];
			immidiate[0] = 1'b0;
		end
		U: begin
			immidiate = {instruction[31:12],{12{1'b0}}};
		end
		J: begin
			immidiate[31:21] = {11{instruction[31]}};
			immidiate[20] = instruction[31];
			immidiate[19:12] = instruction[19:12];
			immidiate[11] = instruction[20];
			immidiate[10:1] = instruction[30:21];
			immidiate[0] = 1'b0;
		end		
		default: immidiate = 32'b0;
	endcase
end

endmodule
