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

#define INTEGER_BITS 10L
#define FRACTIONAL_BITS 5L

#define a0  FIXED(1,  INTEGER_BITS,FRACTIONAL_BITS)
#define a1  FIXED(-3.06616371823434,  INTEGER_BITS,FRACTIONAL_BITS)
#define a2  FIXED(13.5984197099872,  INTEGER_BITS,FRACTIONAL_BITS)
#define a3  FIXED(-29.4185899103035,  INTEGER_BITS,FRACTIONAL_BITS)
#define a4  FIXED(73.6603226986216,  INTEGER_BITS,FRACTIONAL_BITS)
#define a5  FIXED(-122.16960708155,  INTEGER_BITS,FRACTIONAL_BITS)
#define a6  FIXED(218.593678835079,  INTEGER_BITS,FRACTIONAL_BITS)
#define a7  FIXED(-289.11663913317,  INTEGER_BITS,FRACTIONAL_BITS)
#define a8  FIXED(401.066122043343,  INTEGER_BITS,FRACTIONAL_BITS)
#define a9  FIXED(-430.448955092674,  INTEGER_BITS,FRACTIONAL_BITS)
#define a10  FIXED(479.413870827924,  INTEGER_BITS,FRACTIONAL_BITS)
#define a11  FIXED(-418.447497369402,  INTEGER_BITS,FRACTIONAL_BITS)
#define a12  FIXED(379.01853870994,  INTEGER_BITS,FRACTIONAL_BITS)
#define a13  FIXED(-265.580120559829,  INTEGER_BITS,FRACTIONAL_BITS)
#define a14  FIXED(195.191023711125,  INTEGER_BITS,FRACTIONAL_BITS)
#define a15  FIXED(-106.018478039122,  INTEGER_BITS,FRACTIONAL_BITS)
#define a16  FIXED(62.130038867916,  INTEGER_BITS,FRACTIONAL_BITS)
#define a17  FIXED(-24.1076394250769,  INTEGER_BITS,FRACTIONAL_BITS)
#define a18  FIXED(10.8295919107747,  INTEGER_BITS,FRACTIONAL_BITS)
#define a19  FIXED(-2.37128142538004,  INTEGER_BITS,FRACTIONAL_BITS)
#define a20  FIXED(0.751562675072692,  INTEGER_BITS,FRACTIONAL_BITS)
#define b0  FIXED(0.010682695047885,  INTEGER_BITS,FRACTIONAL_BITS)
#define b1  FIXED(-0.0319317945313934,  INTEGER_BITS,FRACTIONAL_BITS)
#define b2  FIXED(0.137985810508501,  INTEGER_BITS,FRACTIONAL_BITS)
#define b3  FIXED(-0.293011163687785,  INTEGER_BITS,FRACTIONAL_BITS)
#define b4  FIXED(0.7214478529803,  INTEGER_BITS,FRACTIONAL_BITS)
#define b5  FIXED(-1.18408684753947,  INTEGER_BITS,FRACTIONAL_BITS)
#define b6  FIXED(2.10260758313083,  INTEGER_BITS,FRACTIONAL_BITS)
#define b7  FIXED(-2.77632706845333,  INTEGER_BITS,FRACTIONAL_BITS)
#define b8  FIXED(3.85810329753079,  INTEGER_BITS,FRACTIONAL_BITS)
#define b9  FIXED(-4.17223897191969,  INTEGER_BITS,FRACTIONAL_BITS)
#define b10  FIXED(4.69928090382868,  INTEGER_BITS,FRACTIONAL_BITS)
#define b11  FIXED(-4.1722389719197,  INTEGER_BITS,FRACTIONAL_BITS)
#define b12  FIXED(3.85810329753078,  INTEGER_BITS,FRACTIONAL_BITS)
#define b13  FIXED(-2.77632706845332,  INTEGER_BITS,FRACTIONAL_BITS)
#define b14  FIXED(2.10260758313084,  INTEGER_BITS,FRACTIONAL_BITS)
#define b15  FIXED(-1.18408684753947,  INTEGER_BITS,FRACTIONAL_BITS)
#define b16  FIXED(0.7214478529803,  INTEGER_BITS,FRACTIONAL_BITS)
#define b17  FIXED(-0.293011163687786,  INTEGER_BITS,FRACTIONAL_BITS)
#define b18  FIXED(0.137985810508501,  INTEGER_BITS,FRACTIONAL_BITS)
#define b19  FIXED(-0.0319317945313934,  INTEGER_BITS,FRACTIONAL_BITS)
#define b20  FIXED(0.010682695047885,  INTEGER_BITS,FRACTIONAL_BITS)

#define ORDER 10
#define STAGES 1
#define MAX_DEPTH 10

#define B {b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20}
#define A {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20}
#define UPPER_INPUT_LIMIT FIXED(178.691288411089,   INTEGER_BITS,FRACTIONAL_BITS)
#define LOWER_INPUT_LIMIT FIXED(-178.691288411089,   INTEGER_BITS,FRACTIONAL_BITS)
#define UPPER_OUTPUT_LIMIT (FIXED(1024.0,  INTEGER_BITS,FRACTIONAL_BITS) -1)
#define LOWER_OUTPUT_LIMIT FIXED(-1024.0, INTEGER_BITS,FRACTIONAL_BITS)
#endif // __FILTER_H