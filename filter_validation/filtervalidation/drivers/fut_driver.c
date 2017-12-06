#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

#define FUT_CONFIG_ADDR 0xFF200000
#define FUT_CONFIG_SPAN 0x10

#define FUT_OUTPUTS_ADDR 0x38000000
#define FUT_OUTPUTS_SPAN 0x100

#define FUT_CONFIG_FIRE_OFFSET 0
#define FUT_CONFIG_INPUTS_OFFSET 4

void* futConfig_base;
void* futOutput_base;

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
void setInputs(void* mem, int* inputs, int nInputs)
{
	int i = 0;
	for (i=0; i < nInputs; i++)
	{
		*((int*)((mem) + FUT_CONFIG_INPUTS_OFFSET + i*4)) = inputs[i];
	}
	
}


int main(){
  int i=0;
  FILE* fout;


  int fd = open("/dev/mem", (O_RDWR|O_SYNC));
  futConfig_base = mmap(NULL,FUT_CONFIG_SPAN,(PROT_READ|PROT_WRITE),MAP_SHARED,fd,FUT_CONFIG_ADDR);
  futOutput_base = mmap(NULL,FUT_OUTPUTS_SPAN,(PROT_READ|PROT_WRITE),MAP_SHARED,fd,FUT_OUTPUTS_ADDR);

  uint16_t *outputs;
  uint32_t *input;

  int inputs[10] = {0xFFCB, 0x37, 0x37, 0x37, 0x37, 6, 7, 8, 9, 10};
  
  setInputs(futConfig_base, inputs, 10);
  input = getInputs(futConfig_base);
  fireFUT(futConfig_base);
  freeFUT(futConfig_base);
  outputs = getOutputs(futOutput_base);

  int* var = (int*)futConfig_base; 
  printf("CONFIG: %x\n", var[0]); 
  for (i=0; i < 10; i++)
    printf("filter_output[%i] = %x  ---- input[%i] = %x\n", i,outputs[i], i, input[i]);

}

