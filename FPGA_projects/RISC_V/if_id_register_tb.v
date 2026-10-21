
`timescale 1ns / 1ps

module if_id_register_tb;

    reg clk, rst, stall, flush;

    reg [31:0] if_pc;
    reg [31:0] if_instruction;
    reg if_valid;

    wire [31:0] id_pc;
    wire [31:0] id_instruction;
    wire id_valid;

    integer tests, errors;

    localparam [31:0] NOP = 32'h00000013;

    if_id_register dut (
        .clk(clk),
        .rst(rst),
        .stall(stall),
        .flush(flush),
        .if_pc(if_pc),
        .if_instruction(if_instruction),
        .if_valid(if_valid),
        .id_pc(id_pc),
        .id_instruction(id_instruction),
        .id_valid(id_valid)
    );

    always #5 clk = ~clk;

    task check;
        input [31:0] expected_pc;
        input [31:0] expected_instruction;
        input expected_valid;
        input [8*40-1:0] name;

        begin
            tests = tests + 1;

            if (id_pc !== expected_pc ||
                id_instruction !== expected_instruction ||
                id_valid !== expected_valid) begin

                errors = errors + 1;

                $display("FAIL %s", name);
                $display(" Expected PC=%h Instruction=%h Valid=%b",
                         expected_pc,
                         expected_instruction,
                         expected_valid);

                $display(" Actual   PC=%h Instruction=%h Valid=%b",
                         id_pc,
                         id_instruction,
                         id_valid);
            end
            else
                $display("PASS %s", name);
        end
    endtask

    task step;
        input reset_i, stall_i, flush_i;
        input [31:0] pc_i, instruction_i;
        input valid_i;
        input [31:0] expected_pc, expected_instruction;
        input expected_valid;
        input [8*40-1:0] name;

        begin
            @(negedge clk);

            rst = reset_i;
            stall = stall_i;
            flush = flush_i;

            if_pc = pc_i;
            if_instruction = instruction_i;
            if_valid = valid_i;

            @(posedge clk);
            #1;

            check(expected_pc, expected_instruction,
                  expected_valid, name);
        end
    endtask

    initial begin
        clk = 0;
        rst = 1;
        stall = 0;
        flush = 0;

        if_pc = 0;
        if_instruction = NOP;
        if_valid = 0;

        tests = 0;
        errors = 0;

        // =====================================
        // INITIAL RESET
        // =====================================

        @(posedge clk);
        #1;
        check(0, NOP, 0, "Initial reset");

        // =====================================
        // NORMAL INSTRUCTION CAPTURE
        // =====================================

        step(0,0,0,
             32'h00000000,32'h00500093,1,
             32'h00000000,32'h00500093,1,
             "Capture ADDI");

        step(0,0,0,
             32'h00000004,32'h00700113,1,
             32'h00000004,32'h00700113,1,
             "Capture second instruction");

        step(0,0,0,
             32'h00000008,32'h002081B3,1,
             32'h00000008,32'h002081B3,1,
             "Capture ADD");

        // =====================================
        // STALL TESTS
        // =====================================

        step(0,1,0,
             32'h0000000C,32'hFFF18213,1,
             32'h00000008,32'h002081B3,1,
             "Stall holds instruction");

        step(0,1,0,
             32'h00000010,32'h00000073,1,
             32'h00000008,32'h002081B3,1,
             "Second stall cycle");

        step(0,0,0,
             32'h0000000C,32'hFFF18213,1,
             32'h0000000C,32'hFFF18213,1,
             "Resume after stall");

        // =====================================
        // FLUSH TESTS
        // =====================================

        step(0,0,1,
             32'h00000010,32'h00000073,1,
             0,NOP,0,
             "Flush inserts bubble");

        step(0,0,0,
             32'h00000020,32'h00500093,1,
             32'h00000020,32'h00500093,1,
             "Capture after flush");

        // Flush must override stall
        step(0,1,1,
             32'h00000024,32'h00700113,1,
             0,NOP,0,
             "Flush overrides stall");

        // Stall holds the bubble
        step(0,1,0,
             32'h00000028,32'h002081B3,1,
             0,NOP,0,
             "Stall holds bubble");

        step(0,0,0,
             32'h00000028,32'h002081B3,1,
             32'h00000028,32'h002081B3,1,
             "Resume from bubble");

        // =====================================
        // RESET PRIORITY
        // =====================================

        step(1,0,0,
             32'h00000100,32'hFFFFFFFF,1,
             0,NOP,0,
             "Reset clears pipeline");

        step(0,0,0,
             32'h00000100,32'h00500093,1,
             32'h00000100,32'h00500093,1,
             "Capture after reset");

        step(1,1,0,
             32'h00000104,32'h00700113,1,
             0,NOP,0,
             "Reset overrides stall");

        step(1,1,1,
             32'h00000108,32'h002081B3,1,
             0,NOP,0,
             "Reset with stall and flush");

        // =====================================
        // INVALID INSTRUCTION / BUBBLE
        // =====================================

        step(0,0,0,
             32'h00000200,32'hFFFFFFFF,0,
             32'h00000200,32'hFFFFFFFF,0,
             "Capture invalid fetch");

        step(0,0,0,
             32'h00000204,32'h00500093,1,
             32'h00000204,32'h00500093,1,
             "Valid instruction after bubble");

        step(0,0,1,
             32'h00000208,32'h00000000,0,
             0,NOP,0,
             "Flush invalid instruction");

        // =====================================
        // PC / DATA EDGE CASES
        // =====================================

        step(0,0,0,
             32'h80000000,32'h12345678,1,
             32'h80000000,32'h12345678,1,
             "High PC address");

        step(0,0,0,
             32'hFFFFFFFC,32'hFFFFFFFF,1,
             32'hFFFFFFFC,32'hFFFFFFFF,1,
             "Maximum aligned PC");

        // Confirm synchronous behavior:
        // Changing inputs must not immediately change outputs.

        @(negedge clk);
        if_pc = 32'h00000300;
        if_instruction = 32'hDEADBEEF;
        if_valid = 1;

        #1;
        check(32'hFFFFFFFC,32'hFFFFFFFF,1,
              "No asynchronous update");

        @(posedge clk);
        #1;
        check(32'h00000300,32'hDEADBEEF,1,
              "Update on rising edge");

        // Final reset
        step(1,0,0,
             32'h00000400,32'h12345678,1,
             0,NOP,0,
             "Final reset");

        // =====================================
        // FINAL SUMMARY
        // =====================================

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("IF/ID PIPELINE REGISTER TEST PASSED");
        else
            $display("IF/ID PIPELINE REGISTER TEST FAILED");

        $finish;
    end

endmodule