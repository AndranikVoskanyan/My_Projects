`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:39:50 10/21/2026 
// Design Name: 
// Module Name:    ex_mem_register 
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

module ex_mem_register (
    input wire clk,
    input wire rst,
    input wire stall,
    input wire flush,

    // Execute-stage inputs
    input wire ex_valid,
    input wire [31:0] ex_pc,
    input wire [31:0] ex_pc_plus4,
    input wire [31:0] ex_alu_result,
    input wire [31:0] ex_store_data,
    input wire [4:0] ex_rd_addr,

    input wire ex_reg_write,
    input wire [1:0] ex_wb_sel,

    input wire ex_mem_en,
    input wire [3:0] ex_mem_op,

    input wire ex_illegal_instr,
    input wire ex_ecall,
    input wire ex_ebreak,

    // Memory-stage outputs
    output reg mem_valid,
    output reg [31:0] mem_pc,
    output reg [31:0] mem_pc_plus4,
    output reg [31:0] mem_alu_result,
    output reg [31:0] mem_store_data,
    output reg [4:0] mem_rd_addr,

    output reg mem_reg_write,
    output reg [1:0] mem_wb_sel,

    output reg mem_mem_en,
    output reg [3:0] mem_mem_op,

    output reg mem_illegal_instr,
    output reg mem_ecall,
    output reg mem_ebreak
);

always @(posedge clk) begin

    // Priority 1: Reset
    if (rst) begin
        mem_valid         <= 1'b0;
        mem_pc            <= 32'b0;
        mem_pc_plus4      <= 32'b0;
        mem_alu_result    <= 32'b0;
        mem_store_data    <= 32'b0;
        mem_rd_addr       <= 5'b0;

        mem_reg_write     <= 1'b0;
        mem_wb_sel        <= 2'b0;

        mem_mem_en        <= 1'b0;
        mem_mem_op        <= 4'b0;

        mem_illegal_instr <= 1'b0;
        mem_ecall         <= 1'b0;
        mem_ebreak        <= 1'b0;
    end

    // Priority 2: Flush
    else if (flush) begin
        mem_valid         <= 1'b0;
        mem_pc            <= 32'b0;
        mem_pc_plus4      <= 32'b0;
        mem_alu_result    <= 32'b0;
        mem_store_data    <= 32'b0;
        mem_rd_addr       <= 5'b0;

        mem_reg_write     <= 1'b0;
        mem_wb_sel        <= 2'b0;

        mem_mem_en        <= 1'b0;
        mem_mem_op        <= 4'b0;

        mem_illegal_instr <= 1'b0;
        mem_ecall         <= 1'b0;
        mem_ebreak        <= 1'b0;
    end

    // Priority 3: Stall holds all values
    else if (stall) begin
        // No assignments: registers retain their values.
    end

    // Priority 4: Normal pipeline advance
    else begin
        mem_valid      <= ex_valid;
        mem_pc         <= ex_pc;
        mem_pc_plus4   <= ex_pc_plus4;
        mem_alu_result <= ex_alu_result;
        mem_store_data <= ex_store_data;
        mem_rd_addr    <= ex_rd_addr;

        // Suppress side effects for bubbles and exceptions
        mem_reg_write <= ex_valid &&
                         !ex_illegal_instr &&
                         !ex_ecall &&
                         !ex_ebreak &&
                         ex_reg_write;

        mem_wb_sel <= ex_wb_sel;

        mem_mem_en <= ex_valid &&
                      !ex_illegal_instr &&
                      !ex_ecall &&
                      !ex_ebreak &&
                      ex_mem_en;

        mem_mem_op <= ex_mem_op;

        mem_illegal_instr <= ex_valid && ex_illegal_instr;
        mem_ecall         <= ex_valid && ex_ecall;
        mem_ebreak        <= ex_valid && ex_ebreak;
    end
end

endmodule