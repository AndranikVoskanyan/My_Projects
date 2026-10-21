
`timescale 1ns / 1ps

module branch_pc_tb;

    reg [31:0] pc, rs1_data, rs2_data, immediate;
    reg [2:0] branch_op;
    reg jump, jalr, branch_en;
    wire branch_taken;
    wire [31:0] target_pc;

    integer tests, errors;

    localparam BEQ  = 3'b000,
               BNE  = 3'b001,
               BLT  = 3'b010,
               BGE  = 3'b011,
               BLTU = 3'b100,
               BGEU = 3'b101;

    branch_pc dut (
        .pc(pc),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data),
        .immediate(immediate),
        .branch_op(branch_op),
        .jump(jump),
        .jalr(jalr),
        .branch_en(branch_en),
        .branch_taken(branch_taken),
        .target_pc(target_pc)
    );

    task check;
        input [8*40-1:0] name;
        input [31:0] p, a, b, imm;
        input [2:0] op;
        input jp, jr, en;
        input expected_taken;
        input [31:0] expected_target;
        begin
            pc = p;
            rs1_data = a;
            rs2_data = b;
            immediate = imm;
            branch_op = op;
            jump = jp;
            jalr = jr;
            branch_en = en;
            #10;
            tests = tests + 1;

            if ((branch_taken !== expected_taken) ||
                (target_pc !== expected_target)) begin
                errors = errors + 1;
                $display("FAIL %s", name);
                $display("  taken: expected=%b got=%b",
                         expected_taken, branch_taken);
                $display("  target: expected=%h got=%h",
                         expected_target, target_pc);
            end else
                $display("PASS %s", name);
        end
    endtask

    // Standard branches: PC=0x1000, immediate=16
    task check_branch;
        input [8*40-1:0] name;
        input [2:0] op;
        input [31:0] a, b;
        input expected_taken;
        begin
            check(name, 32'h00001000, a, b,
                  32'h00000010, op,
                  1'b0, 1'b0, 1'b1,
                  expected_taken, 32'h00001010);
        end
    endtask

    initial begin
        pc = 0;
        rs1_data = 0;
        rs2_data = 0;
        immediate = 0;
        branch_op = 0;
        jump = 0;
        jalr = 0;
        branch_en = 0;
        tests = 0;
        errors = 0;

        // BEQ
        check_branch("BEQ equal", BEQ, 5, 5, 1);
        check_branch("BEQ unequal", BEQ, 5, 6, 0);

        // BNE
        check_branch("BNE equal", BNE, 5, 5, 0);
        check_branch("BNE unequal", BNE, 5, 6, 1);

        // BLT: signed
        check_branch("BLT positive true", BLT, 3, 7, 1);
        check_branch("BLT positive false", BLT, 7, 3, 0);
        check_branch("BLT negative vs positive", BLT,
                     32'hffffffff, 1, 1);
        check_branch("BLT positive vs negative", BLT,
                     1, 32'hffffffff, 0);
        check_branch("BLT two negatives", BLT,
                     32'hfffffff8, 32'hfffffffc, 1);
        check_branch("BLT equal", BLT, 9, 9, 0);

        // BGE: signed
        check_branch("BGE greater", BGE, 7, 3, 1);
        check_branch("BGE less", BGE, 3, 7, 0);
        check_branch("BGE equal", BGE, 7, 7, 1);
        check_branch("BGE negative vs positive", BGE,
                     32'hffffffff, 1, 0);
        check_branch("BGE positive vs negative", BGE,
                     1, 32'hffffffff, 1);
        check_branch("BGE two negatives", BGE,
                     32'hfffffffc, 32'hfffffff8, 1);

        // BLTU: unsigned
        check_branch("BLTU true", BLTU, 3, 7, 1);
        check_branch("BLTU false", BLTU, 7, 3, 0);
        check_branch("BLTU high bit set", BLTU,
                     32'hffffffff, 1, 0);
        check_branch("BLTU zero vs max", BLTU,
                     0, 32'hffffffff, 1);

        // BGEU: unsigned
        check_branch("BGEU greater", BGEU, 7, 3, 1);
        check_branch("BGEU less", BGEU, 3, 7, 0);
        check_branch("BGEU equal", BGEU, 7, 7, 1);
        check_branch("BGEU high bit set", BGEU,
                     32'hffffffff, 1, 1);

        // Branch disabled
        check("Branch disabled even if equal",
              32'h1000, 5, 5, 16, BEQ,
              0, 0, 0, 0, 32'h1010);

        check("No branch or jump",
              32'h2000, 5, 6, 12, BNE,
              0, 0, 0, 0, 32'h200c);

        check("Negative offset no branch",
              32'h1000, 0, 0, 32'hfffffff0, BEQ,
              0, 0, 0, 0, 32'h0ff0);

        // JAL
        check("JAL forward",
              32'h1000, 1, 2, 32'h40, BEQ,
              1, 0, 0, 1, 32'h1040);

        check("JAL backward",
              32'h1000, 1, 2, 32'hfffffffc, BEQ,
              1, 0, 0, 1, 32'h0ffc);

        check("JAL zero offset",
              32'h1000, 1, 2, 0, BEQ,
              1, 0, 0, 1, 32'h1000);

        check("JAL address wraparound",
              32'hfffffffc, 1, 2, 8, BEQ,
              1, 0, 0, 1, 32'h00000004);

        // JALR: target = (rs1 + immediate) & ~1
        check("JALR even target",
              32'h1000, 32'h2000, 0, 16, BEQ,
              0, 1, 0, 1, 32'h2010);

        check("JALR clears bit zero",
              32'h1000, 32'h2000, 0, 17, BEQ,
              0, 1, 0, 1, 32'h2010);

        check("JALR odd rs1",
              32'h1000, 32'h2001, 0, 0, BEQ,
              0, 1, 0, 1, 32'h2000);

        check("JALR negative offset",
              32'h1000, 32'h2000, 0,
              32'hfffffff8, BEQ,
              0, 1, 0, 1, 32'h1ff8);

        check("JALR ignores PC",
              32'haabbcc00, 32'h3000, 0, 4, BEQ,
              0, 1, 0, 1, 32'h3004);

        check("JALR address wraparound",
              32'h1000, 32'hffffffff, 0, 4, BEQ,
              0, 1, 0, 1, 32'h00000002);

        // Unsupported branch condition
        check("Unsupported branch condition",
              32'h1000, 5, 5, 16, 3'b110,
              0, 0, 1, 0, 32'h1010);

        // Control priority
        check("JAL overrides branch",
              32'h1000, 5, 6, 16, BEQ,
              1, 0, 1, 1, 32'h1010);

        check("JALR overrides JAL",
              32'h1000, 32'h3001, 0, 6, BEQ,
              1, 1, 1, 1, 32'h3006);

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("BRANCH/JUMP UNIT TEST PASSED");
        else
            $display("BRANCH/JUMP UNIT TEST FAILED");

        $finish;
    end

endmodule