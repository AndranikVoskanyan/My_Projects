`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:17:11 10/21/2026 
// Design Name: 
// Module Name:    if_id_register 
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
module if_id_register(
    input wire clk,
    input wire rst,
    input wire stall,
    input wire flush,

    input wire [31:0] if_pc,
    input wire [31:0] if_instruction,
    input wire if_valid,

    output reg [31:0] id_pc,
    output reg [31:0] id_instruction,
    output reg id_valid
);

always @(posedge clk) begin

    if (rst) begin
        id_pc          <= 32'b0;
        id_instruction <= 32'h00000013; // NOP
        id_valid       <= 1'b0;
    end

    else if (flush) begin
        id_pc          <= 32'b0;
        id_instruction <= 32'h00000013; // Bubble
        id_valid       <= 1'b0;
    end

    else if (stall) begin
        id_pc          <= id_pc;
        id_instruction <= id_instruction;
        id_valid       <= id_valid;
    end

    else begin
        id_pc          <= if_pc;
        id_instruction <= if_instruction;
        id_valid       <= if_valid;
    end

end

endmodule