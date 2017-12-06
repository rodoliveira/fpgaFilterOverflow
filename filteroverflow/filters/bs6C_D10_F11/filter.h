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

#define INTEGER_BITS 5L
#define FRACTIONAL_BITS 11L

#define a0  FIXED(1,  INTEGER_BITS,FRACTIONAL_BITS)
#define a1  FIXED(-1.65204967472198,  INTEGER_BITS,FRACTIONAL_BITS)
#define a2  FIXED(5.57367371575065,  INTEGER_BITS,FRACTIONAL_BITS)
#define a3  FIXED(-6.59749730310572,  INTEGER_BITS,FRACTIONAL_BITS)
#define a4  FIXED(11.9598072092281,  INTEGER_BITS,FRACTIONAL_BITS)
#define a5  FIXED(-10.4726731930686,  INTEGER_BITS,FRACTIONAL_BITS)
#define a6  FIXED(12.9305915383006,  INTEGER_BITS,FRACTIONAL_BITS)
#define a7  FIXED(-8.29288586261541,  INTEGER_BITS,FRACTIONAL_BITS)
#define a8  FIXED(7.52392608251632,  INTEGER_BITS,FRACTIONAL_BITS)
#define a9  FIXED(-3.30927926866557,  INTEGER_BITS,FRACTIONAL_BITS)
#define a10  FIXED(2.25294055687596,  INTEGER_BITS,FRACTIONAL_BITS)
#define a11  FIXED(-0.543391173519115,  INTEGER_BITS,FRACTIONAL_BITS)
#define a12  FIXED(0.273058077270713,  INTEGER_BITS,FRACTIONAL_BITS)
#define b0  FIXED(0.417189101770226,  INTEGER_BITS,FRACTIONAL_BITS)
#define b1  FIXED(-0.792915148720479,  INTEGER_BITS,FRACTIONAL_BITS)
#define b2  FIXED(3.13106172089605,  INTEGER_BITS,FRACTIONAL_BITS)
#define b3  FIXED(-4.22978610073696,  INTEGER_BITS,FRACTIONAL_BITS)
#define b4  FIXED(8.83255275862672,  INTEGER_BITS,FRACTIONAL_BITS)
#define b5  FIXED(-8.73276612157615,  INTEGER_BITS,FRACTIONAL_BITS)
#define b6  FIXED(12.2377817697193,  INTEGER_BITS,FRACTIONAL_BITS)
#define b7  FIXED(-8.73276612157615,  INTEGER_BITS,FRACTIONAL_BITS)
#define b8  FIXED(8.83255275862672,  INTEGER_BITS,FRACTIONAL_BITS)
#define b9  FIXED(-4.22978610073696,  INTEGER_BITS,FRACTIONAL_BITS)
#define b10  FIXED(3.13106172089605,  INTEGER_BITS,FRACTIONAL_BITS)
#define b11  FIXED(-0.792915148720479,  INTEGER_BITS,FRACTIONAL_BITS)
#define b12  FIXED(0.417189101770226,  INTEGER_BITS,FRACTIONAL_BITS)

#define ORDER 6
#define STAGES 1
#define MAX_DEPTH 10

#define B {b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12}
#define A {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12}
#define UPPER_INPUT_LIMIT FIXED(7.29138897832962,   INTEGER_BITS,FRACTIONAL_BITS)
#define LOWER_INPUT_LIMIT FIXED(-7.29138897832962,   INTEGER_BITS,FRACTIONAL_BITS)
#define UPPER_OUTPUT_LIMIT (FIXED(32.0,  INTEGER_BITS,FRACTIONAL_BITS) -1)
#define LOWER_OUTPUT_LIMIT FIXED(-32.0, INTEGER_BITS,FRACTIONAL_BITS)
#endif // __FILTER_H
