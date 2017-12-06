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

#include "filterChecking.h"
#include "filterSASS.h"
#include "stdio.h"

int __filterChecking(unsigned int depth)
{

	long x[depth];

	if (filterSASS(depth, x))
	{
		printf("Counterexample: { ");
		int i = 0;
		for (;i < depth; ++i)
			printf("%ld, ",x[i]);
		printf("}\n");
		return 0;
	}

	return 1;
}

int filterChecking()
{

	int d = 1;
	for (; d <= MAX_DEPTH; ++d)
	{
		if (!__filterChecking(d))
			return 0;
	}

	return 1;
}
