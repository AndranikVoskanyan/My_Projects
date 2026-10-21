`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:04:23 10/16/2026 
// Design Name: 
// Module Name:    alu 
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
module alu(
	input wire [31:0] operand_a,operand_b,
	input wire [3:0] alu_op,
	output reg [31:0] result
    );

localparam ADD  = 4'b0000;
localparam SUB  = 4'b0001;
localparam AND  = 4'b0010;
localparam OR   = 4'b0011;
localparam XOR  = 4'b0100;
localparam SLL  = 4'b0101;
localparam SRL  = 4'b0110;
localparam SRA  = 4'b0111;
localparam SLT	 = 4'b1000;
localparam SLTU = 4'b1001;



always @(*) begin 
	case(alu_op)
		ADD: begin
			result = operand_a + operand_b;
		end
		SUB:begin
			result = operand_a-operand_b;
		end
		AND:begin
			result = operand_a & operand_b;
		end
		OR:begin
			result = operand_a | operand_b;
		end
		XOR:begin
			result = operand_a ^ operand_b;
		end
		SLL:begin
			result = operand_a << operand_b[4:0];
		end
		SRL:begin
			result = operand_a >> operand_b[4:0];
		end
		SRA:begin
			result = $signed(operand_a) >>> operand_b[4:0];
		end
		SLT:begin
		
			result = (operand_a[31] == operand_b[31])? 
						((operand_a < operand_b)?1'b1:1'b0):
						(operand_a[31] == 1'b1)?1'b1:1'b0;
		end
		SLTU:begin
			result = (operand_a < operand_b) ? 1'b1:1'b0;
		end
		
		default: result = 32'b0;
	endcase
end

endmodule
