
`timescale 1ns / 1ps

module immediate_generator_tb;

    reg  [31:0] instruction;
    reg  [2:0]  imm_sel;
    wire [31:0] immidiate;

    integer tests, errors;

    immediate_generator dut (
        .instruction(instruction),
        .imm_sel(imm_sel),
        .immidiate(immidiate)
    );

    // Build RV32I instruction encodings

    function [31:0] make_i;
        input [11:0] imm;
        begin
            make_i = {imm, 5'd1, 3'b000, 5'd2, 7'b0010011};
        end
    endfunction

    function [31:0] make_s;
        input [11:0] imm;
        begin
            make_s = {imm[11:5], 5'd2, 5'd1, 3'b010,
                      imm[4:0], 7'b0100011};
        end
    endfunction

    function [31:0] make_b;
        input [12:0] imm;
        begin
            make_b = {imm[12], imm[10:5], 5'd2, 5'd1, 3'b000,
                      imm[4:1], imm[11], 7'b1100011};
        end
    endfunction

    function [31:0] make_u;
        input [19:0] upper;
        begin
            make_u = {upper, 5'd2, 7'b0110111};
        end
    endfunction

    function [31:0] make_j;
        input [20:0] imm;
        begin
            make_j = {imm[20], imm[10:1], imm[11], imm[19:12],
                      5'd2, 7'b1101111};
        end
    endfunction

    task check;
        input [2:0] sel;
        input [31:0] instr, expected;
        input [8*32-1:0] name;
        begin
            imm_sel = sel;
            instruction = instr;
            #10;
            tests = tests + 1;

            if (immidiate !== expected) begin
                errors = errors + 1;
                $display("FAIL %s: expected=%h got=%h",
                         name, expected, immidiate);
            end
            else
                $display("PASS %s", name);
        end
    endtask

    initial begin
        instruction = 0;
        imm_sel = 0;
        tests = 0;
        errors = 0;

        // I-type
        check(3'd0, make_i(12'h000), 32'h00000000, "I zero");
        check(3'd0, make_i(12'h001), 32'h00000001, "I plus one");
        check(3'd0, make_i(12'h7ff), 32'h000007ff, "I positive max");
        check(3'd0, make_i(12'hfff), 32'hffffffff, "I minus one");
        check(3'd0, make_i(12'h800), 32'hfffff800, "I negative min");
        check(3'd0, make_i(12'h07b), 32'h0000007b, "I plus 123");
        check(3'd0, make_i(12'hf85), 32'hffffff85, "I minus 123");

        // S-type
        check(3'd1, make_s(12'h000), 32'h00000000, "S zero");
        check(3'd1, make_s(12'h001), 32'h00000001, "S plus one");
        check(3'd1, make_s(12'h7ff), 32'h000007ff, "S positive max");
        check(3'd1, make_s(12'hfff), 32'hffffffff, "S minus one");
        check(3'd1, make_s(12'h800), 32'hfffff800, "S negative min");
        check(3'd1, make_s(12'h07f), 32'h0000007f, "S plus 127");
        check(3'd1, make_s(12'hf80), 32'hffffff80, "S minus 128");

        // B-type
        check(3'd2, make_b(13'h0000), 32'h00000000, "B zero");
        check(3'd2, make_b(13'h0002), 32'h00000002, "B plus two");
        check(3'd2, make_b(13'h0004), 32'h00000004, "B plus four");
        check(3'd2, make_b(13'h0800), 32'h00000800, "B offset bit 11");
        check(3'd2, make_b(13'h0ffe), 32'h00000ffe, "B positive max");
        check(3'd2, make_b(13'h1ffe), 32'hfffffffe, "B minus two");
        check(3'd2, make_b(13'h1000), 32'hfffff000, "B negative min");
        check(3'd2, make_b(13'h1800), 32'hfffff800, "B minus 2048");

        // U-type
        check(3'd3, make_u(20'h00000), 32'h00000000, "U zero");
        check(3'd3, make_u(20'h00001), 32'h00001000, "U low bit");
        check(3'd3, make_u(20'h12345), 32'h12345000, "U placement");
        check(3'd3, make_u(20'h80000), 32'h80000000, "U high bit");
        check(3'd3, make_u(20'hfffff), 32'hfffff000, "U all ones");

        // J-type
        check(3'd4, make_j(21'h000000), 32'h00000000, "J zero");
        check(3'd4, make_j(21'h000002), 32'h00000002, "J plus two");
        check(3'd4, make_j(21'h000004), 32'h00000004, "J plus four");
        check(3'd4, make_j(21'h000800), 32'h00000800, "J bit 11");
        check(3'd4, make_j(21'h001000), 32'h00001000, "J bit 12");
        check(3'd4, make_j(21'h0ffffe), 32'h000ffffe, "J positive max");
        check(3'd4, make_j(21'h1ffffe), 32'hfffffffe, "J minus two");
        check(3'd4, make_j(21'h100000), 32'hfff00000, "J negative min");
        check(3'd4, make_j(21'h1ff800), 32'hfffff800, "J minus 2048");

        // Invalid selectors
        check(3'd5, 32'hffffffff, 32'h00000000, "Invalid sel 5");
        check(3'd6, 32'hffffffff, 32'h00000000, "Invalid sel 6");
        check(3'd7, 32'hffffffff, 32'h00000000, "Invalid sel 7");

        $display("--------------------------------------");
        $display("Tests: %0d Passed: %0d Failed: %0d",
                 tests, tests-errors, errors);
        $display("--------------------------------------");

        if (errors == 0)
            $display("IMMEDIATE GENERATOR TEST PASSED");
        else
            $display("IMMEDIATE GENERATOR TEST FAILED");

        $finish;
    end

endmodule