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
        my_state  : in std_logic                     ;
        index     : in integer range  0 to 3         ;
        start     : in std_logic                     ;
        en_de     : in std_logic                     ;
        arr_0_in  : in std_logic_vector  (7 downto 0);
        arr_1_in  : in std_logic_vector  (7 downto 0);
        arr_2_in  : in std_logic_vector  (7 downto 0);
        arr_3_in  : in std_logic_vector  (7 downto 0);
        arr_0_out : out std_logic_vector (7 downto 0);
        arr_1_out : out std_logic_vector (7 downto 0);
        arr_2_out : out std_logic_vector (7 downto 0);
        arr_3_out : out std_logic_vector (7 downto 0);
        done      : out std_logic                    ;
        ready     : out std_logic         
     );
end col_row_shift;

architecture Behavioral of col_row_shift is
type MyArrayType is array (0 to 3) of std_logic_vector(7 downto 0);
signal data_in  : MyArrayType;
begin
    rst_process:process(rst)
        begin
        end process;
     process(clk,rst)
     begin
                     data_in(0) <= arr_0_in;  data_in(1) <= arr_1_in; data_in(2) <=  arr_2_in; data_in(3) <=  arr_3_in;

       if rst = '1' then
         data_in(0) <= "00000000";  data_in(1) <="00000000"; data_in(2) <=  "00000000"; data_in(3) <=  "00000000";
       elsif  (rst = '0' and rising_edge(clk)) then
            if start = '1' and my_state = '1' then
                    if en_de = '0' then
                        arr_0_out <= data_in((0 + index) mod 4);
                        arr_1_out <= data_in((1 + index) mod 4);
                        arr_2_out <= data_in((2 + index) mod 4);
                        arr_3_out <= data_in((3 + index) mod 4);
                        ready <= '1';
                    else
                        arr_0_out <= data_in((0 - index) mod 4);
                        arr_1_out <= data_in((1 - index) mod 4);
                        arr_2_out <= data_in((2 - index) mod 4);
                        arr_3_out <= data_in((3 - index) mod 4);
                    end if;  
                
                if index = 3 then
                    done <= '1';
                end if;

            elsif rst = '0' and start = '0' then
                done <= '0';
                ready <= '0';
            end if;
        end if;
        
       end process;
end Behavioral;
