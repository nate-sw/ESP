#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*
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
#define A 0x77
#define B 0x7C
#define C 0x39
#define D 0x5E
#define E 0x79
#define F 0x71
*/

/*
Program: Lab 11 Part 3 
Author: nsw
Date: 2023/04/13
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab11
MOTD: Tomorrow, the Canadian Pacific and Kansas City Southern will merge to become the only railroad to connect Canada, the US and Mexico
*/

int main(void)
{
    int msd, lsd, clk;
    int dis[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

    DDRA = 0xFF;
    DDRC = 0xFF;

    msd = 0;
    lsd = 0;

    while(1){

        for(msd=0; msd<16; msd++)
        {
            for(lsd=0; lsd<16; lsd++)
            {
                for(clk=0; clk<25; clk++)
                {
                    PORTA = 0x10;
                    PORTC = dis[msd];
                    _delay_ms(5);
                    PORTA = 0x20;
                    PORTC = dis[lsd];
                    _delay_ms(5);
                    PORTA = 0x00;
                    PORTC = 0X00;
                }
            }
        } 
    }

}