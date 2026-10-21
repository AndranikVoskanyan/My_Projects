
`timescale 1ns / 1ps

module alu_tb_2;

    reg [31:0] operand_a, operand_b;
    reg [3:0] alu_op;
    wire [31:0] result;

    integer tests, errors;

    alu dut (
        .operand_a(operand_a),
        .operand_b(operand_b),
        .alu_op(alu_op),
        .result(result)
    );

    localparam ADD = 4'd0, SUB = 4'd1,
               AND_OP = 4'd2, OR_OP = 4'd3,
               XOR_OP = 4'd4, SLL = 4'd5,
               SRL = 4'd6, SRA = 4'd7,
               SLT = 4'd8, SLTU = 4'd9;

    task check;
        input [3:0] op;
        input [31:0] a, b, expected;
        input [8*32-1:0] name;
        begin
            alu_op = op;
            operand_a = a;
            operand_b = b;
            #10;
            tests = tests + 1;

            if (result !== expected) begin
                errors = errors + 1;
                $display("FAIL %s: expected=%h got=%h",
                         name, expected, result);
            end
            else
                $display("PASS %s", name);
        end
    endtask

    initial begin
        tests = 0;
        errors = 0;
        operand_a = 0;
        operand_b = 0;
        alu_op = 0;

        // ADD
        check(ADD, 15, 7, 22, "ADD normal");
        check(ADD, 32'hffffffff, 1, 0, "ADD wraparound");
        check(ADD, 32'h7fffffff, 1,
              32'h80000000, "ADD overflow");
        check(ADD, 0, 0, 0, "ADD zero");

        // SUB
        check(SUB, 5, 12, 32'hfffffff9, "SUB negative");
        check(SUB, 0, 1, 32'hffffffff, "SUB underflow");
        check(SUB, 32'h80000000, 1,
              32'h7fffffff, "SUB wraparound");
        check(SUB, 7, 7, 0, "SUB equal");

        // AND, OR, XOR
        check(AND_OP, 32'hc, 32'ha, 32'h8, "AND");
        check(AND_OP, 32'hf0f0, 32'h0ff0,
              32'h00f0, "AND masks");
        check(OR_OP, 32'hc, 32'ha, 32'he, "OR");
        check(OR_OP, 0, 32'h12345678,
              32'h12345678, "OR zero");
        check(XOR_OP, 32'hc, 32'ha, 32'h6, "XOR");
        check(XOR_OP, 32'hffffffff,
              32'hffffffff, 0, "XOR identical");

        // SLL
        check(SLL, 3, 2, 12, "SLL by 2");
        check(SLL, 1, 31, 32'h80000000, "SLL by 31");
        check(SLL, 1, 32, 1, "SLL shift mask");
        check(SLL, 32'hffffffff, 1,
              32'hfffffffe, "SLL overflow");

        // SRL
        check(SRL, 32'h80000000, 1,
              32'h40000000, "SRL logical");
        check(SRL, 32'hffffffff, 31, 1, "SRL by 31");
        check(SRL, 32'h80000000, 33,
              32'h40000000, "SRL shift mask");

        // SRA
        check(SRA, 32'h80000000, 1,
              32'hc0000000, "SRA sign extend");
        check(SRA, 32'hffffffff, 31,
              32'hffffffff, "SRA negative");
        check(SRA, 32'h7fffffff, 1,
              32'h3fffffff, "SRA positive");
        check(SRA, 32'h80000000, 31,
              32'hffffffff, "SRA by 31");
        check(SRA, 32'h80000000, 32,
              32'h80000000, "SRA shift mask");

        // SLT: signed comparison
        check(SLT, 32'hffffffff, 1, 1, "SLT negative");
        check(SLT, 1, 32'hffffffff, 0, "SLT reverse");
        check(SLT, 32'h80000000,
              32'h7fffffff, 1, "SLT min max");
        check(SLT, 7, 7, 0, "SLT equal");
        check(SLT, 3, 5, 1, "SLT positive");

        // SLTU: unsigned comparison
        check(SLTU, 32'hffffffff, 1, 0, "SLTU max");
        check(SLTU, 1, 32'hffffffff, 1, "SLTU reverse");
        check(SLTU, 0, 0, 0, "SLTU equal");
        check(SLTU, 0, 32'hffffffff, 1, "SLTU zero");

        // Unsupported operation
        check(4'ha, 32'hffffffff,
              32'hffffffff, 0, "Invalid ALU op");

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("ALU TEST PASSED");
        else
            $display("ALU TEST FAILED");

        $finish;
    end

endmodule