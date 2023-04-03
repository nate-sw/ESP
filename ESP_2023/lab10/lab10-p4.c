#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>



/*
Program: Lab 10 Part 4
Author: nsw
Date: 2023/04/03
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab10
MOTD: It's joever
*/

int main(void)
{
    int msd, lsd, num, clk, max;
    DDRA = 0xFF;
    DDRB = 0xFF;
    DDRD = 0X00;

    msd = 0;
    lsd = 0;
    num = 0;
    max = 10;

    while(1){

        for(msd=0; msd<max; msd++)
        {
            for(lsd=0; lsd<10; lsd++)
            {
                for(clk=0; clk<100; clk++)
                {
                    num = msd + 0x10;
                    PORTA = num;
                    _delay_ms(5);
                    num = lsd + 0x20;
                    PORTA = num;
                    _delay_ms(5);
                    PORTA = 0x00;
                    
                    if((PIND & 0x04) == 0x04)
                        max = 6;
                    else
                        max = 10;
                    
                    if((PIND & 0x80) == 0x80)
                    {
                        msd = 0;
                        lsd = 0;
                    }
                }
            }
        } 
    }
}