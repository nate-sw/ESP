#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 5 Part 1
Author: Nathanael Simard-White
Date: 02/03/2022
MOTD: I could really go for a sandwich right about now.

*/

int main(void)
{
    DDRC = 0xFF;


    while(1)
    {
    PORTC = 0x11;
    _delay_ms(8.3);
    PORTC = 0x22;
    _delay_ms(8.3);
    PORTC = 0x44;
    _delay_ms(8.3);
    PORTC = 0x88;
    _delay_ms(8.3);
    }

}
