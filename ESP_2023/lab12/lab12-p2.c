#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


/*
Program: Lab 12 Part 2 
Author: nsw
Date: 2023/04/24
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab12
MOTD: Template... Response...
*/

int main(void)
{
  int ctr, x;

  char ascii[39] = {"abcdefghijklmnopqrstuvwxyz0123456789- "}; //Adjusted for aditional characters

  char ledpat[39] = {0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x6F, 0x74, 0x30, 0x1E, 0x70, 0x38, 0x15, \
  0x54, 0x5C, 0x73, 0x67, 0x50, 0x6D, 0x78, 0x3E, 0x1C, 0x2A, 0x46, 0x6E, 0x52, 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x40, 0x00}; //Adjusted for aditional characters

  char msg[48]={"nate simard-white 2032574"};

  char conv[48];


  DDRA = 0xFF;
  DDRC = 0xFF;
  DDRD = 0x00;

  while(1)
  {
    for(x=0; x<48; x++)
    {
      for(ctr=0; ctr<39; ctr++)
      {
        if(msg[x] == ascii[ctr])
          conv[x]=ledpat[ctr];
      }

      if((PIND & 0x03) == 0x01)
        _delay_ms(500);
        
      else if((PIND & 0x03) == 0x02)
        _delay_ms(750);
      
      else if((PIND & 0x03) == 0x03)
        _delay_ms(1000);

      else
          _delay_ms(250);

      PORTC = conv[x];
      PORTA = 0x80;
      
      if(conv[x] + conv[x+1] == 0x00)
        break;

    }

  }
}