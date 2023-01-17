#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

/*

Program: PBL - Report
Author: Nathanael Simard-White
Date: 05/05/2022
MOTD: Coelacanths are more closely related to lungfish and tetrapods than to ray-finned fish.

*/


void cnv(int[]);
int main()
{


    DDRA = 0xFF;
    DDRB = 0x1F;
    DDRC = 0xFF;

    //Lookup tables

   /* char alphapat[27] = {0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x6F, 0x74, 0x30, 0x1E, 0x70, 0x38, 0x15, \
  0x54, 0x5C, 0x73, 0x67, 0x50, 0x6D, 0x78, 0x3E, 0x1C, 0x2A, 0x46, 0x6E, 0x52, 0x0};*/

    //char almsg[5] = {"alarm"};

    int s;
    int mlsd, mmsd, hlsd, hmsd;
    int clk[4];
    char dig;
    char conv[4] = dig;

    cnv(clk, dig);

    while(1)
    {

        clk[3] = hmsd;

        for(hlsd = 0; hlsd < 9; hlsd++){

            if((hmsd==2) && (hlsd==4)){
                hlsd = 0;
                break;
            }

            clk[2] = hlsd;

            for(mmsd = 0; mmsd < 5; mmsd++){
                clk[1] = mmsd;

                    for(mlsd = 0; mlsd < 9; mlsd++){

                        clk[0] = mlsd;

                        for(s=0; s<60; s++){
                            _delay_ms(1000);

                            for(int y = 0; y < 100; y++){
                                PORTA = conv[0];
                                PORTB = 0x10;
                                _delay_us(2);
                                PORTA = conv[1];
                                PORTB = 0x08;
                                _delay_us(2);
                                PORTC = conv[2];
                                PORTB = 0x04;
                                _delay_us(2);
                                PORTC = conv[3];
                                PORTB = 0x02;
                                _delay_us(2);
                        }



                    }
                }
            }

        }

    }

}

void cnv(int clk[4])
{

    int c, x;
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char numeric[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};

    for(x=0; x<4; x++){

        for(c=0; c<10; c++){

            if(clk[x] == num[c]){

                dig[x] = numeric[c];
            }
        }
    }
    return;
}


