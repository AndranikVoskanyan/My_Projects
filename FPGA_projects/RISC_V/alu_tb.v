`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:50:06 10/16/2026
// Design Name:   alu
// Module Name:   /home/ise/Desktop/RISC_V/alu_tb.v
// Project Name:  RISC_V
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: alu
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module alu_tb;

	// Inputs
	reg [31:0] operand_a;
	reg [31:0] operand_b;
	reg [3:0] alu_op;

	// Outputs
	wire [31:0] result;

	// Instantiate the Unit Under Test (UUT)
	alu uut (
		.operand_a(operand_a), 
		.operand_b(operand_b), 
		.alu_op(alu_op), 
		.result(result)
	);

	initial begin
		// Initialize Inputs
		operand_a = 0;
		operand_b = 0;
		alu_op = 0;

		// Wait 100 ns for global reset to finish
		#100;
        operand_a = 32'd10;
    operand_b = 32'd5;
    alu_op = 4'b0000;
    #10;

    // Test SUB
    alu_op = 4'b0001;
    #10;

    // Test AND
    alu_op = 4'b0010;
    #10;
    alu_op = 4'b0011;
    #10;
	     alu_op = 4'b0100;
    #10;
	     alu_op = 4'b0101;
    #10;
	     alu_op = 4'b0110;
    #10;
	     alu_op = 4'b0111;
    #10;
	     alu_op = 4'b1000;
    #10;
	     alu_op = 4'b1001;
    #10;
		// Add stimulus here

	end
      
endmodule

