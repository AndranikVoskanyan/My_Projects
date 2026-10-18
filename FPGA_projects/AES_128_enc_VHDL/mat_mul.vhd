library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity mat_mul is
    Port (
        clk           : in  std_logic                       ;
        rst           : in  std_logic                       ;
        start         : in  std_logic                       ;
        data_in       : in std_logic_vector (127 downto 0)  ;
        data_out      : out std_logic_vector (127 downto 0) ;
        done          : out std_logic                       ;
        ready         : out std_logic                              
    );
end mat_mul;

architecture Behavioral of mat_mul is
    type MatrixType is array (0 to 3, 0 to 3) of std_logic_vector(7 downto 0);
    
    signal data_in_mat  : MatrixType :=(others => (others =>(others => '0')));
    signal data_out_mat : MatrixType :=(others => (others =>(others => '0')));
    signal data_out_mul_2  : MatrixType :=(others => (others =>(others => '0')));
    signal data_out_mul_3  : MatrixType :=(others => (others =>(others => '0')));

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
  gen_mul_block : for i in 0 to 3 generate
      
     mul3: LUT_mul3
          Port map (
               byte_in  => data_in_mat(i,0),
               byte_out =>data_out_mul_3(i,0)
          );   
     mul2: LUT_mul2
          Port map (
               byte_in  => data_in_mat(i,0),
               byte_out =>data_out_mul_2(i,0)
          );
     mul3_1: LUT_mul3                         
         Port map (                         
            byte_in  => data_in_mat(i,1),    
            byte_out =>data_out_mul_3(i,1)  
         );                                 
     mul2_1: LUT_mul2                         
         Port map (                          
            byte_in  => data_in_mat(i,1),    
            byte_out =>data_out_mul_2(i,1)  
         );                                 
     mul3_2: LUT_mul3                         
         Port map (                         
            byte_in  => data_in_mat(i,2),    
            byte_out =>data_out_mul_3(i,2)  
         );                                 
     mul2_2: LUT_mul2                         
         Port map (                         
            byte_in  => data_in_mat(i,2),    
            byte_out =>data_out_mul_2(i,2)  
         );                                 
     mul3_3: LUT_mul3                         
         Port map (                         
            byte_in  => data_in_mat(i,3),    
            byte_out =>data_out_mul_3(i,3)  
         );                                 
     mul2_3: LUT_mul2                         
         Port map (                         
            byte_in  => data_in_mat(i,3),    
            byte_out =>data_out_mul_2(i,3)  
         );                                 
    end generate;
    process(clk, rst)
    begin  
        if rst = '1' then
            data_in_mat      <= (others =>(others =>(others =>'0')));
            data_out_mat     <= (others =>(others =>(others =>'0')));
        elsif  rst = '0' and rising_edge(clk) then
            for i in 0 to 3 loop
                for j in 0 to 3 loop
                    data_in_mat(j,i) <= data_in(127-(i*32 + j*8) downto 127-(i*32 + j*8)-7) ;
                end loop;
            end loop;             
            if  start = '1' then
             for i in 0 to 3 loop 
              data_out((i*32 + 7)  downto (i*32+7) -7)  <= (data_out_mul_2(3,3-i) xor data_out_mul_3(0,3-i) xor data_in_mat(1,3-i) xor data_in_mat(2,3-i));                  
              data_out((i*32 + 15) downto (i*32+15)-7)  <= (data_out_mul_2(2,3-i) xor data_out_mul_3(3,3-i) xor data_in_mat(0,3-i) xor data_in_mat(1,3-i)) ;
              data_out((i*32 + 23) downto (i*32+23)-7)  <= (data_out_mul_2(1,3-i) xor data_out_mul_3(2,3-i) xor data_in_mat(0,3-i) xor data_in_mat(3,3-i)) ;   
              data_out((i*32 + 31) downto (i*32+31)-7)  <= (data_out_mul_2(0,3-i) xor data_out_mul_3(1,3-i) xor data_in_mat(2,3-i) xor data_in_mat(3,3-i));  
             end loop;

             done  <= '1';
             ready <= '0';
            elsif  start = '0' then
                done  <= '0';
                ready <= '1';
            end if;
         end if;
    end process;

end Behavioral;
