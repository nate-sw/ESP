#include <avr/io.h>
/*

Program: ESP Lab 4 part 2
Author: Nathanael Simard-White
Date: 17/02/2022

*/

/* Pins 23, 26, 27, 29 & 31 = hi */

int main(void)
{
    DDRC = 0xFF;
    DDRE = 0xF;

    while(1)
    {
        PORTC = 0b01100100;
        PORTE = 0b0101;

    }
}
