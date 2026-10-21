
`timescale 1ns / 1ps

module ex_mem_register_tb;

    reg clk, rst, stall, flush;

    reg [144:0] stimulus;
    reg [144:0] expected;
    reg [144:0] pattern;

    integer tests, errors, i;

    // Execute-stage inputs
    wire ex_valid;
    wire [31:0] ex_pc, ex_pc_plus4;
    wire [31:0] ex_alu_result, ex_store_data;
    wire [4:0] ex_rd_addr;
    wire ex_reg_write;
    wire [1:0] ex_wb_sel;
    wire ex_mem_en;
    wire [3:0] ex_mem_op;
    wire ex_illegal_instr, ex_ecall, ex_ebreak;

    // Memory-stage outputs
    wire mem_valid;
    wire [31:0] mem_pc, mem_pc_plus4;
    wire [31:0] mem_alu_result, mem_store_data;
    wire [4:0] mem_rd_addr;
    wire mem_reg_write;
    wire [1:0] mem_wb_sel;
    wire mem_mem_en;
    wire [3:0] mem_mem_op;
    wire mem_illegal_instr, mem_ecall, mem_ebreak;

    // Pack all Execute-stage signals into one stimulus.
    assign {
        ex_valid,
        ex_pc,
        ex_pc_plus4,
        ex_alu_result,
        ex_store_data,
        ex_rd_addr,
        ex_reg_write,
        ex_wb_sel,
        ex_mem_en,
        ex_mem_op,
        ex_illegal_instr,
        ex_ecall,
        ex_ebreak
    } = stimulus;

    // Combine all registered outputs for comparison.
    wire [144:0] actual = {
        mem_valid,
        mem_pc,
        mem_pc_plus4,
        mem_alu_result,
        mem_store_data,
        mem_rd_addr,
        mem_reg_write,
        mem_wb_sel,
        mem_mem_en,
        mem_mem_op,
        mem_illegal_instr,
        mem_ecall,
        mem_ebreak
    };

    // Expected output when capturing a new instruction.
    // Exceptions and bubbles must disable side effects.
    wire [144:0] captured = {
        ex_valid,
        ex_pc,
        ex_pc_plus4,
        ex_alu_result,
        ex_store_data,
        ex_rd_addr,

        (ex_valid && !ex_illegal_instr &&
         !ex_ecall && !ex_ebreak && ex_reg_write),

        ex_wb_sel,

        (ex_valid && !ex_illegal_instr &&
         !ex_ecall && !ex_ebreak && ex_mem_en),

        ex_mem_op,

        (ex_valid && ex_illegal_instr),
        (ex_valid && ex_ecall),
        (ex_valid && ex_ebreak)
    };

    ex_mem_register dut (
        .clk(clk),
        .rst(rst),
        .stall(stall),
        .flush(flush),

        .ex_valid(ex_valid),
        .ex_pc(ex_pc),
        .ex_pc_plus4(ex_pc_plus4),
        .ex_alu_result(ex_alu_result),
        .ex_store_data(ex_store_data),
        .ex_rd_addr(ex_rd_addr),

        .ex_reg_write(ex_reg_write),
        .ex_wb_sel(ex_wb_sel),
        .ex_mem_en(ex_mem_en),
        .ex_mem_op(ex_mem_op),

        .ex_illegal_instr(ex_illegal_instr),
        .ex_ecall(ex_ecall),
        .ex_ebreak(ex_ebreak),

        .mem_valid(mem_valid),
        .mem_pc(mem_pc),
        .mem_pc_plus4(mem_pc_plus4),
        .mem_alu_result(mem_alu_result),
        .mem_store_data(mem_store_data),
        .mem_rd_addr(mem_rd_addr),

        .mem_reg_write(mem_reg_write),
        .mem_wb_sel(mem_wb_sel),
        .mem_mem_en(mem_mem_en),
        .mem_mem_op(mem_mem_op),

        .mem_illegal_instr(mem_illegal_instr),
        .mem_ecall(mem_ecall),
        .mem_ebreak(mem_ebreak)
    );

    always #5 clk = ~clk;

    // =====================================
    // SELF-CHECKING TEST TASK
    // =====================================

    task step;
        input [8*40-1:0] name;
        input do_reset, do_flush, do_stall;
        input [144:0] data;

        reg failed;

        begin
            @(negedge clk);

            rst = do_reset;
            flush = do_flush;
            stall = do_stall;
            stimulus = data;
            failed = 0;

            // Outputs must not change before the clock.
            #1;
            if (actual !== expected) begin
                failed = 1;
                $display("  Outputs changed before clock!");
            end

            // Golden reference behavior
            if (rst || flush)
                expected = 145'b0;
            else if (!stall)
                expected = captured;

            // Check after rising edge
            @(posedge clk);
            #1;

            if (actual !== expected) begin
                failed = 1;
                $display("  Expected = %h", expected);
                $display("  Actual   = %h", actual);
            end

            tests = tests + 1;

            if (failed) begin
                errors = errors + 1;
                $display("FAIL %s", name);
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
        stimulus = 145'b0;
        expected = 145'b0;
        pattern = 145'b0;

        tests = 0;
        errors = 0;

        // =====================================
        // BASIC REGISTER BEHAVIOR
        // =====================================

        step("Initial reset",
             1, 0, 0, {145{1'b1}});

        // Valid instruction, all other bits asserted,
        // except exception flags.
        pattern = {145{1'b1}};
        pattern[2:0] = 3'b000;

        step("Normal valid capture",
             0, 0, 0, pattern);

        step("Stall holds all values",
             0, 0, 1, 145'b0);

        step("Second stalled cycle",
             0, 0, 1, {145{1'b1}});

        step("Flush overrides stall",
             0, 1, 1, {145{1'b1}});

        // =====================================
        // EXCEPTION HANDLING
        // =====================================

        step("All exceptions asserted",
             0, 0, 0, {145{1'b1}});

        // Invalid instruction with all control bits high.
        pattern = {145{1'b1}};
        pattern[144] = 1'b0;
        pattern[2:0] = 3'b000;

        step("Invalid bubble suppresses writes",
             0, 0, 0, pattern);

        // Illegal instruction
        pattern = {145{1'b1}};
        pattern[2:0] = 3'b100;

        step("Illegal instruction",
             0, 0, 0, pattern);

        // ECALL
        pattern[2:0] = 3'b010;

        step("ECALL exception",
             0, 0, 0, pattern);

        // EBREAK
        pattern[2:0] = 3'b001;

        step("EBREAK exception",
             0, 0, 0, pattern);

        // All three flags high
        pattern[2:0] = 3'b111;

        step("Simultaneous exception flags",
             0, 0, 0, pattern);

        // Recover from exceptions
        pattern[2:0] = 3'b000;

        step("Recovery after exception",
             0, 0, 0, pattern);

        // =====================================
        // FLUSH AND RESET PRIORITY
        // =====================================

        step("Flush clears outputs",
             0, 1, 0, {145{1'b1}});

        step("Reset overrides stall",
             1, 0, 1, {145{1'b1}});

        step("Reset overrides flush",
             1, 1, 0, {145{1'b1}});

        step("Capture zero",
             0, 0, 0, 145'b0);

        // =====================================
        // DISTINCT DATA FIELDS
        // =====================================

        pattern = 145'b0;

        pattern[144]     = 1'b1;          // valid
        pattern[143:112] = 32'h00001000;  // PC
        pattern[111:80]  = 32'h00001004;  // PC+4
        pattern[79:48]   = 32'hAABBCCDD;  // ALU result
        pattern[47:16]   = 32'h12345678;  // store data
        pattern[15:11]   = 5'd17;         // rd
        pattern[10]      = 1'b1;          // reg_write
        pattern[9:8]     = 2'b01;         // wb_sel
        pattern[7]       = 1'b1;          // mem_en
        pattern[6:3]     = 4'b0111;       // SW
        pattern[2:0]     = 3'b000;        // no exception

        step("Distinct PC data and controls",
             0, 0, 0, pattern);

        // =====================================
        // WALKING-BIT TESTS
        // =====================================

        // Test every one of the 145 input bits.
        for (i = 0; i < 145; i = i + 1) begin
            pattern = 145'b0;
            pattern[144] = 1'b1;
            pattern[i] = 1'b1;

            step("Walking input bit",
                 0, 0, 0, pattern);
        end

        // =====================================
        // FINAL RESET
        // =====================================

        step("Final reset",
             1, 0, 0, 145'b0);

        // =====================================
        // RESULTS
        // =====================================

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("EX/MEM PIPELINE REGISTER TEST PASSED");
        else
            $display("EX/MEM PIPELINE REGISTER TEST FAILED");

        $finish;
    end

endmodule