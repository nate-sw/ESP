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
#define A 0x77
#define B 0x7C
#define C 0x39
#define D 0x5E
#define E 0x79
#define F 0x71


/*
Program: Lab 11.2 Prelab
Author: nsw
Date: 2023/04/16
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab11
MOTD: Test
*/

int main(void)
{
    int msd, ctd, lsd, clk;
    DDRA = 0xFF;
    DDRC = 0xFF;

    msd = FIVE;
    ctd = SEVEN;
    lsd = FOUR;

    while(1){
        for(clk=0; clk<50; clk++)
        {
            _delay_ms(5);
            PORTA = 0x20;
            PORTC = msd;
            _delay_ms(5);
            PORTA = 0x40;
            PORTC = ctd;
            _delay_ms(5);
            PORTA = 0x80;
            PORTC = lsd;
            _delay_ms(5);
            PORTA = 0x00;
            PORTC = 0x00;

        }
    }

}
