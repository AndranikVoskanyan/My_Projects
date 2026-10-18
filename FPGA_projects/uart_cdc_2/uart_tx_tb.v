`timescale 1ns/1ps

module tb_uart_tx;

reg clk=0,rst=1,tx_start=0;
reg [7:0] tx_data=0;
wire tx_uart,tx_busy;

always #5 clk=~clk;

uart_tx #(
	.CLK_FREQ(100),
	.BAUD_RATE(10),
	.DATA_BITS_AMOUNT(8)
) dut(
	.clk(clk),
	.rst(rst),
	.tx_start(tx_start),
	.tx_data(tx_data),
	.tx_uart(tx_uart),
	.tx_busy(tx_busy)
);

initial begin
	#20;
	rst=0;
	#20;
	tx_data=8'hA6;
	tx_start=1;
	#10;
	tx_start=0;
	wait(tx_busy==0);
	#20;
	$stop;
end

endmodule 