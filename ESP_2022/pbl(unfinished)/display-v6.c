#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <string.h>

/*

Program: PBL - Display
Author: Nathanael Simard-White
Date: 11/05/2022
MOTD: Coelacanths are more closely related to lungfish and tetrapods than to ray-finned fish.

*/




void dspt(int, int);
void stmsg();

    //Startup Message

void stmsg(){
    char ascii[38] = {"abcdefghijklmnopqrstuvwxyz0123456789_ "};
    char alphanum[38] = {0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x6F, 0x74, 0x30, 0x1E, 0x70, 0x38, 0x15, \
    0x54, 0x5C, 0x73, 0x67, 0x50, 0x6D, 0x78, 0x3E, 0x1C, 0x2A, 0x46, 0x6E, 0x52, 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x08, 0x0};
    char conv[38] = {};
    int c, x, y;
    char message[] = {"time clock by_2032574     "};
    int mlgth = strlen(message);


    for(x=0; x<mlgth; x++)
    {
      for(c=0; c<sizeof(ascii); c++)
      {

        if(message[x] == ascii[c])
        {
          conv[x]=alphanum[c];
        }
      }



      for(y=0; y<=100; y++)
        {
            PORTA = conv[x-4];
            PORTB = 0x10;
            _delay_ms(2);
            PORTA = conv[x-3];
            PORTB = 0x08;
            _delay_ms(2);
            PORTC = conv[x-2];
            PORTB = 0x04;
            _delay_ms(2);
            PORTC = conv[x-1];
            PORTB = 0x02;
            _delay_ms(2);
            PORTC = conv[x];
            PORTB = 0x01;
            _delay_ms(2);
        }
    }
    return;
}

int main(void)
{
    DDRA = 0xFF;
    DDRB = 0x1F;
    DDRC = 0xFF;
    DDRD = 0x00;


    //Lookup tables
   // char numeric[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};


    //char almsg[5] = {"alarm"};



    int sec;
    int hour, minute;
    int start = 1;


    stmsg();
    while(1)
    {

        for(hour = 0; hour < 24; hour++){

            if(start == 1){
             hour = 12;
            }
            start=0;

            for(minute = 0; minute < 60; minute++){


                for(sec=0; sec<60; sec++){

                    for(int z=0; z<=20; z++){
                        if(hour > 24){
                            hour = 0;
                        }
                        if(minute > 60){
                        minute = 0;
                        }

                        dspt(hour, minute);
                    }
                    if((PIND == 0x0A) || (PIND == 0x0B)){
                        hour++;
                    }
                    else if((PIND == 0x12) || (PIND == 0x13)){
                        minute++;
                    }


                }
            }

        }
    }
}


    //Display Time

void dspt(int hour, int minute){
    char numeric[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int clk[4];
    char conv[4];
    int c, x, ampm;



    if((PIND == 0x01) || (PIND == 0x03)){

        if(hour%12 == 0){
            clk[0] = 1;
            clk[1] = 2;

        }
        else{
            clk[0] = ((hour%12)/10);
            clk[1] = ((hour%12)%10);

        }
        if(hour/12 == 1){
            ampm = 0x73;
        }
        else{
            ampm = 0x77;
        }

    }
    else{
        clk[0] = hour/10;
        clk[1] = hour%10;
        ampm = 0x08;
    }
    clk[2] = minute/10;
    clk[3] = minute%10;


    for(x=0; x<4; x++){

        for(c=0; c<10; c++){

            if(clk[x] == num[c]){

                conv[x] = numeric[c];
            }
        }
    }
    for(int y=0; y<=10; y++){
        PORTA = conv[0];
        PORTB = 0x10;
        _delay_us(820);
        PORTA = conv[1];
        PORTB = 0x08;
        _delay_us(820);
        PORTC = conv[2];
        PORTB = 0x04;
        _delay_us(82000);
        PORTC = conv[3];
        PORTB = 0x02;
        _delay_us(820);
        PORTC = ampm;
        PORTB = 0x01;
        _delay_us(820);
    }

    return;
}

