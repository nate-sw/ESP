#include <stdio.h>
#include <math.h>


/*
Program: Lab 3 Part 3
Author: nsw
Date: 2023/02/06
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab3
MOTD: The heaviest Sunfish ever caught weighed approximately 2745kg.

Program: The purpose of the following program is to perform 
basic logic decisions using if() statements.

*/

int main(){

    char c;
    int msb, lsb;

    printf("\nPlease insert a character> ");
    scanf("%c", &c);

    msb = (c & 0xF0)>>4;
    lsb = c & 0x0F;


    if(msb>lsb){
        printf("\nFor character '%c', it's msb '%i', is greater than it's lsb '%i'.\n", c, msb, lsb);

    }

    if(msb<lsb){
        printf("\nFor character '%c', it's lsb '%i', is greater than it's msb '%i'.\n", c, lsb, msb);

    }

    if(msb==lsb){
        printf("\nFor character '%c', it's lsb '%i' and it's msb '%i' are equal.\n", c, lsb, msb);

    }

    return 0;
}