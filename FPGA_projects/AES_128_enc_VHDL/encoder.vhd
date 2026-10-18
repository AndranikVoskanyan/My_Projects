--This code is make by Andranik Voskanyan and Zinar Zeynep for Digital Architecture and design project 
--Project  is about AES-128 encryption 
  
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_arith.ALL;
USE IEEE.std_logic_unsigned.ALL;


--==========================
-- Entity Declaration: Encoder
--==========================
-- Define the ports and their purposes for the encoder entity, including:
-- - Clock and reset signals.
-- - Input controls for starting and switching operations.
-- - Outputs for 7-segment display and anode control.
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

--================================
-- Architecture: Behavioral
--================================
-- Define the architecture, including:
-- - Components used in the design.
-- - Internal signals and states.

architecture Behavioral of encoder is
    component col_row_shift
        Port (
            clk            : in std_logic                       ;
            rst            : in std_logic                       ;
            start          : in std_logic                       ;
            data_in        : in std_logic_vector (127 downto 0) ;
            data_out       : out std_logic_vector (127 downto 0);
            done           : out std_logic                      ;
            ready          : out std_logic         

        );
    end component;
    
    --======================
-- Component Declarations
--======================
-- Declare reusable components for S-box, column-row shift, key generation, 
-- and matrix multiplication. Define their ports for integration.

    component key
        Port (
            clk            : in std_logic                       ;
            rst            : in std_logic                       ;
            start          : in std_logic                       ;
            rounds         : in integer range  0 to 10          ;
            data_in        : in std_logic_vector (127 downto 0) ;
            data_out       : out std_logic_vector (127 downto 0);
            done           : out std_logic                      ;
            ready          :   out std_logic    
        );
    end component;
    component mat_mul
        Port (
            clk           : in  std_logic                       ;
            rst           : in  std_logic                       ;
            start         : in  std_logic                       ;
            data_in       : in std_logic_vector (127 downto 0)  ;
            data_out      : out std_logic_vector (127 downto 0) ;
            done          : out std_logic                       ;
            ready         : out std_logic 
        );
    end component;
    component S_box
        Port (
           clk             : in std_logic                        ;
           rst             : in std_logic                        ;
           start           : in std_logic                        ;
           data_in         : in std_logic_vector (127 downto 0)  ;
           data_out        : out std_logic_vector (127 downto 0) ;        
           done            : out std_logic                       ;
           ready           : out std_logic
        );
    end component;
    
--=========================
-- State Type Definition
--=========================
-- Define the finite state machine (FSM) states for the AES process stages:
-- - Add Round Key
-- - Substitution Box (S-box)
-- - Column Shift
-- - Matrix Multiplication

    type state_type is (add_k,s_box_s,col_shift,mat_multiple)                                                        ;
       
--====================
-- Signal Declarations
--====================
-- Internal signals for:
-- - Data flow between components.
-- - Control signals (start, done, ready).
-- - Round counters and segment updates for the display.  
       
    signal  data_in_k                : std_logic_vector   (127 downto 0)     := (others => '0')                      ;
    
    signal data_out_k               : std_logic_vector   (127 downto 0)     := (others => '0')                       ;
    signal data_out_cs              : std_logic_vector   (127 downto 0)     := (others => '0')                       ;
    signal data_out_s               : std_logic_vector   (127 downto 0)     := (others => '0')                       ;        
    signal data_out_mat_mul         : std_logic_vector   (127 downto 0)     := (others => '0')                       ;
    
    signal ready                     : std_logic_vector  (3 downto 0)       := "0000"                                ;
    signal current_state, next_state : state_type                           := add_k                                 ;
    signal case_done                 : std_logic                            := '0'                                   ;
    signal start                     : std_logic_vector  (3 downto 0)       := "0000"                                ;
    signal done                      : std_logic_vector  (3 downto 0)       := "0000"                                ;
    signal rounds                    : integer range 0 to 13                := 0                                     ;
    signal state                     : std_logic_vector (1 downto 0)        := "00"                                  ;
    signal segment_counter           : integer range 0 to 28                := 0                                     ;

    signal counter                   : integer range 0 to 50000             := 0                                     ;
    signal counter_next_value        : integer range 0 to 100               := 0                                     ;   
   
    signal ready_data                : std_logic_vector (127 downto 0)      := (others => '0')                       ;

    signal string_data               : std_logic_vector (127 downto 0)      := x"6BC1BEE22E409F96E93D7E117393172A"   ;
    signal push_start_buf            : std_logic                            :='0'                                    ;
    signal push_buf_counter          : integer  range 0 to 3                := 0                                     ;
    signal next_value_buf            : std_logic                            :='0'                                    ;    
