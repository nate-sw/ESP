#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

/*The Following defines have been modified as the output
at  PORTC was wired in reverse*/
#define ZERO 0xFC
#define ONE 0x60
#define TWO 0xDB
#define THREE 0xF2
#define FOUR 0x66
#define FIVE 0xB6

/*
Program: Lab 8 Part 2
Author: nsw
Date: 2023/03/20
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab08
MOTD: 
*/

int main(void)
{
    int msb, lsb;
    DDRA = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;
    
    while(1)
    {
        msb = 0;
        lsb = 0;
        for(msb=0; msb<6; msb++)
        {
            if(msb == 0)
                PORTC = ZERO;
            if(msb == 1)
                PORTC = ONE;
            if(msb == 2)
                PORTC = TWO;
            if(msb == 3)
                PORTC = THREE;
            if(msb == 4)
                PORTC = FOUR;
            if(msb == 5)
                PORTC = FIVE;

            for(lsb=0; lsb<10; lsb++)
            {
                PORTA = lsb;
                _delay_ms(1000);
            }
        }
    }
}