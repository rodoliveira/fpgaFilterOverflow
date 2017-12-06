-------------------------------------------------------------------------------
-- Title      : Testbench for design "iir_test"
-- Project    : 
-------------------------------------------------------------------------------
-- File       : iir_test_tb.vhd
-- Author     :   <rodrigo@shannon>
-- Company    : 
-- Created    : 2017-04-14
-- Last update: 2017-04-14
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

-------------------------------------------------------------------------------

entity iir_test_tb is

end entity iir_test_tb;

-------------------------------------------------------------------------------

architecture tb of iir_test_tb is

  -- component generics
  constant NBITS                      : integer := 16;
  constant NORDER                     : integer := 3;
  constant NINPUTS                    : integer := 5;
  constant NBITS_INTERNAL_MULTIPLIERS : integer := 64;

  -- component ports
  --signal clk   : std_logic;
  signal rst_n : std_logic := '0';

  -- clock
  signal Clk : std_logic := '1';

begin  -- architecture tb

  -- component instantiation
  DUT: entity work.iir_test
    generic map (
      NBITS                      => NBITS,
      NORDER                     => NORDER,
      NINPUTS                    => NINPUTS,
      NBITS_INTERNAL_MULTIPLIERS => NBITS_INTERNAL_MULTIPLIERS)
    port map (
      clk   => clk,
      rst_n => rst_n);

  -- clock generation
  Clk <= not Clk after 10 ns;
 rst_n <= '1' after 60 ns;
  -- waveform generation
  WaveGen_Proc: process
  begin
    -- insert signal assignments here

    wait until Clk = '1';
  end process WaveGen_Proc;

  

end architecture tb;

-------------------------------------------------------------------------------

configuration iir_test_tb_tb_cfg of iir_test_tb is
  for tb
  end for;
end iir_test_tb_tb_cfg;

-------------------------------------------------------------------------------
