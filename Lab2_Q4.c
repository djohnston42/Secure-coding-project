/********************************************************/
/*    ELE8094 SwA Assessed Practical 2 Q4 2015          */
/*                                                      */
/* The following code accepts an 8 character            */
/* password from the user that must contain only        */
/* alphanumeric characters.                             */
/* Write a function to sanitise the input               */
/********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define passwordLen 9
#define error 1
#define ok 0

int getPassword(char password[passwordLen]);
int sanitizer (char *pwd);

int main(void)
{
  	char password[passwordLen] = {0};
  	
	while (getPassword(password) != ok)
	{
		/* keep checking password is right length until it finally is */
		printf("Wrong length. Try again.\n\n");
	}
	
	//printf("Entered password was %s (%d)\n", password, (int)strlen(password));
  	
	/* call saniziter() and check return value */
	if(sanitizer(password) == ok)
	{
		/* sanitizer() returned 'ok' */
        	printf("password ok\n");
        }
        else
	{
		/* sanitizer() returned 'error' */
        	printf("wrong password format\n");
	}
  	
	return ok;

}

int getPassword(char password[passwordLen])
{
	int returnValue;

	
  	fputs("Enter Password of 8 Characters Containing Only Letters and Numbers\n", stdout);
  	
	fgets(password, 20, stdin);
	/*copies 20 chars from stdin incl enter char*/
	if (strlen(password) != passwordLen)
	{
		returnValue = error;
	}
	else
	{
		returnValue = ok;
		
	
  	}
  	
	return returnValue;
}

int sanitizer (char *pwd)
{
        int validLen = 9;
        int pwdLen = strlen(pwd);
        char validchars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char validnums[] = "0123456789\n";// /n included as fgets counts it as a char in the input
        int isValid = 0;
	int i,j;
	int returnValue = 0;

        if (strlen(pwd) == validLen) 
	{
                for (i=0; i<pwdLen; i++)
		{
			/* reset flag for each iteration of password character */
                	isValid =0;

			/* compare current character in 'password' to each character in 'validchars' */
                        for (j=0; j<strlen(validchars); j++)
			{
                                if (pwd[i] == validchars[j])
				{
					/* password character is valid */
                                	isValid = 1;
                                }
                        }

			/* compare current character in 'password' to each character in 'validnums' */
                        for (j=0; j<strlen(validnums); j++ )
			{
                                if(pwd[i] == validnums[j])
				{
					/* password character is valid */
                                	isValid = 1;
                                }
                        }

			/* check to see if isValid flag has been set (it should have been) */
			if (isValid == 0)
			{
				/* returnValue is what is returned - set it to 'error' */
				returnValue = error;
				break;
                	}

			/* go to next password character, and reset isValid flag to 0 */
		}
	}
	else
 	{
		/* length was wrong, don't even bother checking contents */
		returnValue = error;
	}

	/* if each password character was valid, returnValue won't have been set to 'error' earlier; it will still be 'ok' */
       	return returnValue;
}


