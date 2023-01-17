#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 5 Part 2
Author: Nathanael Simard-White
Date: 02/03/2022
MOTD: I could really go for a sandwich right about now.

*/

int main(void)
{

    DDRA = 0xFF;
    int ctr=0;

    while(1)
    {
        do
        {
        PORTA = ctr;
        _delay_ms(1);
        ctr++;

        }
        while(ctr<16);
    }
}
