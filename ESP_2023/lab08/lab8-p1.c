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
Program: Lab 8 Part 1
Author: nsw
Date: 2023/03/20
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab08
MOTD: 
*/

int main(void)
{
    int lsb;
    DDRA = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;

    lsb = 0;
    
    while(1)
    {
        for(lsb=0; lsb<6; lsb++)
        {
            if(lsb == 0)
                PORTC = ZERO;
            if(lsb == 1)
                PORTC = ONE;
            if(lsb == 2)
                PORTC = TWO;
            if(lsb == 3)
                PORTC = THREE;
            if(lsb == 4)
                PORTC = FOUR;
            if(lsb == 5)
                PORTC = FIVE;
            _delay_ms(1000);
        }
    }


}