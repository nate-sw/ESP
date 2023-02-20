#include <stdio.h>
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


/*
Program: Lab 5 Part 2
Author: nsw
Date: 2023/02/20
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab5
MOTD: Pufferfish are among the most poisonous vertebrates in the world.

*/

int main(void)
{
   
   DDRC = 0xFF;
   DDRD = 0x00;

   int d;

   while(1)
   {

    d = PIND & 0x0F;
    PORTC = 0X01;

    if(d == 0x0){
        _delay_ms(2);
    }

    else if(d == 0x1){
        _delay_ms(3);
    }

    else if(d == 0x2){
        _delay_ms(4);
    }

    else if(d == 0x4){
        _delay_ms(5);
    }

    else if(d == 0x8){
        _delay_ms(6);
    }

    else{
        _delay_ms(7);
    }

    PORTC = 0X00;
    _delay_ms(2);

   }

    return 0;

}