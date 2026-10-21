
`timescale 1ns / 1ps

module load_store_tb;

    reg clk, rst;
    reg mem_valid;
    reg [3:0] mem_op;
    reg [31:0] effective_addr, rs2_data;

    wire ram_req, ram_we;
    wire [31:0] ram_addr, ram_wr_data;
    wire [3:0] ram_byte_en;
    wire [31:0] ram_read_data;
    wire ram_rvalid, ram_error;
    wire [31:0] load_result;
    wire lsu_valid, lsu_error;

    integer tests, errors;

    localparam [3:0] LB=4'd0, LH=4'd1, LW=4'd2,
                     LBU=4'd3, LHU=4'd4,
                     SB=4'd5, SH=4'd6, SW=4'd7;

    lsu_store lsu (
        .clk(clk), .rst(rst),
        .mem_valid(mem_valid), .mem_op(mem_op),
        .effective_addr(effective_addr),
        .rs2_data(rs2_data),
        .ram_read_data(ram_read_data),
        .ram_rvalid(ram_rvalid),
        .ram_error(ram_error),
        .ram_req(ram_req),
        .ram_we(ram_we),
        .ram_addr(ram_addr),
        .ram_wr_data(ram_wr_data),
        .ram_byte_en(ram_byte_en),
        .load_result(load_result),
        .lsu_valid(lsu_valid),
        .lsu_error(lsu_error)
    );

    data_memory ram (
        .clk(clk), .rst(rst),
        .req(ram_req), .we(ram_we),
        .addr(ram_addr),
        .wr_data(ram_wr_data),
        .byte_en(ram_byte_en),
        .read_data(ram_read_data),
        .rvalid(ram_rvalid),
        .error(ram_error)
    );

    always #5 clk = ~clk;

    // One LSU transaction.
    // Valid memory requests complete on the second rising edge.
    // Misaligned/unsupported operations complete on the first.

    task check_op;
        input [8*36-1:0] name;
        input [3:0] op;
        input [31:0] address, store_data;
        input expect_request, expect_error, check_load_result;
        input [31:0] expected_load_result;
        input [3:0] expected_byte_en;
        input [31:0] expected_wr_data;

        reg failed;
        reg [31:0] prior_result;

        begin
            failed = 0;

            @(negedge clk);
            mem_valid = 1'b1;
            mem_op = op;
            effective_addr = address;
            rs2_data = store_data;
            prior_result = load_result;
            #1;

            // Check LSU to RAM interface
            if (ram_req !== expect_request ||
                ram_addr !== {address[31:2], 2'b00} ||
                ram_we !== ((op >= SB) && (op <= SW)) ||
                ram_byte_en !== expected_byte_en ||
                ram_wr_data !== expected_wr_data) begin

                failed = 1;
                $display("  BUS req=%b we=%b addr=%h mask=%b data=%h",
                         ram_req, ram_we, ram_addr,
                         ram_byte_en, ram_wr_data);

                $display("  EXP req=%b we=%b addr=%h mask=%b data=%h",
                         expect_request,
                         ((op >= SB) && (op <= SW)),
                         {address[31:2], 2'b00},
                         expected_byte_en, expected_wr_data);
            end

            @(posedge clk);
            #1;

            if (expect_request) begin
                if (lsu_valid !== 1'b0 ||
                    ram_rvalid !== 1'b1 ||
                    ram_error !== expect_error) begin

                    failed = 1;
                    $display("  FIRST EDGE: valid=%b ram_valid=%b ram_error=%b",
                             lsu_valid, ram_rvalid, ram_error);
                end
            end
            else begin
                if (lsu_valid !== 1'b1 ||
                    lsu_error !== 1'b1 ||
                    ram_rvalid !== 1'b0) begin

                    failed = 1;
                    $display("  REJECT: valid=%b error=%b ram_valid=%b",
                             lsu_valid, lsu_error, ram_rvalid);
                end
            end

            @(negedge clk);
            mem_valid = 1'b0;
            #1;

            if (ram_req !== 1'b0) begin
                failed = 1;
                $display("  ERROR: RAM request stayed high");
            end

            if (expect_request) begin
                @(posedge clk);
                #1;

                if (lsu_valid !== 1'b1 ||
                    lsu_error !== expect_error) begin

                    failed = 1;
                    $display("  RESPONSE: valid=%b error=%b",
                             lsu_valid, lsu_error);
                end
            end

            if (check_load_result &&
                load_result !== expected_load_result) begin

                failed = 1;
                $display("  LOAD expected=%h actual=%h",
                         expected_load_result, load_result);
            end

            // Stores/errors must preserve the previous load result
            if (!check_load_result &&
                load_result !== prior_result) begin

                failed = 1;
                $display("  ERROR: load_result changed unexpectedly");
            end

            tests = tests + 1;

            if (failed) begin
                errors = errors + 1;
                $display("FAIL %s op=%d addr=%h",
                         name, op, address);
            end
            else
                $display("PASS %s", name);
        end
    endtask

    task load;
        input [8*36-1:0] name;
        input [3:0] op;
        input [31:0] address, expected;
        begin
            check_op(name, op, address, 32'd0,
                     1, 0, 1, expected, 4'b0000, 32'd0);
        end
    endtask

    task store;
        input [8*36-1:0] name;
        input [3:0] op;
        input [31:0] address, data;
        input [3:0] mask;
        input [31:0] placed_data;
        begin
            check_op(name, op, address, data,
                     1, 0, 0, 0, mask, placed_data);
        end
    endtask

    task bad_align;
        input [8*36-1:0] name;
        input [3:0] op;
        input [31:0] address;
        begin
            check_op(name, op, address, 32'hffffffff,
                     0, 1, 0, 0, 0, 0);
        end
    endtask

    task access_fault;
        input [8*36-1:0] name;
        input [3:0] op;
        input [31:0] address;
        input [3:0] mask;
        input [31:0] placed_data;
        begin
            check_op(name, op, address, 32'hdeadbeef,
                     1, 1, 0, 0, mask, placed_data);
        end
    endtask

    initial begin
        clk = 0;
        rst = 1;
        mem_valid = 0;
        mem_op = LW;
        effective_addr = 0;
        rs2_data = 0;
        tests = 0;
        errors = 0;

        @(posedge clk);
        #1;
        tests = tests + 1;

        if (lsu_valid !== 0 || lsu_error !== 0 ||
            load_result !== 0 || ram_rvalid !== 0 ||
            ram_error !== 0) begin

            errors = errors + 1;
            $display("FAIL initial reset");
        end
        else
            $display("PASS initial reset");

        rst = 0;

        // =====================================
        // FULL-WORD STORE AND LOAD
        // =====================================

        store("SW pattern", SW,
              32'h10000000, 32'hA1B2C3D4,
              4'b1111, 32'hA1B2C3D4);

        load("LW pattern", LW,
             32'h10000000, 32'hA1B2C3D4);

        // =====================================
        // BYTE LOADS: SIGN / ZERO EXTENSION
        // =====================================

        load("LB offset 0", LB,
             32'h10000000, 32'hffffffd4);

        load("LBU offset 0", LBU,
             32'h10000000, 32'h000000d4);

        load("LB offset 1", LB,
             32'h10000001, 32'hffffffc3);

        load("LBU offset 1", LBU,
             32'h10000001, 32'h000000c3);

        load("LB offset 2", LB,
             32'h10000002, 32'hffffffb2);

        load("LBU offset 2", LBU,
             32'h10000002, 32'h000000b2);

        load("LB offset 3", LB,
             32'h10000003, 32'hffffffa1);

        load("LBU offset 3", LBU,
             32'h10000003, 32'h000000a1);

        // =====================================
        // HALFWORD LOADS
        // =====================================

        load("LH offset 0", LH,
             32'h10000000, 32'hffffc3d4);

        load("LHU offset 0", LHU,
             32'h10000000, 32'h0000c3d4);

        load("LH offset 2", LH,
             32'h10000002, 32'hffffa1b2);

        load("LHU offset 2", LHU,
             32'h10000002, 32'h0000a1b2);

        // =====================================
        // BYTE STORES
        // =====================================

        store("SW initialize word 1", SW,
              32'h10000004, 0,
              4'b1111, 0);

        store("SB lane 0", SB,
              32'h10000004, 32'h00000080,
              4'b0001, 32'h00000080);

        store("SB lane 1", SB,
              32'h10000005, 32'h000000ff,
              4'b0010, 32'h0000ff00);

        store("SB lane 2", SB,
              32'h10000006, 32'h00000012,
              4'b0100, 32'h00120000);

        store("SB lane 3", SB,
              32'h10000007, 32'h0000007f,
              4'b1000, 32'h7f000000);

        load("Read four stored bytes", LW,
             32'h10000004, 32'h7f12ff80);

        // =====================================
        // HALFWORD STORES
        // =====================================

        store("SH lower half", SH,
              32'h10000004, 32'h000089ab,
              4'b0011, 32'h000089ab);

        load("LH after SH", LH,
             32'h10000004, 32'hffff89ab);

        load("LHU after SH", LHU,
             32'h10000004, 32'h000089ab);

        store("SH upper half", SH,
              32'h10000006, 32'h0000cdef,
              4'b1100, 32'hcdef0000);

        load("LW after halfword stores", LW,
             32'h10000004, 32'hcdef89ab);

        load("Original word unchanged", LW,
             32'h10000000, 32'hA1B2C3D4);

        // =====================================
        // LAST MEMORY WORD
        // =====================================

        store("SW last word", SW,
              32'h10000ffc, 32'hDEADBEEF,
              4'b1111, 32'hDEADBEEF);

        load("LW last word", LW,
             32'h10000ffc, 32'hDEADBEEF);

        load("LB last byte", LB,
             32'h10000fff, 32'hffffffde);

        // =====================================
        // MISALIGNED ACCESSES
        // =====================================

        bad_align("LH misaligned", LH, 32'h10000001);
        bad_align("LHU misaligned", LHU, 32'h10000003);
        bad_align("LW misaligned", LW, 32'h10000002);
        bad_align("SH misaligned", SH, 32'h10000001);
        bad_align("SW misaligned", SW, 32'h10000002);
        bad_align("SW misaligned at edge", SW, 32'h10000ffe);

        check_op("Unsupported LSU op", 4'd8,
                 32'h10000000, 0,
                 0, 1, 0, 0, 0, 0);

        load("Unchanged after bad stores", LW,
             32'h10000000, 32'hA1B2C3D4);

        // =====================================
        // ACCESS FAULTS
        // =====================================

        access_fault("LW above region", LW,
                     32'h10001000, 0, 0);

        access_fault("LW below region", LW,
                     32'h0ffffffc, 0, 0);

        access_fault("LB wrong region", LB,
                     32'h00000000, 0, 0);

        access_fault("SW above region", SW,
                     32'h10001000, 4'b1111,
                     32'hDEADBEEF);

        load("Read last word after fault", LW,
             32'h10000ffc, 32'hDEADBEEF);

        // =====================================
        // RESET AND MEMORY RETENTION
        // =====================================

        @(negedge clk);
        rst = 1;
        mem_valid = 0;

        @(posedge clk);
        #1;

        tests = tests + 1;

        if (lsu_valid !== 0 || lsu_error !== 0 ||
            load_result !== 0 || ram_rvalid !== 0 ||
            ram_error !== 0) begin

            errors = errors + 1;
            $display("FAIL reset clears outputs");
        end
        else
            $display("PASS reset clears outputs");

        rst = 0;

        load("RAM survives reset", LW,
             32'h10000004, 32'hcdef89ab);

        // =====================================
        // FINAL RESULTS
        // =====================================

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("LSU + DATA MEMORY TEST PASSED");
        else
            $display("LSU + DATA MEMORY TEST FAILED");

        $finish;
    end

endmodule