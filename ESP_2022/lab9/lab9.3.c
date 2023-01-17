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

Program: Lab 9 Part 3
Author: Nathanael Simard-White
Date: 31/03/2022
MOTD: Despite what their name may suggest, catfish, are in fact not cats.

*/

int main(void)
{
  int dis, ctr;
  DDRA = 0xFF;
  DDRD = 0x00;
  DDRE = 0xFF;


  while(1)
  {
     for(dis=0;  dis<=1; dis++)
    {
      switch(dis)
      {
        case 0: PORTE = 0x01; break;
        case 1: PORTE = 0x02; break;
      }
        for(ctr=0; ctr<=6; ctr++)
        {
          switch(ctr)
          {
            case 0: PORTA = 0x01; break;
            case 1: PORTA = 0x02; break;
            case 2: PORTA = 0x04; break;
            case 3: PORTA = 0x08; break;
            case 4: PORTA = 0x10; break;
            case 5: PORTA = 0x20; break;
            case 6: PORTA = 0x40; break;
          }
          //Variable interval logic

          if((PIND & 0x03) == 0x00)
          {
            _delay_ms(500);
          }
          else if((PIND & 0x03) == 0x01)
          {
            _delay_ms(1000);
          }
          else if((PIND & 0x03) == 0x02)
          {
            _delay_ms(1500);
          }
          else if((PIND & 0x03) == 0x03)
          {
            _delay_ms(2000);
          }

        }
    }
  }
}
