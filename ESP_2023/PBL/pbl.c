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

int twlvhrs(int);

int main(void)
{
    int hrs, min, sec, dly, stcng;
    int systime, distime, alarm;
    
    char clk[5];
    char alrmmsg[5] = "alrm";
    int dis[5];

    DDRA = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;

    alarm = 0;
    stcng = 0;
    systime = 0;
    distime = 0;


    startup();

    dly = 100; //Delay for main program

    while(1)
    {
        for(hrs = 0; hrs < 24; hrs++)
        {
            for(min = 0; min < 60; min++)
            {
                systime = (hrs * 100) + min;

                if((PIND & 0x04) == 0x04)
                {
                    distime = twlvhrs(systime);
                    clk[0] = distime/10 +'0';
                    clk[1] = distime%10 +'0';
                }
                else
                {
                    clk[0] = systime/1000 +'0';
                    clk[1] = systime%1000/100 +'0';
                }

                clk[2] = systime%1000%100/10 +'0';
                clk[3] = systime%1000%100%10 +'0';

                asconv(clk, dis);

                if((PIND & 0x04) == 0x04)
                {
                    if(hrs/12 == 1)
                    {
                        dis[0] = dis[0]+0x80;
                        dis[1] = dis[1]+0x80;
                    }
                    dis[3] = dis[3]+0x80;
                }

                for(sec=0; sec<60; sec++)
                {
                    if((PIND & 0x01) == 0x01) //Set time
                    {
                        systime = setmode(hrs, min);
                        hrs = (systime/100);
                        min = (systime%100)-1;
                        break;
                    }
                    else if((PIND & 0x02) == 0x02) // Set alarm
                    {
                        alarm = setmode(hrs, min);
                        min--;
                        break;
                    }


                   /* if((PIND & 0x04) == 0x04)
                    {
                        if(stcng == 0)
                        {
                            distime = twlvhrs(systime);
                
                            clk[0] = distime/10 +'0';
                            clk[1] = distime%10 +'0';

                            asconv(clk, dis);
                            if(hrs/12 == 1)
                            {
                                dis[0] = dis[0]+0x80;
                                dis[1] = dis[1]+0x80;
                            }
                            dis[3] = dis[3]+0x80;

                            stcng = 1;
                        }
                        
                    }
                    else
                    {
                        if(stcng == 1)
                        {

                            clk[0] = systime/1000 +'0';
                            clk[1] = systime%1000/100 +'0';


                            asconv(clk, dis);

                            stcng = 0;
                        }
                    }*/
                    
                    if((alarm == systime) && (sec < 3)) //Alarm mode
                    {
                        do
                        {
                            asconv(alrmmsg, dis);
                            timemux(dis, dly);
                        }while((alarm == systime) && (sec < 3));
                    }

                        
                    timemux(dis, dly);
                    PIND = 0x00;

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

    char startmsg[] = {"time system by nate simard-white 2032574"};
    char starttime[] = {"0000"};

    dly = 10;

    asconv(startmsg, conv);
    for(i=0; i<42; i++)
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

        asconv(starttime, conv);
        dismsg[0] = conv[0];
        dismsg[1] = conv[1];
        dismsg[2] = conv[2];
        dismsg[3] = conv[3];

        dly = 50;
    do
    {
        timemux(dismsg, dly);
        _delay_ms(500);
    } while (PIND != 0x01);
}

void timemux(int dist[], int dly)
{

    int i;
    
    DDRA = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;

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
    char setalrm[] = {"set alrm"};

    char clk[5];

    int msg[9];
    int dis[5];
    
    i = 0;

    dly = 100;

    DDRA = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;

    if(PIND == 0x01)
        asconv(settime, msg);
    

    else if(PIND == 0x02)
        asconv(setalrm, msg);
    

    for(i=0; i<8; i = i+4)
    {
        dis[0] = msg[i];
        dis[1] = msg[i+1];
        dis[2] = msg[i+2];
        dis[3] = msg[i+3];

        timemux(dis, dly);
    }
    
    
    do
    {
        if(PIND == 0x11 || PIND == 0x12)  //Hours + 10
            hrs = hrs + 10;
        else if(PIND == 0x21 || PIND == 0x22)  // Hours + 1 
            hrs = hrs + 1;
        else if(PIND == 0x41 || PIND == 0x42)  // Minutes + 10
            min = min + 10;
        else if(PIND == 0x81 || PIND == 0x82)   // Minutes + 1
            min = min + 1;
        else if(PIND == 0xF1 || PIND == 0xF2)  //Reset Time
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

    } while((PIND & 0x01) == 0X01 || (PIND & 0x02) == 0X02);

    for(i=8; i>=0; i = i-4)
    {
        dis[0] = msg[i];
        dis[1] = msg[i+1];
        dis[2] = msg[i+2];
        dis[3] = msg[i+3];

        timemux(dis, dly);
    }
    i = 0;
    
    time = (hrs * 100) + min;


    return time;
}

void asconv(char msg2conv[], int convmsg[])
{
    int i, j;

    i = 0;
    j = 0;

    char ascii[39] = {"-abcdefghijklmnopqrstuvwxyz0123456789 "}; //Adjusted for aditional characters
    int ledpat[39] = {0x40, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x6F, 0x74, 0x30, 0x1E, 0x70, 0x38, 0x15, \
    0x54, 0x5C, 0x73, 0x67, 0x50, 0x6D, 0x78, 0x3E, 0x1C, 0x2A, 0x46, 0x6E, 0x52, 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67,  0x00}; //Adjusted for aditional characters

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

int twlvhrs(int systime)
{
    int distime, hrs;
    hrs = systime/100;

    if(hrs == 0)//12AM
        distime = 12;
    
    else if(hrs >= 12)//1PM-11PM
        distime = hrs%12;
    
    else//1AM-12PM
        distime = hrs;

    return distime;
}