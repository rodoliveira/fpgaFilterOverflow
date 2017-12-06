-------------------------------------------------------------------------------
-- Title      : Testbench for design "iir_avalon"
-- Project    : 
-------------------------------------------------------------------------------
-- File       : iir_avalon_tb.vhd
-- Author     :   <rodrigo@shannon>
-- Company    : 
-- Created    : 2017-05-26
-- Last update: 2017-05-26
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: 
-------------------------------------------------------------------------------
-- Copyright (c) 2017 
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2017-05-26  1.0      rodrigo	Created
-------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

use work.iir_package.all;

LIBRARY lpm;
USE lpm.lpm_components.all;

-------------------------------------------------------------------------------

entity iir_avalon_tb is

end entity iir_avalon_tb;

-------------------------------------------------------------------------------

architecture tb of iir_avalon_tb is

  -- component generics
  constant NBITS_ADDR        : integer := NBITS;
  constant NBITS_ADDR_MASTER : integer := 32;
  constant NBITS_ADDR_SLAVE  : integer := 1;
  constant NBITS_DATA_MASTER : integer := NBITS;
  constant NBITS_DATA_SLAVE  : integer := 32;

  -- component ports
  signal clk                 : std_logic := '1';
  signal rst_n               : std_logic := '0';
  signal slave_chipselect    : std_logic;
  signal slave_read          : std_logic;
  signal slave_write         : std_logic;
  signal slave_address       : std_logic_vector(NBITS_ADDR_SLAVE-1 downto 0);
  signal slave_writedata     : std_logic_vector(NBITS_DATA_SLAVE-1 downto 0);
  signal slave_waitrequest   : std_logic;
  signal slave_readdatavalid : std_logic;
  signal slave_readdata      : std_logic_vector(NBITS_DATA_SLAVE-1 downto 0);
  signal master_waitrequest  : std_logic;
  signal master_address      : std_logic_vector(NBITS_ADDR_MASTER-1 downto 0);
  signal master_write        : std_logic;
  signal master_writedata    : std_logic_vector(NBITS_DATA_MASTER-1 downto 0);

  -- clock  

begin  -- architecture tb

  -- component instantiation
  DUT: entity work.iir_avalon
    generic map (
      NBITS_ADDR        => NBITS_ADDR,
      NBITS_ADDR_MASTER => NBITS_ADDR_MASTER,
      NBITS_ADDR_SLAVE  => NBITS_ADDR_SLAVE,
      NBITS_DATA_MASTER => NBITS_DATA_MASTER,
      NBITS_DATA_SLAVE  => NBITS_DATA_SLAVE)
    port map (
      clk                 => clk,
      rst_n               => rst_n,
      slave_chipselect    => slave_chipselect,
      slave_read          => slave_read,
      slave_write         => slave_write,
      slave_address       => slave_address,
      slave_writedata     => slave_writedata,
      slave_waitrequest   => slave_waitrequest,
      slave_readdatavalid => slave_readdatavalid,
      slave_readdata      => slave_readdata,
      master_waitrequest  => master_waitrequest,
      master_address      => master_address,
      master_write        => master_write,
      master_writedata    => master_writedata);

  -- clock generation
  Clk <= not Clk after 10 ns;
  rst_n <= '1' after 60 ns;

  slave_chipselect <= '1';
  slave_writedata <= x"FFFFFFFF";
  slave_write <= '1' after 100 ns;

  master_waitrequest <= '0';
  
  -- waveform generation
  WaveGen_Proc: process
  begin
    -- insert signal assignments here
    if master_write = '1' then
      report "writing master";
    end if;
    
    wait until Clk = '1';
  end process WaveGen_Proc;

  

end architecture tb;

-------------------------------------------------------------------------------

configuration iir_avalon_tb_tb_cfg of iir_avalon_tb is
  for tb
  end for;
end iir_avalon_tb_tb_cfg;

-------------------------------------------------------------------------------
