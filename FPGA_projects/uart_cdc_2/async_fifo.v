`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:21:22 10/02/2026 
// Design Name: 
// Module Name:    async_fifo 
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
module async_fifo #(
    parameter DATA_WIDTH = 8,
    parameter ADDR_WIDTH = 4
)(
    input wire wr_clk,
    input wire rd_clk,
    input wire rst,

    input wire wr_en,
    input wire [DATA_WIDTH-1:0] wr_data,
    output reg full,

    input wire rd_en,
    output reg [DATA_WIDTH-1:0] rd_data,
    output reg empty
);

localparam DEPTH = (1 << ADDR_WIDTH);
localparam PTR_WIDTH = ADDR_WIDTH + 1;

reg [DATA_WIDTH-1:0] mem [0:DEPTH-1];

reg [PTR_WIDTH-1:0] wr_pointer,rd_pointer;
reg [PTR_WIDTH-1:0] wr_gray_pointer,rd_gray_pointer;
reg [PTR_WIDTH-1:0] wr_gff1,wr_gff2;
wire [PTR_WIDTH-1:0] wr_pointer_next;
wire [PTR_WIDTH-1:0] wr_gray_next;
wire full_next;

wire [PTR_WIDTH-1:0] rd_pointer_next;
wire [PTR_WIDTH-1:0] rd_gray_next;
reg [PTR_WIDTH-1:0] rd_gff1,rd_gff2;
wire empty_next;


assign wr_pointer_next = wr_pointer + ((wr_en && !full )? 1'b1 : 1'b0);
assign wr_gray_next = wr_pointer_next ^ (wr_pointer_next >> 1);
assign full_next = (wr_gray_next == {~rd_gff2[PTR_WIDTH-1:PTR_WIDTH-2],rd_gff2[PTR_WIDTH-3:0]});

assign rd_pointer_next = rd_pointer + ((rd_en && !empty) ? 1'b1 : 1'b0);
assign rd_gray_next = rd_pointer_next ^ (rd_pointer_next >> 1);
assign empty_next = (rd_gray_next == wr_gff2);
	


always @(posedge wr_clk) begin
    if(rst) begin
        wr_pointer      <= 0;
        wr_gray_pointer <= 0;
        rd_gff1         <= 0;
        rd_gff2         <= 0;
		  full <= 0;
	 end
    else begin
        wr_pointer      <= wr_pointer_next;
        wr_gray_pointer <= wr_gray_next;

        rd_gff1 <= rd_gray_pointer;
        rd_gff2 <= rd_gff1;
		  
		  full <= full_next;
		  
		  if(wr_en && !full) begin
				mem[wr_pointer[ADDR_WIDTH-1:0]] <= wr_data;
		  end
		  
    end
end


always @(posedge rd_clk) begin
	if(rst) begin
		rd_pointer <= 0;
		rd_gray_pointer <= 0;
		wr_gff1 <= 0;
		wr_gff2 <= 0;
		empty <= 1'b1;
		rd_data <= 0;
	end
	else begin
		rd_pointer <= rd_pointer_next;
		rd_gray_pointer <= rd_gray_next;

		wr_gff1 <= wr_gray_pointer;
		wr_gff2 <= wr_gff1;
		empty <= empty_next;
		
		if(rd_en && !empty) begin
			rd_data <= mem[rd_pointer[ADDR_WIDTH-1:0]]; // ADDR_WIDTH - 1 because we have overflow flag at ADDR_WIDTH bit 
		end
	end
end

endmodule
