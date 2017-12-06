//#define SIGNED_BIT_LIMIT(number, bits) ((number << (sizeof(long)*8 - (bits))) >> (sizeof(long)*8 - (bits)))
#include <stdio.h>
#define SIGNED_BIT_LIMIT(number, bits) (number)
#define FIXED(number, i, f) SIGNED_BIT_LIMIT((long)(number * (1 << f) + (number >=0 ? 0.5 : -0.5)), i + f)
#define FIXED_MUL(n1, n2, f) ((n1*n2)>>f)

int main(){
  printf("%04x\n", SIGNED_BIT_LIMIT(-4,1));
  printf("%04x\n", FIXED(-1.25, 2,2));
}
