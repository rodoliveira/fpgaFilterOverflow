---PACKAGE GENERETADED AUTOMATICALLY

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

package iir_package is

constant NBITS : integer := 16;
constant NBITS_FRAC : integer := 5;
constant NORDER : integer := 3;
constant NINPUTS : integer := 0;
constant NBITS_INTERNAL_MULTIPLIERS : integer := 64;

type in_out_type is array (0 to NINPUTS-1) of std_logic_vector(NBITS-1 downto 0);

type in_coef_type is array (0 to NORDER-1) of std_logic_vector(NBITS-1 downto 0);
constant IN_COEF_MAP : in_coef_type := (
x"0007",
x"000d",
x"0007"
);

type out_coef_type is array (0 to NORDER-1) of std_logic_vector(NBITS-1 downto 0);
constant OUT_COEF_MAP : in_coef_type := (
x"fff4",
x"0006",
x"0000"
);

end iir_package;