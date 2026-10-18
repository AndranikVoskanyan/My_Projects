`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:46:26 10/02/2026 
// Design Name: 
// Module Name:    uart_tx 
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
module uart_tx#(
	 parameter CLK_FREQ  = 50_000_000,
    parameter BAUD_RATE = 115_200,
	 parameter DATA_BITS_AMOUNT = 8
)(
	input wire clk,rst,tx_start,
	input wire [DATA_BITS_AMOUNT - 1:0] tx_data,
	output reg tx_uart, tx_busy
    );

 localparam CLKS_PER_BIT = CLK_FREQ / BAUD_RATE;
 localparam COUNTER_WIDTH = clog2(DATA_BITS_AMOUNT);
 localparam UART_CLK_BIT_COUNTER_WIDTH = clog2(CLKS_PER_BIT);
 localparam IDLE = 2'b00;
 localparam START_BIT = 2'b01;
 localparam DATA_BITS = 2'b10;
 localparam STOP_BIT = 2'b11;

 reg [UART_CLK_BIT_COUNTER_WIDTH - 1:0] clk_counter; 
 reg [COUNTER_WIDTH-1:0] bit_counter;

 reg [DATA_BITS_AMOUNT - 1:0] tx_data_buf;
 reg [1:0] current_state,next_state;
 
 always @(posedge clk) begin
	if(rst) begin
		current_state <= IDLE;
	end
	else begin
		current_state <= next_state;
	end
 end
 
 always @(*) begin
	next_state = current_state;
	case(current_state)
		IDLE: begin
			if(tx_start) begin
				next_state = START_BIT;
			end 
		end
		START_BIT:begin
			if(clk_counter == CLKS_PER_BIT-1) begin
				next_state = DATA_BITS;
			end
		end
		DATA_BITS:begin
			if(clk_counter == CLKS_PER_BIT-1) begin
				if(bit_counter == DATA_BITS_AMOUNT - 1 ) begin
					next_state = STOP_BIT;
				end
			end
		end
		STOP_BIT:begin
			if(clk_counter == CLKS_PER_BIT-1) begin
				next_state = IDLE;
			end
		end
		default: begin
			 next_state = IDLE;
		end
	endcase
 end
 
 always @(posedge clk) begin
	if(rst) begin
		clk_counter <= 0;
		bit_counter <= 0;
		tx_data_buf <= 0;
		tx_uart <= 1'b1; 
		tx_busy <= 1'b0;
	end
	else begin
		case(current_state)
			IDLE: begin
				tx_uart <= 1'b1;
				tx_busy <= 1'b0;
				bit_counter <= 0;
				clk_counter <= 0;
				if(tx_start) begin
					tx_data_buf <= tx_data;
				end
			end
			START_BIT: begin
				tx_uart <= 1'b0;
				tx_busy <= 1'b1;
				if(clk_counter == CLKS_PER_BIT-1) begin
					clk_counter <= 0;
				end
				else begin
					clk_counter <= clk_counter + 1'b1;
				end
			end
			DATA_BITS: begin
				tx_uart <= tx_data_buf[bit_counter];
				tx_busy <= 1'b1;
				if(clk_counter == CLKS_PER_BIT-1) begin
					clk_counter <= 0;
					if(bit_counter == DATA_BITS_AMOUNT - 1 ) begin
						bit_counter<=0;
					end
					else begin
						bit_counter <= bit_counter + 1'b1;
					end
				end
				else begin
					clk_counter <= clk_counter + 1'b1;
				end
			end
			STOP_BIT: begin
				tx_uart <= 1'b1;
				tx_busy <= 1'b1;
				if(clk_counter == CLKS_PER_BIT-1) begin
					clk_counter <= 0;
				end
				else begin
					clk_counter <= clk_counter + 1'b1;
				end
			end

			default: begin
				 clk_counter <= 0;
				 bit_counter <= 0;
				 tx_uart <= 1'b1;
				 tx_busy <= 1'b0;
			end	
		endcase
	end
 end
 
 function integer clog2;
    input integer value;
    integer i;
	 if  (value == 1) begin
		clog2 =	1;
	 end
		 else begin
		 begin
			  value = value - 1;

			  for (i = 0; value > 0; i = i + 1)
					value = value >> 1;

			  clog2 = i;
		 end
	 end
endfunction
 
endmodule



