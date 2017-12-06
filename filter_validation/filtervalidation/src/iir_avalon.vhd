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

entity iir_avalon is
  generic (
    NBITS_ADDR : integer := NBITS;
    NBITS_ADDR_MASTER : integer := 32;
    NBITS_ADDR_SLAVE : integer := 7;
    NBITS_DATA_MASTER : integer := NBITS;
    NBITS_DATA_SLAVE : integer := 32
    );
---@INIT_PORT
  port (clk      : in std_logic;
        rst_n    : in std_logic;

        -- avalon MM Slave
        slave_chipselect    : in std_logic;
        slave_read          : in std_logic;
        slave_write         : in std_logic;
        slave_address       : in std_logic_vector(NBITS_ADDR_SLAVE-1 downto 0);
        slave_writedata     : in std_logic_vector(NBITS_DATA_SLAVE-1 downto 0);
        slave_waitrequest   : out std_logic;
        slave_readdatavalid : out std_logic;
        slave_readdata      : out std_logic_vector(NBITS_DATA_SLAVE-1 downto 0);

        
        -- avalon MM Master Write    
        master_waitrequest : in std_logic;
        master_address     : out std_logic_vector(NBITS_ADDR_MASTER-1 downto 0);
        master_write       : out std_logic;
        master_writedata   : out std_logic_vector(NBITS_DATA_MASTER-1 downto 0)
        
        );
---@END_PORT
end entity iir_avalon;

architecture bhv of iir_avalon is

  type reg_type is array (0 to NINPUTS) of std_logic_vector(31 downto 0);
  signal registers : reg_type := (
    x"FFFF0000",
    x"0000FFCB",
    x"00000037",
    x"00000037",
    x"00000037",
    x"00000005",
    x"00000006",
    x"00000007",
    x"00000008",
    x"00000009",
    x"0000000A"
    );

   signal input_map : in_out_type := (    
     x"FFCB", 
     x"0037", 
     x"0037", 
     x"0037", 
     x"0005",
     x"0006", 
     x"0007", 
     x"0008", 
     x"0009", 
     x"000A"
     );
  
  type mm_wr_state is (st_idle, st_start, st_wait_finish, st_write_result);
  signal state : mm_wr_state := st_idle;

  signal start_filter, start_filter_f : std_logic := '0';

  signal start_filter_core  : std_logic := '0';
  signal output_map : in_out_type;
  signal filter_busy, filter_busy_f  : std_logic := '0';

  signal s_address : std_logic_vector(NBITS_ADDR_MASTER-1 downto 0) := (others => '0');
  signal s_writedata : std_logic_vector(NBITS_DATA_MASTER-1 downto 0) := (others => '0');
  
  signal index, count_writes : unsigned(10 downto 0) := (others => '0');
  signal rst_n_filter : std_logic := '1';

  signal overflow : std_logic := '0';
  constant ADDR_BASE_WR : std_logic_vector(NBITS_ADDR_MASTER-1 downto 0) := x"38000000";
begin  -- architecture bhv

  iir_test_1: entity work.iir_test
    port map (
      clk        => clk,
      rst_n      => rst_n_filter,
      start      => start_filter_core,
      input_map  => input_map,
      overflow   => overflow,
      output_map => output_map,
      busy       => filter_busy);

  
 rd_wr_slave_proc: process (clk, rst_n) is
  begin  -- process rd_wr_slave_proc
    if rst_n = '0' then                 -- asynchronous reset (active low)
      slave_readdata <= (others => '0');
      slave_readdatavalid <= '0';
      registers(0) <= x"FFFF0000";
    elsif clk'event and clk = '1' then  -- rising clock edge     
      start_filter_f <= start_filter;     
      filter_busy_f <= filter_busy;
      
      if state = st_write_result then
        registers(0)(0) <= overflow;
      else
        registers(0)(0) <= registers(0)(0);
      end if;
      
      --LEITURA DO SLAVE  ---- READ PROC
      if slave_read = '1' then
        slave_readdata <= registers(to_integer(unsigned(slave_address)));
        slave_readdatavalid <= '1';        
      --ESCRITA NO SLAVE
      elsif slave_write = '1' and slave_chipselect = '1' then
        if unsigned(slave_address) = 0 then
          start_filter <= slave_writedata(0);
          slave_readdatavalid <= '0';
        elsif unsigned(slave_address) < NINPUTS+1 then
          registers(to_integer(unsigned(slave_address))) <= slave_writedata;
          input_map(to_integer(unsigned(slave_address)-1)) <= slave_writedata(15 downto 0);
          slave_readdatavalid <= '0';
        else
          slave_readdatavalid <= '0';  
        end if;        
      else
        slave_readdatavalid <= '0';
      end if;      
    end if;
  end process rd_wr_slave_proc;

wr_proc: process (clk, rst_n) is
begin  -- process wr_proc
  if rst_n = '0' then                   -- asynchronous reset (active low)
      index <= (others => '0');
      count_writes <= (others => '0');
      s_address <= ADDR_BASE_WR;    
  elsif clk'event and clk = '1' then    -- rising clock edge
    -- WR MASTER PROC
    if state = st_write_result then
      if master_waitrequest = '0' then
        s_address <= std_logic_vector(unsigned(s_address) + NBITS_DATA_MASTER/8);        
        index <= index + 1;
        count_writes <= count_writes + 1;        
      else
        s_address <= s_address;
        index <= index;
        count_writes <= count_writes;
      end if;
    else 
      s_address <= ADDR_BASE_WR;
      index <= (others => '0');
      count_writes <= (others => '0');
    end if;
    
  end if;
end process wr_proc;

  state_proc: process (clk, rst_n) is
  begin  -- process state_proc
    if rst_n = '0' then                 -- asynchronous reset (active low)
      state <= st_idle;
    elsif clk'event and clk = '1' then  -- rising clock edge
          ---- STATE MACHINE
    case state is
      when st_idle =>
        if start_filter = '1' and start_filter_f = '0' then
          state <= st_start;
        else
          state <= st_idle;
        end if;

      when st_start =>
        
        state <= st_wait_finish;

      when st_wait_finish =>
        if filter_busy = '0' and filter_busy_f = '1' then
          state <= st_write_result;
        else
          state <= st_wait_finish;
        end if;

      when st_write_result =>
        if count_writes < NINPUTS-1 then
          state <= st_write_result;
        else
          state <= st_idle;
        end if;
    end case;
    

    end if;
  end process state_proc;
  s_writedata <= output_map(to_integer(index));
  master_writedata <= s_writedata;
  master_write <= '1' when state = st_write_result else '0';
  master_address <= s_address;
  start_filter_core <= '1' when state = st_start else '0';
  rst_n_filter <= '1' when rst_n = '1' and (state /= st_idle) else '0'; 


  
end architecture bhv;
