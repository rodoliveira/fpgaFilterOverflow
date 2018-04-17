--IIR FILTER
-- Created by rodrigo@labsci
-- 13/04/2017


library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

use work.iir_package.all;

LIBRARY lpm;
USE lpm.lpm_components.all;

entity iir_test is
  generic (NBITS : integer := NBITS;
           NORDER : integer := NORDER;           
           NINPUTS : integer := NINPUTS;
           NBITS_FRAC : integer := NBITS_FRAC;
           NBITS_INTERNAL_MULTIPLIERS : integer := NBITS_INTERNAL_MULTIPLIERS
           );
---@INIT_PORT
  port (clk      : in std_logic;
        rst_n    : in std_logic;
        start    : in std_logic;
        overflow : out std_logic;
        input_map : in in_out_type;
        output_map : out in_out_type;
        busy : out std_logic
        );
---@END_PORT
end entity iir_test;

architecture bhv of iir_test is

---@CORE_INIT
  signal output_vec : in_out_type := (others => (others => '0'));

  -- internal signals
  type in_tmp_type is array (NORDER-1 downto 0) of std_logic_vector(NBITS-1 downto 0);
  signal in_vec_tmp : in_tmp_type := (others => (others => '0'));
  
  type out_tmp_type is array (NORDER-1 downto 0) of std_logic_vector(NBITS_INTERNAL_MULTIPLIERS-1 downto 0);
  signal out_vec_tmp : out_tmp_type := (others => (others => '0'));    

  
  type in_mult_result_type is array (NORDER-1 downto 0) of std_logic_vector(NBITS_INTERNAL_MULTIPLIERS-1 downto 0);
  signal in_mult_result : in_mult_result_type := (others => (others => '0'));
  signal in_mult_result_shifted : in_mult_result_type := (others => (others => '0'));

  type out_mult_result_type is array (NORDER-1 downto 0) of std_logic_vector(NBITS_INTERNAL_MULTIPLIERS-1 downto 0);
  signal out_mult_result : out_mult_result_type := (others => (others => '0'));
  signal out_mult_result_shifted : out_mult_result_type := (others => (others => '0'));

  type out_mult_tmp_resized_type is array (0 to NORDER-1) of std_logic_vector(NBITS_INTERNAL_MULTIPLIERS-NBITS-1 downto 0);  
  signal out_mult_input_resized : out_mult_tmp_resized_type := (others => (others => '0'));


  --control signals
  signal run : std_logic := '0';

  --iteration index signals
  signal input_index : unsigned(NBITS-1 downto 0) := (others => '0');
  signal output_index : unsigned(NBITS-1 downto 0) := (others => '0');

  -- check if overflow exists
  signal overflow_s : std_logic := '0';

  --dff start signal
  signal start_f, fire : std_logic := '0';

  -- function to check overflow.  
 function CHECK_OVERFLOW (X : std_logic_vector)
   return std_logic is
   variable tmp : std_logic;
begin
  if (to_integer(signed(X)) > UPPER_LIMIT) or (to_integer(signed(X)) < LOWER_LIMIT) then
    tmp := '1';
  else
    tmp := '0';
  end if;
  
  return tmp;
end CHECK_OVERFLOW;

   
begin  -- architecture bhv
  proc: process (clk, rst_n) is
    variable result_tmp : std_logic_vector(NBITS_INTERNAL_MULTIPLIERS-1 downto 0) := (others => '0');
  begin  -- process proc
    if rst_n = '0' then                 -- asynchronous reset (active low)
      output_vec <= (others => (others => '0'));
      input_index <= (others => '0');
      output_index <= (others => '0');
      out_vec_tmp <= (others => (others => '0'));
      in_vec_tmp <= (others => (others => '0'));
      fire <= '0';
      run <= '0';
      result_tmp := (others => '0');
      overflow_s <= '0';
    elsif clk'event and clk = '1' then  -- rising clock edge

      start_f <= start;
      if (start_f = '0' and start = '1') then
        fire <= '1';
      end if;
      
      -- check_overlow at last output
      if (CHECK_OVERFLOW(out_vec_tmp(0)) = '1') then
        overflow_s <= '1';
      end if;
      
      -- Register inputs
      if input_index < NINPUTS then
        if (fire = '1') then
          run <= '1';
          in_vec_tmp <= in_vec_tmp(NORDER-2 downto 0) & input_map(to_integer(input_index));
          input_index <= input_index + 1;
        end if;
      end if;
      
      if output_index < NINPUTS then
        result_tmp := (others => '0');
        for i in 0 to NORDER-1 loop      
          result_tmp := result_tmp + in_mult_result_shifted(i) - out_mult_result_shifted(i);
        end loop;
        if run = '1' then
          output_vec(to_integer(output_index)) <= result_tmp(NBITS-1 downto 0);
          out_vec_tmp <= out_vec_tmp(NORDER-2 downto 0) & result_tmp;
          output_index <= output_index + 1;
        end if;
      else
        fire <= '0';
        run <= '0';
      end if;      

    end if;      
  end process proc;

--output signals
  output_map <= output_vec;
  busy <= fire;
-- multiplier inputs and input coefs.
  GEN_INPUT_MULTIPLIERS: 
  for i in 0 to NORDER-1 generate
    lpm_multX : lpm_mult
      GENERIC MAP (
        lpm_hint => "DEDICATED_MULTIPLIER_CIRCUITRY=YES,MAXIMIZE_SPEED=5",
        lpm_representation => "SIGNED",
        lpm_type => "LPM_MULT",
        lpm_widtha => NBITS,
        lpm_widthb => NBITS,
        lpm_widthp => NBITS_INTERNAL_MULTIPLIERS
	)
      PORT MAP (
        dataa => in_vec_tmp(i),
        datab => IN_COEF_MAP(i),
        result => in_mult_result(i)
	);
  end generate GEN_INPUT_MULTIPLIERS;

 -- multiplier outputs and output coefs.
  GEN_OUTPUT_MULTIPLIERS: 
  for i in 0 to NORDER-1 generate
    lpm_mult_component : lpm_mult
      GENERIC MAP (
        lpm_hint => "DEDICATED_MULTIPLIER_CIRCUITRY=YES,MAXIMIZE_SPEED=5",
        lpm_representation => "SIGNED",
        lpm_type => "LPM_MULT",
        lpm_widtha => NBITS_INTERNAL_MULTIPLIERS-NBITS,
        lpm_widthb => NBITS,
        lpm_widthp => NBITS_INTERNAL_MULTIPLIERS
	)
      PORT MAP (
        dataa => out_mult_input_resized(i),
        datab => OUT_COEF_MAP(i),
        result => out_mult_result(i)
	);
  end generate GEN_OUTPUT_MULTIPLIERS;

  -- shift bits to restore original fixed point
  RESIZE_GEN:
  for i in 0 to NORDER-1 generate
    in_mult_result_shifted(i) <= std_logic_vector(shift_right(signed(in_mult_result(i)), NBITS_FRAC));
    out_mult_result_shifted(i) <= std_logic_vector(shift_right(signed(out_mult_result(i)), NBITS_FRAC));
    out_mult_input_resized(i) <= std_logic_vector(resize(signed(out_vec_tmp(i)),NBITS_INTERNAL_MULTIPLIERS-NBITS));
  end generate;
                                                       
overflow <= overflow_s;	
end architecture bhv;
