#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#define ZERO 0x3F
#define ONE 0x06
#define TWO 0x5B
#define THREE 0x4F
#define FOUR 0x66
#define FIVE 0x6D
#define SIX 0x7D
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE 0x67

/*

Program: Lab 9 Part 2
Author: Nathanael Simard-White
Date: 31/03/2022
MOTD: Despite what their name may suggest, catfish, are in fact not cats.

*/

int main(void)
{
  int num, msd=SEVEN, lsd=FOUR, ctr;
  DDRA = 0xFF;
  DDRE = 0xFF;

  while(1)
  {

    for(ctr=0; ctr<=100; ctr++)
    {
      num=msd;
      PORTE=0x01;
      PORTA=num;
      _delay_ms(4);
      PORTA=0x00;
      PORTE=0x02;
      num=lsd;
      PORTA=num;
      _delay_ms(4);
      PORTA=0x00;
      _delay_ms(2);
    }
  }
}
