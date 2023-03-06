#include <stdio.h>
//#include <conio.h> /* Disable if compiled on UNIX based system */
#define MAX 64


/*
Program: Lab 7 Part 1
Author: nsw
Date: 2023/03/06
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab07
MOTD: 
*/

int main(void)
{
	int ctr, upcnt, lwcnt, numcnt;
	char key;

	ctr = 0;
    upcnt = 0;
    lwcnt = 0;
    numcnt = 0;

	printf("\nEnter sentence [Max 64 characters]> ");

	for(ctr=0; ctr<=MAX; ctr++)
	{
		key = getchar(); /* Disable if compiled on DOS based system */
        // key = getche(); /* Disable if compiled on UNIX based system */
		if((key>='A')&&(key<='Z'))
        {
            upcnt++;
        }
        if((key>='a')&&(key<='z'))
        {
            lwcnt++;
        }

        if((key>='0')&&(key<='9'))
        {
            numcnt++;
        }

		if(key==0x0A)
        {
            break;
        }
	}

    if((upcnt+lwcnt+numcnt) > MAX)
    {
        printf("\n\nSentence must be less than 64 characters. Try again.\n");
    }

    else
    {
        printf("\n\nAmount of uppercase characters entered = %d",upcnt);
        printf("\nAmount of lowercase characters entered = %d",lwcnt);
        printf("\nAmount of numerical characters entered = %d\n",numcnt);
    }
    return 0;
}
