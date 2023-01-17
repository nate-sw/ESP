#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


/*

Program: Lab 11 Part 1
Author: Nathanael Simard-White
Date: 14/04/2022
MOTD: You can tune a guitar but you can't tuna fish

*/


int bcd2led();

int main(void)
{
  DDRA = 0xFF;
  DDRE = 0xFF;


  int dis;

  while(1)
  {
    dis = bcd2led();


    PORTA = dis;
    PORTE = 0x02;
  }
  return 0;
}

int bcd2led(int num)
{
  int ipt;
  ipt = 0b0100;


    switch(ipt)
    {
      case 0:
        num = 0x3F;
      break;

      case 1:
        num = 0x06;
      break;

      case 2:
        num = 0x5B;
      break;

      case 3:
        num = 0x4F;
      break;

      case 4:
        num = 0x66;
      break;

      case 5:
        num = 0x6D;
      break;

      case 6:
        num = 0x7C;
      break;

      case 7:
        num = 0x07;
      break;

      case 8:
        num = 0x7F;
      break;

      case 9:
        num = 0x67;
      break;
    }
  return num;
}






