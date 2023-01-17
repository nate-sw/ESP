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
#define HEXA 0x77
#define HEXB 0x7C
#define HEXC 0x39
#define HEXD 0x5E
#define HEXE 0x79
#define HEXF 0x71

/*

Program: Lab 9 Part 4
Author: Nathanael Simard-White
Date: 31/03/2022
MOTD: Despite what their name may suggest, catfish, are in fact not cats.

*/

int main(void)
{
  int msd, lsd, ctr/* dis*/;
  int ledpat[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
  DDRA = 0xFF;
  DDRE = 0xFF;


  while(1)
  {
     for(msd=0;  msd<16; msd++)
    {
      for(lsd=0; lsd<16; lsd++)
      {

        for(ctr=0; ctr<=100; ctr++)
        {
          PORTE=0x01;
          PORTA=ledpat[msd];
          _delay_ms(4);
          PORTE=0x02;
          PORTA=ledpat[lsd];
          _delay_ms(4);
          PORTA=0x00;
          _delay_ms(2);
        }
      }
    }
  }
}
