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

entity encoder is
    Port (
        clk                : in  std_logic                       ;
        rst                : in  std_logic                       ;
        push_start         : in  std_logic                       ;
        next_values        : in std_logic                        ;
        out_switch         : in  std_logic                       ;
        anod               : out std_logic_vector (3 downto 0)   ;
        led_seg0           : out std_logic_vector (6 downto 0)   

    );
end encoder;

architecture Behavioral of encoder is

    component col_row_shift
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

    end component;

    component key
        Port (
            clk       : in std_logic                     ;
            rst       : in std_logic                     ;
            en_de     : in std_logic                     ;
            my_state  : in std_logic                     ;
            rounds    : in integer range 0 to 12         ;
            start     : in std_logic                     ;
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

    end component;
    component mat_mul
        Port (
            clk           : in  std_logic                   ;
            rst           : in  std_logic                   ;
            my_state      : in  std_logic                   ;
            index         : in integer range 0 to 4         ;
            start         : in  std_logic                   ;
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
    end component;

    component S_box
        Port (
            clk      : in std_logic;
            start    : in std_logic;
            index    : integer range 0 to 4 ;
            byte_in  : in std_logic_vector (7 downto 0)  ;
            my_state : in std_logic                      ;
            byte_out : out std_logic_vector (7 downto 0) ;
            done     : out std_logic;
            ready : out std_logic
        );
    end component;
    type MatrixType is array (0 to 3, 0 to 3) of STD_LOGIC_VECTOR(7 downto 0);

    type state_type is (add_k,s_box_s,col_shift,mat_multiple,noth)                   ;

    signal matrix ,mat_buf          : MatrixType                    := (others => (others => (others => '0')))        ;
    
    signal arr_0_in                  : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_1_in                  : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_2_in                  : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_3_in                  : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_0_out_buf             : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_1_out_buf             : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_2_out_buf             : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_3_out_buf             : std_logic_vector (7 downto 0)        := "00000000"                            ;
                                                                                                                       
    signal arr_0_in_s                : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_1_in_s                : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_2_in_s                : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_3_in_s                : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_0_out_s               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_1_out_s               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_2_out_s               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_3_out_s               : std_logic_vector (7 downto 0)        := "00000000"                            ;
                                                                                                                     
    signal arr_0_in_cs               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_1_in_cs               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_2_in_cs               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_3_in_cs               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_0_out_cs              : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_1_out_cs              : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_2_out_cs              : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_3_out_cs              : std_logic_vector (7 downto 0)        := "00000000"                            ;
                                                                                                                     
    signal arr_0_in_mm               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_1_in_mm               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_2_in_mm               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_3_in_mm               : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_0_out_mm              : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_1_out_mm              : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_2_out_mm              : std_logic_vector (7 downto 0)        := "00000000"                            ;
    signal arr_3_out_mm              : std_logic_vector (7 downto 0)        := "00000000"                            ;
                                                                                                              
    signal ready                     : std_logic_vector  (3 downto 0)       := "0000"                                ;
    signal index_checker             : std_logic                            := '1'                                   ;
    signal checker                   : std_logic                            := '0'                                   ;
    signal index                     : integer range  0 to 4                := 0                                     ;
    signal current_state, next_state : state_type                                                                    ;
    signal case_done                 : std_logic                            := '0'                                   ;
    signal state_act                 : std_logic_vector (3 downto 0)        := "0000"                                ;
    signal start                     : std_logic_vector  (3 downto 0)       := "0000"                                ;
    signal done                      : std_logic_vector  (3 downto 0)       := "0000"                                ;
    signal counter_i, counter_j      : integer range 0 to 3                 := 0                                     ;
    signal rounds                    : integer range 0 to 12                := 0                                     ;
    signal state                     : std_logic_vector (1 downto 0)        := "00"                                ;
    signal segment_counter           : integer                              := 0                                     ;
    
    signal push_start_buf            : std_logic                            :='0'                                    ;
    signal push_buf_counter          : integer  range 0 to 3                := 0                                     ;
    signal next_value_buf            : std_logic                            :='0'                                    ;  
    
    signal counter                   : integer range 0 to 50000             := 0                                     ;
    signal counter_next_value        : integer range 0 to 100               := 0                                     ;     
    signal ready_data                : std_logic_vector (127 downto 0)      := (others => '0')                       ;
    
    
    
    signal string_data               : std_logic_vector (127 downto 0)      := x"3243f6a8885a308d313198a2e0370734"   ;
    signal done_sbox                        :std_logic_vector (2 downto 0)         :=  "000";
       signal ready_sbox                        :std_logic_vector (2 downto 0)         :=  "000";
 
begin
    S_box_1: S_box
        Port map (
        clk => clk,  
            start => start(1),
            index => index, 
            my_state => state_act(1)   ,
            byte_in  => arr_0_in_s       ,
            byte_out => arr_0_out_s       ,
            done     => done(1),
            ready => ready_sbox(2)
        );
    S_box_2: S_box
        Port map (
            clk => clk,
            start => start(1),
            index => index, 
            my_state => state_act(1)          ,
            byte_in  => arr_1_in_s      ,
            byte_out => arr_1_out_s      ,
            done     => done_sbox(2),
            ready => ready_sbox(1)

        );
    S_box_3: S_box
        Port map (
            clk => clk,  
            start => start(1) ,
            index => index,      my_state => state_act(1)          ,
            byte_in  =>  arr_2_in_s      ,
            byte_out =>  arr_2_out_s      ,
            done     => done_sbox(1),
            ready => ready(1)

        );
    S_box_4: S_box
        Port map (
            clk => clk,   
            start => start(1),
            index => index,              
            my_state => state_act(1)          ,
            byte_in  =>  arr_3_in_s      ,
            byte_out =>  arr_3_out_s     ,
            done     => done_sbox(0),
            ready => ready_sbox(0)

        );
    col_row_shift_inst: col_row_shift
        Port map (
            clk       => clk,
            rst       => rst,
            en_de     => '0',
            my_state => state_act(2),
            index     => index,
            start     => start(2),
            arr_0_in  =>  arr_0_in_cs,
            arr_1_in  =>  arr_1_in_cs,
            arr_2_in  =>  arr_2_in_cs,
            arr_3_in  =>  arr_3_in_cs,
            arr_0_out =>  arr_0_out_cs,
            arr_1_out =>  arr_1_out_cs,
            arr_2_out =>  arr_2_out_cs,
            arr_3_out =>  arr_3_out_cs,
            done      => done(2)      ,
            ready     => ready(2)
        );
    key_inst: key
        Port map (
            clk        => clk ,
            rst        => rst ,
            en_de      => '0' ,
            my_state   => state_act(0),
            start      => start(0),
            index      => index,
            rounds     => rounds,
            arr_0_in   => arr_0_in,
            arr_1_in   => arr_1_in,
            arr_2_in   => arr_2_in,
            arr_3_in   => arr_3_in,
            arr_0_out  => arr_0_out_buf,
            arr_1_out  => arr_1_out_buf,
            arr_2_out  => arr_2_out_buf,
            arr_3_out  => arr_3_out_buf,
            done       => done(0),
            ready      => ready(0)
        );
    mat_multiplier_inst: mat_mul
        Port map (
            clk       => clk,
            rst       => rst,
            my_state  => state_act(3),
            index     => index,
            start     => start(3),
            arr_0_in  =>  arr_0_in_mm,
            arr_1_in  =>  arr_1_in_mm,
            arr_2_in  =>  arr_2_in_mm,
            arr_3_in  =>  arr_3_in_mm,
            arr_0_out =>  arr_0_out_mm,
            arr_1_out =>  arr_1_out_mm,
            arr_2_out =>  arr_2_out_mm,
            arr_3_out =>  arr_3_out_mm,
            done      =>  done(3)     ,
            ready     =>   ready(3)
        );
    process(clk, rst)

    begin
        if rst = '1' then     
            start             <= (others => '0');       
            state             <= (others => '0');  
            push_start_buf    <=             '0';       
            case_done         <=             '0'; 
            rounds            <=               0;            
            segment_counter   <=               0;       
            push_buf_counter  <=               0;                                 
            counter           <=               0; 
            ready_data        <= (others => '0');             
            current_state     <=           add_k;
            next_state        <=           add_k;
            next_value_buf    <=             '0';
            led_seg0          <=       "1111111";    
            anod              <=          "0000";
            

        elsif (rst = '0' and rising_edge(clk)) then
            
             current_state <= next_state;
             if (rst = '0' and  checker = '0') then
                  


                    matrix(counter_j, counter_i) <= string_data(127-(counter_i*32 + counter_j*8) downto 127-(counter_i*32 + counter_j*8)-7);
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
              end if;
           elsif rst = '0' and  checker = '1' then
               if push_start = '1' and counter_next_value >= 90 then
                        push_start_buf <= '1';
                        counter_next_value <= 0;
                 elsif  push_start = '1' and counter_next_value < 90 then
                    counter_next_value <= counter_next_value + 1;
                 end if;
                 case push_buf_counter is 
                        when 0      => string_data <= x"6BC1BEE22E409F96E93D7E117393172A";
                        when 1      => string_data <= x"AE2D8A571E03AC9C9EB76FAC45AF8E51";
                        when 2      => string_data <= x"30C81C46A35CE411E5FBC1191A0A52EF";
                        when 3      => string_data <= x"F69F2445DF4F9B17AD2B417BE66C3710";
                        when others => string_data <= (others => '0');
                 end case;    
            case case_done is 

            when '0' =>
               if  push_start_buf = '1' and push_start = '0'    then     
                case current_state is
                    when add_k =>
                            arr_0_in  <= matrix(index,0);    
                            arr_1_in  <= matrix(index,1);    
                            arr_2_in  <= matrix(index,2);    
                            arr_3_in  <= matrix(index,3);    
                            mat_buf(index,0)<= arr_0_out_buf;
                            mat_buf(index,1)<= arr_1_out_buf;
                            mat_buf(index,2)<= arr_2_out_buf;
                            mat_buf(index,3)<= arr_3_out_buf;   
                 if index = 3 and index_checker =    '0' then
                                index <= 0;
                                index_checker <= '1';
                 else
                        if (start(0) = '0' and index <=3 and done(0) = '0' ) then
                            start(0) <= '1';
                            state_act(0) <= '1';                      
                            next_state <= add_k;                         
                        elsif  start(0) = '1' and ready(0) ='1' and state_act(0) ='1' and index < 3  and done(0) = '0'  then   
                            start(0) <= '0';
                            index <= index +1;                 
                            next_state <= add_k;
                        elsif(done(0) = '1') then          
                            start(0) <= '0';
                            state_act(0) <= '0';
                            if rounds /= 10 then 
                                next_state <= s_box_s;
                            else 
                                next_state <= noth;
                            end if;
                            index_checker <= '0';                       
                        else
                            next_state <= add_k;
                            
                        end if;
                end if ;
                    when s_box_s =>
                            arr_0_in_s  <= mat_buf(index,0); 
                            arr_1_in_s  <= mat_buf(index,1);
                            arr_2_in_s  <= mat_buf(index,2);
                            arr_3_in_s  <= mat_buf(index,3);
                            matrix(index,0)<= arr_0_out_s;
                            matrix(index,1)<= arr_1_out_s;
                            matrix(index,2)<= arr_2_out_s;
                            matrix(index,3)<= arr_3_out_s;
                    if index = 3 and index_checker =    '0' then
                                index <= 0;
                                index_checker <= '1';
                    else
                        if (start(1) = '0' and index <=3 and done(1) = '0' ) then
                            start(1) <= '1';
                            state_act(1) <= '1';                      
                            next_state <= s_box_s;
                            
                        elsif  start(1) = '1' and ready(1) ='1' and state_act(1) ='1' and index < 3  and done(1) = '0'  then
                            start(1) <= '0';
                            index <= index +1;                 
                            next_state <= s_box_s;
                        elsif(done(1) = '1') then          
                            start(1) <= '0';
                            state_act(1) <= '0';
                            index_checker <= '0';
                            next_state <= col_shift;                                                                  
                        else
                            next_state <= s_box_s;
                        end if;
                    end if ;                    
                    when col_shift =>                          
                            arr_0_in_cs  <= matrix(index,0); 
                            arr_1_in_cs  <= matrix(index,1);
                            arr_2_in_cs  <= matrix(index,2);
                            arr_3_in_cs  <= matrix(index,3);
                            mat_buf(index,0)<= arr_0_out_cs;
                            mat_buf(index,1)<= arr_1_out_cs;
                            mat_buf(index,2)<= arr_2_out_cs;
                            mat_buf(index,3)<= arr_3_out_cs;
                    if index = 3 and index_checker =    '0' then
                                index <= 0;
                                index_checker <= '1';
                    else
                        if (start(2) = '0' and index <=3 and done(2) = '0' ) then
                            start(2) <= '1';
                            state_act(2) <= '1';                      
                            next_state <= col_shift;                           
                        elsif  start(2) = '1' and ready(2) ='1' and state_act(2) ='1' and index < 3  and done(2) = '0'  then
                            start(2) <= '0';
                            index <= index +1;                 
                            next_state <= col_shift;
                        elsif(done(2) = '1') then          
                            start(2) <= '0';
                            state_act(2) <= '0';
                            index_checker <= '0';
                            if rounds < 10 then
                                next_state <= mat_multiple;
                            else 
                                next_state <= noth;
                            end if;
                        else
                            next_state <= col_shift;                           
                        end if;
                    end if ;
                    when mat_multiple =>                     
                           arr_0_in_mm  <=  mat_buf(0,index) ;
                           arr_1_in_mm  <=  mat_buf(1,index) ;
                           arr_2_in_mm  <=  mat_buf(2,index) ;
                           arr_3_in_mm  <=  mat_buf(3,index) ;
                           matrix(0,index)<= arr_0_out_mm;
                           matrix(1,index)<= arr_1_out_mm;
                           matrix(2,index)<= arr_2_out_mm;
                           matrix(3,index)<= arr_3_out_mm;
                    if index = 3 and index_checker =    '0' then
                                index <= 0;
                                index_checker <= '1';
                    else
                        if (start(3) = '0' and index <=3 and ready(3) = '0' ) then
                            start(3) <= '1';
                            state_act(3) <= '1';                      
                            next_state <= mat_multiple;
                           
                        elsif  start(3) = '1' and ready(3) ='1' and state_act(3) ='1' and index < 3  and done(3) = '0'  then
                            start(3) <= '0';
                            index <= index +1;                 
                            next_state <= mat_multiple;
                        elsif(done(3) = '1') then          
                            start(3) <= '0';
                            state_act(3) <= '0';
                            next_state <= noth;                                    
                            index_checker <= '0';
                        else
                            next_state <= mat_multiple;
                            
                        end if;
                      
                    end if ;
                            
                    when noth =>
                        if rounds < 10 and next_state = noth then
                            rounds     <= rounds + 1;
                            next_state <= add_k     ;
                        elsif next_state = noth then                            
                            matrix <= mat_buf;
                            case_done <= '1';
                            ready_data <= mat_buf(0,0) & mat_buf(1,0) & mat_buf(2,0) & mat_buf(3,0) & -- Column 0
                                          mat_buf(0,1) & mat_buf(1,1) & mat_buf(2,1) & mat_buf(3,1) & -- Column 1
                                          mat_buf(0,2) & mat_buf(1,2) & mat_buf(2,2) & mat_buf(3,2) & -- Column 2
                                          mat_buf(0,3) & mat_buf(1,3) & mat_buf(2,3) & mat_buf(3,3);  -- Column 3 
                        end if;
                     when others =>
                            anod <= "0000";
                            led_seg0 <= "0000000";
                            ready_data  <= (others => '0'); 
                end case;
                end if;
           when '1' =>
             if push_start = '1' then     
                    rounds           <=                      0;
                    case_done        <=                    '0'; 
                    push_buf_counter <=   push_buf_counter + 1;
                    push_start_buf   <=                    '0';
                    segment_counter  <=                      0;
                    anod             <=                 "0000";
                    led_seg0         <=              "1111111";
                end if;
--=========================
-- 7-Segment Display Logic
--=========================
-- Display data on the 7-segment LEDs:
-- - Decode 4-bit data to 7-segment codes.
-- - Cycle through anodes for multiplexed display.
                if out_switch = '1' then
                    if counter = 50000 then
                        case state is 
                         when "00" =>
                            anod <= "1110";              
                            case ready_data((segment_counter+1)*4-1 downto segment_counter*4 ) is 
                                when "0000" =>led_seg0 <= "1000000";
                                when "0001" =>led_seg0 <= "1001111";
                                when "0010" =>led_seg0 <= "0100100";
                                when "0011" =>led_seg0 <= "0110000";
                                when "0100" =>led_seg0 <= "0011001";
                                when "0101" =>led_seg0 <= "0010010";
                                when "0110" =>led_seg0 <= "0000010";
                                when "0111" =>led_seg0 <= "1111000";
                                when "1000" =>led_seg0 <= "0000000";
                                when "1001" =>led_seg0 <= "0010000";
                                when "1010" =>led_seg0 <= "0001000";
                                when "1011" =>led_seg0 <= "0000011";
                                when "1100" =>led_seg0 <= "1000110";
                                when "1101" =>led_seg0 <= "0100001";
                                when "1110" =>led_seg0 <= "0000110";
                                when "1111" =>led_seg0 <= "0001110";
                                when others => null;                             
                            end case;
                        when "01" =>
                            anod <= "1101";
                            case ready_data((segment_counter+2)*4-1 downto (segment_counter+1)*4 ) is 
                            when "0000" =>led_seg0 <= "1000000";
                            when "0001" =>led_seg0 <= "1001111";
                            when "0010" =>led_seg0 <= "0100100";
                            when "0011" =>led_seg0 <= "0110000";
                            when "0100" =>led_seg0 <= "0011001";
                            when "0101" =>led_seg0 <= "0010010";
                            when "0110" =>led_seg0 <= "0000010";
                            when "0111" =>led_seg0 <= "1111000";
                            when "1000" =>led_seg0 <= "0000000";
                            when "1001" =>led_seg0 <= "0010000";
                            when "1010" =>led_seg0 <= "0001000";
                            when "1011" =>led_seg0 <= "0000011";
                            when "1100" =>led_seg0 <= "1000110";
                            when "1101" =>led_seg0 <= "0100001";
                            when "1110" =>led_seg0 <= "0000110";
                            when "1111" =>led_seg0 <= "0001110";
                            when others => null;                            
                         end case ;
          
                         when "10" =>
                            anod <= "1011";
                            case ready_data((segment_counter+3)*4-1 downto (segment_counter+2)*4 ) is 
                                when "0000" =>led_seg0 <= "1000000";
                                when "0001" =>led_seg0 <= "1001111";
                                when "0010" =>led_seg0 <= "0100100";
                                when "0011" =>led_seg0 <= "0110000";
                                when "0100" =>led_seg0 <= "0011001";
                                when "0101" =>led_seg0 <= "0010010";
                                when "0110" =>led_seg0 <= "0000010";
                                when "0111" =>led_seg0 <= "1111000";
                                when "1000" =>led_seg0 <= "0000000";
                                when "1001" =>led_seg0 <= "0010000";
                                when "1010" =>led_seg0 <= "0001000";
                                when "1011" =>led_seg0 <= "0000011";
                                when "1100" =>led_seg0 <= "1000110";
                                when "1101" =>led_seg0 <= "0100001";
                                when "1110" =>led_seg0 <= "0000110";
                                when "1111" =>led_seg0 <= "0001110";
                                when others => null;                
                         end case ;
        
                         when "11" =>
                            anod <= "0111";
                            case ready_data((segment_counter+4)*4-1 downto (segment_counter+3)*4 ) is 
                                when "0000" =>led_seg0 <= "1000000";
                                when "0001" =>led_seg0 <= "1001111";
                                when "0010" =>led_seg0 <= "0100100";
                                when "0011" =>led_seg0 <= "0110000";
                                when "0100" =>led_seg0 <= "0011001";
                                when "0101" =>led_seg0 <= "0010010";
                                when "0110" =>led_seg0 <= "0000010";
                                when "0111" =>led_seg0 <= "1111000";
                                when "1000" =>led_seg0 <= "0000000";
                                when "1001" =>led_seg0 <= "0010000";
                                when "1010" =>led_seg0 <= "0001000";
                                when "1011" =>led_seg0 <= "0000011";
                                when "1100" =>led_seg0 <= "1000110";
                                when "1101" =>led_seg0 <= "0100001";
                                when "1110" =>led_seg0 <= "0000110";
                                when "1111" =>led_seg0 <= "0001110";
                                when others => null;                                  
                            end case ;
                            
                            when others => null;
                         end case ;
                         state <= state +"1";
                         counter <= counter + 1;

                    else 
                        counter <= counter + 1;
                    end if;
                    
                    if next_values = '1' then
                         next_value_buf <= '1';
                    end if;
                           
                    if next_value_buf = '1' and next_values = '0' and counter_next_value >=90 then
                         segment_counter <= segment_counter + 4;
                         next_value_buf <= '0';
                         counter_next_value <= 0;
                    elsif next_value_buf = '1' and next_values = '0' and counter_next_value <90   then
                         counter_next_value <= counter_next_value + 1;
                    end if;
                else 
--=========================
-- 7-Segment Display Logic
--=========================
-- Display AES on the 7-segment LEDs:
-- - Decode 4-bit data to 7-segment codes.
-- - Cycle through anodes for multiplexed display.
                    if counter = 50000 then
                        case state is 
                         when "00" =>
                            anod <= "0111";
                            led_seg0 <= "0001000";  -- a 
                                                       
                        when "01" =>
                            anod <= "1011";
                            led_seg0 <= "0000110";  -- e
                            
                         when "10" =>
                            anod <= "1101";
                            led_seg0 <= "0010010";  -- 5
                             
                         when "11" =>
                            anod <= "1110";
                            led_seg0 <= "1111111";
                           
                         when others => null;
                        end case ;
                        state <= state +"1";
                        counter <= counter + 1;
                    else 
                        counter <= counter + 1;
                    end if;   
                end if;         
        when others => 
            anod <= "0000";
            led_seg0 <= "0000000";
            case_done <= '0';      
        end case;
        
      end if;
      end if ;
 end process;

end Behavioral;
