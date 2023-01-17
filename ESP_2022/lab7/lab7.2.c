#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 7 Part 2
Author: Nathanael Simard-White
Date: 10/03/2022
MOTD: So long, and thanks for all the fish

*/



int main(void)
{
  int ctr;
  DDRA = 0xFF; //I'm too lazy to remove the other display, so it's locked at 0
  DDRC = 0xFF;



    for(ctr=0; ctr<=5; ctr++)
    {
      switch(ctr)
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
          ctr=(-1);
          break;
      }
      _delay_ms(1000);

    }


}
