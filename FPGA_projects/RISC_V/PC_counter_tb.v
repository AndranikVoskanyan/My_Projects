
`timescale 1ns / 1ps

module PC_counter_tb;

    reg clk, rst, stall;
    reg [31:0] next_pc;
    wire [31:0] pc;

    integer tests, errors;

    PC dut (
        .clk(clk),
        .rst(rst),
        .stall(stall),
        .next_pc(next_pc),
        .pc(pc)
    );

    always #5 clk = ~clk;

    task check_pc;
        input [31:0] expected;
        input [8*40-1:0] test_name;
        begin
            tests = tests + 1;
            if (pc !== expected) begin
                errors = errors + 1;
                $display("FAIL %s expected=%h got=%h",
                         test_name, expected, pc);
            end else begin
                $display("PASS %s", test_name);
            end
        end
    endtask

    // Apply inputs on falling edge, check after rising edge.
    task step;
        input [31:0] value, expected;
        input do_reset, do_stall;
        input [8*40-1:0] test_name;
        begin
            @(negedge clk);
            next_pc = value;
            rst = do_reset;
            stall = do_stall;

            @(posedge clk);
            #1;
            check_pc(expected, test_name);
        end
    endtask

    initial begin
        clk = 0;
        rst = 1;
        stall = 0;
        next_pc = 32'h12345678;
        tests = 0;
        errors = 0;

        // Initial reset
        @(posedge clk);
        #1;
        check_pc(32'h00000000, "Initial synchronous reset");

        // Normal PC updates
        step(32'h00001000, 32'h00001000, 0, 0,
             "Load PC 0x1000");

        step(32'h00001004, 32'h00001004, 0, 0,
             "Sequential address +4");

        step(32'h00001008, 32'h00001008, 0, 0,
             "Sequential address again");

        // Stall behavior
        step(32'h00002000, 32'h00001008, 0, 1,
             "Stall holds PC");

        step(32'h00003000, 32'h00001008, 0, 1,
             "Stall still holds PC");

        step(32'h00002000, 32'h00002000, 0, 0,
             "Resume after stall");

        // Target addresses
        step(32'h00000100, 32'h00000100, 0, 0,
             "Jump to lower address");

        step(32'h80000000, 32'h80000000, 0, 0,
             "High-bit address");

        step(32'hFFFFFFFF, 32'hFFFFFFFF, 0, 0,
             "Maximum 32-bit address");

        step(32'h00000003, 32'h00000003, 0, 0,
             "PC accepts arbitrary bits");

        step(32'h00000000, 32'h00000000, 0, 0,
             "Explicit next PC zero");

        // Confirm PC updates only on rising edge
        step(32'h00004000, 32'h00004000, 0, 0,
             "Prepare timing test");

        @(negedge clk);
        next_pc = 32'h00005000;
        #1;
        check_pc(32'h00004000,
                 "No asynchronous PC update");

        @(posedge clk);
        #1;
        check_pc(32'h00005000,
                 "Update on rising edge");

        // Synchronous reset must override stall
        @(negedge clk);
        rst = 1;
        stall = 1;
        next_pc = 32'hDEADBEEF;

        #1;
        check_pc(32'h00005000,
                 "Reset not asynchronous");

        @(posedge clk);
        #1;
        check_pc(32'h00000000,
                 "Reset overrides stall");

        // Resume after reset
        step(32'h00006000, 32'h00000000, 0, 1,
             "Hold zero after reset");

        step(32'h00006000, 32'h00006000, 0, 0,
             "Resume from reset");

        step(32'hFFFFFFFF, 32'h00000000, 1, 0,
             "Reset overrides PC update");

        step(32'h00000004, 32'h00000004, 0, 0,
             "Update after second reset");

        $display("--------------------------------------");
        $display("Tests: %0d   Passed: %0d   Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("PC TEST PASSED");
        else
            $display("PC TEST FAILED");

        $finish;
    end

endmodule