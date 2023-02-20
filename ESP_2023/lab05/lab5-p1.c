#include <stdio.h>
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


/*
Program: Lab 5 Part 1
Author: nsw
Date: 2023/02/20
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab5
MOTD: Pufferfish are among the most poisonous vertebrates in the world.

*/

int main(void)
{
   
   DDRA = 0xFF;

   while(1)
   {

        PORTA = 0x41;
        _delay_ms(8.5);
        PORTA = 0x82;
        _delay_ms(9.3);
        PORTA = 0x14;
        _delay_ms(7.7);
        PORTA = 0x28;
        _delay_ms(10.5);

   }

    return 0;

}