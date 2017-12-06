#include "fut_driver.h"

void fireFUT(void* mem)
{
  *((int*)((mem) + FUT_CONFIG_FIRE_OFFSET)) = 1;
}

void freeFUT(void* mem)
{
  *((int*)((mem) + FUT_CONFIG_FIRE_OFFSET)) = 0;
}

uint16_t* getOutputs(void* mem)
{
  uint16_t *fut_output = (uint16_t*) (mem);
  return fut_output;
}

uint32_t* getInputs(void* mem)
{
	uint32_t *fut_input = (uint32_t*) ((mem) + FUT_CONFIG_INPUTS_OFFSET);
        return fut_input;
}	

void setInputs(void* mem, uint32_t* inputs, int nInputs)
{
	int i = 0;
	for (i=0; i < nInputs; i++)
	{
		*((uint32_t*)((mem) + FUT_CONFIG_INPUTS_OFFSET + i*4)) = inputs[i];
	}	
}

int checkOverflow(void* mem)
{
  if (*((uint32_t*) mem) & OVERFLOW_MASK) return 1;
  else return 0;
}


