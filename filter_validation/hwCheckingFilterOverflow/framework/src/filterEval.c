#include "filterEval.h"
#include "filterSimul.h"
#include "filter.h"
#include <math.h>

#define POWER   2.0

/* the penaltyGT function is possible because
 * we are dealing with integers
 */
long penaltyGT(long alpha, long beta)
{
	if (alpha > beta)
	{
		return 0;
	}else{
		register int r = alpha + 1 - beta;
		return pow(r, POWER);
	}
}


long penaltyGE(long alpha, long beta)
{
	if (alpha >= beta)
	{
		return 0;
	}else{
		register int r = alpha - beta;
		return pow(r, POWER);
	}
}

/* the penaltyLT function is possible because
 * we are dealing with integers
 */
long penaltyLT(long alpha, long beta)
{
	if (alpha < beta)
	{
		return 0;
	}else{
		register int r = alpha + 1 - beta;
		return pow(r, POWER);
	}
}

long penaltyLE(long alpha, long beta)
{
	if (alpha <= beta)
	{
		return 0;
	}else{
		register int r = alpha - beta;
		return pow(r, POWER);
	}
}


long filterEval(unsigned int depth, long x[])
{
	long y = hw_filterSimul(depth,x);

	long g = penaltyGE(y, UPPER_OUTPUT_LIMIT+1);
	long l = penaltyLE(y, LOWER_OUTPUT_LIMIT-1);

	if (g < l) return g;
	else return l;

}

