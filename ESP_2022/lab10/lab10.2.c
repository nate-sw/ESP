#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#define MAX 32

/*

Program: Lab 10 Part 2
Author: Nathanael Simard-White
Date: 07/04/2022
MOTD: Do fish know they are in water, or do they think that they can fly?

*/

int main(void)
{
  int ctr, x, dly;

  char asci[27] = {"abcdefghijklmnopqrstuvwxyz "};
  char ledpat[27] = {0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x6F, 0x74, 0x30, 0x1E, 0x70, 0x38, 0x15, \
  0x54, 0x5C, 0x73, 0x67, 0x50, 0x6D, 0x78, 0x3E, 0x1C, 0x2A, 0x46, 0x6E, 0x52, 0x0};
  char msg[32]={"digital electronics rocks       "};
  char conv[32];

  DDRA = 0xFF;
  DDRD = 0x00;


  while(1)
  {
    for(x=0; x<32; x++)
    {
      for(ctr=0; ctr<27; ctr++)
      {
        dly=PIND&0x03;

        if(msg[x] == asci[ctr])
        {
          conv[x]=ledpat[ctr];
        }
      }
      PORTA = conv[x];
      switch(dly)
      {
        case(1):_delay_ms(400.0);
          break;

        case(2):_delay_ms(600.0);
          break;

        case(3):_delay_ms(800.0);
          break;

        default:_delay_ms(200.0);
      }
    }
  }
}







