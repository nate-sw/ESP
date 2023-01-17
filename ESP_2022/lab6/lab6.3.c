#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 6 Part 3
Author: Nathanael Simard-White
Date: 03/03/2022
MOTD: Do fish know about the world outside of the water?

*/


int main(void)
{

    int ctr;
    DDRA = 0xFF;
    DDRD = 0x00;

    while(1)
    {

      ctr=0;
        do

        {
            if((PIND & 0x40) == 0x40)
            {
            ctr=0;
            PORTD = 0x00;
            }

            else
            {
            PORTA = ctr;
            _delay_ms(1000);
            ctr=ctr+1;
            }
        }
        while(ctr<=9);
    }
}
