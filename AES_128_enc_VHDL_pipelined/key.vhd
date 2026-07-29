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
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity key is 
    Port (
        clk       : in std_logic                     ;
        rst       : in std_logic                     ;
        en_de     : in std_logic                     ;
        my_state  : in std_logic                     ;
        start     : in std_logic                     ;
        rounds    : in integer range  0 to 12        ;
        index     : in integer range  0 to 4         ;
        arr_0_in  : in std_logic_vector  (7 downto 0);
        arr_1_in  : in std_logic_vector  (7 downto 0);
        arr_2_in  : in std_logic_vector  (7 downto 0);
        arr_3_in  : in std_logic_vector  (7 downto 0);
        arr_0_out : out std_logic_vector (7 downto 0);
        arr_1_out : out std_logic_vector (7 downto 0);
        arr_2_out : out std_logic_vector (7 downto 0);
        arr_3_out : out std_logic_vector (7 downto 0);
        done      : out std_logic                    ;
        ready       :   out std_logic    
     );
end key;
architecture Behavioral of key is
    type MatrixType is array (0 to 3, 0 to 3) of STD_LOGIC_VECTOR(7 downto 0);
    signal matrix : MatrixType := (
        0 => (0 => x"2b", 1 => x"28", 2 => x"ab", 3 => x"09"), -- Row 0
        1 => (0 => x"7e", 1 => x"ae", 2 => x"f7", 3 => x"cf"), -- Row 1
        2 => (0 => x"15", 1 => x"d2", 2 => x"15", 3 => x"4f"), -- Row 2
        3 => (0 => x"16", 1 => x"a6", 2 => x"88", 3 => x"3c")  -- Row 3
    );
    signal key_reg    : std_logic_vector (127 downto 0) := (others => '0');
    signal counter_i, counter_j      : integer range 0 to 3                 := 0                                     ;

    signal checker: std_logic :='0';
    begin
      rst_process:process(clk,rst) 
       begin
        if rst = '1' then
            checker <= '0';
            
        elsif (rst = '0' and rising_edge(clk)  ) then
             case rounds is 
                 when 0 =>
                    key_reg <= x"2b7e151628aed2a6abf7158809cf4f3c";
                 when 1 =>
                    key_reg <= x"a0fafe1788542cb123a339392a6c7605";
                 when 2 =>
                    key_reg <= x"f2c295f27a96b9435935807a7359f67f";
                 when 3 =>
                    key_reg <= x"3d80477d4716fe3e1e237e446d7a883b";
                 when 4 =>
                    key_reg <= x"ef44a541a8525b7fb671253bdb0bad00";
                 when 5 =>
                    key_reg <= x"d4d1c6f87c839d87caf2b8bc11f915bc";
                 when 6 =>
                    key_reg <= x"6d88a37a110b3efddbf98641ca0093fd";
                 when 7 =>
                    key_reg <= x"4e54f70e5f5fc9f384a64fb24ea6dc4f";
                 when 8 =>
                    key_reg <= x"ead27321b58dbad2312bf5607f8d292f";
                 when 9 =>
                    key_reg <= x"ac7766f319fadc2128d12941575c006e";
                 when 10 =>
                    key_reg <= x"d014f9a8c9ee2589e13f0cc8b6630ca6";
                 when others => 
                    key_reg <= x"00000000000000000000000000000000";
            end case;
             if (  checker = '0') then
                 
                    matrix(counter_j, counter_i) <= key_reg(127-(counter_i*32 + counter_j*8) downto 127-(counter_i*32 + counter_j*8)-7);
                    if counter_i <3 then
                        counter_i <= counter_i + 1;
                    else
                        counter_i <= 0 ;
                        if counter_j < 3 then
                            counter_j <= counter_j + 1;
                        else
                            counter_j <= 0;
                            counter_i <= 0;
                            checker <= '1';
                        end if;
                    end if ;
                end if;
            if start = '1' and my_state = '1' then
               if en_de = '0' then
                arr_0_out <= arr_0_in + matrix(index,0);
                arr_1_out <= arr_1_in + matrix(index,1);
                arr_2_out <= arr_2_in + matrix(index,2);
                arr_3_out <= arr_3_in + matrix(index,3);
               else
                arr_0_out <= arr_0_in - matrix(index,0);
                arr_1_out <= arr_1_in - matrix(index,1);
                arr_2_out <= arr_2_in - matrix(index,2);
                arr_3_out <= arr_3_in - matrix(index,3);
               end if;
                ready <= '1';
                if index = 3 then
                    done <= '1';
                end if;
          elsif rst = '0'  and start = '0' then
                done <= '0';
                ready <= '0';
          end if;
       end if ;
           end process;
end Behavioral;

