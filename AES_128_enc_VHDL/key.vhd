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
        start     : in std_logic                     ;
        rounds     : in integer range  0 to 10         ;
        data_in   : in std_logic_vector (127 downto 0);
        data_out   : out std_logic_vector (127 downto 0);
        done      : out std_logic                    ;
        ready       :   out std_logic    
     );
end key;
architecture Behavioral of key is
    signal key    : std_logic_vector (127 downto 0) := (others => '0');
    signal checker: std_logic :='0';
    begin
      rst_process:process(clk,rst) 
       begin
        if rst = '1' then
             key <= (others => '0')   ;
             checker <= '0';
             ready <= '1';
        elsif (rst = '0' and rising_edge(clk)  ) then
            case rounds is 
                 when 0 =>
                    key <= x"2b7e151628aed2a6abf7158809cf4f3c";
                 when 1 =>
                    key <= x"a0fafe1788542cb123a339392a6c7605";
                 when 2 =>
                    key <= x"f2c295f27a96b9435935807a7359f67f";
                 when 3 =>
                    key <= x"3d80477d4716fe3e1e237e446d7a883b";
                 when 4 =>
                    key <= x"ef44a541a8525b7fb671253bdb0bad00";
                 when 5 =>
                    key <= x"d4d1c6f87c839d87caf2b8bc11f915bc";
                 when 6 =>
                    key <= x"6d88a37a110b3efddbf98641ca0093fd";
                 when 7 =>
                    key <= x"4e54f70e5f5fc9f384a64fb24ea6dc4f";
                 when 8 =>
                    key <= x"ead27321b58dbad2312bf5607f8d292f";
                 when 9 =>
                    key <= x"ac7766f319fadc2128d12941575c006e";
                 when 10 =>
                    key <= x"d014f9a8c9ee2589e13f0cc8b6630ca6";
                 when others => 
                    key <= x"00000000000000000000000000000000";
            end case;
            if start = '1'  then
                ready <= '0' ;
                data_out <= key xor data_in;
                done <= '1';
            elsif rst = '0'  and start = '0' then
                done <= '0';
                ready <= '1';
          end if;
       end if ;
           end process;
end Behavioral;

