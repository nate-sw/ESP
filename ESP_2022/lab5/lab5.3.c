#include <stdio.h>
#include <stdlib.h>

/*

Program: Lab 5 Part 3
Author: Nathanael Simard-White
Date: 02/03/2022
MOTD: I could really go for a sandwich right about now.

*/

int main(void)
{

	char select;
	float mi;
	float km;
	float c;
	float f;
    char rep;


 do
    {

	/* User inserts the desired value here */

	printf("\n\nSelect Conversion:");
	printf("\n [1] Miles to Kilometers");
	printf("\n [2] Kilometers to Miles");
	printf("\n [3] Celsius to Fahrenheit");
	printf("\n [4] Fahrenheit to Celsius");

	printf("\n\nEnter Selection >> ");
	scanf("%c", &select);

	/* Equations */


        switch(select)
        {
            case '1':
                printf("\nEnter distance in Miles > ");
                scanf("%f", &mi);
                km = mi * 1.609 ;
                printf("\nDistance in Kilometers: %.3f", km);
                break;


            case '2':
                printf("\nEnter distance in Kilometers > ");
                scanf("%f", &km);
                mi = km / 1.609 ;
                printf("\nDistance in Miles: %.3f", mi);
                break;


            case '3':
                printf("\nEnter temperature in Celsius > ");
                scanf("%f", &c);
                f = (c * 9 / 5 ) + 32.0;
                printf("\nTemperature in Fahrenheit: %.3f", f);
                break;



            case '4':
                printf("\nEnter temperature in Fahrenheit > ");
                scanf("%f", &f);
                c = (f - 32.0) * 5.0 / 9.0;
                printf("\nTemperature in Celcius: %.3f", c);
                break;



            default:
                printf("\nInvalid Entry.");
                break;
        }

            printf("\n\nRepeat Run? [Y/N] > ");
            scanf("%c", &rep);
            rep = getchar();
            getchar();

        }
        while(rep=='Y');

    printf("\nThank You.");
    printf("\n\nEnd run.");

	return 0;
}
