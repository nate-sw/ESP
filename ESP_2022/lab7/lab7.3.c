#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 7 Part 3
Author: Nathanael Simard-White
Date: 10/03/2022
MOTD: So long, and thanks for all the fish

*/



int main(void)
{
  int ctr, minctr;
  DDRA = 0xFF;
  DDRC = 0xFF;

    for(minctr=0;  minctr<=5; minctr++)
    {

      switch(minctr)
      {
        case 0:
          PORTC = 0x3F;
          break;

        case 1:
          PORTC = 0x06;
          break;

        case 2:
          PORTC = 0x5B;
          break;

        case 3:
          PORTC = 0x4F;
          break;

        case 4:
          PORTC = 0x66;
          break;

        case 5:
          PORTC = 0x6D;
          minctr=(-1);
          break;
      }

      for(ctr=0; ctr<=9; ctr++)
      {

          PORTA = ctr;
        _delay_ms(1000);
      }
    }
}

