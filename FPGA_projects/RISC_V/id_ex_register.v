`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:29:23 10/21/2026 
// Design Name: 
// Module Name:    id_ex_register 
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

module id_ex_register (
    input wire clk,
    input wire rst,
    input wire flush,
    input wire stall,

    // Decode-stage data
    input wire id_valid,
    input wire [31:0] id_pc,
    input wire [31:0] id_rs1_data,
    input wire [31:0] id_rs2_data,
    input wire [31:0] id_immediate,
    input wire [4:0] id_rs1_addr,
    input wire [4:0] id_rs2_addr,
    input wire [4:0] id_rd_addr,

    // Decode-stage control
    input wire [3:0] id_alu_op,
    input wire [1:0] id_alu_src_a,
    input wire id_alu_src_b,
    input wire id_reg_write,
    input wire [1:0] id_wb_sel,
    input wire id_mem_en,
    input wire [3:0] id_mem_op,
    input wire id_branch_en,
    input wire [2:0] id_branch_op,
    input wire id_jump,
    input wire id_jalr,
    input wire id_illegal_instr,
    input wire id_ecall,
    input wire id_ebreak,

    // Execute-stage data
    output reg ex_valid,
    output reg [31:0] ex_pc,
    output reg [31:0] ex_rs1_data,
    output reg [31:0] ex_rs2_data,
    output reg [31:0] ex_immediate,
    output reg [4:0] ex_rs1_addr,
    output reg [4:0] ex_rs2_addr,
    output reg [4:0] ex_rd_addr,

    // Execute-stage control
    output reg [3:0] ex_alu_op,
    output reg [1:0] ex_alu_src_a,
    output reg ex_alu_src_b,
    output reg ex_reg_write,
    output reg [1:0] ex_wb_sel,
    output reg ex_mem_en,
    output reg [3:0] ex_mem_op,
    output reg ex_branch_en,
    output reg [2:0] ex_branch_op,
    output reg ex_jump,
    output reg ex_jalr,
    output reg ex_illegal_instr,
    output reg ex_ecall,
    output reg ex_ebreak
);

always @(posedge clk) begin

    if (rst || flush) begin
        ex_valid         <= 1'b0;
        ex_pc            <= 32'b0;
        ex_rs1_data      <= 32'b0;
        ex_rs2_data      <= 32'b0;
        ex_immediate     <= 32'b0;
        ex_rs1_addr      <= 5'b0;
        ex_rs2_addr      <= 5'b0;
        ex_rd_addr       <= 5'b0;

        ex_alu_op        <= 4'b0;
        ex_alu_src_a     <= 2'b0;
        ex_alu_src_b     <= 1'b0;
        ex_reg_write     <= 1'b0;
        ex_wb_sel        <= 2'b0;

        ex_mem_en        <= 1'b0;
        ex_mem_op        <= 4'b0;

        ex_branch_en     <= 1'b0;
        ex_branch_op     <= 3'b0;
        ex_jump          <= 1'b0;
        ex_jalr          <= 1'b0;

        ex_illegal_instr <= 1'b0;
        ex_ecall         <= 1'b0;
        ex_ebreak        <= 1'b0;
    end

    else if (!stall) begin
        ex_valid         <= id_valid;
        ex_pc            <= id_pc;
        ex_rs1_data      <= id_rs1_data;
        ex_rs2_data      <= id_rs2_data;
        ex_immediate     <= id_immediate;
        ex_rs1_addr      <= id_rs1_addr;
        ex_rs2_addr      <= id_rs2_addr;
        ex_rd_addr       <= id_rd_addr;

        ex_alu_op        <= id_alu_op;
        ex_alu_src_a     <= id_alu_src_a;
        ex_alu_src_b     <= id_alu_src_b;
        ex_reg_write     <= id_valid && id_reg_write;
        ex_wb_sel        <= id_wb_sel;

        ex_mem_en        <= id_valid && id_mem_en;
        ex_mem_op        <= id_mem_op;

        ex_branch_en     <= id_valid && id_branch_en;
        ex_branch_op     <= id_branch_op;
        ex_jump          <= id_valid && id_jump;
        ex_jalr          <= id_valid && id_jalr;

        ex_illegal_instr <= id_valid && id_illegal_instr;
        ex_ecall         <= id_valid && id_ecall;
        ex_ebreak        <= id_valid && id_ebreak;
    end

    // When stalled, all registers hold their values.

end

endmodule