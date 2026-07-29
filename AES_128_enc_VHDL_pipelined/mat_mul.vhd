library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity mat_mul is
    Port (
        clk           : in  std_logic                   ;
        rst           : in  std_logic                   ;
        my_state      : in  std_logic                   ; 
        start         : in  std_logic                   ;
        index         : in integer range 0 to 4         ;
        arr_0_in      : in  std_logic_vector(7 downto 0); -- First element of the 1x4 matrix
        arr_1_in      : in  std_logic_vector(7 downto 0); -- Second element of the 1x4 matrix
        arr_2_in      : in  std_logic_vector(7 downto 0); -- Third element of the 1x4 matrix
        arr_3_in      : in  std_logic_vector(7 downto 0); -- Fourth element of the 1x4 matrix
        arr_0_out     : out std_logic_vector(7 downto 0); -- First element of the output matrix
        arr_1_out     : out std_logic_vector(7 downto 0); -- Second element of the output matrix
        arr_2_out     : out std_logic_vector(7 downto 0); -- Third element of the output matrix
        arr_3_out     : out std_logic_vector(7 downto 0); -- Fourth element of the output matrix
        done          : out std_logic                   ;
        ready         : out std_logic                              
    );
end mat_mul;

architecture Behavioral of mat_mul is
    type MatrixType is array (0 to 3, 0 to 3) of std_logic_vector(7 downto 0);
    type MyArrayType is array (0 to 3) of std_logic_vector(7 downto 0);

    -- Constant 4x4 matrix
    constant constant_matrix : MatrixType := (
        0 => (0 => "00000010", 1 => "00000011", 2 => "00000001", 3 => "00000001"), -- Row 0
        1 => (0 => "00000001", 1 => "00000010", 2 => "00000011", 3 => "00000001"), -- Row 1
        2 => (0 => "00000001", 1 => "00000001", 2 => "00000010", 3 => "00000011"), -- Row 2
        3 => (0 => "00000011", 1 => "00000001", 2 => "00000001", 3 => "00000010")  -- Row 3
    );
    signal in_matrix: MyArrayType ;
    signal result_matrix                   :  std_logic_vector(7 downto 0)   := "00000000" ; -- Signal to hold the result of multiplication
    signal state                           : integer                         := 0          ; -- State variable for FSM
    signal counter_inner, counter_outter   : integer                         := 0          ;
    signal byte_in, byte_out_3, byte_out_2 : std_logic_vector (7 downto 0) :=  "00000000"  ;
    signal check                           : std_logic                     := '0'          ;
    component LUT_mul2
       Port ( 
              byte_in : in STD_LOGIC_VECTOR (7 downto 0);   
              byte_out : out STD_LOGIC_VECTOR (7 downto 0)
              );
    end component;       
    component LUT_mul3
       Port ( 
              byte_in : in STD_LOGIC_VECTOR (7 downto 0);   
              byte_out : out STD_LOGIC_VECTOR (7 downto 0)
              );
    end component;    
begin
    mul3: LUT_mul3
        Port map (
           byte_in => byte_in,
           byte_out =>byte_out_3
        );   
    mul2: LUT_mul2
        Port map (
           byte_in => byte_in,
           byte_out =>byte_out_2
        );     
    process(clk, rst)
    begin
        if rst = '1' then
            state <= 0;
            result_matrix <= "00000000";
        elsif  rst = '0' and rising_edge(clk) then
            if  start = '1' and my_state = '1'  then
                case state is
                    when 0 =>
                       
                            in_matrix(0) <= arr_0_in;
                            in_matrix(1) <= arr_1_in;
                            in_matrix(2) <= arr_2_in;
                            in_matrix(3) <= arr_3_in;
                            state        <= 1; 
                            byte_in      <= arr_0_in;
                    when 1 =>
    
    
                            if counter_inner <= 3 then
                               byte_in <= in_matrix(counter_inner);
                               check <= '1';
                               if constant_matrix(counter_outter, counter_inner) = "00000001" then
                                       result_matrix <= result_matrix + in_matrix(counter_inner);
                               elsif  constant_matrix(counter_outter, counter_inner) = "00000010" then
                                       result_matrix <= result_matrix +  byte_out_2 ;
    
                               elsif  constant_matrix(counter_outter, counter_inner) = "00000011"  then
                                           result_matrix <= result_matrix +  byte_out_3 ;
                               end if;
                               if check = '1' then
                                    counter_inner <= counter_inner + 1;     
                               end if;
                            else
                                   case counter_outter is
                                        when 0 => arr_0_out <= result_matrix;
                                        when 1 => arr_1_out <= result_matrix;
                                        when 2 => arr_2_out <= result_matrix;
                                        when 3 => arr_3_out <= result_matrix;
                                        when others => null; -- Do nothing for other cases
                                   end case;
                                   counter_inner <= 0;
                                   if counter_outter <3 then
                                        counter_outter <= counter_outter + 1;
                                        result_matrix <= "00000000"; -- Initialize the result for the current row
                                        
                                   else
                                        ready <= '1';
                                        check <= '0';
                                        if index = 3 then
                                            done <= '1';
                                            
                                        end if ;
--                                        state <= 0;  -- Return to idle state
                                        counter_outter <= 0;
                                        counter_inner <= 0;
                                   end if;
                            end if ;
    
    
                    when others =>
                        state <= 0; -- Reset state for safety
                end case;
            elsif  start = '0' then
                done <= '0';
                ready <= '0';
                state <= 0;
                result_matrix <= "00000000";
            end if;
         end if;
    end process;

end Behavioral;
