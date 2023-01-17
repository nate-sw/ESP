#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 6 Part 1
Author: Nathanael Simard-White
Date: 03/03/2022
MOTD: Do fish know about the world outside of the water?

*/

int main(void)
{
    DDRA = 0xFF;


    while(1)
    {
    PORTA = 0x05;
    }

}
