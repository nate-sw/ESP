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
Program: Lab 8 Part 3
Author: nsw
Date: 2023/03/20
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab08
MOTD: She's a regular combination on the Wabash Cannonball
*/

int main(void)
{
    int lsb, msb;
    DDRA = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;
    lsb=0;
    msb=-1;

    do
    {
        if(((PIND & 0x40) == 0x40) & (msb==-1))
        {
            msb=5;
        }
        else if(((PIND & 0x40) == 0x00) & (msb==-1))
        {
            msb=0;
        }

      //ATmega8515 driven 7-segment display

        switch(msb)
        {
            case 0: PORTC = ZERO; break;
            case 1: PORTC = ONE; break;
            case 2: PORTC = TWO; break;
            case 3: PORTC = THREE; break;
            case 4: PORTC = FOUR; break;
            case 5: PORTC = FIVE; break;
        }

        if((PIND & 0x40) == 0x40)
            lsb=9;

        else
            lsb=0;


        do
        {
            if((PIND & 0x80) == 0x80)  //Reset Displays
            {
                lsb=-1;
                PORTA=0x00;
                msb=0;
                PORTC=ZERO;
            }

            else
                PORTA = lsb;

            //Variable interval logic

            if((PIND & 0x03) == 0x00)
                _delay_ms(500);

            else if((PIND & 0x03) == 0x01)
                 _delay_ms(1000);

            else if((PIND & 0x03) == 0x02)
                _delay_ms(1500);

            else if((PIND & 0x03) == 0x03)
                _delay_ms(2000);


            if((PIND & 0x40) == 0x40)
                lsb--;

            else
                lsb++;

        }
        while((lsb<=9)&&(lsb>=0));

        if((PIND & 0x40) == 0x40)
        {
          if(msb<=0)
            msb=5;

          else
            msb--;
        }
        else
        {
            if(msb==5)
                msb=0;
                
            else
                msb++;
        }
    }
    while((msb<=5)&&(msb>=0));
}