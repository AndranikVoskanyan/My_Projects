`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:15:46 10/21/2026 
// Design Name: 
// Module Name:    riscv_cpu 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////

`timescale 1ns / 1ps

// RV32I 5-stage CPU - Initial Integration
// Target: Spartan-6, Xilinx ISE
// Exception handling: temporary halt mechanism
// CSR/trap controller: not implemented yet

module riscv_cpu (
    input wire clk,
    input wire rst,

    output reg halted,
    output reg [31:0] trap_pc,
    output reg [3:0] trap_cause,

    output wire [31:0] debug_pc,
    output wire debug_wb_we,
    output wire [4:0] debug_wb_rd,
    output wire [31:0] debug_wb_data
);

    // ============================================
    // IF STAGE - FETCH
    // ============================================

    wire [31:0] fetch_pc;
    wire [31:0] imem_instruction;
    wire imem_valid;

    reg [31:0] fetched_pc;

    wire [31:0] id_pc;
    wire [31:0] id_instruction;
    wire id_valid;

    wire mem_stall;
    wire load_use_stall;

    wire ex_redirect;
    wire [31:0] ex_redirect_pc;
    wire trap_now;

    wire pipeline_stall = mem_stall || load_use_stall;
    wire fetch_stall = pipeline_stall || halted || trap_now;

    wire [31:0] seq_request_pc =
        (imem_valid && fetch_pc == fetched_pc) ?
        fetch_pc + 32'd4 : fetch_pc;

    wire [31:0] request_pc =
        ex_redirect ? ex_redirect_pc :
        fetch_stall ? fetched_pc : seq_request_pc;

    wire [31:0] next_fetch_pc = request_pc + 32'd4;

    assign debug_pc = fetch_pc;

    PC u_pc (
        .clk(clk),
        .rst(rst),
        .stall(fetch_stall && !ex_redirect),
        .next_pc(next_fetch_pc),
        .pc(fetch_pc)
    );

    instruction_memmory u_imem (
        .clk(clk),
        .rst(rst),
        .addr(request_pc),
        .instruction(imem_instruction),
        .valid(imem_valid)
    );

    always @(posedge clk) begin
        if (rst)
            fetched_pc <= 32'b0;
        else
            fetched_pc <= request_pc;
    end

    if_id_register u_if_id (
        .clk(clk),
        .rst(rst),
        .stall(pipeline_stall && !trap_now && !halted),
        .flush(ex_redirect || trap_now || halted),

        .if_pc(fetched_pc),
        .if_instruction(imem_instruction),
        .if_valid(imem_valid),

        .id_pc(id_pc),
        .id_instruction(id_instruction),
        .id_valid(id_valid)
    );

    // ============================================
    // ID STAGE - DECODE
    // ============================================

    wire [6:0] id_opcode;
    wire [6:0] id_funct7;

    wire [4:0] id_rs1_addr;
    wire [4:0] id_rs2_addr;
    wire [4:0] id_rd_addr;

    wire [2:0] id_funct3;

    instruction_decoder u_fields (
        .instruction(id_instruction),

        .opcode(id_opcode),
        .rd(id_rd_addr),
        .rs1(id_rs1_addr),
        .rs2(id_rs2_addr),
        .funct3(id_funct3),
        .funct7(id_funct7)
    );

    wire [3:0] id_alu_op;
    wire [3:0] id_mem_op;

    wire [2:0] id_imm_sel;
    wire [2:0] id_branch_op;

    wire [1:0] id_alu_src_a;
    wire [1:0] id_wb_sel;

    wire id_alu_src_b;
    wire id_reg_write;
    wire id_mem_en;
    wire id_branch_en;

    wire id_jump;
    wire id_jalr;

    wire id_illegal_instr;
    wire id_ecall;
    wire id_ebreak;

    control_unit u_control (
        .instruction(id_instruction),

        .alu_op(id_alu_op),
        .mem_op(id_mem_op),

        .imm_sel(id_imm_sel),
        .branch_op(id_branch_op),

        .alu_src_a(id_alu_src_a),
        .alu_src_b(id_alu_src_b),

        .reg_write(id_reg_write),
        .wb_sel(id_wb_sel),

        .mem_en(id_mem_en),
        .branch_en(id_branch_en),

        .jump(id_jump),
        .jalr(id_jalr),

        .illegal_instr(id_illegal_instr),
        .ecall(id_ecall),
        .ebreak(id_ebreak)
    );

    wire [31:0] id_immediate;

    immediate_generator u_immediate (
        .instruction(id_instruction),
        .imm_sel(id_imm_sel),
        .immidiate(id_immediate)
    );

    // ============================================
    // REGISTER FILE
    // ============================================

    wire [31:0] rf_rs1_data;
    wire [31:0] rf_rs2_data;

    wire [31:0] wb_write_data;
    wire [4:0] wb_rd_addr;
    wire wb_write_enable;

    register_file u_rf (
        .clk(clk),

        .rd_we(wb_write_enable),
        .rd_addr(wb_rd_addr),
        .rd_data(wb_write_data),

        .rs1_addr(id_rs1_addr),
        .rs2_addr(id_rs2_addr),

        .rs1_data(rf_rs1_data),
        .rs2_data(rf_rs2_data)
    );

    // WB to ID bypass

    wire [31:0] id_rs1_data =
        (wb_write_enable &&
         id_rs1_addr != 5'd0 &&
         id_rs1_addr == wb_rd_addr)
        ? wb_write_data : rf_rs1_data;

    wire [31:0] id_rs2_data =
        (wb_write_enable &&
         id_rs2_addr != 5'd0 &&
         id_rs2_addr == wb_rd_addr)
        ? wb_write_data : rf_rs2_data;

    // ============================================
    // LOAD-USE HAZARD DETECTION
    // ============================================

    wire ex_valid;

    wire [31:0] ex_pc;
    wire [31:0] ex_rs1_data;
    wire [31:0] ex_rs2_data;
    wire [31:0] ex_immediate;

    wire [4:0] ex_rs1_addr;
    wire [4:0] ex_rs2_addr;
    wire [4:0] ex_rd_addr;

    wire [3:0] ex_alu_op;
    wire [3:0] ex_mem_op;

    wire [1:0] ex_alu_src_a;
    wire [1:0] ex_wb_sel;

    wire ex_alu_src_b;
    wire ex_reg_write;
    wire ex_mem_en;
    wire ex_branch_en;

    wire [2:0] ex_branch_op;

    wire ex_jump;
    wire ex_jalr;

    wire ex_illegal_instr;
    wire ex_ecall;
    wire ex_ebreak;

    wire id_uses_rs1 =
        (id_opcode == 7'b0110011) ||
        (id_opcode == 7'b0010011) ||
        (id_opcode == 7'b0000011) ||
        (id_opcode == 7'b0100011) ||
        (id_opcode == 7'b1100011) ||
        (id_opcode == 7'b1100111);

    wire id_uses_rs2 =
        (id_opcode == 7'b0110011) ||
        (id_opcode == 7'b0100011) ||
        (id_opcode == 7'b1100011);

    wire ex_is_load =
        ex_mem_en && (ex_mem_op <= 4'd4);

    assign load_use_stall =
        ex_valid &&
        ex_is_load &&
        (ex_rd_addr != 5'd0) &&
        id_valid &&
        (
            (id_uses_rs1 && id_rs1_addr == ex_rd_addr) ||
            (id_uses_rs2 && id_rs2_addr == ex_rd_addr)
        );

    // ============================================
    // ID/EX PIPELINE REGISTER
    // ============================================

    id_ex_register u_id_ex (
        .clk(clk),
        .rst(rst),
        .stall(mem_stall),

        .flush(
            (load_use_stall && !mem_stall) ||
            ex_redirect || trap_now || halted
        ),

        .id_valid(id_valid),
        .id_pc(id_pc),

        .id_rs1_data(id_rs1_data),
        .id_rs2_data(id_rs2_data),
        .id_immediate(id_immediate),

        .id_rs1_addr(id_rs1_addr),
        .id_rs2_addr(id_rs2_addr),
        .id_rd_addr(id_rd_addr),

        .id_alu_op(id_alu_op),
        .id_alu_src_a(id_alu_src_a),
        .id_alu_src_b(id_alu_src_b),

        .id_reg_write(id_reg_write),
        .id_wb_sel(id_wb_sel),

        .id_mem_en(id_mem_en),
        .id_mem_op(id_mem_op),

        .id_branch_en(id_branch_en),
        .id_branch_op(id_branch_op),

        .id_jump(id_jump),
        .id_jalr(id_jalr),

        .id_illegal_instr(id_illegal_instr),
        .id_ecall(id_ecall),
        .id_ebreak(id_ebreak),

        .ex_valid(ex_valid),
        .ex_pc(ex_pc),

        .ex_rs1_data(ex_rs1_data),
        .ex_rs2_data(ex_rs2_data),
        .ex_immediate(ex_immediate),

        .ex_rs1_addr(ex_rs1_addr),
        .ex_rs2_addr(ex_rs2_addr),
        .ex_rd_addr(ex_rd_addr),

        .ex_alu_op(ex_alu_op),
        .ex_alu_src_a(ex_alu_src_a),
        .ex_alu_src_b(ex_alu_src_b),

        .ex_reg_write(ex_reg_write),
        .ex_wb_sel(ex_wb_sel),

        .ex_mem_en(ex_mem_en),
        .ex_mem_op(ex_mem_op),

        .ex_branch_en(ex_branch_en),
        .ex_branch_op(ex_branch_op),

        .ex_jump(ex_jump),
        .ex_jalr(ex_jalr),

        .ex_illegal_instr(ex_illegal_instr),
        .ex_ecall(ex_ecall),
        .ex_ebreak(ex_ebreak)
    );

    // ============================================
    // EX STAGE - FORWARDING
    // ============================================

    wire mem_valid;
    wire mem_reg_write;
    wire mem_mem_en;

    wire [31:0] mem_pc;
    wire [31:0] mem_pc_plus4;

    wire [31:0] mem_alu_result;
    wire [31:0] mem_store_data;

    wire [4:0] mem_rd_addr;

    wire [1:0] mem_wb_sel;
    wire [3:0] mem_mem_op;

    wire mem_illegal_instr;
    wire mem_ecall;
    wire mem_ebreak;

    wire [31:0] mem_forward_data =
        (mem_wb_sel == 2'b10) ?
        mem_pc_plus4 : mem_alu_result;

    wire forward_mem_rs1 =
        (ex_rs1_addr != 5'd0) &&
        mem_valid &&
        mem_reg_write &&
        (mem_rd_addr == ex_rs1_addr) &&
        (mem_wb_sel != 2'b01);

    wire forward_mem_rs2 =
        (ex_rs2_addr != 5'd0) &&
        mem_valid &&
        mem_reg_write &&
        (mem_rd_addr == ex_rs2_addr) &&
        (mem_wb_sel != 2'b01);

    wire forward_wb_rs1 =
        (ex_rs1_addr != 5'd0) &&
        wb_write_enable &&
        (wb_rd_addr == ex_rs1_addr);

    wire forward_wb_rs2 =
        (ex_rs2_addr != 5'd0) &&
        wb_write_enable &&
        (wb_rd_addr == ex_rs2_addr);

    wire [31:0] ex_rs1_forwarded =
        forward_mem_rs1 ? mem_forward_data :
        forward_wb_rs1 ? wb_write_data :
        ex_rs1_data;

    wire [31:0] ex_rs2_forwarded =
        forward_mem_rs2 ? mem_forward_data :
        forward_wb_rs2 ? wb_write_data :
        ex_rs2_data;

    // ============================================
    // ALU INPUT MULTIPLEXERS
    // ============================================

    wire [31:0] ex_alu_a =
        (ex_alu_src_a == 2'b01) ? ex_pc :
        (ex_alu_src_a == 2'b10) ? 32'b0 :
        ex_rs1_forwarded;

    wire [31:0] ex_alu_b =
        ex_alu_src_b ? ex_immediate :
        ex_rs2_forwarded;

    wire [31:0] ex_alu_result;

    alu u_alu (
        .operand_a(ex_alu_a),
        .operand_b(ex_alu_b),
        .alu_op(ex_alu_op),
        .result(ex_alu_result)
    );

    // ============================================
    // BRANCH / JUMP UNIT
    // ============================================

    wire ex_branch_taken;
    wire [31:0] ex_target_pc;

    branch_pc u_branch (
        .pc(ex_pc),

        .rs1_data(ex_rs1_forwarded),
        .rs2_data(ex_rs2_forwarded),

        .immediate(ex_immediate),
        .branch_op(ex_branch_op),

        .jump(ex_jump),
        .jalr(ex_jalr),
        .branch_en(ex_branch_en),

        .branch_taken(ex_branch_taken),
        .target_pc(ex_target_pc)
    );

    wire ex_bad_target =
        ex_valid &&
        ex_branch_taken &&
        (ex_target_pc[1:0] != 2'b00);

    wire ex_exception =
        ex_valid &&
        (
            ex_illegal_instr ||
            ex_ecall ||
            ex_ebreak ||
            ex_bad_target
        );

    wire mem_fault;

    assign trap_now =
        !halted &&
        (
            mem_fault ||
            (ex_exception && !mem_stall)
        );

    assign ex_redirect =
        ex_valid &&
        ex_branch_taken &&
        !ex_bad_target &&
        !ex_exception &&
        !mem_stall &&
        !mem_fault &&
        !halted &&
        !rst;

    assign ex_redirect_pc = ex_target_pc;

    // ============================================
    // EX/MEM PIPELINE REGISTER
    // ============================================

    ex_mem_register u_ex_mem (
        .clk(clk),
        .rst(rst),
        .stall(mem_stall),
        .flush(halted || mem_fault),

        .ex_valid(ex_valid),
        .ex_pc(ex_pc),

        .ex_pc_plus4(ex_pc + 32'd4),

        .ex_alu_result(ex_alu_result),
        .ex_store_data(ex_rs2_forwarded),

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

    // ============================================
    // MEM STAGE - LSU + DATA MEMORY
    // ============================================

    wire lsu_valid;
    wire lsu_error;

    wire [31:0] lsu_load_result;

    wire ram_req;
    wire ram_we;
    wire ram_rvalid;
    wire ram_error;

    wire [31:0] ram_addr;
    wire [31:0] ram_wr_data;
    wire [31:0] ram_read_data;

    wire [3:0] ram_byte_en;

    reg mem_issued;

    wire mem_is_operation =
        mem_valid && mem_mem_en;

    assign mem_stall =
        mem_is_operation && !lsu_valid;

    wire lsu_start =
        mem_is_operation &&
        !mem_issued &&
        !halted &&
        !rst;

    assign mem_fault =
        mem_is_operation &&
        lsu_valid &&
        lsu_error;

    // Issue exactly one request per memory instruction

    always @(posedge clk) begin
        if (rst || halted)
            mem_issued <= 1'b0;
        else if (lsu_start)
            mem_issued <= 1'b1;
        else if (!mem_stall)
            mem_issued <= 1'b0;
    end

    lsu_store u_lsu (
        .clk(clk),
        .rst(rst),

        .mem_valid(lsu_start),
        .mem_op(mem_mem_op),

        .effective_addr(mem_alu_result),
        .rs2_data(mem_store_data),

        .ram_read_data(ram_read_data),
        .ram_rvalid(ram_rvalid),
        .ram_error(ram_error),

        .ram_req(ram_req),
        .ram_we(ram_we),

        .ram_addr(ram_addr),
        .ram_wr_data(ram_wr_data),
        .ram_byte_en(ram_byte_en),

        .load_result(lsu_load_result),
        .lsu_valid(lsu_valid),
        .lsu_error(lsu_error)
    );

    data_memory u_dmem (
        .clk(clk),
        .rst(rst),

        .req(ram_req),
        .we(ram_we),

        .addr(ram_addr),
        .wr_data(ram_wr_data),
        .byte_en(ram_byte_en),

        .read_data(ram_read_data),
        .rvalid(ram_rvalid),
        .error(ram_error)
    );

    // ============================================
    // MEM/WB PIPELINE REGISTER
    // ============================================

    wire wb_valid;
    wire wb_reg_write;

    wire wb_illegal_instr;
    wire wb_ecall;
    wire wb_ebreak;
    wire wb_access_fault;

    wire [31:0] wb_pc;
    wire [31:0] wb_pc_plus4;

    wire [31:0] wb_alu_result;
    wire [31:0] wb_load_result;

    wire [1:0] wb_wb_sel;

    mem_wb_register u_mem_wb (
        .clk(clk),
        .rst(rst),

        .stall(mem_stall),
        .flush(1'b0),

        .mem_valid(mem_valid),
        .mem_pc(mem_pc),

        .mem_pc_plus4(mem_pc_plus4),
        .mem_alu_result(mem_alu_result),
        .mem_load_result(lsu_load_result),

        .mem_rd_addr(mem_rd_addr),

        .mem_reg_write(mem_reg_write),
        .mem_wb_sel(mem_wb_sel),

        .mem_illegal_instr(mem_illegal_instr),
        .mem_ecall(mem_ecall),
        .mem_ebreak(mem_ebreak),
        .mem_access_fault(mem_fault),

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

    // ============================================
    // WRITEBACK STAGE
    // ============================================

    assign wb_write_data =
        (wb_wb_sel == 2'b01) ? wb_load_result :
        (wb_wb_sel == 2'b10) ? wb_pc_plus4 :
        wb_alu_result;

    assign wb_write_enable =
        wb_valid &&
        wb_reg_write &&
        (wb_rd_addr != 5'd0) &&
        !mem_stall &&
        !rst;

    assign debug_wb_we = wb_write_enable;
    assign debug_wb_rd = wb_rd_addr;
    assign debug_wb_data = wb_write_data;

    // ============================================
    // TEMPORARY EXCEPTION HANDLING
    // ============================================

    wire mem_is_store =
        (mem_mem_op >= 4'd5);

    wire mem_misaligned =
        (
            (
                (mem_mem_op == 4'd1) ||
                (mem_mem_op == 4'd4) ||
                (mem_mem_op == 4'd6)
            ) &&
            mem_alu_result[0]
        ) ||
        (
            (
                (mem_mem_op == 4'd2) ||
                (mem_mem_op == 4'd7)
            ) &&
            (mem_alu_result[1:0] != 2'b00)
        );

    always @(posedge clk) begin

        if (rst) begin
            halted <= 1'b0;
            trap_pc <= 32'b0;
            trap_cause <= 4'b0;
        end

        else if (!halted && trap_now) begin
            halted <= 1'b1;

            if (mem_fault) begin
                trap_pc <= mem_pc;

                trap_cause <=
                    mem_is_store ?
                    (mem_misaligned ? 4'd6 : 4'd7) :
                    (mem_misaligned ? 4'd4 : 4'd5);
            end

            else begin
                trap_pc <= ex_pc;

                trap_cause <=
                    ex_bad_target ? 4'd0 :
                    ex_illegal_instr ? 4'd2 :
                    ex_ebreak ? 4'd3 : 4'd11;
            end
        end
    end

endmodule