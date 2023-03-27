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
Program: Lab 9 Part 1
Author: nsw
Date: 2023/03/27
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab09
MOTD: 
*/

int main(void)
{
    int ctr = 0;
    int lednum[10]={ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    DDRA = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;
    
    while(1)
    {
        for(ctr=0; ctr<10; ctr++)
        {
            PORTC = lednum[ctr];
            _delay_ms(1000);
        }
    }
}