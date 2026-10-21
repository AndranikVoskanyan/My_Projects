
`timescale 1ns / 1ps

module mem_wb_register_tb;

    reg clk, rst, stall, flush;

    reg [140:0] stimulus;
    reg [140:0] expected;
    reg [140:0] pattern;

    integer tests, errors, i;

    // =====================================
    // MEMORY STAGE INPUTS
    // =====================================

    wire mem_valid;
    wire [31:0] mem_pc;
    wire [31:0] mem_pc_plus4;
    wire [31:0] mem_alu_result;
    wire [31:0] mem_load_result;
    wire [4:0] mem_rd_addr;

    wire mem_reg_write;
    wire [1:0] mem_wb_sel;

    wire mem_illegal_instr;
    wire mem_ecall;
    wire mem_ebreak;
    wire mem_access_fault;

    // =====================================
    // WRITEBACK STAGE OUTPUTS
    // =====================================

    wire wb_valid;
    wire [31:0] wb_pc;
    wire [31:0] wb_pc_plus4;
    wire [31:0] wb_alu_result;
    wire [31:0] wb_load_result;
    wire [4:0] wb_rd_addr;

    wire wb_reg_write;
    wire [1:0] wb_wb_sel;

    wire wb_illegal_instr;
    wire wb_ecall;
    wire wb_ebreak;
    wire wb_access_fault;

    // =====================================
    // PACK INPUT SIGNALS
    // =====================================

    assign {
        mem_valid,
        mem_pc,
        mem_pc_plus4,
        mem_alu_result,
        mem_load_result,
        mem_rd_addr,
        mem_reg_write,
        mem_wb_sel,
        mem_illegal_instr,
        mem_ecall,
        mem_ebreak,
        mem_access_fault
    } = stimulus;

    // =====================================
    // PACK OUTPUT SIGNALS
    // =====================================

    wire [140:0] actual = {
        wb_valid,
        wb_pc,
        wb_pc_plus4,
        wb_alu_result,
        wb_load_result,
        wb_rd_addr,
        wb_reg_write,
        wb_wb_sel,
        wb_illegal_instr,
        wb_ecall,
        wb_ebreak,
        wb_access_fault
    };

    // =====================================
    // EXPECTED CAPTURE BEHAVIOR
    // =====================================

    wire [140:0] captured = {
        mem_valid,
        mem_pc,
        mem_pc_plus4,
        mem_alu_result,
        mem_load_result,
        mem_rd_addr,

        (mem_valid &&
         mem_reg_write &&
         !mem_illegal_instr &&
         !mem_ecall &&
         !mem_ebreak &&
         !mem_access_fault),

        mem_wb_sel,

        (mem_valid && mem_illegal_instr),
        (mem_valid && mem_ecall),
        (mem_valid && mem_ebreak),
        (mem_valid && mem_access_fault)
    };

    // =====================================
    // DUT
    // =====================================

    mem_wb_register dut (
        .clk(clk),
        .rst(rst),
        .stall(stall),
        .flush(flush),

        .mem_valid(mem_valid),
        .mem_pc(mem_pc),
        .mem_pc_plus4(mem_pc_plus4),
        .mem_alu_result(mem_alu_result),
        .mem_load_result(mem_load_result),
        .mem_rd_addr(mem_rd_addr),

        .mem_reg_write(mem_reg_write),
        .mem_wb_sel(mem_wb_sel),

        .mem_illegal_instr(mem_illegal_instr),
        .mem_ecall(mem_ecall),
        .mem_ebreak(mem_ebreak),
        .mem_access_fault(mem_access_fault),

        .wb_valid(wb_valid),
        .wb_pc(wb_pc),
        .wb_pc_plus4(wb_pc_plus4),
        .wb_alu_result(wb_alu_result),
        .wb_load_result(wb_load_result),
        .wb_rd_addr(wb_rd_addr),

        .wb_reg_write(wb_reg_write),
        .wb_wb_sel(wb_wb_sel),

        .wb_illegal_instr(wb_illegal_instr),
        .wb_ecall(wb_ecall),
        .wb_ebreak(wb_ebreak),
        .wb_access_fault(wb_access_fault)
    );

    always #5 clk = ~clk;

    // =====================================
    // SELF-CHECKING TASK
    // =====================================

    task step;
        input [8*40-1:0] name;
        input do_reset, do_flush, do_stall;
        input [140:0] data;

        reg failed;

        begin
            @(negedge clk);

            rst = do_reset;
            flush = do_flush;
            stall = do_stall;
            stimulus = data;
            failed = 0;

            // Outputs must remain unchanged
            // before rising clock edge.

            #1;

            if (actual !== expected) begin
                failed = 1;
                $display("  Outputs changed before clock!");
            end

            // Reference model
            if (rst || flush)
                expected = 141'b0;
            else if (!stall)
                expected = captured;

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

    // =====================================
    // TEST SEQUENCE
    // =====================================

    initial begin

        clk = 0;
        rst = 1;
        stall = 0;
        flush = 0;

        stimulus = 141'b0;
        expected = 141'b0;
        pattern = 141'b0;

        tests = 0;
        errors = 0;

        // =====================================
        // BASIC REGISTER OPERATION
        // =====================================

        step("Initial reset",
             1, 0, 0, {141{1'b1}});

        pattern = {141{1'b1}};
        pattern[3:0] = 4'b0000;

        step("Normal valid capture",
             0, 0, 0, pattern);

        step("Stall holds values",
             0, 0, 1, 141'b0);

        step("Second stall cycle",
             0, 0, 1, {141{1'b1}});

        step("Flush overrides stall",
             0, 1, 1, {141{1'b1}});

        step("Capture after flush",
             0, 0, 0, pattern);

        step("Reset overrides stall",
             1, 0, 1, {141{1'b1}});

        step("Reset overrides flush",
             1, 1, 0, {141{1'b1}});

        step("Capture all zeros",
             0, 0, 0, 141'b0);

        // =====================================
        // INVALID INSTRUCTION
        // =====================================

        pattern = {141{1'b1}};
        pattern[140] = 1'b0;
        pattern[3:0] = 4'b0000;

        step("Invalid bubble disables writes",
             0, 0, 0, pattern);

        // =====================================
        // EXCEPTION TESTS
        // =====================================

        pattern = {141{1'b1}};
        pattern[3:0] = 4'b1000;

        step("Illegal instruction",
             0, 0, 0, pattern);

        pattern[3:0] = 4'b0100;

        step("ECALL exception",
             0, 0, 0, pattern);

        pattern[3:0] = 4'b0010;

        step("EBREAK exception",
             0, 0, 0, pattern);

        pattern[3:0] = 4'b0001;

        step("Memory access fault",
             0, 0, 0, pattern);

        pattern[3:0] = 4'b1111;

        step("All exception flags",
             0, 0, 0, pattern);

        pattern[3:0] = 4'b0000;

        step("Recover after exceptions",
             0, 0, 0, pattern);

        // =====================================
        // DISTINCT DATA FIELD TEST
        // =====================================

        pattern = 141'b0;

        pattern[140]     = 1'b1;
        pattern[139:108] = 32'h00001000;
        pattern[107:76]  = 32'h00001004;
        pattern[75:44]   = 32'hAABBCCDD;
        pattern[43:12]   = 32'h12345678;
        pattern[11:7]    = 5'd17;
        pattern[6]       = 1'b1;
        pattern[5:4]     = 2'b01;
        pattern[3:0]     = 4'b0000;

        step("Distinct PC data and controls",
             0, 0, 0, pattern);

        // =====================================
        // FLUSH
        // =====================================

        step("Flush clears all outputs",
             0, 1, 0, {141{1'b1}});

        // =====================================
        // WALKING BIT TEST
        // =====================================

        for (i = 0; i < 141; i = i + 1) begin

            pattern = 141'b0;
            pattern[140] = 1'b1;
            pattern[i] = 1'b1;

            step("Walking input bit",
                 0, 0, 0, pattern);

        end

        // =====================================
        // FINAL RESET
        // =====================================

        step("Final reset",
             1, 0, 0, 141'b0);

        // =====================================
        // FINAL RESULTS
        // =====================================

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("MEM/WB PIPELINE REGISTER TEST PASSED");
        else
            $display("MEM/WB PIPELINE REGISTER TEST FAILED");

        $finish;

    end

endmodule