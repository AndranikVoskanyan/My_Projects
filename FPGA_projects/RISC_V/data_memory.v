`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:39:19 10/17/2026 
// Design Name: 
// Module Name:    data_memory 
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
module data_memory(
	input wire clk,rst,	req, we,
	input wire [31:0] addr, wr_data,
	input wire [3:0] byte_en,
	output reg [31:0] read_data,
	output reg rvalid, error
    );
	 
	 
reg [31:0] mem [0:1023];
//wire [31:0] mask;
//
//assign mask = {{8{byte_en[3]}},{8{byte_en[2]}},{8{byte_en[1]}},{8{byte_en[0]}}};

always @(posedge clk) begin
	if(rst) begin
		error <= 0;
		rvalid <= 0;
		read_data <= 0;
	end
	else if(req) begin
		if(addr[31:12] == 'h10000) begin
			error <= 1'b0;
			case(we)
				1'b0: begin 
					read_data <= mem[addr[11:2]];
					rvalid <= 1'b1;
				end
				1'b1: begin
					rvalid <= 1'b1;
					// different ways of changing byte wise data 
//					mem[addr[11:2]] <= (mem[addr[11:2]] & ~mask ) | (mask & wr_data); 
//					mem[addr[11:2]][7:0] <= (byte_en[0] == 1'b1)? wr_data[7:0] : mem[addr[11:2]][7:0];
//					mem[addr[11:2]][15:8] <= (byte_en[1] == 1'b1)? wr_data[15:8] : mem[addr[11:2]][15:8];
//					mem[addr[11:2]][23:16] <= (byte_en[2] == 1'b1)? wr_data[23:16] : mem[addr[11:2]][23:16];
//					mem[addr[11:2]][31:24] <= (byte_en[3] == 1'b1)? wr_data[31:24] : mem[addr[11:2]][31:24];
					if(byte_en[0] == 1'b1) 
						mem[addr[11:2]][7:0] <= wr_data[7:0];
					if(byte_en[1] == 1'b1) 
						mem[addr[11:2]][15:8] <= wr_data[15:8];
					if(byte_en[2] == 1'b1) 
						mem[addr[11:2]][23:16] <= wr_data[23:16];
					if(byte_en[3] == 1'b1) 
						mem[addr[11:2]][31:24] <= wr_data[31:24];	
				end
				default:  begin
					rvalid <= 1'b0;
					read_data <= 0;
					error <= 1'b0;
				end
			endcase
		end
		else begin
			rvalid <= 1'b1;
			error <= 1'b1;		
		end
	end
	else begin
		rvalid <= 1'b0;
		read_data <= 0;
		error <= 1'b0;
	end

end


endmodule
