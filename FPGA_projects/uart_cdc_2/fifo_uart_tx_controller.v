`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:53:53 10/03/2026 
// Design Name: 
// Module Name:    fifo_uart_tx_controller 
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
module fifo_uart_tx_controller #(
	parameter DATA_WIDTH = 8
)(
	input wire clk,
	input wire rst,

	input wire fifo_empty,
	input wire [DATA_WIDTH-1:0] fifo_rd_data,
	output reg fifo_rd_en,

	input wire tx_busy,
	output reg [DATA_WIDTH-1:0] tx_data,
	output reg tx_start
);


localparam IDLE = 3'b000;
localparam READ_FIFO = 3'b001;
localparam LOAD_DATA = 3'b010;
localparam START_TX  = 3'b011;
localparam WAIT_BUSY = 3'b100;
localparam WAIT_DONE = 3'b101;
localparam WAIT_DATA = 3'b110;


reg [2:0] current_state, next_state;
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
			if(!fifo_empty && !tx_busy) begin
				next_state = READ_FIFO;
			end
		end
		READ_FIFO: begin
			next_state = WAIT_DATA;
		end
		WAIT_DATA: begin
			next_state = LOAD_DATA;
		end
		LOAD_DATA: begin
			next_state = START_TX;
		end

		START_TX: begin
			next_state = WAIT_BUSY;
		end
		WAIT_BUSY: begin
			if(tx_busy)
				next_state = WAIT_DONE;
		end
		WAIT_DONE: begin
			if(!tx_busy) begin
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
			fifo_rd_en <= 1'b0;
			tx_data <= {DATA_WIDTH{1'b0}};
			tx_start <= 1'b0;
	end
	else begin
		
		case(current_state)
			IDLE: begin
				fifo_rd_en <= 1'b0;
				tx_start <= 1'b0;
			end
			READ_FIFO: begin
				fifo_rd_en <= 1'b1;
			end
			WAIT_DATA: begin
				fifo_rd_en <= 1'b0;
			end
			LOAD_DATA: begin
				tx_data <= fifo_rd_data;
			end
			START_TX: begin
				tx_start <= 1'b1;
			end
			WAIT_BUSY: begin
				tx_start <= 1'b0;
			end
			WAIT_DONE: begin
				tx_start <= 1'b0;
			end
			default: begin
				fifo_rd_en <= 1'b0;
				tx_data <= {DATA_WIDTH{1'b0}};
				tx_start <= 1'b0;
				end
		endcase
	end
end
endmodule 