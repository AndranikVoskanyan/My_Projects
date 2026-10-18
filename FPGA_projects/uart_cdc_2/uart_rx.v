`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:32:28 10/02/2026 
// Design Name: 
// Module Name:    uart_rx 
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
module uart_rx#(
	 parameter CLK_FREQ  = 50_000_000,
    parameter BAUD_RATE = 115_200,
	 parameter DATA_BITS_AMOUNT = 8
)(
	input wire clk,rst,rx_uart,
	output reg [DATA_BITS_AMOUNT - 1:0] rx_data, 
	output reg rx_valid
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

 reg [DATA_BITS_AMOUNT - 1:0] rx_data_buf;
 reg [1:0] current_state,next_state;
 
 
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
			if(!rx_uart) 
				next_state = START_BIT;
			end
		START_BIT: begin
			if((clk_counter == (CLKS_PER_BIT >> 1)- 1'b1)) begin
				if(rx_uart == 1'b0) begin
					next_state = DATA_BITS;
				end
				else begin
					next_state = IDLE;
				end
			end
		end
		DATA_BITS: begin
			if(clk_counter == CLKS_PER_BIT-1'b1) begin
				if(bit_counter == DATA_BITS_AMOUNT -1'b1 ) begin
					next_state = STOP_BIT;
				end
			end
		end
		STOP_BIT: begin
			if(clk_counter == CLKS_PER_BIT-1'b1) begin
				next_state = IDLE;
			end
		end
		default: next_state = IDLE;
	endcase;
end

always @(posedge clk) begin
	if(rst) begin
		bit_counter <= 0;
		clk_counter <= 0;
		rx_data_buf <= 0;
		rx_valid <= 0;
		rx_data <= 0;
	end
	else begin
		case(current_state) 
			IDLE: begin
				bit_counter <= 0;
				clk_counter <= 0;
				rx_data_buf <= 0;
				rx_valid <= 0;
			end
			START_BIT: begin
				if(clk_counter == (CLKS_PER_BIT>>1'b1)-1'b1) begin
					clk_counter <= 0;
				end
				else begin
					clk_counter <= clk_counter + 1'b1;
				end 
			end
			DATA_BITS: begin
				
				if(clk_counter == CLKS_PER_BIT-1'b1) begin
					clk_counter <= 0;
					rx_data_buf[bit_counter] <= rx_uart;
					if(bit_counter == DATA_BITS_AMOUNT - 1'b1) begin
						bit_counter <= 0;
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
				if(clk_counter == CLKS_PER_BIT-1'b1) begin
					clk_counter <= 0;
					if(rx_uart) begin
						rx_valid <= 1;
						rx_data <= rx_data_buf;
					end
					else begin
						rx_data <= 0;
						rx_data_buf <= 0;
					end
				end
				else begin
					clk_counter <= clk_counter + 1'b1;
				end 
			end
			default: begin
				bit_counter <= 0;
				clk_counter <= 0;
				rx_data_buf <= 0;
				rx_valid <= 0;
				rx_data <= 0;
			end
		endcase
	end
end

endmodule
