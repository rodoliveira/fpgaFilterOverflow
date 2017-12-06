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

#ifndef __FILTER_SIMUL_H
#define __FILTER_SIMUL_H

//#define SIGNED_BIT_LIMIT(number, bits) ((number << (sizeof(long)*8 - (bits))) >> (sizeof(long)*8 - (bits)))
#define SIGNED_BIT_LIMIT(number, bits) (number)
#define FIXED(number, i, f) SIGNED_BIT_LIMIT((long)(number * (1 << f) + (number >=0 ? 0.5 : -0.5)), i + f)
#define FIXED_MUL(n1, n2, f) ((n1*n2)>>f)

long filter(long x, long histX[], long histY[]);
long filterSimul(unsigned int depth, long x[]);
long hw_filterSimul(unsigned int depth, long x[]);


#endif // __FILTER_SIMUL_H

