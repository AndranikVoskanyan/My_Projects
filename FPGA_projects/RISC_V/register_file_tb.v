
`timescale 1ns / 1ps

module register_file_tb;

    reg clk;
    reg rd_we;
    reg [4:0] rs1_addr, rs2_addr, rd_addr;
    reg [31:0] rd_data;
    wire [31:0] rs1_data, rs2_data;

    integer tests, errors, i;

    register_file dut (
        .clk(clk),
        .rd_we(rd_we),
        .rs1_addr(rs1_addr),
        .rs2_addr(rs2_addr),
        .rd_addr(rd_addr),
        .rd_data(rd_data),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data)
    );

    always #5 clk = ~clk;

    task write_reg;
        input [4:0] addr;
        input [31:0] data;
        input enable;
        begin
            @(negedge clk);
            rd_addr = addr;
            rd_data = data;
            rd_we = enable;
            @(posedge clk);
            #1;
            rd_we = 1'b0;
        end
    endtask

    task check;
        input [4:0] addr1, addr2;
        input [31:0] expected1, expected2;
        input [8*32-1:0] name;
        begin
            rs1_addr = addr1;
            rs2_addr = addr2;
            #1;
            tests = tests + 1;

            if ((rs1_data !== expected1) ||
                (rs2_data !== expected2)) begin
                errors = errors + 1;
                $display("FAIL %s", name);
                $display("  rs1 x%0d expected=%h actual=%h",
                         addr1, expected1, rs1_data);
                $display("  rs2 x%0d expected=%h actual=%h",
                         addr2, expected2, rs2_data);
            end else
                $display("PASS %s", name);
        end
    endtask

    initial begin
        clk = 0;
        rd_we = 0;
        rs1_addr = 0;
        rs2_addr = 0;
        rd_addr = 0;
        rd_data = 0;
        tests = 0;
        errors = 0;

        // x0 must always read zero
        check(0, 0, 0, 0, "x0 reads zero");

        // Write x1
        write_reg(1, 32'h11111111, 1);
        check(1, 0, 32'h11111111, 0, "Write x1");

        // Two independent read ports
        write_reg(2, 32'h22222222, 1);
        check(1, 2, 32'h11111111, 32'h22222222,
              "Two read ports");

        // Highest register address
        write_reg(31, 32'hFEDCBA98, 1);
        check(31, 2, 32'hFEDCBA98, 32'h22222222,
              "Register x31");

        // Attempt to write x0
        write_reg(0, 32'hFFFFFFFF, 1);
        check(0, 31, 0, 32'hFEDCBA98,
              "x0 write ignored");

        // Disabled write must not modify x1
        write_reg(1, 32'h55555555, 0);
        check(1, 2, 32'h11111111, 32'h22222222,
              "Write enable disabled");

        // Overwrite existing register
        write_reg(2, 32'hDEADBEEF, 1);
        check(2, 1, 32'hDEADBEEF, 32'h11111111,
              "Overwrite x2");

        // Both ports read the same register
        check(2, 2, 32'hDEADBEEF, 32'hDEADBEEF,
              "Simultaneous same-register read");

        // Change read addresses without clock
        check(0, 2, 0, 32'hDEADBEEF,
              "Combinational read");

        // Value must not change before rising edge
        @(negedge clk);
        rd_addr = 1;
        rd_data = 32'h12345678;
        rd_we = 1;

        check(1, 2, 32'h11111111, 32'hDEADBEEF,
              "Before rising edge");

        @(posedge clk);
        #1;
        rd_we = 0;

        check(1, 2, 32'h12345678, 32'hDEADBEEF,
              "After rising edge");

        // Write and read all remaining registers
        for (i = 3; i <= 30; i = i + 1) begin
            write_reg(i[4:0], (32'hA5000000 | i), 1);

            check(i[4:0], 5'd0,
                  (32'hA5000000 | i), 32'd0,
                  "Register write/read");
        end

        // Check that previous values remain unchanged
        check(1, 31, 32'h12345678, 32'hFEDCBA98,
              "Register values preserved");

        check(2, 1, 32'hDEADBEEF, 32'h12345678,
              "Independent reads");

        check(0, 30, 0, 32'hA500001E,
              "x0 remains zero");

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("REGISTER FILE TEST PASSED");
        else
            $display("REGISTER FILE TEST FAILED");

        $finish;
    end

endmodule