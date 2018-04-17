---PACKAGE GENERETADED AUTOMATICALLY
 ---FILTER: lp2B_D10_F10
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

package iir_package is

constant NBITS : integer := 16;
constant NBITS_FRAC : integer := 10;
constant NBITS_INT : integer := 2;
constant UPPER_LIMIT : integer := 4095;
constant LOWER_LIMIT : integer := -4096;

constant NORDER : integer := 3;
constant NINPUTS : integer := 10;
constant NBITS_INTERNAL_MULTIPLIERS : integer := 64;

type in_out_type is array (0 to NINPUTS-1) of std_logic_vector(NBITS-1 downto 0);

type in_coef_type is array (0 to NORDER-1) of std_logic_vector(NBITS-1 downto 0);
constant IN_COEF_MAP : in_coef_type := (
x"00d4",
x"01a7",
x"00d4"
);

type out_coef_type is array (0 to NORDER-1) of std_logic_vector(NBITS-1 downto 0);
constant OUT_COEF_MAP : in_coef_type := (
x"fe86",
x"00c9",
x"0000"
);

end iir_package;