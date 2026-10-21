`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:24:04 10/15/2026 
// Design Name: 
// Module Name:    instruction_memmory 
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
module instruction_memmory(
	input wire clk,rst,
	input wire [31:0] addr,
	output reg [31:0] instruction,
	output reg valid
    );
// 1024 words x 32 bits = 4 KB
    reg [31:0] mem [0:1023];

    // Load instructions from file
    initial begin
        $readmemh("program.mem", mem);
    end

always @(posedge clk) begin
	if(rst) begin
		valid <= 0;
	end
	else begin
		if(addr[31:12] == 20'b0 && addr[1:0] == 2'b0) begin
			instruction <= mem[addr[11:2]];
			valid <= 1'b1;
		end
		else begin
			valid <= 0;
		end
	end
end

endmodule
