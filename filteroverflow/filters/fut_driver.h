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

#define OVERFLOW_MASK 0x01

void* futConfig_base;
void* futOutput_base;

// Dispara filtro
void fireFUT(void* mem);

//Libera filtro
void freeFUT(void* mem);

//Puxa as saidas do filtro
uint16_t* getOutputs(void* mem);

//Puxa as entradas do filtro
uint32_t* getInputs(void* mem);

//Seta as entradas do filtro
void setInputs(void* mem, uint32_t* inputs, int nInputs);

//Checa se houve overflow
int checkOverflow(void* mem);
