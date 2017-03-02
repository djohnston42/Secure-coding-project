/********************************************************/
/*    ELE8094 SwA Assessed Practical 2 Q2 2016          */
/*                                                      */
/* What is the value of result in the code              */
/* Explain the flaw                                     */
/* Define a variable fix and write a statement          */
/* with the correct expression                          */
/********************************************************/
#include <stdio.h>

/* Integer Promotion */

int main(void)
{
  int a = -1;
  int b = 1;
//unsigned integers cannot be compared with integers. Compiler outputs 0;  
  printf("%d\n", a < b);
 
  return 0;
}
