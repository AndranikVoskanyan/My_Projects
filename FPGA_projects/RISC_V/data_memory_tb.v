
`timescale 1ns / 1ps

module data_memory_tb;

    reg clk, rst, req, we;
    reg [31:0] addr, wr_data;
    reg [3:0] byte_en;

    wire [31:0] read_data;
    wire rvalid, error;

    integer tests, errors;

    data_memory dut (
        .clk(clk),
        .rst(rst),
        .req(req),
        .we(we),
        .addr(addr),
        .wr_data(wr_data),
        .byte_en(byte_en),
        .read_data(read_data),
        .rvalid(rvalid),
        .error(error)
    );

    always #5 clk = ~clk;

    task cycle;
        input reset_i, req_i, we_i;
        input [31:0] addr_i, data_i;
        input [3:0] mask_i;
        input [31:0] expected_data;
        input expected_valid, expected_error;
        input [8*40-1:0] name;

        begin
            @(negedge clk);

            rst = reset_i;
            req = req_i;
            we = we_i;
            addr = addr_i;
            wr_data = data_i;
            byte_en = mask_i;

            @(posedge clk);
            #1;

            tests = tests + 1;

            if (read_data !== expected_data ||
                rvalid !== expected_valid ||
                error !== expected_error) begin

                errors = errors + 1;
                $display("FAIL %s", name);
                $display(" Expected: data=%h valid=%b error=%b",
                    expected_data, expected_valid, expected_error);
                $display(" Actual:   data=%h valid=%b error=%b",
                    read_data, rvalid, error);

            end else
                $display("PASS %s", name);
        end
    endtask

    initial begin
        clk = 0;
        rst = 1;
        req = 0;
        we = 0;
        addr = 0;
        wr_data = 0;
        byte_en = 0;

        tests = 0;
        errors = 0;

        @(posedge clk);
        #1;
        tests = tests + 1;

        if ({read_data, rvalid, error} !==
            {32'd0, 1'b0, 1'b0}) begin
            errors = errors + 1;
            $display("FAIL initial reset");
        end else
            $display("PASS initial reset");

        // =====================================
        // FULL WORD READ / WRITE
        // =====================================

        cycle(0,1,1,32'h10000000,32'hAABBCCDD,4'b1111,
              0,1,0,"Write first word");

        cycle(0,1,0,32'h10000000,0,0,
              32'hAABBCCDD,1,0,"Read first word");

        cycle(0,1,1,32'h10000000,32'h11223344,4'b1111,
              32'hAABBCCDD,1,0,"Overwrite first word");

        cycle(0,1,0,32'h10000000,0,0,
              32'h11223344,1,0,"Verify overwritten word");

        // =====================================
        // BYTE ENABLE TESTS
        // =====================================

        cycle(0,1,1,32'h10000000,32'hAABBCCDD,4'b1111,
              32'h11223344,1,0,"Restore pattern");

        // Byte 0
        cycle(0,1,1,32'h10000000,32'h00000011,4'b0001,
              32'h11223344,1,0,"Write byte 0");

        cycle(0,1,0,32'h10000000,0,0,
              32'hAABBCC11,1,0,"Verify byte 0");

        // Byte 1
        cycle(0,1,1,32'h10000000,32'h00002200,4'b0010,
              32'hAABBCC11,1,0,"Write byte 1");

        cycle(0,1,0,32'h10000000,0,0,
              32'hAABB2211,1,0,"Verify byte 1");

        // Byte 2
        cycle(0,1,1,32'h10000000,32'h00330000,4'b0100,
              32'hAABB2211,1,0,"Write byte 2");

        cycle(0,1,0,32'h10000000,0,0,
              32'hAA332211,1,0,"Verify byte 2");

        // Byte 3
        cycle(0,1,1,32'h10000000,32'h44000000,4'b1000,
              32'hAA332211,1,0,"Write byte 3");

        cycle(0,1,0,32'h10000000,0,0,
              32'h44332211,1,0,"Verify byte 3");

        // Two byte lanes together
        cycle(0,1,1,32'h10000000,32'h00AA00BB,4'b0101,
              32'h44332211,1,0,"Write lanes 0 and 2");

        cycle(0,1,0,32'h10000000,0,0,
              32'h44AA22BB,1,0,"Verify lanes 0 and 2");

        cycle(0,1,1,32'h10000000,32'hDD00EE00,4'b1010,
              32'h44AA22BB,1,0,"Write lanes 1 and 3");

        cycle(0,1,0,32'h10000000,0,0,
              32'hDDAAEEBB,1,0,"Verify lanes 1 and 3");

        // No bytes enabled
        cycle(0,1,1,32'h10000000,32'hFFFFFFFF,4'b0000,
              32'hDDAAEEBB,1,0,"Zero byte enable");

        cycle(0,1,0,32'h10000000,0,0,
              32'hDDAAEEBB,1,0,"Verify unchanged data");

        // =====================================
        // MULTIPLE MEMORY WORDS
        // =====================================

        cycle(0,1,1,32'h10000004,32'h12345678,4'b1111,
              32'hDDAAEEBB,1,0,"Write second word");

        cycle(0,1,0,32'h10000004,0,0,
              32'h12345678,1,0,"Read second word");

        cycle(0,1,0,32'h10000000,0,0,
              32'hDDAAEEBB,1,0,"Word isolation");

        // =====================================
        // LAST MEMORY LOCATION
        // =====================================

        cycle(0,1,1,32'h10000FFC,32'hCAFEBABE,4'b1111,
              32'hDDAAEEBB,1,0,"Write last word");

        cycle(0,1,0,32'h10000FFC,0,0,
              32'hCAFEBABE,1,0,"Read last word");

        // =====================================
        // INVALID ADDRESSES
        // =====================================

        cycle(0,1,0,32'h10001000,0,0,
              32'hCAFEBABE,1,1,"Above memory boundary");

        cycle(0,1,0,32'h0FFFFFFC,0,0,
              32'hCAFEBABE,1,1,"Below memory boundary");

        cycle(0,1,0,32'h00000000,0,0,
              32'hCAFEBABE,1,1,"Wrong memory region");

        cycle(0,1,1,32'h10001000,32'h0,4'b1111,
              32'hCAFEBABE,1,1,"Invalid write");

        cycle(0,1,0,32'h10000FFC,0,0,
              32'hCAFEBABE,1,0,"Invalid write no corruption");

        cycle(0,1,0,32'h10000000,0,0,
              32'hDDAAEEBB,1,0,"Recover from error");

        // Lower address bits are ignored by this RAM.
        // The LSU is responsible for alignment checks.

        cycle(0,1,0,32'h10000001,0,0,
              32'hDDAAEEBB,1,0,"Low address bits ignored");

        // =====================================
        // IDLE AND RESET
        // =====================================

        cycle(0,0,0,32'h10000000,0,0,
              0,0,0,"Idle clears outputs");

        cycle(0,0,0,32'h10000000,0,0,
              0,0,0,"Consecutive idle");

        cycle(1,1,1,32'h10000000,32'hFFFFFFFF,4'b1111,
              0,0,0,"Reset overrides write");

        // Reset should not erase stored memory.
        cycle(0,1,0,32'h10000000,0,0,
              32'hDDAAEEBB,1,0,"Memory survives reset");

        cycle(0,1,0,32'h10000004,0,0,
              32'h12345678,1,0,"Second word survives reset");

        // =====================================
        // FINAL SUMMARY
        // =====================================

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("DATA MEMORY TEST PASSED");
        else
            $display("DATA MEMORY TEST FAILED");

        $finish;
    end

endmodule