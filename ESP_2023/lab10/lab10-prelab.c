#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>



/*
Program: Lab 10 Prelab
Author: nsw
Date: 2023/04/03
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab10
MOTD: It's joever
*/

int main(void)
{
    int num;
    DDRA = 0xFF;
    DDRB = 0xFF;

    while(1)
    {
        num = 0x04;
        PORTA = num;
        PORTB = 0x10;
        _delay_ms(1.0);
    }
}