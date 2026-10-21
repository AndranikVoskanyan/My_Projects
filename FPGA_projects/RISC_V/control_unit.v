`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:32:29 10/20/2026 
// Design Name: 
// Module Name:    control_unit 
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

//instruction	Input	32	Full machine instruction
//alu_op	Output	4	Select ALU operation
//imm_sel	Output	3	Select immediate format
//alu_src_a	Output	2	Select rs1, PC or zero
//alu_src_b	Output	1	Select rs2 or immediate
//reg_write	Output	1	Enable destination register write
//wb_sel	Output	2	Select writeback data
//mem_en	Output	1	Enable memory operation
//mem_op	Output	4	Select LSU operation
//branch_en	Output	1	Enable branch comparison
//branch_op	Output	3	Select branch condition
//jump	Output	1	Indicate jump
//jalr	Output	1	Indicate register-relative jump
//illegal_instr	Output	1	Indicate illegal encoding
module control_unit(
	input wire [31:0] instruction,
	output reg [3:0] alu_op, mem_op,
	output reg [2:0] imm_sel,branch_op,
	output reg [1:0] alu_src_a,wb_sel,
	output reg alu_src_b,reg_write,mem_en,branch_en,jump,jalr,illegal_instr,ecall,ebreak
    );

wire [6:0] opcode;
wire [2:0] func3;
wire [6:0] func7;

localparam [6:0] R_type = 7'b0110011, I_type = 7'b0010011, 
					  Load = 7'b0000011, Store = 7'b0100011,
					  Branch = 7'b1100011, LUI = 7'b0110111,
					  AUIPC = 7'b0010111,  JAL = 7'b1101111,
					  JALR = 7'b1100111,   FENCE = 7'b0001111, SYSTEM = 7'b1110011;

assign opcode = instruction[6:0];
		
assign func3 = instruction[14:12];
assign func7 = instruction[31:25];

always @(*) begin
	 alu_op        = 4'b0000;
    imm_sel       = 3'b000;
    alu_src_a     = 2'b00;
    alu_src_b     = 1'b0;
    reg_write     = 1'b0;
    wb_sel        = 2'b00;
    mem_en        = 1'b0;
    mem_op        = 4'b0000;
    branch_en     = 1'b0;
    branch_op     = 3'b000;
    jump          = 1'b0;
    jalr          = 1'b0;
    illegal_instr = 1'b1;
	 ecall 			= 1'b0;
	 ebreak 			= 1'b0;
	// instruction decodeing for R type instruction 
	if(opcode == R_type)  begin
	
		reg_write = 1'b1;
		illegal_instr = 1'b0;

		case(func3)
			3'b000: begin
				if (func7 == 7'b0000000)
					alu_op = 4'b0;
				else if (func7 == 7'b0100000)
					alu_op = 4'b0001;
				else
					illegal_instr = 1'b1;
			end
			
			3'b001: begin
				if (func7 == 7'b0) 
					alu_op = 4'b0101;
				else
					illegal_instr = 1'b1;			
			end
			
			3'b010: begin
				if (func7 == 7'b0) 
					alu_op = 4'b1000;
				else
					illegal_instr = 1'b1;			
			end
			
			3'b011: begin
				if (func7 == 7'b0) 
					alu_op = 4'b1001;
				else
					illegal_instr = 1'b1;			
			end
			
			3'b100: begin
				if (func7 == 7'b0) 
					alu_op = 4'b0100;
				else
					illegal_instr = 1'b1;
			end
			
			3'b101: begin
				if (func7 == 7'b0) 
					alu_op = 4'b0110;
				else if (func7 == 7'b0100000)
					alu_op = 4'b0111;
				else
					illegal_instr = 1'b1;
			end
			
			3'b110: begin
				if (func7 == 7'b0) 
					alu_op = 4'b0011;
				else
					illegal_instr = 1'b1;
			end
			
			3'b111: begin
			
				if (func7 == 7'b0) 
					alu_op = 4'b0010;
				else
					illegal_instr = 1'b1;
			end
		endcase
	end
	
	// instruction decodeing for I type instruction 
	else if(opcode == I_type)  begin
		alu_src_b = 1'b1;
		reg_write = 1'b1;
		illegal_instr = 1'b0;

		case(func3)
			3'b000: begin
				alu_op = 4'b0;
			end
			
			3'b001: begin
				if(func7 == 7'b0) 
					alu_op = 4'b0101;	
				else
					illegal_instr = 1'b1;					
			end
			
			3'b010: begin
				alu_op = 4'b1000;	
			end
			
			3'b011: begin
				alu_op = 4'b1001;		
			end
			
			3'b100: begin
				alu_op = 4'b0100;
			end
			
			3'b101: begin
				if(func7 == 7'b0) 
					alu_op = 4'b0110;
				else if (func7 == 7'b0100000)
					alu_op = 4'b0111;
				else
					illegal_instr = 1'b1;
			end
			
			3'b110: begin
				alu_op = 4'b0011;
			end
			
			3'b111: begin
				alu_op = 4'b0010;
			end
		endcase
	end	
	// instruction decodeing for I type LOAD instruction 
	else if(opcode == Load ) begin
		alu_src_b = 1'b1;
		reg_write = 1'b1;
		wb_sel = 2'b01;
		mem_en = 1'b1;
		alu_op = 4'b0;
		illegal_instr = 1'b0;

		case(func3)
			3'b000: begin
				mem_op = 4'b0;
			end
			
			3'b001: begin
				mem_op = 4'b0001;	
			end
			
			3'b010: begin
				mem_op = 4'b0010;	
			end
			
			3'b100: begin
				mem_op = 4'b0011;
			end
			
			3'b101: begin
				mem_op = 4'b0100;
			end
			
			default: illegal_instr = 1'b1;
		endcase
	end
	// instruction decodeing for I type Store instruction 
	else if(opcode == Store) begin
		alu_src_b = 1'b1;
		mem_en = 1'b1;
		illegal_instr = 1'b0;
		imm_sel = 3'b001;
		
		case(func3)
			3'b000: begin
				mem_op = 4'b0101;
			end
			
			3'b001: begin
				mem_op = 4'b0110;	
			end
			
			3'b010: begin
				mem_op = 4'b0111;	
			end
			
			default: illegal_instr = 1'b1;
			
		endcase
	end
	else if(opcode == Branch) begin
			branch_en = 1'b1;
			illegal_instr = 1'b0;
			imm_sel = 3'b010;
			
			case(func3)
				3'b000: begin
					branch_op = 3'b000;
				end
				
				3'b001: begin
					branch_op = 3'b001;	
				end
				
				3'b100: begin
					branch_op = 3'b010;	
				end
				
				3'b101: begin
					branch_op = 3'b011;	
				end
				
				3'b110: begin
					branch_op = 3'b100;	
				end
				
				3'b111: begin
					branch_op = 3'b101;	
				end
				default: illegal_instr = 1'b1;
				
			endcase
		end
		
	else begin
		case(opcode)
			JAL: begin
				imm_sel = 3'b100;
				jump =  1'b1;
				jalr = 1'b0 ;
				reg_write = 1'b1 ;
				wb_sel = 2'b10;
				illegal_instr = 1'b0;
			end
			JALR: begin
				if (func3 == 3'b0) begin
					jump =  1'b1;
					jalr = 1'b1 ;
					reg_write = 1'b1 ;
					wb_sel = 2'b10;
					illegal_instr = 1'b0;
				end
				
			end
			LUI: begin
				imm_sel = 3'b011;	
				alu_src_a =	2'b10;
				alu_src_b = 1'b1;
				reg_write = 1'b1;	
				illegal_instr =1'b0;
			end
			AUIPC: begin
				imm_sel = 3'b011;	
				alu_src_a =	2'b01;
				alu_src_b = 1'b1;
				reg_write = 1'b1;	
				illegal_instr =1'b0;
			end
			FENCE: begin
				case(func3)
					3'b000: illegal_instr = 1'b0;
				
					default: illegal_instr = 1'b1;
				endcase
			end
			
			SYSTEM: begin
				if (instruction == 32'h00000073) begin
					illegal_instr = 1'b0;				
					ecall = 1'b1;
				end
				else if (instruction == 32'h00100073) begin
					illegal_instr = 1'b0;
					ebreak = 1'b1;
				end
				else
					illegal_instr = 1'b1;
			end
			default: illegal_instr = 1'b1;
		endcase
			
	end
	if(illegal_instr) begin
		 alu_op        = 4'b0000;
		 imm_sel       = 3'b000;
		 alu_src_a     = 2'b00;
		 alu_src_b     = 1'b0;
		 reg_write     = 1'b0;
		 wb_sel        = 2'b00;
		 mem_en        = 1'b0;
		 mem_op        = 4'b0000;
		 branch_en     = 1'b0;
		 branch_op     = 3'b000;
		 jump          = 1'b0;
		 jalr          = 1'b0;
		 ecall 			= 1'b0;
		 ebreak 			= 1'b0;
	end
end



endmodule
