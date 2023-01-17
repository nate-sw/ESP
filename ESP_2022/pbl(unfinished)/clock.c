#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

/*

Program: PBL - Clock
Author: Nathanael Simard-White
Date: 05/05/2022
MOTD: Coelacanths are more closely related to lungfish and tetrapods than to ray-finned fish.

*/
int main(void)
{
    int s;
    int mlsd, mmsd, hlsd, hmsd;
    int clk[4];

    while(1){
        for(hmsd = 0; hmsd < 2; hmsd++){

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
                        }



                    }
                }
            }

        }
    }
}
