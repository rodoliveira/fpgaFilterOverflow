-------------------------------------------------------------------------------
-- Title      : Testbench for design "iir_test"
-- Project    : 
-------------------------------------------------------------------------------
-- File       : iir_test_tb.vhd
-- Author     :   <rodrigo@shannon>
-- Company    : 
-- Created    : 2017-04-14
-- Last update: 2018-03-19
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: 
-------------------------------------------------------------------------------
-- Copyright (c) 2017 
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2017-04-14  1.0      rodrigo	Created
-------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;


use work.iir_package.all;
-------------------------------------------------------------------------------

entity iir_test_tb is

end entity iir_test_tb;

-------------------------------------------------------------------------------

architecture tb of iir_test_tb is

  -- component ports
  --signal clk   : std_logic;
  signal rst_n : std_logic := '0';

  -- clock
  signal Clk : std_logic := '1';

  signal start      : std_logic := '0';
  signal overflow   : std_logic;
  signal input_map  : in_out_type;
  signal output_map : in_out_type;
  signal busy       : std_logic;
  
begin  -- architecture tb

  -- component instantiation
  iir_test_1: entity work.iir_test
    generic map (
      NBITS                      => NBITS,
      NORDER                     => NORDER,
      NINPUTS                    => NINPUTS,
      NBITS_FRAC                 => NBITS_FRAC,
      NBITS_INTERNAL_MULTIPLIERS => NBITS_INTERNAL_MULTIPLIERS)
    port map (
      clk        => clk,
      rst_n      => rst_n,
      start      => start,
      overflow   => overflow,
      input_map  => input_map,
      output_map => output_map,
      busy       => busy);
  
  -- clock generation
 Clk <= not Clk after 10 ns;
 rst_n <= '1' after 60 ns;

  --input_map <= (x"65e3", x"cff3", x"9a1d", x"9b5b", x"e4a3", x"65e3", x"3287", x"4d62", x"0000", x"0000");

  input_map <= (x"65e3", x"e988", x"0000", x"0000", x"0000", x"0000", x"0000", x"0000", x"0000", x"0000");

  start <= '1' after 100 ns;
--waveform generation
  WaveGen_Proc: process
  begin
    if (busy = '1') then
      report "BUSY";
    end if;

    if (overflow = '1') then
      report "OVERFLOW";
    end if;
    
    if (start = '1') then
      report "START";
    end if;

    for i in 0 to 8 loop      
        report "y[" & integer'image(i) & "] = " & integer'image(to_integer(signed(output_map(i))));
    end loop;
                       

    report "end CYCLE ---------------------";
    wait until Clk = '1';
  end process WaveGen_Proc;

  -- WaveGen_Proc: process
  -- begin
  --   if (overflow = '1') then
  --     report "OVERflOW";
  --    for i in 0 to 8 loop      
  --      report "y[" & integer'image(i) & "] = " & integer'image(to_integer(signed(output_map(i))));
  --    end loop;
      
  --    end if;

  --   wait until Clk = '1';
  -- end process WaveGen_Proc;

  

end architecture tb;

-------------------------------------------------------------------------------

configuration iir_test_tb_tb_cfg of iir_test_tb is
  for tb
  end for;
end iir_test_tb_tb_cfg;

-------------------------------------------------------------------------------
