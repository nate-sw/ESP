#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*

Program: Lab 7 Part 1
Author: Nathanael Simard-White
Date: 10/03/2022
MOTD: So long, and thanks for all the fish

*/

int main(void)
{

  DDRA = 0xFF; //I'm too lazy to remove the other display, so it's locked at 0
  DDRC = 0xFF;
  DDRD = 0x00;
  while(1)
    {
    PORTC = ~PIND; //Output value is the inverse of input
    PORTA = 0x00;
    }

}
