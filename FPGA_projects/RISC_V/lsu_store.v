`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:46:22 10/18/2026 
// Design Name: 
// Module Name:    lsu_store 
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
module lsu_store(
	 input  wire        clk, rst,
    input  wire        mem_valid,
    input  wire [3:0]  mem_op,
    input  wire [31:0] effective_addr,
    input  wire [31:0] rs2_data,

    input  wire [31:0] ram_read_data,
    input  wire        ram_rvalid,
    input  wire        ram_error,

    output wire        ram_req,
    output wire        ram_we,
    output wire [31:0] ram_addr,
    output reg  [31:0] ram_wr_data,
    output reg  [3:0]  ram_byte_en,
	 
    output reg  [31:0] load_result,
    output reg         lsu_valid,
    output reg         lsu_error
);

localparam LB  = 4'd0, LH  = 4'd1,
           LW  = 4'd2, LBU = 4'd3,
           LHU = 4'd4, SB  = 4'd5,
           SH  = 4'd6, SW  = 4'd7;

localparam IDLE = 1'b0, WAIT_RAM = 1'b1;

reg state;
reg [3:0] saved_op;
reg [1:0] saved_offset;

wire is_load  = (mem_op <= LHU);
wire is_store = (mem_op >= SB && mem_op <= SW);
wire valid_op = is_load || is_store;

wire misaligned =
    ((mem_op == LH || mem_op == LHU || mem_op == SH)
        && effective_addr[0]) ||
    ((mem_op == LW || mem_op == SW)
        && (effective_addr[1:0] != 2'b00));
assign ram_addr = {effective_addr[31:2], 2'b00};

assign ram_req = (state == IDLE) && mem_valid &&
                 valid_op && !misaligned && !rst;

assign ram_we = is_store;



always @(*) begin
    ram_wr_data = 32'b0;
    ram_byte_en = 4'b0000;
	 if (is_store && !misaligned) begin
        case (mem_op)
            SB: begin
                ram_byte_en = 4'b0001 << effective_addr[1:0];
                ram_wr_data = rs2_data << (effective_addr[1:0] * 8);
            end
            SH: begin
                ram_byte_en = 4'b0011 << effective_addr[1:0];
                ram_wr_data = rs2_data << (effective_addr[1:0] * 8);
            end

            SW: begin
                ram_byte_en = 4'b1111;
                ram_wr_data = rs2_data;
            end
        endcase
    end
end
wire [31:0] shifted_data = ram_read_data >> (saved_offset * 8);

always @(posedge clk) begin
    if (rst) begin
        state        <= IDLE;
        saved_op     <= 0;
        saved_offset <= 0;
        load_result  <= 0;
        lsu_valid    <= 0;
        lsu_error    <= 0;
    end
    else begin
        lsu_valid <= 0;
        lsu_error <= 0;
        case (state)
            IDLE: begin
                if (mem_valid) begin
                    if (!valid_op || misaligned) begin
                        lsu_valid <= 1'b1;
                        lsu_error <= 1'b1;
                    end
                    else begin
                        saved_op <= mem_op;
                        saved_offset <= effective_addr[1:0];
                        state <= WAIT_RAM;
                    end
                end
            end
            WAIT_RAM: begin
                if (ram_rvalid) begin
                    lsu_valid <= 1'b1;
                    lsu_error <= ram_error;
                    state <= IDLE;

                    if (!ram_error) begin
                        case (saved_op)
                            LB: load_result <=
                                {{24{shifted_data[7]}},
                                  shifted_data[7:0]};
                            LBU: load_result <=	
                                {24'b0, shifted_data[7:0]};

                            LH: load_result <=
                                {{16{shifted_data[15]}},
                                  shifted_data[15:0]};

                            LHU: load_result <=
                                {16'b0, shifted_data[15:0]};

                            LW: load_result <= shifted_data;
                       endcase
                    end
                end
            end
        endcase
    end
end

endmodule
