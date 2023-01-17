#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define MAX 54
#define CR 0x0A
/*

Program: Lab 7 Question 2
Author: Nathanael Simard-White
Date: 18/03/2022
MOTD: Luca Brasi sleeps with the fishes.

*/


int main(void)
{
	int ctr, upcnt = 0, lwcnt=0, numcnt=0;
	char key;

	ctr = 0;

	printf("\nEnter sentence > ");

	for(ctr=0; ctr<=MAX; ctr++)
	{
		key = getchar();
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

		if(key==CR)
        {
            break;
        }
	}
    printf("\n\nAmount of uppercase characters entered = %d",upcnt);
    printf("\nAmount of lowercase characters entered = %d",lwcnt);
    printf("\nAmount of numerical characters entered = %d",numcnt);

    return 0;
}

