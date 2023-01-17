#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 8 Part 4
Author: Nathanael Simard-White
Date: 24/03/2022
MOTD: The giant grouper is one of the largest extant species of bony fish.

*/

int main(void)
{
  int num;
  DDRA = 0xFF;

  while(1)
    {
    num=4;
    PORTA=num+0x20;
    _delay_ms(1.0);
    }

}
