#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 6 Part 2
Author: Nathanael Simard-White
Date: 03/03/2022
MOTD: Do fish know about the world outside of the water?

*/

int main(void)
{

    int ctr;
    ctr=0;
    DDRA = 0xFF;


    do
    {
        PORTA = 0x00;
        ctr=ctr+1;
        _delay_ms(1000);
        PORTA = 0x01;
        ctr=ctr+1;
        _delay_ms(1000);
        PORTA = 0x02;
        ctr=ctr+1;
        _delay_ms(1000);
        PORTA = 0x03;
        ctr=ctr+1;
        _delay_ms(1000);
        PORTA = 0x04;
        ctr=ctr+1;
        _delay_ms(1000);
        PORTA = 0x05;
        ctr=ctr+1;
        _delay_ms(1000);
        PORTA = 0x06;
        ctr=ctr+1;
        _delay_ms(1000);
        PORTA = 0x07;
        ctr=ctr+1;
        _delay_ms(1000);
        PORTA = 0x08;
        ctr=ctr+1;
        _delay_ms(1000);
        PORTA = 0x09;
        ctr=ctr+1;
        _delay_ms(1000);
        ctr=0;

    }
    while(ctr<10);
}
