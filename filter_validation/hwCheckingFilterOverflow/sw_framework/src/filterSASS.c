#include "filterSASS.h"
#include "filterEval.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include <limits.h>

long population[PARTICLES][MAX_DEPTH];

void printPopulation(unsigned int depth)
{
	printf("\n----------------------\n");
	unsigned int i = 0;
	for (; i < PARTICLES; ++i)
	{
		printf("%d - [ ", i);
		unsigned int j = 0;
		for (; j < depth; ++j)
		{
			printf("%ld ", population[i][j]);
		}
		printf("] = %ld\n", filterEval(depth, population[i]));
		fflush(stdout);
	}
}

void randomPopulation(unsigned int depth)
{
	unsigned int i = 0;
	for (; i < PARTICLES; ++i)
	{
		unsigned int j = 0;
		for (; j < depth; ++j)
		{
			population[i][j] = (rand() % (UPPER_INPUT_LIMIT - LOWER_INPUT_LIMIT)) + LOWER_INPUT_LIMIT;
		}
	}
}

void copy(unsigned int depth, long dest[], long orig[])
{
	unsigned int i = 0;
	for (; i < depth; ++i)
	{
		dest[i] = orig[i];
	}
}

int filterSASS(unsigned int depth, long x[])
{
	int solved = 0;

	unsigned int restarts = 0;

	for (; (restarts < MAX_RESTARTS) && !solved; ++restarts)
	{
		solved = 0;

		randomPopulation(depth);

		unsigned int iter = 0;
		for (; iter < MAX_ITERATIONS && !solved; ++iter)
		{
			unsigned int p = 0;
			for (; p < PARTICLES && !solved; ++p)
			{
				unsigned int s;
				do s = rand() % PARTICLES; while(s==p);
				long current[depth];

				memcpy(current, population[p], depth*sizeof(long));

				long e = filterEval(depth, current);

				if (e == 0) solved = 1; // stop criterion

				unsigned int i = 0;
				for(i = 0; i < depth && !solved; ++i)
				{
					long smax = abs(current[i] - population[s][i]);
					long r = smax > 0 ? rand()%(smax<<1) - smax : 0;
					current[i] += r;
					if (current[i] > UPPER_INPUT_LIMIT) current[i] = UPPER_INPUT_LIMIT;
					if (current[i] < LOWER_INPUT_LIMIT) current[i] = LOWER_INPUT_LIMIT;
				}

				long currentEval = filterEval(depth, current);

				if (currentEval < e)
				{
					memcpy(population[p], current,depth*sizeof(long));
				}
			}
		}
	}

	long bestEval = LONG_MAX;

	unsigned int p = 0;
	for (; p < PARTICLES; ++p)
	{
		long e = filterEval(depth,population[p]);
		if ( e < bestEval)
		{
			bestEval = e;
			memcpy(x,population[p],depth*sizeof(long));
		}
	}

	if (bestEval == 0)
		return 1;
	else
		return 0;
}

