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

#define INTEGER_BITS 3L
#define FRACTIONAL_BITS 13L

#define a0  FIXED(1,  INTEGER_BITS,FRACTIONAL_BITS)
#define a1  FIXED(-1.99240148160141,  INTEGER_BITS,FRACTIONAL_BITS)
#define a2  FIXED(3.01948286335538,  INTEGER_BITS,FRACTIONAL_BITS)
#define a3  FIXED(-2.81852242649451,  INTEGER_BITS,FRACTIONAL_BITS)
#define a4  FIXED(2.03872063706253,  INTEGER_BITS,FRACTIONAL_BITS)
#define a5  FIXED(-1.05454462109568,  INTEGER_BITS,FRACTIONAL_BITS)
#define a6  FIXED(0.414446268750399,  INTEGER_BITS,FRACTIONAL_BITS)
#define a7  FIXED(-0.115718625236828,  INTEGER_BITS,FRACTIONAL_BITS)
#define a8  FIXED(0.0224985092722183,  INTEGER_BITS,FRACTIONAL_BITS)
#define a9  FIXED(-0.0026689123535761,  INTEGER_BITS,FRACTIONAL_BITS)
#define a10  FIXED(0.000148764452177762,  INTEGER_BITS,FRACTIONAL_BITS)
#define b0  FIXED(0.0004994540782331,  INTEGER_BITS,FRACTIONAL_BITS)
#define b1  FIXED(0.004994540782331,  INTEGER_BITS,FRACTIONAL_BITS)
#define b2  FIXED(0.0224754335204895,  INTEGER_BITS,FRACTIONAL_BITS)
#define b3  FIXED(0.059934489387972,  INTEGER_BITS,FRACTIONAL_BITS)
#define b4  FIXED(0.104885356428951,  INTEGER_BITS,FRACTIONAL_BITS)
#define b5  FIXED(0.125862427714741,  INTEGER_BITS,FRACTIONAL_BITS)
#define b6  FIXED(0.104885356428951,  INTEGER_BITS,FRACTIONAL_BITS)
#define b7  FIXED(0.059934489387972,  INTEGER_BITS,FRACTIONAL_BITS)
#define b8  FIXED(0.0224754335204895,  INTEGER_BITS,FRACTIONAL_BITS)
#define b9  FIXED(0.004994540782331,  INTEGER_BITS,FRACTIONAL_BITS)
#define b10  FIXED(0.0004994540782331,  INTEGER_BITS,FRACTIONAL_BITS)

#define ORDER 10
#define STAGES 1
#define MAX_DEPTH 10

#define B {b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10}
#define A {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10}
#define UPPER_INPUT_LIMIT FIXED(3.7977063493579,   INTEGER_BITS,FRACTIONAL_BITS)
#define LOWER_INPUT_LIMIT FIXED(-3.7977063493579,   INTEGER_BITS,FRACTIONAL_BITS)
#define UPPER_OUTPUT_LIMIT (FIXED(8.0,  INTEGER_BITS,FRACTIONAL_BITS) -1)
#define LOWER_OUTPUT_LIMIT FIXED(-8.0, INTEGER_BITS,FRACTIONAL_BITS)
#endif // __FILTER_H


