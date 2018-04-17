/***************************************************************************************
*
*  Copyright 2016 Alair Dias Junior
*
*  This file is part of FixedFilterOverflow.
*
*  FixedFilterOverflow is free software: you can redistribute it and/or modify it under the
*  terms of the GNU General Public License as published by the Free Software Foundation,
*  either version 3 of the License, or any later version.
*
*  FilterOverflow is distributed in the hope that it will be useful, but WITHOUT ANY 
*  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
*  PARTICULAR PURPOSE. See the GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License along with 
*  FixedFilterOverflow. If not, see http://www.gnu.org/licenses/.
*
***************************************************************************************/
#ifndef __FILTER_H
#define __FILTER_H

#include "filterSimul.h"

#define INTEGER_BITS 2L
#define FRACTIONAL_BITS 14L

#define a0  FIXED(1,  INTEGER_BITS,FRACTIONAL_BITS)
#define a1  FIXED(-0.579008685386832,  INTEGER_BITS,FRACTIONAL_BITS)
#define a2  FIXED(1.74072047511593,  INTEGER_BITS,FRACTIONAL_BITS)
#define a3  FIXED(-0.494373404048699,  INTEGER_BITS,FRACTIONAL_BITS)
#define a4  FIXED(0.732816932128206,  INTEGER_BITS,FRACTIONAL_BITS)
#define b0  FIXED(0.755008503538254,  INTEGER_BITS,FRACTIONAL_BITS)
#define b1  FIXED(-0.478326397092688,  INTEGER_BITS,FRACTIONAL_BITS)
#define b2  FIXED(1.58577646577249,  INTEGER_BITS,FRACTIONAL_BITS)
#define b3  FIXED(-0.478326397092688,  INTEGER_BITS,FRACTIONAL_BITS)
#define b4  FIXED(0.755008503538254,  INTEGER_BITS,FRACTIONAL_BITS)

#define ORDER 2
#define STAGES 1
#define MAX_DEPTH 10

#define B {b0, b1, b2, b3, b4}
#define A {a0, a1, a2, a3, a4}
#define UPPER_INPUT_LIMIT FIXED(1.59199201122155,   INTEGER_BITS,FRACTIONAL_BITS)
#define LOWER_INPUT_LIMIT FIXED(-1.59199201122155,   INTEGER_BITS,FRACTIONAL_BITS)
#define UPPER_OUTPUT_LIMIT (FIXED(4.0,  INTEGER_BITS,FRACTIONAL_BITS) -1)
#define LOWER_OUTPUT_LIMIT FIXED(-4.0, INTEGER_BITS,FRACTIONAL_BITS)
#endif // __FILTER_H
