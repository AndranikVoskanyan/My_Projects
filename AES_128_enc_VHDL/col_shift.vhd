----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 24.11.2024 17:10:51
-- Design Name: 
-- Module Name: col_shift - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_arith.ALL;
USE IEEE.std_logic_unsigned.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity col_row_shift is 
    Port (
        clk       : in std_logic                     ;
        rst       : in std_logic                     ;
        start     : in std_logic                     ;
        data_in   : in std_logic_vector (127 downto 0);
        data_out  : out std_logic_vector (127 downto 0);
        done      : out std_logic                    ;
        ready     : out std_logic         
     );
end col_row_shift;

architecture Behavioral of col_row_shift is
type MyArrayType is array (0 to 3 , 0 to 3) of std_logic_vector(7 downto 0);
signal data_in_mat  : MyArrayType := (others =>(others =>(others => '0')));
begin
    rst_process:process(rst)
        begin
        end process;
     process(clk,rst)
     begin
       if rst = '1' then
            data_in_mat <= (others =>(others =>(others =>'0')));
            ready <= '1';
       elsif  (rst = '0' and rising_edge(clk)) then
        for i in 0 to 3 loop
            for j in 0 to 3 loop
              data_in_mat(j,i) <= data_in(127-(i*32 + j*8) downto 127-(i*32 + j*8)-7);
            end loop;
        end loop;
            if start = '1' then
                    done <= '1';
                    ready <= '0';
                  data_out <= data_in_mat(0, 0) & data_in_mat(1, 1) & data_in_mat(2, 2) & data_in_mat(3, 3) &
                              data_in_mat(0, 1) & data_in_mat(1, 2) & data_in_mat(2, 3) & data_in_mat(3, 0) &
                              data_in_mat(0, 2) & data_in_mat(1, 3) & data_in_mat(2, 0) & data_in_mat(3, 1) &
                              data_in_mat(0, 3) & data_in_mat(1, 0) & data_in_mat(2, 1) & data_in_mat(3, 2) ;
            elsif rst = '0' and start = '0' then
                done <= '0';
                ready <= '1';
            end if;
        end if;
        
       end process;
end Behavioral;
