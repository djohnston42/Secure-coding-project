/********************************************************/
/*    ELE8094 SwA Assessed Practical 2 Q3 2016          */
/*                                                      */
/* Explain the vulnerability in the                     */
/* code below.  Write code to provide a fix.            */
/********************************************************/
#include <stdio.h>
#include <string.h>

//#define SIZE 10

/*concatinating strings pFirstName and pLastName and copying them into name[SIZE] where SIZE = 10  was causing a buffer overflow as the two strings totaled more than 10 chars, setting the "name" array length to the length of the two strings +1 ensures that enough buffer space is allocated to the resulting concatinated string */

int main(void)
{
  char *pFirstName = "FirstName";
  char *pLastName  = "LastName";
  int len;
  len = strlen(pFirstName) + strlen(pLastName);
  char name[len + 1];
  
  strcat(strcpy(name, pFirstName), pLastName);
  printf("Name: %s\n", name);
 // printf("%x, %x\n", pFirstName, pLastName);
  
 
  return 0;
}
