#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

#include "fut_driver.h"

void* futConfig_base;
void* futOutput_base;

int main(){
  int i=0;
  FILE* fout;


  int fd = open("/dev/mem", (O_RDWR|O_SYNC));
  futConfig_base = mmap(NULL,FUT_CONFIG_SPAN,(PROT_READ|PROT_WRITE),MAP_SHARED,fd,FUT_CONFIG_ADDR);
  futOutput_base = mmap(NULL,FUT_OUTPUTS_SPAN,(PROT_READ|PROT_WRITE),MAP_SHARED,fd,FUT_OUTPUTS_ADDR);

  if (futConfig_base == MAP_FAILED) {
	close(fd);
	perror("Error mmapping the file");
	exit(EXIT_FAILURE);
    }
  uint16_t *outputs;
  uint32_t *input;

  int overf = 0;
  
  //HP2C_D10_F6 CounterExample from framework
  uint32_t inputs[10] = {112, 156, -176, -176, -176, 172, 176, -176, -176, 175};
  //uint32_t inputs[10] = {0xFFC9, 0x37, 0x37, 0x37, 0x37, 6, 7, 8, 9, 10};
  //uint32_t inputs[10] = {0x0, 0x0, 0x0, 0x0, 0x0, 6, 7, 8, 9, 10};
  
  setInputs(futConfig_base, inputs, 10);
  input = getInputs(futConfig_base);
  fireFUT(futConfig_base);
  freeFUT(futConfig_base);
  overf = checkOverflow(futConfig_base);
  outputs = getOutputs(futOutput_base);

  int* var = (int*)futConfig_base; 
  printf("CONFIG: %x\n", var[0]); 
  for (i=0; i < 10; i++)
    printf("filter_output[%i] = %x  ---- input[%i] = %x --- overflow = %i\n", i,outputs[i], i, input[i], overf);

}

