#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define ZERO 0x3F
#define ONE 0x06
#define TWO 0x5B
#define THREE 0x4F
#define FOUR 0x66
#define FIVE 0x6D
#define SIX 0x7D
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE 0x67


/*
Program: Lab 9 Part 2
Author: nsw
Date: 2023/03/27
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab09
MOTD: 
*/

int main(void)
{
    int msb, lsb;
    int lednum[10]={ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    DDRA = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;
    
    while(1)
    {
        msb = 0;
        lsb = 0;
        for(msb=0; msb<10; msb++)
        {
            PORTC = lednum[msb];

            for(lsb=0; lsb<10; lsb++)
            {
                PORTA = lsb;
                _delay_ms(1000);
            }
        }
    }
}