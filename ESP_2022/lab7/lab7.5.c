#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50000
#define MIN 100
/*

Program: Lab 7 Question 1
Author: Nathanael Simard-White
Date: 18/03/2022
MOTD: Luca Brasi sleeps with the fishes.

*/



int main(void)
{
    int i, sum_o=0, sum_e=0, val;


        printf("\nEnter a value > ");
        scanf("%d", &val);

        if((val>MAX)||(val<MIN))
        {
            printf("\n\nError, invalid entry!");
        }
        else
        {
            for(i=1; i<=val; i++)
            {
                if(i%2==0)
                {
                    sum_e = sum_e + i;
                }
                else
                {
                    sum_o = sum_o + i;
                }

            }
            printf("\n\nSum of all odd numbers = %d", sum_o);
            printf("\n\nSum of all even numbers = %d", sum_e);
        }
    return 0;
}

