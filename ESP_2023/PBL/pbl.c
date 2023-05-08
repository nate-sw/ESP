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

int setmode(int, int);

void asconv(char[], int[]);



int main(void)
{
    int hrs, min, sec, state, dly;
    int time, alarm;
    
    char clk[5];
    char dis[5];

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
                        time = setmode(hrs, min);
                        hrs = (time/100);
                        min = (time%100) - 1;
                        break;
                    }
                    else if(PIND == 0x02) // Set alarm
                    {
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
    char starttime[] = {"0000    "};

    dly = 10;

    asconv(startmsg, conv);
    for(i=0; i<startmsg; i++)
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
    do
    {
        asconv(starttime, conv);
        for(i=0; i<starttime; i++)
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
    } while (PIND != 0x01);
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
    int i, dly, time, alrm, setstate;

    char settime[] = {"set time"};
    char timeset[] = {"time set"};
    char setalrm[] = {"set alrm"};
    char alrmset[] = {"arlm set"};
    int dismsg[9];

    char clk[5];
    int dis[5];

    dly = 100;

    DDRD = 0x00;

    if(PIND == 0x01)
    {
        setstate = 1;
        asconv(settime, dismsg);
    }
    else if(PIND == 0x02)
    {
        setstate = 2;
        asconv(setalrm, dismsg);
    }

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
        if((PIND & 0xF0) == 0x1) //Hours + 10
            hrs = hrs + 10;
        else if((PIND & 0xF0) == 0x2) // Hours + 1 
            hrs = hrs + 1;
        else if((PIND & 0xF0) == 0x4) // Minutes + 10
            min = min + 10;
        else if((PIND & 0xF0) == 0x8) // Minutes + 1
            min = min + 1;
        else if((PIND & 0xF0) == 0xF) //Reset Time
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

    } while((PIND & 0x01) == 0X01) || ((PIND & 0x02) == 0X02);

    if(setstate = 1)
        asconv(settime, dismsg);

    else if(setstate = 2)
        asconv(setalrm, dismsg);

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



void asconv(char msg2conv[], int convmsg[])
{
    int i, j;

    char ascii[39] = {"abcdefghijklmnopqrstuvwxyz0123456789- "}; //Adjusted for aditional characters
    int ledpat[39] = {0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x6F, 0x74, 0x30, 0x1E, 0x70, 0x38, 0x15, \
    0x54, 0x5C, 0x73, 0x67, 0x50, 0x6D, 0x78, 0x3E, 0x1C, 0x2A, 0x46, 0x6E, 0x52, 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x40, 0x20}; //Adjusted for aditional characters

    for(i=0; i<msg2conv; i++)
    {
        for(j=0; j<39; j++)
        {
            if(msg2conv[i] == ascii[j])
                convmsg[i] = ledpat[j];
        }
        
        if(msg2conv[i] + msg2conv[i+2] == 0x00)
            break;
    }
}
