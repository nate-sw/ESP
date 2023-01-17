#include <avr/io.h>
/*

Program: ESP Lab 4 part 2
Author: Nathanael Simard-White
Date: 17/02/2022

*/

/* Pins 23, 26, 27, 29 & 31 = hi */

int main(void)
{
    /* Initialize the Data Direction register for Port A (PA0 - PA7) as an output */
    DDRA = 0xFF;

    while(1)
    {
        PORTA = 0x00;

    DDRB = 0xFF;

    while(1)
    {
        PORTB = 0x00;

}
