#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 8 Part 7
Author: Nathanael Simard-White
Date: 24/03/2022
MOTD: The giant grouper is one of the largest extant species of bony fish.

*/

int main(void)
{
  int num, msd, lsd, ctr;
  DDRA = 0xFF;

  while(1)
  {
     for(msd=0;  msd<=5; msd++)
    {
      for(lsd=0; lsd<=9; lsd++)
      {
        for(ctr=0; ctr<=100; ctr++)
        {
          num=msd+0x10;
          PORTA=num;
          _delay_ms(4);
          PORTA=0x00;
          num=lsd+0x20;
          PORTA=num;
          _delay_ms(4);
          PORTA=0x00;
          _delay_ms(2);
        }
      }
    }
  }
}
