#include <stdio.h>
//#include <conio.h> /* Disable if compiled on UNIX based system */
#define MAX 64


/*
Program: Lab 7 Part 1
Author: nsw
Date: 2023/03/06
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab07
MOTD: 
*/

int main(void)
{
    int mark, tot, avg, gnum, cnuma, cnumb;
    char cnumc, cnumd;

    
    

	printf("\nEnter Course number > ");
    scanf("%d-%d-%c%c", &cnuma, &cnumb, &cnumc, &cnumd);

    mark = 0;
    tot = 0;
    avg = 0;
    gnum = 0;

    printf("\n\nData entry:\n");


    while(1)
    {
        printf("Enter Mark> ");
        scanf("%d", &mark);

        if(mark < 0)
        {
            break;
        }
        if(mark > 100)
        {
            printf("\n**Invalid Value**\n");
        }
        else
        {
            tot = tot + mark;
            gnum++;
            mark = 0;
        }

        

    }

    avg = tot/gnum;

     printf("\n\nStatistics for %d course",cnumb);

    printf("\n\nTotal Marks entered = %d",gnum);
    printf("\nTotal Course average = %d\n",avg);

    return 0;
}
