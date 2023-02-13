#include <stdio.h>
#include <avr/io.h>


/*
Program: Lab 4 Part 1
Author: nsw
Date: 2023/02/13
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab4
MOTD: Cladistically, Tetrapods are cosidered fish.

*/

int main(void)
{
   
    DDRC = 0xFF;

    while(1){
        PORTC = 0xA5;

    }
    
    /*The output value, 0xA5, corresponds to the desired
    output of pins 21, 23, 26 & 28 being set to high whilst
    all other pins on port C are set to low.*/

}