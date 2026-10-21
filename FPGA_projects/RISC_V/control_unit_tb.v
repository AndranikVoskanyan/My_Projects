
`timescale 1ns / 1ps

module control_unit_tb;

    reg [31:0] instruction;

    wire [3:0] alu_op, mem_op;
    wire [2:0] imm_sel, branch_op;
    wire [1:0] alu_src_a, wb_sel;
    wire alu_src_b, reg_write, mem_en;
    wire branch_en, jump, jalr, illegal_instr;
    wire ecall, ebreak;

    integer tests, errors;

    control_unit dut (
        .instruction(instruction),
        .alu_op(alu_op),
        .mem_op(mem_op),
        .imm_sel(imm_sel),
        .branch_op(branch_op),
        .alu_src_a(alu_src_a),
        .wb_sel(wb_sel),
        .alu_src_b(alu_src_b),
        .reg_write(reg_write),
        .mem_en(mem_en),
        .branch_en(branch_en),
        .jump(jump),
        .jalr(jalr),
        .illegal_instr(illegal_instr),
        .ecall(ecall),
        .ebreak(ebreak)
    );

    // Existing 25-bit control vector.
    wire [24:0] actual = {
        alu_op, mem_op, imm_sel, branch_op,
        alu_src_a, wb_sel,
        alu_src_b, reg_write, mem_en,
        branch_en, jump, jalr, illegal_instr
    };

    // bit 1 = ecall, bit 0 = ebreak
    wire [1:0] actual_exceptions = {ecall, ebreak};

    localparam [6:0]
        C_R    = 7'b0100000,
        C_I    = 7'b1100000,
        C_LOAD = 7'b1110000,
        C_ST   = 7'b1010000,
        C_BR   = 7'b0001000,
        C_JAL  = 7'b0100100,
        C_JALR = 7'b0100110,
        C_U    = 7'b1100000;

    localparam [24:0] BAD = 25'd1;

    // Assemble a test instruction.
    function [31:0] ins;
        input [6:0] opcode;
        input [2:0] funct3;
        input [6:0] upper;
        begin
            ins = {upper, 5'd2, 5'd1, funct3, 5'd3, opcode};
        end
    endfunction

    // Check all 27 output bits.
    task verify;
        input [31:0] code;
        input [24:0] expected;
        input [1:0] expected_exceptions;
        input [8*28-1:0] name;
        begin
            instruction = code;
            #10;
            tests = tests + 1;

            if ((actual !== expected) ||
                (actual_exceptions !== expected_exceptions)) begin
                errors = errors + 1;
                $display("FAIL %s instr=%h", name, code);
                $display("     control expected=%07h actual=%07h",
                         expected, actual);
                $display("     {ecall,ebreak} expected=%b actual=%b",
                         expected_exceptions, actual_exceptions);
            end
            else
                $display("PASS %s", name);
        end
    endtask

    // Normal instructions: ecall=0 and ebreak=0.
    task check;
        input [31:0] code;
        input [24:0] expected;
        input [8*28-1:0] name;
        begin
            verify(code, expected, 2'b00, name);
        end
    endtask

    // Exception instructions: no normal control effects.
    task check_exception;
        input [31:0] code;
        input [1:0] expected_exceptions;
        input [8*28-1:0] name;
        begin
            verify(code, 25'd0, expected_exceptions, name);
        end
    endtask

    initial begin
        instruction = 32'd0;
        tests = 0;
        errors = 0;

        // =========================================
        // R-TYPE INSTRUCTIONS
        // =========================================

        check(ins(7'h33, 3'd0, 7'h00),
              {4'd0,4'd0,3'd0,3'd0,2'd0,2'd0,C_R}, "ADD");

        check(ins(7'h33, 3'd0, 7'h20),
              {4'd1,4'd0,3'd0,3'd0,2'd0,2'd0,C_R}, "SUB");

        check(ins(7'h33, 3'd1, 7'h00),
              {4'd5,4'd0,3'd0,3'd0,2'd0,2'd0,C_R}, "SLL");

        check(ins(7'h33, 3'd2, 7'h00),
              {4'd8,4'd0,3'd0,3'd0,2'd0,2'd0,C_R}, "SLT");

        check(ins(7'h33, 3'd3, 7'h00),
              {4'd9,4'd0,3'd0,3'd0,2'd0,2'd0,C_R}, "SLTU");

        check(ins(7'h33, 3'd4, 7'h00),
              {4'd4,4'd0,3'd0,3'd0,2'd0,2'd0,C_R}, "XOR");

        check(ins(7'h33, 3'd5, 7'h00),
              {4'd6,4'd0,3'd0,3'd0,2'd0,2'd0,C_R}, "SRL");

        check(ins(7'h33, 3'd5, 7'h20),
              {4'd7,4'd0,3'd0,3'd0,2'd0,2'd0,C_R}, "SRA");

        check(ins(7'h33, 3'd6, 7'h00),
              {4'd3,4'd0,3'd0,3'd0,2'd0,2'd0,C_R}, "OR");

        check(ins(7'h33, 3'd7, 7'h00),
              {4'd2,4'd0,3'd0,3'd0,2'd0,2'd0,C_R}, "AND");


        // =========================================
        // I-TYPE ARITHMETIC
        // =========================================

        check(ins(7'h13, 3'd0, 7'h7f),
              {4'd0,4'd0,3'd0,3'd0,2'd0,2'd0,C_I}, "ADDI negative");

        check(ins(7'h13, 3'd1, 7'h00),
              {4'd5,4'd0,3'd0,3'd0,2'd0,2'd0,C_I}, "SLLI");

        check(ins(7'h13, 3'd2, 7'h00),
              {4'd8,4'd0,3'd0,3'd0,2'd0,2'd0,C_I}, "SLTI");

        check(ins(7'h13, 3'd3, 7'h00),
              {4'd9,4'd0,3'd0,3'd0,2'd0,2'd0,C_I}, "SLTIU");

        check(ins(7'h13, 3'd4, 7'h00),
              {4'd4,4'd0,3'd0,3'd0,2'd0,2'd0,C_I}, "XORI");

        check(ins(7'h13, 3'd5, 7'h00),
              {4'd6,4'd0,3'd0,3'd0,2'd0,2'd0,C_I}, "SRLI");

        check(ins(7'h13, 3'd5, 7'h20),
              {4'd7,4'd0,3'd0,3'd0,2'd0,2'd0,C_I}, "SRAI");

        check(ins(7'h13, 3'd6, 7'h00),
              {4'd3,4'd0,3'd0,3'd0,2'd0,2'd0,C_I}, "ORI");

        check(ins(7'h13, 3'd7, 7'h00),
              {4'd2,4'd0,3'd0,3'd0,2'd0,2'd0,C_I}, "ANDI");


        // =========================================
        // LOAD INSTRUCTIONS
        // =========================================

        check(ins(7'h03, 3'd0, 7'h00),
              {4'd0,4'd0,3'd0,3'd0,2'd0,2'd1,C_LOAD}, "LB");

        check(ins(7'h03, 3'd1, 7'h00),
              {4'd0,4'd1,3'd0,3'd0,2'd0,2'd1,C_LOAD}, "LH");

        check(ins(7'h03, 3'd2, 7'h00),
              {4'd0,4'd2,3'd0,3'd0,2'd0,2'd1,C_LOAD}, "LW");

        check(ins(7'h03, 3'd4, 7'h00),
              {4'd0,4'd3,3'd0,3'd0,2'd0,2'd1,C_LOAD}, "LBU");

        check(ins(7'h03, 3'd5, 7'h00),
              {4'd0,4'd4,3'd0,3'd0,2'd0,2'd1,C_LOAD}, "LHU");


        // =========================================
        // STORE INSTRUCTIONS
        // =========================================

        check(ins(7'h23, 3'd0, 7'h00),
              {4'd0,4'd5,3'd1,3'd0,2'd0,2'd0,C_ST}, "SB");

        check(ins(7'h23, 3'd1, 7'h00),
              {4'd0,4'd6,3'd1,3'd0,2'd0,2'd0,C_ST}, "SH");

        check(ins(7'h23, 3'd2, 7'h00),
              {4'd0,4'd7,3'd1,3'd0,2'd0,2'd0,C_ST}, "SW");


        // =========================================
        // BRANCH INSTRUCTIONS
        // =========================================

        check(ins(7'h63, 3'd0, 7'h00),
              {4'd0,4'd0,3'd2,3'd0,2'd0,2'd0,C_BR}, "BEQ");

        check(ins(7'h63, 3'd1, 7'h00),
              {4'd0,4'd0,3'd2,3'd1,2'd0,2'd0,C_BR}, "BNE");

        check(ins(7'h63, 3'd4, 7'h00),
              {4'd0,4'd0,3'd2,3'd2,2'd0,2'd0,C_BR}, "BLT");

        check(ins(7'h63, 3'd5, 7'h00),
              {4'd0,4'd0,3'd2,3'd3,2'd0,2'd0,C_BR}, "BGE");

        check(ins(7'h63, 3'd6, 7'h00),
              {4'd0,4'd0,3'd2,3'd4,2'd0,2'd0,C_BR}, "BLTU");

        check(ins(7'h63, 3'd7, 7'h00),
              {4'd0,4'd0,3'd2,3'd5,2'd0,2'd0,C_BR}, "BGEU");


        // =========================================
        // JUMP INSTRUCTIONS
        // =========================================

        check(ins(7'h6f, 3'd0, 7'h00),
              {4'd0,4'd0,3'd4,3'd0,2'd0,2'd2,C_JAL}, "JAL");

        check(ins(7'h67, 3'd0, 7'h00),
              {4'd0,4'd0,3'd0,3'd0,2'd0,2'd2,C_JALR}, "JALR");


        // =========================================
        // U-TYPE INSTRUCTIONS
        // =========================================

        check(ins(7'h37, 3'd0, 7'h00),
              {4'd0,4'd0,3'd3,3'd0,2'd2,2'd0,C_U}, "LUI");

        check(ins(7'h17, 3'd0, 7'h00),
              {4'd0,4'd0,3'd3,3'd0,2'd1,2'd0,C_U}, "AUIPC");


        // =========================================
        // ILLEGAL INSTRUCTION TESTS
        // =========================================

        check(ins(7'h33, 3'd0, 7'h7f),
              BAD, "Illegal R-type");

        check(ins(7'h13, 3'd1, 7'h20),
              BAD, "Illegal SLLI");

        check(ins(7'h13, 3'd5, 7'h7f),
              BAD, "Illegal right shift");

        check(ins(7'h03, 3'd3, 7'h00),
              BAD, "Illegal LOAD");

        check(ins(7'h23, 3'd7, 7'h00),
              BAD, "Illegal STORE");

        check(ins(7'h63, 3'd2, 7'h00),
              BAD, "Illegal BRANCH");

        check(ins(7'h67, 3'd1, 7'h00),
              BAD, "Illegal JALR");

        check(32'h00000000,
              BAD, "Invalid opcode");


        // =========================================
        // FENCE INSTRUCTIONS
        // =========================================

        check(32'h0000000f,
              25'd0, "FENCE");

        check(ins(7'h0f, 3'd0, 7'h7f),
              25'd0, "FENCE nonzero fields");

        check(ins(7'h0f, 3'd1, 7'h00),
              BAD, "FENCE.I unsupported");

        check(ins(7'h0f, 3'd2, 7'h00),
              BAD, "FENCE bad funct3");


        // =========================================
        // SYSTEM INSTRUCTIONS
        // =========================================

        check_exception(32'h00000073,
                        2'b10, "ECALL");

        check_exception(32'h00100073,
                        2'b01, "EBREAK");

        check(ins(7'h73, 3'd0, 7'h00),
              BAD, "SYSTEM bad rs1/rd");

        check(ins(7'h73, 3'd1, 7'h00),
              BAD, "CSR unsupported");


        // =========================================
        // EXCEPTION SIGNAL CLEARING
        // =========================================

        check(ins(7'h13, 3'd0, 7'h00),
              {4'd0,4'd0,3'd0,3'd0,2'd0,2'd0,C_I},
              "ADDI after exceptions");


        // =========================================
        // FINAL RESULTS
        // =========================================

        $display("--------------------------------------");
        $display("Tests: %0d   Passed: %0d   Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("CONTROL UNIT TEST PASSED");
        else
            $display("CONTROL UNIT TEST FAILED");

        $finish;
    end

endmodule