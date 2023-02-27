#include <stdio.h>
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


/*
Program: Lab 6 Part 4
Author: nsw
Date: 2023/02/27
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab6
MOTD: Dragonet fish are benthic organisms, spending most of their life 200m below sea level.

*/

int main(void)
{
   int clk, rst;
   rst = 0;



   DDRA = 0xFF;
   DDRD = 0x00;
   

   while(1)
   {
      
      clk = rst;
      
      do
      {
         
         PORTA = clk;
         _delay_ms(1000);

         if((PIND & 0x40) == 0x40)
         {
            clk--;
            rst = 9;

            if((PIND & 0x80) == 0x80)
            {
               clk = rst;
            }
         }
         else
         {
            clk++;
            rst = 0;

            if(PIND == 0x80)
            {
               clk = rst;
            }
         }

      }while(clk<=9 && clk>=0);
   }
}