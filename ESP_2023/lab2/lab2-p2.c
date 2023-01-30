#include <stdio.h>
#include <math.h>

/*
Program: Lab 2 Part 2
Author: nsw
Date: 2023/01/30
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab2
MOTD: Silver carp are easily frightened by boats, which cause them to leap up to 2.5-3 meters into the air.

*/

int main(){

    float fahr, celc;
	
	printf("\nPlease enter a temperature in Fahrenheit between -29.9 and 250.9 > ");
	scanf("%f", &fahr);

    if(((fahr<250.9) && (fahr>-29.9))){
        
        celc = (fahr - 32.0) * 5.0/9.0;
	
	    printf("\n\nTemperature in Farenheit = %f", fahr);
	    printf("\nTemperature in Celcius = %f\n", celc);
        return 0;
    }

    else{
        
        printf("\n\nInvalid temperature value\n");
        return 1;
    }
}