#include <stdio.h>
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


/*
Program: Lab 6 Part 1
Author: nsw
Date: 2023/02/27
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab6
MOTD: Dragonet fish are benthic organisms, spending most of their life 200m below sea level.

*/

int main(void)
{
   
   DDRA = 0xFF;

    while(1)
    {

        PORTA = 0x04;

    }

}