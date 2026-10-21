`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:46:04 10/21/2026 
// Design Name: 
// Module Name:    mem_wb_register 
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

`timescale 1ns / 1ps

module mem_wb_register (
    input wire clk,
    input wire rst,
    input wire stall,
    input wire flush,

    // Memory-stage inputs
    input wire mem_valid,
    input wire [31:0] mem_pc,
    input wire [31:0] mem_pc_plus4,
    input wire [31:0] mem_alu_result,
    input wire [31:0] mem_load_result,
    input wire [4:0] mem_rd_addr,

    input wire mem_reg_write,
    input wire [1:0] mem_wb_sel,

    input wire mem_illegal_instr,
    input wire mem_ecall,
    input wire mem_ebreak,
    input wire mem_access_fault,

    // Writeback-stage outputs
    output reg wb_valid,
    output reg [31:0] wb_pc,
    output reg [31:0] wb_pc_plus4,
    output reg [31:0] wb_alu_result,
    output reg [31:0] wb_load_result,
    output reg [4:0] wb_rd_addr,

    output reg wb_reg_write,
    output reg [1:0] wb_wb_sel,

    output reg wb_illegal_instr,
    output reg wb_ecall,
    output reg wb_ebreak,
    output reg wb_access_fault
);

always @(posedge clk) begin

    // Priority 1: Reset or flush
    if (rst || flush) begin
        wb_valid         <= 1'b0;
        wb_pc            <= 32'b0;
        wb_pc_plus4      <= 32'b0;
        wb_alu_result    <= 32'b0;
        wb_load_result   <= 32'b0;
        wb_rd_addr       <= 5'b0;

        wb_reg_write     <= 1'b0;
        wb_wb_sel        <= 2'b0;

        wb_illegal_instr <= 1'b0;
        wb_ecall         <= 1'b0;
        wb_ebreak        <= 1'b0;
        wb_access_fault  <= 1'b0;
    end

    // Priority 2: Hold values during stall
    else if (stall) begin
        // No assignments: retain all registered values.
    end

    // Priority 3: Capture Memory-stage outputs
    else begin
        wb_valid       <= mem_valid;
        wb_pc          <= mem_pc;
        wb_pc_plus4    <= mem_pc_plus4;
        wb_alu_result  <= mem_alu_result;
        wb_load_result <= mem_load_result;
        wb_rd_addr     <= mem_rd_addr;

        // Suppress register write on invalid instructions
        // and exceptions.
        wb_reg_write <= mem_valid &&
                        mem_reg_write &&
                        !mem_illegal_instr &&
                        !mem_ecall &&
                        !mem_ebreak &&
                        !mem_access_fault;

        wb_wb_sel <= mem_wb_sel;

        wb_illegal_instr <= mem_valid && mem_illegal_instr;
        wb_ecall         <= mem_valid && mem_ecall;
        wb_ebreak        <= mem_valid && mem_ebreak;
        wb_access_fault  <= mem_valid && mem_access_fault;
    end

end

endmodule