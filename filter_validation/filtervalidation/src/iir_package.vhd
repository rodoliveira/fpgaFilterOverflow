---PACKAGE GENERETADED AUTOMATICALLY
 ---FILTER: bp10E_D10_F5
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

package iir_package is

constant NBITS : integer := 16;
constant NBITS_FRAC : integer := 5;
constant NBITS_INT : integer := 10;
constant UPPER_LIMIT : integer := 32767;
constant LOWER_LIMIT : integer := -32768;

constant NORDER : integer := 11;
constant NINPUTS : integer := 10;
constant NBITS_INTERNAL_MULTIPLIERS : integer := 64;

type in_out_type is array (0 to NINPUTS-1) of std_logic_vector(NBITS-1 downto 0);

type in_coef_type is array (0 to NORDER-1) of std_logic_vector(NBITS-1 downto 0);
constant IN_COEF_MAP : in_coef_type := (
x"0000",
x"ffff",
x"0004",
x"fff7",
x"0017",
x"ffda",
x"0043",
x"ffa7",
x"007b",
x"ff7a",
x"0096"
);

type out_coef_type is array (0 to NORDER-1) of std_logic_vector(NBITS-1 downto 0);
constant OUT_COEF_MAP : in_coef_type := (
x"ff9e",
x"01b3",
x"fc53",
x"0935",
x"f0bb",
x"1b53",
x"dbdc",
x"3222",
x"ca32",
x"3bed",
x"0000"
);

end iir_package;