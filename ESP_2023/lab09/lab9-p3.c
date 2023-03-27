#include <stdio.h>
#include <conio.h> /* Will not function if compiled on UNIX based system */
#define MAX 64


/*
Program: Lab 9 Part 3
Author: nsw
Date: 2023/03/27
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab09
MOTD: 
*/

int main(void)
{
	int ctr, chk, alphanum, nonal;
	char key;
    char og[MAX]={};
    char mod[MAX]={};

	ctr = 0;
    chk = 0;
    alphanum = 0;
    nonal = 0;


	printf("\nEnter ASCII message [Max 64 characters]> ");


	for(ctr=0; ctr<=MAX; ctr++)
	{

        key = getche(); /* Will not function if compiled on UNIX based system */

		if(key == 0x08) /* Prevents Backspace from being input into array */
			ctr = ctr-1;
		
        og[ctr] = key;
        
        
		if((key>='A')&&(key<='Z')||(key>='a')&&(key<='z')||(key>='0')&&(key<='9'))
        {
            alphanum++;

            if((key>='A')&&(key<='Z'))
            {
                mod[chk] = og[ctr] + 0x20;
                chk++;
            }
            else if((key>='a')&&(key<='z'))
            {
                mod[chk] = og[ctr] - 0x20;
                chk++;
            }
            else if((key>='0')&&(key<='9'))
            {
                mod[chk] = og[ctr];
                chk++;
            }
            
        
        }
        else
        {
            if((key=='!')||(key=='?')||(key==',')||(key=='.'))
            {
                mod[chk] = og[ctr];
                chk++;
			}
			else if(key==0x20)
            {
                mod[chk] = og[ctr];
                chk++;
            }
			else if((key == 0x08)||(key == 0x0D))
			{
				chk=chk;
				nonal=nonal;
			}
            else
                nonal++;

        }

		if(key==0x0D)
        {
            break;
        }
	}


    printf("\n\nOriginal message >> %s",og);

    printf("\n\nModified message >> %s",mod);

    printf("\n\nTotal alphanumeric characters = %d",alphanum);
    printf("\nTotal non-alpha striped = %d",nonal);

    return 0;
}