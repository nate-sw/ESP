#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


/*
Program: Lab 12 Part 1 
Author: nsw
Date: 2023/04/24
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab12
MOTD: Template... Response...
*/

int main(void)
{
  int ctr;
  char ledpat[27] = {0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x6F, 0x74, 0x30, 0x1E, 0x70, 0x38, 0x15, \
  0x54, 0x5C, 0x73, 0x67, 0x50, 0x6D, 0x78, 0x3E, 0x1C, 0x2A, 0x46, 0x6E, 0x52};


  DDRA = 0xFF;
  DDRC = 0xFF;

  while(1)
  {
    for(ctr=0; ctr<27; ctr++)
    {
      PORTC = ledpat[ctr];
      PORTA = 0x40;
      _delay_ms(1000);
    }
  }
}