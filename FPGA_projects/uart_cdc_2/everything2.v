`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:16:50 10/03/2026 
// Design Name: 
// Module Name:    everything2 
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
module everything2 #(
	parameter DATA_WIDTH = 8,
	parameter ADDR_WIDTH = 4,
	parameter BAUD_RATE  = 115200
)(
	input  wire clk,
	input  wire reset_in,
	input  wire write_button,
	input  wire check_button,
	input  wire uart_line_rx,
	output wire uart_line_tx,
	output wire [7:0] led
);
localparam DEBOUNCE_COUNT        = 500_000;
localparam DEBOUNCE_COUNTER_BITS = 19;
localparam CHECK_IDLE = 2'b00;
localparam CHECK_READ = 2'b01;
localparam CHECK_WAIT = 2'b10;
localparam CHECK_DATA = 2'b11;
wire rst;
wire CLK_OUT_25;
wire CLK_OUT_10;
wire clk_locked;
wire internal_rst;
wire reset_n_sync;

wire button_fliped;
wire button_synced;
wire button_debounced;
wire rising_edge;
wire falling_edge;

wire ch_button_fliped;
wire ch_button_synced;
wire ch_button_debounced;
wire ch_rising_edge;
wire ch_falling_edge;

reg [2:0] pattern_index;
wire [DATA_WIDTH-1:0] pattern_data;
wire tx_wr_en;
wire [DATA_WIDTH-1:0] tx_wr_data;

wire tx_fifo_full;
wire tx_fifo_empty;
wire [DATA_WIDTH-1:0] tx_fifo_rd_data;
wire tx_fifo_rd_en;

wire [DATA_WIDTH-1:0] uart_tx_data;
wire uart_tx_start;
wire tx_busy;

reg uart_rx_ff1;
reg uart_rx_ff2;

wire [DATA_WIDTH-1:0] uart_rx_data;
wire rx_valid;

wire rx_fifo_full;
wire rx_fifo_empty;
wire [DATA_WIDTH-1:0] rx_fifo_rd_data;
reg rx_fifo_rd_en;

reg [1:0] check_state;
reg [1:0] check_next_state;
reg [2:0] check_index;

reg pass_flag;
reg checker_error;

reg rx_overflow_uart;
reg rx_overflow_ff1;
reg rx_overflow_ff2;

wire final_error;

function [DATA_WIDTH-1:0] pattern_value;
	input [2:0] index;
	begin
		case(index)
			3'd0: pattern_value = 8'h11;
			3'd1: pattern_value = 8'h22;
			3'd2: pattern_value = 8'h33;
			3'd3: pattern_value = 8'h44;
			3'd4: pattern_value = 8'h55;
			3'd5: pattern_value = 8'hAA;
			3'd6: pattern_value = 8'hA5;
			3'd7: pattern_value = 8'h5A;
			default: pattern_value = 8'h00;
		endcase
	end
endfunction 

assign rst = ~reset_in;
assign internal_rst = rst | ~clk_locked;
assign reset_n_sync = internal_rst;

assign button_fliped = ~write_button;
assign ch_button_fliped = ~check_button;
assign pattern_data = pattern_value(pattern_index);

assign tx_wr_en   = rising_edge && !tx_fifo_full;
assign tx_wr_data = pattern_data;

assign final_error = checker_error | rx_overflow_ff2;

clk_div clk_dev_uart (
	.CLK_IN1  (clk),
	.CLK_OUT1 (CLK_OUT_25),
	.CLK_OUT2 (CLK_OUT_10),
	.RESET    (rst),
	.LOCKED   (clk_locked)
);

button_sync u_button_sync (
	.clk          (CLK_OUT_25),
	.reset_n      (reset_n_sync),
	.button_async (button_fliped),
	.button_sync  (button_synced)
);
debounce #(
	.COUNT_MAX    (DEBOUNCE_COUNT),
	.COUNTER_BITS (DEBOUNCE_COUNTER_BITS)
) u_debounce (
	.clk              (CLK_OUT_25),
	.reset_n          (reset_n_sync),
	.button_sync      (button_synced),
	.debounced_button (button_debounced)
);

edge_detector u_edge_detector (
	.clk              (CLK_OUT_25),
	.reset_n          (reset_n_sync),
	.debounced_button (button_debounced),
	.rising_edge      (rising_edge),
	.falling_edge     (falling_edge)
);
button_sync ch_button_sync (
	.clk          (CLK_OUT_25),
	.reset_n      (reset_n_sync),
	.button_async (ch_button_fliped),
	.button_sync  (ch_button_synced)
);


debounce #(
	.COUNT_MAX    (DEBOUNCE_COUNT),
	.COUNTER_BITS (DEBOUNCE_COUNTER_BITS)
) ch_debounce (
	.clk              (CLK_OUT_25),
	.reset_n          (reset_n_sync),
	.button_sync      (ch_button_synced),
	.debounced_button (ch_button_debounced)
);

edge_detector ch_edge_detector (
	.clk              (CLK_OUT_25),
	.reset_n          (reset_n_sync),
	.debounced_button (ch_button_debounced),
	.rising_edge      (ch_rising_edge),
	.falling_edge     (ch_falling_edge)
);

always @(posedge CLK_OUT_25) begin
	if(internal_rst) begin
		pattern_index <= 0;
	end
	else begin
		if(tx_wr_en)
			pattern_index <= pattern_index + 1'b1;
	end
end
async_fifo #(
	.DATA_WIDTH(DATA_WIDTH),
	.ADDR_WIDTH(ADDR_WIDTH)) TX_FIFO (
	.wr_clk  (CLK_OUT_25),
	.rd_clk  (CLK_OUT_10),
	.rst     (internal_rst),

	.wr_en   (tx_wr_en),
	.wr_data (tx_wr_data),
	.full    (tx_fifo_full),

	.rd_en   (tx_fifo_rd_en),
	.rd_data (tx_fifo_rd_data),
	.empty   (tx_fifo_empty)
);

fifo_uart_tx_controller #(
	.DATA_WIDTH(DATA_WIDTH)
) TX_CTRL (
	.clk          (CLK_OUT_10),
	.rst          (internal_rst),

	.fifo_empty   (tx_fifo_empty),
	.fifo_rd_data (tx_fifo_rd_data),
	.fifo_rd_en   (tx_fifo_rd_en),

	.tx_busy      (tx_busy),
	.tx_data      (uart_tx_data),
	.tx_start     (uart_tx_start)
);
uart_tx #(
	.CLK_FREQ         (10_000_000),
	.BAUD_RATE        (BAUD_RATE),
	.DATA_BITS_AMOUNT (DATA_WIDTH)
) UART_TX (
	.clk      (CLK_OUT_10),
	.rst      (internal_rst),

	.tx_start (uart_tx_start),
	.tx_data  (uart_tx_data),

	.tx_uart  (uart_line_tx),
	.tx_busy  (tx_busy)
);
always @(posedge CLK_OUT_10) begin
	if(internal_rst) begin
		uart_rx_ff1 <= 1'b1;
		uart_rx_ff2 <= 1'b1;
	end
	else begin
		uart_rx_ff1 <= uart_line_rx;
		uart_rx_ff2 <= uart_rx_ff1;
	end
end


uart_rx #(
	.CLK_FREQ         (10_000_000),
	.BAUD_RATE        (BAUD_RATE),
	.DATA_BITS_AMOUNT (DATA_WIDTH)
) UART_RX (
	.clk      (CLK_OUT_10),
	.rst      (internal_rst),

	.rx_uart  (uart_rx_ff2),

	.rx_data  (uart_rx_data),
	.rx_valid (rx_valid)
);
async_fifo #(
	.DATA_WIDTH(DATA_WIDTH),
	.ADDR_WIDTH(ADDR_WIDTH)
) RX_FIFO (
	.wr_clk  (CLK_OUT_10),
	.rd_clk  (CLK_OUT_25),
	.rst     (internal_rst),

	.wr_en   (rx_valid),
	.wr_data (uart_rx_data),
	.full    (rx_fifo_full),

	.rd_en   (rx_fifo_rd_en),
	.rd_data (rx_fifo_rd_data),
	.empty   (rx_fifo_empty)
);
always @(posedge CLK_OUT_10) begin
	if(internal_rst) begin
		rx_overflow_uart <= 1'b0;
	end
	else begin
		if(rx_valid && rx_fifo_full)
			rx_overflow_uart <= 1'b1;
	end
end

always @(posedge CLK_OUT_25) begin
	if(internal_rst) begin
		rx_overflow_ff1 <= 1'b0;
		rx_overflow_ff2 <= 1'b0;
	end
	else begin
		rx_overflow_ff1 <= rx_overflow_uart;
		rx_overflow_ff2 <= rx_overflow_ff1;
	end
end

always @(posedge CLK_OUT_25) begin
	if(internal_rst)
		check_state <= CHECK_IDLE;
	else
		check_state <= check_next_state;
end
always @(*) begin
	check_next_state = check_state;

	case(check_state)

		CHECK_IDLE: begin
			if(!rx_fifo_empty && ch_rising_edge)
				check_next_state = CHECK_READ;
		end

		CHECK_READ: begin
			check_next_state = CHECK_WAIT;
		end

		CHECK_WAIT: begin
			check_next_state = CHECK_DATA;
		end
				CHECK_DATA: begin
			check_next_state = CHECK_IDLE;
		end

		default: begin
			check_next_state = CHECK_IDLE;
		end

	endcase
end 
always @(posedge CLK_OUT_25) begin
	if(internal_rst) begin
		rx_fifo_rd_en <= 1'b0;
		check_index   <= 0;
		pass_flag     <= 1'b0;
		checker_error <= 1'b0;
	end
	else begin

		case(check_state)

			CHECK_IDLE: begin
				rx_fifo_rd_en <= 1'b0;
			end

			CHECK_READ: begin
				rx_fifo_rd_en <= 1'b1;
			end

			CHECK_WAIT: begin
				rx_fifo_rd_en <= 1'b0;
			end
			CHECK_DATA: begin 
					if(rx_fifo_rd_data == pattern_value(check_index)) begin
					if(!checker_error)
						pass_flag <= 1'b1;
				end
				else begin
					pass_flag <= 1'b0;
					checker_error <= 1'b1;
				end

				check_index <= check_index + 1'b1;

			end

			default: begin
				rx_fifo_rd_en <= 1'b0;
			end

		endcase
	end
end
assign led[0] = ~(pass_flag && !final_error);
assign led[1] = ~final_error;
assign led[2] = ~tx_fifo_full;
assign led[3] = ~tx_fifo_empty;
assign led[4] = ~tx_busy;
assign led[5] = ~rx_fifo_full;
assign led[6] = ~rx_fifo_empty;
assign led[7] = ~clk_locked;


endmodule 