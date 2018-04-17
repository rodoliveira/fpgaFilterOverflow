---PACKAGE GENERETADED AUTOMATICALLY

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

package iir_package is

constant NBITS : integer := 16;
constant NBITS_FRAC : integer := 14;
constant NBITS_INT : integer := 2;
constant UPPER_LIMIT : integer := 65535;
constant LOWER_LIMIT : integer := -65536;

constant NORDER : integer := 3;
constant NINPUTS : integer := 10;
constant NBITS_INTERNAL_MULTIPLIERS : integer := 64;

type in_out_type is array (0 to NINPUTS-1) of std_logic_vector(NBITS-1 downto 0);

type in_coef_type is array (0 to NORDER-1) of std_logic_vector(NBITS-1 downto 0);
constant IN_COEF_MAP : in_coef_type := (
x"3052",
x"e163",
x"657d"
);

type out_coef_type is array (0 to NORDER-1) of std_logic_vector(NBITS-1 downto 0);
constant OUT_COEF_MAP : in_coef_type := (
x"daf2",
x"6f68",
x"0000"
);

end iir_package;