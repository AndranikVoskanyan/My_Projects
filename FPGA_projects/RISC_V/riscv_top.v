`timescale 1ns / 1ps

// Board top: Spartan-6 XC6SLX9, Xilinx ISE (Verilog-2001).
// Buttons are active LOW; LEDs are active LOW.
module riscv_top #(
    parameter integer CLK_FREQ_HZ = 50_000_000
)(
    input  wire       clk,
    input  wire       btn_start_n,
    input  wire       btn_reset_n,
    output wire       led_running_n,
    output wire       led_done_n,
    output wire       led_error_n,
    output wire [4:0] led_unused_n
);

    reg [3:0] por_count = 4'b0000;
    always @(posedge clk) begin
        if (!por_count[3])
            por_count <= por_count + 4'd1;
    end
    wire por_reset = !por_count[3];

    
    wire start_pressed = !btn_start_n;
    wire reset_pressed = !btn_reset_n;

    wire reset_synced;
    wire reset_debounced;
    wire reset_pulse;
    wire reset_falling_unused;

    button_sync u_reset_sync (
        .clk(clk),
        .reset_n(por_reset),
        .button_async(reset_pressed),
        .button_sync(reset_synced)
    );

    debounce #(
        .COUNT_MAX(CLK_FREQ_HZ / 100), // 10 milliseconds
        .COUNTER_BITS(21)
    ) u_reset_debounce (
        .clk(clk),
        .reset_n(por_reset),
        .button_sync(reset_synced),
        .debounced_button(reset_debounced)
    );

    edge_detector u_reset_edge (
        .clk(clk),
        .reset_n(por_reset),
        .debounced_button(reset_debounced),
        .rising_edge(reset_pulse),
        .falling_edge(reset_falling_unused)
    );

  
    wire reset_active = por_reset || reset_pressed || reset_debounced;

    // ---- START button: same three modules ----
    wire start_synced;
    wire start_debounced;
    wire start_pulse;
    wire start_falling_unused;

    button_sync u_start_sync (
        .clk(clk),
        .reset_n(reset_active),
        .button_async(start_pressed),
        .button_sync(start_synced)
    );

    debounce #(
        .COUNT_MAX(CLK_FREQ_HZ / 100), // 10 milliseconds
        .COUNTER_BITS(21)
    ) u_start_debounce (
        .clk(clk),
        .reset_n(reset_active),
        .button_sync(start_synced),
        .debounced_button(start_debounced)
    );

    edge_detector u_start_edge (
        .clk(clk),
        .reset_n(reset_active),
        .debounced_button(start_debounced),
        .rising_edge(start_pulse),
        .falling_edge(start_falling_unused)
    );

    // START pulse latches CPU run permission. RESET clears it.
    reg started = 1'b0;
    always @(posedge clk) begin
        if (reset_active || reset_pulse)
            started <= 1'b0;
        else if (start_pulse)
            started <= 1'b1;
    end

    // Processor remains reset until START has been pressed.
    wire cpu_rst = reset_active || !started;
    wire cpu_halted;
    wire [3:0] cpu_trap_cause;

    riscv_cpu u_cpu (
        .clk(clk),
        .rst(cpu_rst),
        .halted(cpu_halted),
        .trap_pc(),
        .trap_cause(cpu_trap_cause),
        .debug_pc(),
        .debug_wb_we(),
        .debug_wb_rd(),
        .debug_wb_data()
    );

    // Demo program: ECALL (cause 11) = success; other halts = error.
    wire running = started && !reset_active && !cpu_halted;
    wire done    = started && !reset_active && cpu_halted &&
                   (cpu_trap_cause == 4'd11);
    wire error   = started && !reset_active && cpu_halted &&
                   (cpu_trap_cause != 4'd11);

    // Physical LEDs are active-low: drive 0 to light.
    assign led_running_n = !running; // LED1
    assign led_done_n    = !done;    // LED2
    assign led_error_n   = !error;   // LED3

    // LED4/LED5 indicate the conditioned button press (10 ms debounce).
    assign led_unused_n[0] = !start_debounced; // LED4: START held
    assign led_unused_n[1] = !reset_debounced; // LED5: RESET held
    assign led_unused_n[4:2] = 3'b111;         // LED6-8: always OFF

endmodule