
`timescale 1ns / 1ps

module instruction_decoder_tb;

    reg  [31:0] instruction;
    wire [6:0]  opcode, funct7;
    wire [4:0]  rd, rs1, rs2;
    wire [2:0]  funct3;

    integer tests, errors, i;
    reg [31:0] pattern;

    instruction_decoder dut (
        .instruction(instruction),
        .opcode(opcode),
        .rd(rd),
        .rs1(rs1),
        .rs2(rs2),
        .funct3(funct3),
        .funct7(funct7)
    );

    // Reconstruct the instruction from extracted fields.
    wire [31:0] reconstructed = {
        funct7, rs2, rs1, funct3, rd, opcode
    };

    task check;
        input [8*32-1:0] name;
        input [31:0] value;
        begin
            instruction = value;
            #10;
            tests = tests + 1;

            if (reconstructed !== value) begin
                errors = errors + 1;

                $display("FAIL %s", name);
                $display("  Instruction=%h", value);
                $display("  Reconstructed=%h", reconstructed);
                $display("  opcode=%h rd=%h funct3=%h",
                         opcode, rd, funct3);
                $display("  rs1=%h rs2=%h funct7=%h",
                         rs1, rs2, funct7);
            end
            else
                $display("PASS %s", name);
        end
    endtask

    initial begin
        instruction = 32'd0;
        tests = 0;
        errors = 0;

        // Test every bit field independently
        check("All zeros",     32'h00000000);
        check("All ones",      32'hFFFFFFFF);
        check("Alternating A", 32'hAAAAAAAA);
        check("Alternating 5", 32'h55555555);

        check("Only opcode",   32'h0000007F);
        check("Only rd",       32'h00000F80);
        check("Only funct3",   32'h00007000);
        check("Only rs1",      32'h000F8000);
        check("Only rs2",      32'h01F00000);
        check("Only funct7",   32'hFE000000);

        // Real RISC-V instructions
        check("ADDI x1,x0,5",   32'h00500093);
        check("ADD x3,x1,x2",   32'h002081B3);
        check("LUI x1,0x12345", 32'h123450B7);
        check("ECALL",          32'h00000073);
        check("EBREAK",         32'h00100073);

        // 64 additional deterministic bit patterns
        pattern = 32'hACE1B00C;

        for (i = 0; i < 64; i = i + 1) begin
            pattern = {
                pattern[30:0],
                pattern[31] ^ pattern[21] ^
                pattern[1]  ^ pattern[0]
            };

            check("Bit-pattern test", pattern);
        end

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("INSTRUCTION DECODER TEST PASSED");
        else
            $display("INSTRUCTION DECODER TEST FAILED");

        $finish;
    end

endmodule