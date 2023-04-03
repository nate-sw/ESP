#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>



/*
Program: Lab 10 Part 2
Author: nsw
Date: 2023/04/03
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab10
MOTD: It's joever
*/

int main(void)
{
    int msd, lsd, num, clk;
    DDRA = 0xFF;
    DDRB = 0xFF;

    msd = 7;
    lsd = 4;
    num = 0;

    while(1){
        for(clk=0; clk<100; clk++)
        {
            num = msd + 0x10;
            PORTA = num;
            _delay_ms(25);
            num = lsd + 0x20;
            PORTA = num;
            _delay_ms(25);
            PORTA = 0x00;

        }
    }

}