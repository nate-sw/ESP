#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

//Hex values for correcponding digits on 7-segment display

#define ZERO 0x3F
#define ONE 0x06
#define TWO 0x5B
#define THREE 0x4F
#define FOUR 0x66
#define FIVE 0x6D
/*

Program: Lab 7 Part 4
Author: Nathanael Simard-White
Date: 14/03/2022
MOTD: You can teach a man to fish, but you can't teach a fish to man.

*/

int main(void)
{
  int ctr, minctr;
  DDRA = 0xFF;
  DDRC = 0xFF;
  DDRD = 0x00;
  ctr=0;
  minctr=-1;

      do
      {

        //Startup Logic

      if(((PIND & 0x08) == 0x08) & (minctr==-1)) //Displays starts at 59 if set to countdown at startup
        {
        minctr=5;
        }
      else if(((PIND & 0x08) == 0x00) & (minctr==-1)) //Displays start at 00 if set to countup at startup
      {
        minctr=0;
      }

      //ATmega8515 driven 7-segment display

        switch(minctr)
        {
          case 0: PORTC = ZERO; break;
          case 1: PORTC = ONE; break;
          case 2: PORTC = TWO; break;
          case 3: PORTC = THREE; break;
          case 4: PORTC = FOUR; break;
          case 5: PORTC = FIVE; break;
        }
        if((PIND & 0x08) == 0x08)
        {
          ctr=9;

        }
        else
        {
          ctr=0;
        }

        do
        {
          if((PIND & 0x40) == 0x40)  //Reset Displays
          {
            ctr=-1;
            PORTA=0x00;
            minctr=0;
            PORTC=ZERO;
          }
          else
          {
            PORTA = ctr;
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

          if((PIND & 0x08) == 0x08)
          {
            ctr=ctr-1;
          }
          else
          {
            ctr=ctr+1;
          }
        }
        while((ctr<=9)&&(ctr>=0));

        if((PIND & 0x08) == 0x08)
        {
          if(minctr<=0)
          {
            minctr=5;
          }
          else
          {
          minctr=minctr-1;
          }
        }
        else
        {
          if(minctr==5)
          {
            minctr=0;
          }
          else
          {
          minctr++;
          }
        }
    }
    while((minctr<=5)&&(minctr>=0));
}
