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
#include <assert.h>
#include "filterSimul.h"
#include "filter.h"

void filterVerify(long x[]){

	long y = filterSimul(MAX_DEPTH, x);
        assert(y <= UPPER_OUTPUT_LIMIT && y >= LOWER_OUTPUT_LIMIT);

}


    
