`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:00:19 10/16/2026 
// Design Name: 
// Module Name:    branch_pc 
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
module branch_pc(
	input wire [31:0] pc,rs1_data,rs2_data,immediate,
	input wire [2:0] branch_op,
	input wire jump,jalr,branch_en,
	output reg  branch_taken,
	output reg [31:0] target_pc
    );
	
localparam BEQ  = 3'b000;
localparam BNE  = 3'b001;
localparam BLT  = 3'b010;
localparam BGE  = 3'b011;
localparam BLTU = 3'b100;
localparam BGEU = 3'b101;

	
always @(*) begin
	target_pc = pc + immediate;
	branch_taken = 1'b0;
	if(jalr) begin
		target_pc = (rs1_data+immediate)&32'hFFFFFFFE;
		branch_taken = 1'b1;
	end
	else if(jump) 
		branch_taken = 1'b1;
	else if(branch_en) begin
		case(branch_op)
			BEQ: branch_taken = (rs1_data == rs2_data);  
			BNE: branch_taken = (rs1_data != rs2_data);  
			BLT: branch_taken = (rs1_data[31] == rs2_data[31])?((rs1_data < rs2_data)? 1'b1:1'b0):(rs1_data[31]==1'b1)?1'b1:1'b0;  
			BGE: branch_taken = (rs1_data[31] == rs2_data[31])?((rs1_data >= rs2_data)? 1'b1:1'b0):(rs1_data[31]==1'b1)?1'b0:1'b1;  
			BLTU: branch_taken = (rs1_data < rs2_data);    
			BGEU: branch_taken = (rs1_data >= rs2_data);
			default: branch_taken = 0;
		endcase
	end
end


endmodule
