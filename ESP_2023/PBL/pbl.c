#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


/*
Program: ESP PBL 2023
Author: nsw
Date: 2023/05/04
Github Location: https://github.com/nate-sw/ESP/tree/main/ESP_2023/PBL
MOTD: Daisy, Daisy, give me yout answer do
*/

void startup(void);

void timemux(int[], int);
void msgmux(int, int, int, int);

int setmode(int, int);

void asconv(char[], int[]);



int main(void)
{
    int hrs, min, sec, state, dly;
    int time, alarm;
    
    char clk[5];
    char dis[5];

    

    /*
        The "state" varialbe is used to control what the TMS is doing

        State values:
        0: Time has not been set, likely at startup.
        1: Clock is functionning in 24h mode
        2: Clock is functionning in 12h mode.
        3: Time set mode, must be set in 24h notation.
        4: Alarm set mode, must be set in 24h notation.
        5: Alarm state; The current time is the same as that which the alarm is set to.

    */

    DDRA = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;


    startup();

    dly = 100; //Delay for main program

    while(1)
    {
        for(hrs = 0; hrs < 24; hrs++)
        {
            for(min = 0; min < 60; min++)
            {
                time =(hrs * 100) + min;

                clk[0] = hrs/10 +'0';
                clk[1] = hrs%10 +'0';
                clk[2] = min/10 +'0';
                clk[3] = min%10 +'0';


                asconv(clk, dis);

                for(sec=0; sec<60; sec++)
                {
                    if(PIND == 0x01) //Set time
                    {
                        state = 3;
                        time = setmode(hrs, min);
                        hrs = (time/100);
                        min = (time%100);
                        clk[0] = hrs/10 +'0';
                        clk[1] = hrs%10 +'0';
                        clk[2] = min/10 +'0';
                        clk[3] = min%10 +'0';
                        asconv(clk, dis);
                    }
                    else if(PIND == 0x02) // Set alarm
                    {
                        state = 4;
                        alarm = setmode(hrs, min);
                    }
                    else
                        timemux(dis, dly);
                }
            }
        }
    }
}



void startup()
{
    int i, j, dly;

    int conv[48];
    int dismsg[5];

    char startmsg[] = {"time manager by nate simard-white 2032574"};

    dly = 10;

    asconv(startmsg, conv);
    for(i=0; i<48; i++)
    {
        for(j=0; j<5; j++)
        {
            dismsg[0] = conv[i];
            dismsg[1] = conv[i+1];
            dismsg[2] = conv[i+2];
            dismsg[3] = conv[i+3];

            if(conv[i] + conv[i+2] == 0x00)
                break;

            timemux(dismsg, dly);

        }
        if(conv[i] + conv[i+2] == 0x00)
            break;
    }

}


void timemux(int dist[], int dly)
{

    int i;
    
    DDRA = 0xFF;
    DDRC = 0xFF;

    for(i=0; i<dly; i++)
    {
        _delay_ms(2);
        PORTA = 0x10;
        PORTC = dist[0];
        _delay_ms(2);
        PORTA = 0x20;
        PORTC = dist[1];
        _delay_ms(2);
        PORTA = 0x40;
        PORTC = dist[2];
        _delay_ms(2);
        PORTA = 0x80;
        PORTC = dist[3];
        _delay_ms(2);
        PORTA = 0x00;
        PORTC = 0x00;
    }
}


int setmode(int hrs, int min)
{
    int i, dly, time;

    char settime[] = {"set time"};
    char timeset[] = {"time set"};
    char setalrm[] = {"set alrm"};
    char alrmset[] = {"arlm set"};
    int dismsg[9];

    char clk[5];
    int dis[5];

    DDRD = 0x00;


    if(PIND == 0X01) // time set
    {
        dly = 100;
        asconv(settime, dismsg);

        for(i=0; i<9; i = i+4)
        {
            dis[0] = dismsg[i];
            dis[1] = dismsg[i+1];
            dis[2] = dismsg[i+2];
            dis[3] = dismsg[i+3];

            timemux(dis, dly);
        }
        
        
        do
        {
            dly = 100;
            if(PIND == 0x11) //Hours + 10
                hrs = hrs + 10;
            else if(PIND == 0x21) // Hours + 1 
                hrs = hrs + 1;
            else if(PIND == 0x41) // Minutes + 10
                min = min + 10;
            else if(PIND == 0x81) // Minutes + 1
                min = min + 1;
            else if(PIND == 0xF1) //Reset Time
            {
                hrs = 0;
                min = 0;
            }
            else
            {
                hrs = hrs;
                min = min;
            }

            if(hrs >= 24)
                hrs = 0;
            if(min >= 60)
                min = 0;

            clk[0] = hrs/10 +'0';
            clk[1] = hrs%10 +'0';
            clk[2] = min/10 +'0';
            clk[3] = min%10 +'0';

        
            asconv(clk, dis);
            timemux(dis, dly);

        } while((PIND & 0x01) == 0X01);
        dly = 100;

        asconv(timeset, dismsg);

        for(i=0; i<9; i = i+4)
        {
            dis[0] = dismsg[i];
            dis[1] = dismsg[i+1];
            dis[2] = dismsg[i+2];
            dis[3] = dismsg[i+3];

            timemux(dis, dly);
        }
        
        time = (hrs * 100) + min;

        return time;
    }

    /*else if(sta == 4) //alarm set
    {
        asconv(setalrm, dismsg);

        for(i=0; i<8; i = i+4)
            msgmux(dismsg[i], dismsg[i+1], dismsg[i+2], dismsg[i+3]);
        
        do
        {
            timemux(time);

            if(swt == 1)
                alrm = alrm+1000;
            else if(swt == 2)
                alrm = alrm+100;
            else if(swt == 3)
                alrm = alrm+10;
            else if(swt == 4)
                alrm = alrm+1;
            else
                alrm = alrm;

        } while(sta == 3);

        asconv(alrmset, dismsg);

        for(i=0; i<8; i = i+4)
            msgmux(dismsg[i], dismsg[i+1], dismsg[i+2], dismsg[i+3]);

        return alrm;
    }
*/


}



void asconv(char msg2conv[], int convmsg[])
{
    int i, j;

    char ascii[39] = {"abcdefghijklmnopqrstuvwxyz0123456789- "}; //Adjusted for aditional characters
    int ledpat[39] = {0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x6F, 0x74, 0x30, 0x1E, 0x70, 0x38, 0x15, \
    0x54, 0x5C, 0x73, 0x67, 0x50, 0x6D, 0x78, 0x3E, 0x1C, 0x2A, 0x46, 0x6E, 0x52, 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x40, 0x00}; //Adjusted for aditional characters

    for(i=0; i<48; i++)
    {
        for(j=0; j<39; j++)
        {
            if(msg2conv[i] == ascii[j])
                convmsg[i] = ledpat[j];
        }
        
        if(msg2conv[i] + msg2conv[i+1] == 0x00)
            break;
    }
}
