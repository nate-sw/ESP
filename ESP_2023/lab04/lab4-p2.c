#include <stdio.h>
#include <avr/io.h>


/*
Program: Lab 4 Part 2
Author: nsw
Date: 2023/02/13
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab4
MOTD: Cladistically, Tetrapods are cosidered fish.

*/

int main(void)
{
   
    DDRC = 0xFF;

    int c = 0xA5;

    while(1){
        PORTC = c;

    }

    /*The output values are the same as the previous task's
    because the integer variable being used has the same value
    as the output value that had previously been set directly
    to port C.*/

}