begin

--===================================
-- Component Instantiations
--===================================
-- Instantiate and connect the declared components:
-- - S_box
-- - col_row_shift
-- - key
-- - mat_mul
    S_box_inst: S_box
        Port map (
            clk => clk,  
            start => start(1),
            rst => rst,
            data_in  => data_out_k       ,
            data_out => data_out_s       ,
            done     => done(1),
            ready => ready(1)
        );

     col_row_shift_inst: col_row_shift
        Port map (
            clk       => clk,
            rst       => rst,
            start     => start(2),
            data_in =>  data_out_s,
            data_out =>  data_out_cs,
            done      => done(2)      ,
            ready     => ready(2)
        );
    key_inst: key
        Port map (
            clk        => clk ,
            rst        => rst ,
            rounds     => rounds,
            start      => start(0),
            data_in    => data_in_k,
            data_out   => data_out_k, 
            done       => done(0),
            ready      => ready(0)
        );
    mat_multiplier_inst: mat_mul
        Port map (
           clk      => clk, 
           rst      => rst,
           start    => start(3),
           data_in  => data_out_cs,
           data_out => data_out_mat_mul,
           done     => done(3),
           ready    => ready(3)
         );
    process(clk,rst)
    begin

--=============================
-- Reset Logic
--=============================
-- Define behavior during reset:
-- - Initialize all signals and states to default values.
        if rst = '1' then     
            data_in_k         <= (others => '0');      
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
            
--============================
-- Main Process: AES Encryption
--============================
-- Main logic controlling the encryption process:
-- - State machine implementation for the AES rounds.
-- - Data initialization, state transitions, and control signal updates.

        elsif (rst = '0' and rising_edge(clk)) then
             current_state <= next_state;     
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
                            if rounds = 0 and next_state = add_k then
                                data_in_k  <= string_data;                           
                                next_state <= s_box_s ; 
                                rounds <= rounds + 1;
                            elsif rounds = 10 and next_state = add_k then
                                data_in_k  <= data_out_cs;
                                rounds <= rounds + 1;
                            elsif rounds >11 then
                                case_done <= '1';
                                ready_data <= data_out_k;
                            elsif next_state = add_k then
                                data_in_k  <= data_out_mat_mul;
                                next_state <= s_box_s;
                                rounds <= rounds + 1;
    
                            end if;                       
                            if next_state = add_k then
                                start      <= "0001";
                            else
                                start      <= "0000";
                            end if;
                                                  
                        when s_box_s =>
                            if next_state = s_box_s then
                                start      <= "0010";
                            else
                                start      <= "0000";
                            end if;
                                
                                next_state <= col_shift;   
                                                                                               
                        when col_shift => 
                                if next_state = col_shift then
                                    start  <= "0100";
                                else
                                    start  <= "0000";
                                end if;
    
                                if rounds < 10 then
                                    next_state <= mat_multiple;
                                elsif rounds = 10 and next_state = col_shift then                                
                                    next_state <= add_k;
                                else 
                                end if;
                                
                        when mat_multiple =>                     
                               if next_state = mat_multiple then
                                    start  <= "1000";
                                else
                                    start  <= "0000";
                                end if;
                                next_state <= add_k;                                                                                            
                    end case;  
                 end if; 
    
--============================
-- Display Update Process
--============================
-- Logic for updating the 7-segment display and anodes:
-- - Decode data and display on specific segments.
-- - Manage counters and transitions based on input controls.
                          
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
 end process;
end Behavioral;
