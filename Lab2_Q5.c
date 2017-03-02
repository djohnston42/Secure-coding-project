/********************************************************/
/*    ELE8094 SwA Assessed Practical 2 Q5 2016          */
/*                                                      */
/* Identify and Explain the vulnerability in the        */
/* code below.  Provide a fix.                          */
/********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAC_ADDRESS_LENGTH 36 
#define LINELENGTH 56         
#define SEPERATOR ':'
//const int MAC_ADDRESS_LENGTH = 36;

int GetMacAddress(char *MacAddress);

int main()
{
  char outPutMacAddress[MAC_ADDRESS_LENGTH];

  if (1 == GetMacAddress(outPutMacAddress))
  {
    printf("Failed to get Mac address\n");
  }
  else
  {
    printf("%s\n", outPutMacAddress);
  }

  return 0;
}


int GetMacAddress(char *MacAddress)
{
  FILE *fp = NULL;
  char line[LINELENGTH];
  unsigned char counter = 1; 
  unsigned char i = 0;
  char *address = NULL;
  
  if (-1 == system("/sbin/ifconfig |grep --binary-files=text HWaddr >macAddress"))
  {
    printf("SYSTEM_ERROR_GET_MAC_ADDRESS_FAILURE\n");
    return 1;
  }
  else
  {
    fp=fopen("macAddress", "r");
    if(NULL == fp)
    {
      printf("Error reading macAddress file\n");
      return 1;
    }
    else
    {
      if (NULL == fgets(line, sizeof(line), fp))
      {
        printf("Error reading line from file - mac adddr\n");
        return 1;
      }
      else
      {
        address = strchr(line, SEPERATOR);
        if (NULL == address)
        {
          printf("Error in line format\n");
          return 1;
        }
        else
        {
	printf("%s\n", line);
          while ((address[counter] != MAC_ADDRESS_LENGTH) && (i < MAC_ADDRESS_LENGTH))
	/*changed condition for address[counter] from !=0 to != MAC_ADDERSS_LENGTH because 
	  counter = 1 and the loop will not terminate and will read beyond the bounds of the 
	  line string*/
          {
            MacAddress[i] = address[counter];
            counter++;
            i++;
          }
        }
      }
      fclose(fp);
    }
  }
  if (-1 == remove("macAddress"))
  {
    printf("Error removing file\n");
    return 1;
  }  
  return 0;
}

