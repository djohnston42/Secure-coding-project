/********************************************************/
/*    ELE8094 SwA Assessed Practical 2 Q1 2016          */
/*                                                      */
/* What is the value of result in the code              */
/* Explain the flaw                                     */
/* Define a variable fix and write a statement          */
/* with the correct expression                          */
/********************************************************/
#include <stdio.h>


int main(void)
{
  float   a = 23;
  int b = 45;
  float c = 3.1415927;
  float result;
  //division of int 23 with int 45 not possible, changed int a to double. Is now divisible with float c. 
  result = a / b * c;
 // float result2 = a /b;
  printf("The value is %f\n", result);
 // printf("The value is %f", result2);
  return 0;
}
