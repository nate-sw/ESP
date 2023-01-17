#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 8 Part 5
Author: Nathanael Simard-White
Date: 24/03/2022
MOTD: The giant grouper is one of the largest extant species of bony fish.

*/

int main(void)
{
  int num, msd=7, lsd=4, ctr;
  DDRA = 0xFF;
  while(1)
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
