
`timescale 1ns / 1ps

module id_ex_register_tb;

    reg clk, rst, stall, flush;
    reg [167:0] stimulus;
    reg [167:0] expected;
    integer tests, errors, i;
    reg [167:0] pattern;

    wire id_valid;
    wire [31:0] id_pc, id_rs1_data, id_rs2_data, id_immediate;
    wire [4:0] id_rs1_addr, id_rs2_addr, id_rd_addr;
    wire [3:0] id_alu_op, id_mem_op;
    wire [1:0] id_alu_src_a, id_wb_sel;
    wire id_alu_src_b, id_reg_write, id_mem_en, id_branch_en;
    wire [2:0] id_branch_op;
    wire id_jump, id_jalr, id_illegal_instr, id_ecall, id_ebreak;

    wire ex_valid;
    wire [31:0] ex_pc, ex_rs1_data, ex_rs2_data, ex_immediate;
    wire [4:0] ex_rs1_addr, ex_rs2_addr, ex_rd_addr;
    wire [3:0] ex_alu_op, ex_mem_op;
    wire [1:0] ex_alu_src_a, ex_wb_sel;
    wire ex_alu_src_b, ex_reg_write, ex_mem_en, ex_branch_en;
    wire [2:0] ex_branch_op;
    wire ex_jump, ex_jalr, ex_illegal_instr, ex_ecall, ex_ebreak;

    // Pack all 168 Decode-stage bits into one test stimulus.
    assign {
        id_valid, id_pc, id_rs1_data, id_rs2_data, id_immediate,
        id_rs1_addr, id_rs2_addr, id_rd_addr,
        id_alu_op, id_alu_src_a, id_alu_src_b,
        id_reg_write, id_wb_sel, id_mem_en, id_mem_op,
        id_branch_en, id_branch_op, id_jump, id_jalr,
        id_illegal_instr, id_ecall, id_ebreak
    } = stimulus;

    wire [167:0] actual = {
        ex_valid, ex_pc, ex_rs1_data, ex_rs2_data, ex_immediate,
        ex_rs1_addr, ex_rs2_addr, ex_rd_addr,
        ex_alu_op, ex_alu_src_a, ex_alu_src_b,
        ex_reg_write, ex_wb_sel, ex_mem_en, ex_mem_op,
        ex_branch_en, ex_branch_op, ex_jump, ex_jalr,
        ex_illegal_instr, ex_ecall, ex_ebreak
    };

    // Invalid instructions must not trigger side effects.
    wire [167:0] captured = {
        id_valid, id_pc, id_rs1_data, id_rs2_data, id_immediate,
        id_rs1_addr, id_rs2_addr, id_rd_addr,
        id_alu_op, id_alu_src_a, id_alu_src_b,
        (id_valid & id_reg_write), id_wb_sel,
        (id_valid & id_mem_en), id_mem_op,
        (id_valid & id_branch_en), id_branch_op,
        (id_valid & id_jump), (id_valid & id_jalr),
        (id_valid & id_illegal_instr),
        (id_valid & id_ecall), (id_valid & id_ebreak)
    };

    id_ex_register dut (
        .clk(clk), .rst(rst), .flush(flush), .stall(stall),
        .id_valid(id_valid), .id_pc(id_pc),
        .id_rs1_data(id_rs1_data), .id_rs2_data(id_rs2_data),
        .id_immediate(id_immediate),
        .id_rs1_addr(id_rs1_addr), .id_rs2_addr(id_rs2_addr),
        .id_rd_addr(id_rd_addr),
        .id_alu_op(id_alu_op), .id_alu_src_a(id_alu_src_a),
        .id_alu_src_b(id_alu_src_b), .id_reg_write(id_reg_write),
        .id_wb_sel(id_wb_sel), .id_mem_en(id_mem_en),
        .id_mem_op(id_mem_op), .id_branch_en(id_branch_en),
        .id_branch_op(id_branch_op), .id_jump(id_jump),
        .id_jalr(id_jalr), .id_illegal_instr(id_illegal_instr),
        .id_ecall(id_ecall), .id_ebreak(id_ebreak),
        .ex_valid(ex_valid), .ex_pc(ex_pc),
        .ex_rs1_data(ex_rs1_data), .ex_rs2_data(ex_rs2_data),
        .ex_immediate(ex_immediate),
        .ex_rs1_addr(ex_rs1_addr), .ex_rs2_addr(ex_rs2_addr),
        .ex_rd_addr(ex_rd_addr),
        .ex_alu_op(ex_alu_op), .ex_alu_src_a(ex_alu_src_a),
        .ex_alu_src_b(ex_alu_src_b), .ex_reg_write(ex_reg_write),
        .ex_wb_sel(ex_wb_sel), .ex_mem_en(ex_mem_en),
        .ex_mem_op(ex_mem_op), .ex_branch_en(ex_branch_en),
        .ex_branch_op(ex_branch_op), .ex_jump(ex_jump),
        .ex_jalr(ex_jalr), .ex_illegal_instr(ex_illegal_instr),
        .ex_ecall(ex_ecall), .ex_ebreak(ex_ebreak)
    );

    always #5 clk = ~clk;

    task step;
        input [8*40-1:0] name;
        input do_reset, do_flush, do_stall;
        input [167:0] data;

        begin
            @(negedge clk);

            rst = do_reset;
            flush = do_flush;
            stall = do_stall;
            stimulus = data;

            // Outputs must not change before rising edge.
            #1;
            if (actual !== expected) begin
                errors = errors + 1;
                $display("FAIL before clock: %s", name);
            end

            // Reference behavior
            if (rst || flush)
                expected = 168'b0;
            else if (!stall)
                expected = captured;

            @(posedge clk);
            #1;

            tests = tests + 1;

            if (actual !== expected) begin
                errors = errors + 1;
                $display("FAIL %s", name);
                $display(" expected=%h", expected);
                $display(" actual  =%h", actual);
            end
            else
                $display("PASS %s", name);
        end
    endtask

    initial begin
        clk = 0;
        rst = 1;
        stall = 0;
        flush = 0;
        stimulus = 168'b0;
        expected = 168'b0;
        tests = 0;
        errors = 0;

        // Basic behavior
        step("Initial reset", 1, 0, 0, {168{1'b1}});
        step("Capture all ones", 0, 0, 0, {168{1'b1}});
        step("Stall holds all outputs", 0, 0, 1, 168'b0);
        step("Second stalled cycle", 0, 0, 1, {168{1'b1}});
        step("Flush overrides stall", 0, 1, 1, {168{1'b1}});
        step("Capture after flush", 0, 0, 0, {168{1'b1}});
        step("Reset overrides stall", 1, 0, 1, {168{1'b1}});
        step("Reset overrides flush", 1, 1, 0, {168{1'b1}});
        step("Capture all zeros", 0, 0, 0, 168'b0);

        // Valid=0 should disable all side-effect controls
        step("Invalid bubble gates side effects", 0, 0, 0,
             {1'b0, {167{1'b1}}});

        step("Valid after bubble", 0, 0, 0, {168{1'b1}});
        step("Flush during execution", 0, 1, 0, {168{1'b1}});

        // Walking-bit test: individually exercise all 167
        // remaining input bits while keeping valid=1.
        for (i = 0; i < 167; i = i + 1) begin
            pattern = 168'b0;
            pattern[167] = 1'b1;
            pattern[i] = 1'b1;

            step("Walking input bit", 0, 0, 0, pattern);
        end

        step("Final reset", 1, 0, 0, 168'b0);

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("ID/EX PIPELINE REGISTER TEST PASSED");
        else
            $display("ID/EX PIPELINE REGISTER TEST FAILED");

        $finish;
    end

endmodule