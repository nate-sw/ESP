#include <stdio.h>
#include <avr/io.h>


/*
Program: Lab 4 Part 3
Author: nsw
Date: 2023/02/13
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab4
MOTD: Cladistically, Tetrapods are cosidered fish.

*/

int main(void)
{
   
    DDRC = 0xFF;
    DDRD = 0x00;
    

    while(1){
        PORTC = PIND;

    }


}