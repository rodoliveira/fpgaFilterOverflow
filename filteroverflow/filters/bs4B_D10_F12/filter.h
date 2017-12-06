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

#define INTEGER_BITS 4L
#define FRACTIONAL_BITS 12L

#define a0  FIXED(1,  INTEGER_BITS,FRACTIONAL_BITS)
#define a1  FIXED(-1.13730141773631,  INTEGER_BITS,FRACTIONAL_BITS)
#define a2  FIXED(3.6673778052532,  INTEGER_BITS,FRACTIONAL_BITS)
#define a3  FIXED(-2.82727591413143,  INTEGER_BITS,FRACTIONAL_BITS)
#define a4  FIXED(4.65362114542467,  INTEGER_BITS,FRACTIONAL_BITS)
#define a5  FIXED(-2.3021645572765,  INTEGER_BITS,FRACTIONAL_BITS)
#define a6  FIXED(2.43393504635258,  INTEGER_BITS,FRACTIONAL_BITS)
#define a7  FIXED(-0.612190060881391,  INTEGER_BITS,FRACTIONAL_BITS)
#define a8  FIXED(0.43826514226198,  INTEGER_BITS,FRACTIONAL_BITS)
#define b0  FIXED(0.662015837202618,  INTEGER_BITS,FRACTIONAL_BITS)
#define b1  FIXED(-0.838824062890528,  INTEGER_BITS,FRACTIONAL_BITS)
#define b2  FIXED(3.04663338800548,  INTEGER_BITS,FRACTIONAL_BITS)
#define b3  FIXED(-2.60064191212229,  INTEGER_BITS,FRACTIONAL_BITS)
#define b4  FIXED(4.77590068887623,  INTEGER_BITS,FRACTIONAL_BITS)
#define b5  FIXED(-2.60064191212229,  INTEGER_BITS,FRACTIONAL_BITS)
#define b6  FIXED(3.04663338800548,  INTEGER_BITS,FRACTIONAL_BITS)
#define b7  FIXED(-0.838824062890528,  INTEGER_BITS,FRACTIONAL_BITS)
#define b8  FIXED(0.662015837202618,  INTEGER_BITS,FRACTIONAL_BITS)

#define ORDER 4
#define STAGES 1
#define MAX_DEPTH 10

#define B {b0, b1, b2, b3, b4, b5, b6, b7, b8}
#define A {a0, a1, a2, a3, a4, a5, a6, a7, a8}
#define UPPER_INPUT_LIMIT FIXED(5.14192323258976,   INTEGER_BITS,FRACTIONAL_BITS)
#define LOWER_INPUT_LIMIT FIXED(-5.14192323258976,   INTEGER_BITS,FRACTIONAL_BITS)
#define UPPER_OUTPUT_LIMIT (FIXED(16.0,  INTEGER_BITS,FRACTIONAL_BITS) -1)
#define LOWER_OUTPUT_LIMIT FIXED(-16.0, INTEGER_BITS,FRACTIONAL_BITS)
#endif // __FILTER_H
