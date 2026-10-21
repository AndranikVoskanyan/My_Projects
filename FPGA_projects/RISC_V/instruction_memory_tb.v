
`timescale 1ns / 1ps

module instruction_memmory_tb;

    reg clk, rst;
    reg [31:0] addr;
    wire [31:0] instruction;
    wire valid;

    integer tests, errors;
    reg [31:0] previous_instruction;
    reg previous_valid;

    instruction_memmory dut (
        .clk(clk),
        .rst(rst),
        .addr(addr),
        .instruction(instruction),
        .valid(valid)
    );

    always #5 clk = ~clk;

    // Check one clock cycle, including synchronous behavior.
    task check_cycle;
        input [31:0] test_addr;
        input test_rst;
        input expected_valid;
        input [31:0] expected_instruction;
        input [8*36-1:0] name;
        begin
            @(negedge clk);
            previous_instruction = instruction;
            previous_valid = valid;
            addr = test_addr;
            rst = test_rst;

            #1;
            if (instruction !== previous_instruction ||
                valid !== previous_valid) begin
                errors = errors + 1;
                $display("FAIL %s: changed before rising edge", name);
            end

            @(posedge clk);
            #1;
            tests = tests + 1;
            if (valid !== expected_valid ||
                instruction !== expected_instruction) begin
                errors = errors + 1;
                $display("FAIL %s: addr=%h rst=%b",
                         name, test_addr, test_rst);
                $display("  expected: valid=%b instruction=%h",
                         expected_valid, expected_instruction);
                $display("  actual:   valid=%b instruction=%h",
                         valid, instruction);
            end else
                $display("PASS %s", name);
        end
    endtask

    initial begin
        clk = 0;
        rst = 1;
        addr = 0;
        tests = 0;
        errors = 0;

        // Reset clears valid synchronously.
        // Instruction is initially unknown.
        @(posedge clk);
        #1;
        tests = tests + 1;
        if (valid !== 1'b0) begin
            errors = errors + 1;
            $display("FAIL initial reset");
        end else
            $display("PASS initial reset");

        // Test instructions loaded from program.mem
        check_cycle(32'h00000000, 0, 1, 32'h00500093, "Fetch word 0");
        check_cycle(32'h00000004, 0, 1, 32'h00700113, "Fetch word 1");
        check_cycle(32'h00000008, 0, 1, 32'h002081b3, "Fetch word 2");
        check_cycle(32'h0000000c, 0, 1, 32'hfff18213, "Fetch word 3");
        check_cycle(32'h00000010, 0, 1, 32'h00000073, "Fetch ECALL word");
        check_cycle(32'h00000014, 0, 1, 32'h00100073, "Fetch EBREAK word");
        check_cycle(32'h00000018, 0, 1, 32'h00000013, "Fetch NOP word");
        check_cycle(32'h0000001c, 0, 1, 32'h0000006f, "Fetch JAL word");

        // Last word: address 4092, index 1023
        check_cycle(32'h00000ffc, 0, 1, 32'hdeadbeef, "Fetch last word");

        // Invalid addresses must clear valid.
        // Instruction output must retain its previous value.
        check_cycle(32'h00000001, 0, 0, 32'hdeadbeef, "Misaligned +1");
        check_cycle(32'h00000002, 0, 0, 32'hdeadbeef, "Misaligned +2");
        check_cycle(32'h00000003, 0, 0, 32'hdeadbeef, "Misaligned +3");
        check_cycle(32'h00000005, 0, 0, 32'hdeadbeef, "Misaligned word 1");
        check_cycle(32'h00000ffd, 0, 0, 32'hdeadbeef, "Misaligned end");
        check_cycle(32'h00001000, 0, 0, 32'hdeadbeef, "Beyond 4 KB");
        check_cycle(32'h10000000, 0, 0, 32'hdeadbeef, "Wrong address region");
        check_cycle(32'hfffffffc, 0, 0, 32'hdeadbeef, "High invalid address");

        // Resume after invalid addresses
        check_cycle(32'h00000004, 0, 1, 32'h00700113, "Recover valid fetch");
        check_cycle(32'h00000ffc, 0, 1, 32'hdeadbeef, "Recover last word");

        // Reset priority and recovery
        check_cycle(32'h00000000, 1, 0, 32'hdeadbeef, "Reset overrides fetch");
        check_cycle(32'h00000000, 0, 1, 32'h00500093, "Fetch after reset");
        check_cycle(32'h00000004, 0, 1, 32'h00700113, "Next fetch after reset");

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("INSTRUCTION MEMORY TEST PASSED");
        else
            $display("INSTRUCTION MEMORY TEST FAILED");

        $finish;
    end

endmodule