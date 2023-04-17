#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
/*
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
#define A 0x77
#define B 0x7C
#define C 0x39
#define D 0x5E
#define E 0x79
#define F 0x71
*/

/*
Program: Lab 11.2 Part 2
Author: nsw
Date: 2023/04/17
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/lab11
MOTD: Now we can count to 9999
*/

int main(void)
{   //  msd *   *   lsd
    int d3, d2, d1, d0, clk, max, chk, big, dif, conv;
    int dis[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};

    DDRA = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;

    d3 = 0;
    d2 = 0;
    d1 = 0;
    d0 = 0;

    chk = 0;
    big = 0;
    dif = 0;
    conv = 0;


    max = 6;

    while(1){
        for(d3=0; d3<max; d3++)
        {
            for(d2=0; d2<10; d2++)
            {
                for(d1=0; d1<max; d1++)
                {
                    for(d0=0; d0<10; d0++)
                    {
                        for(clk=0; clk<50; clk++)
                        {
                            PORTA = 0x80;
                            PORTC = dis[d0];
                            _delay_ms(5);
                            PORTA = 0x40;
                            PORTC = dis[d1];
                            _delay_ms(5);
                            PORTA = 0x20;
                            PORTC = dis[d2];
                            _delay_ms(5);
                            PORTA = 0x10;
                            PORTC = dis[d3];
                            _delay_ms(5);
                            PORTA = 0x00;
                            PORTC = 0x00;

                            if((PIND & 0x80) == 0x80)
                            {
                                d3 = 0;
                                d2 = 0;
                                d1 = 0;
                                d0 = 0;
                                if(clk == 49)
                                    clk = 0;
                            }

                            if((PIND & 0x40) == 0x40)
                                if(clk == 49)
                                    clk = 0;
                            
                            if((PIND & 0x04) == 0x04)
                            {
                                if(chk == 0)
                                {
                                big = ((d3*1000)+(d2*100)+(d1*10)+d0);
                                dif = (((d3*10)+d2)*40);
                                conv = big - dif;

                                d3 = conv / 1000;
                                d2 = (conv % 1000) / 100;
                                d1 = ((conv % 1000) % 100) / 10;
                                d0 = ((conv % 1000) % 100) % 10;

                                chk = 1;
                                }
                                
                                max = 10;
                            }

                            
                            else
                            {
                                if(chk == 01)
                                {
                                d3 = 0;
                                d2 = 0;
                                d1 = 0;
                                d0 = 0;
                                chk = 0;
                                }

                                max = 6;
                            }

                        }
                    }
                }
            }
        } 
    }

}