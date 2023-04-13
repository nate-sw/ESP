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
/*#define A
#define B
#define C
#define D
#define E
#define F*/


/*
Program: Lab 11 Part 2 
Author: nsw
Date: 2023/04/13
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab11
MOTD: Tomorrow, the Canadian Pacific and Kansas City Southern will merge to become the only railroad to connect Canada, the US and Mexico
*/

int main(void)
{
    int msd, lsd, clk;
    DDRA = 0xFF;
    DDRC = 0xFF;

    msd = SEVEN;
    lsd = FOUR;

    while(1){
        for(clk=0; clk<100; clk++)
        {
            PORTA = 0x10;
            PORTC = msd;
            _delay_ms(10);
            PORTA = 0x00;
            PORTC = 0x00;

        }
    }

}