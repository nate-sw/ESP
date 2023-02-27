#include <stdio.h>
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


/*
Program: Lab 6 Part 2
Author: nsw
Date: 2023/02/27
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab6
MOTD: Dragonet fish are benthic organisms, spending most of their life 200m below sea level.

*/

int main(void)
{
   int clk;
   DDRA = 0xFF;


   while(1)
   {
      clk = 0;
      do
      {

      PORTA = clk;
      _delay_ms(1000);
      clk++;
      
      }while(clk<10);
   }

}