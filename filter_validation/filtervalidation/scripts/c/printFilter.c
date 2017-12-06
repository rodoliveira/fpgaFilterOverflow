#include <stdio.h>
#include "filter.h"

void printVec(int* vec[], int order){
  int count = 0;
  for (count = 0; count < order; count++)
    {
      if (count != order-1)
        printf("%u,",vec[count]);
      else
        printf("%u]\n  ",vec[count]);
    }
}

int main(int argc, char* argv[])
{
  int* coef_out[] = A; 
  int* coef_in[] = B;
  int nfrac_bits = FRACTIONAL_BITS;
  int nint_bits = INTEGER_BITS;
  int order = ORDER + 1;
  int ninputs = MAX_DEPTH;
  int upper_limit = UPPER_OUTPUT_LIMIT;
  int lower_limit = LOWER_OUTPUT_LIMIT;
  
  int count = 0;
  printf("filter:\n  ");
  printf("name: C_TO_VHDL\n  ");
  printf("bits: 16\n  ");
  printf("order: %i\n  ", order);
  printf("coef_in: [");
  printVec(coef_in, order);
  printf("coef_out: [");
  printVec(coef_out, order);
  printf("nbits_frac: %i\n  ", nfrac_bits);
  printf("nbits_int: %i\n  ",nint_bits);
  printf("ninputs: %i\n  ", ninputs);
  printf("uplimit: %i\n  ", upper_limit);
  printf("lwlimit: %i\n  ", lower_limit);
      
}
	 
    
