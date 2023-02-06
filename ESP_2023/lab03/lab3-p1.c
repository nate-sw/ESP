#include <stdio.h>
#include <math.h>


/*
Program: Lab 3 Part 1
Author: nsw
Date: 2023/02/06
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab3
MOTD: The heaviest Sunfish ever caught weighed approximately 2745kg.

Program: The purpose of the following program is to perform 
basic logic decisions using if() statements.

*/

int main(){

    int sel;
    float mi, km, c, f;
	
	printf("\n\nSelect Conversion:");
	printf("\n [1] Miles to Kilometers");
	printf("\n [2] Kilometers to Miles");
	printf("\n [3] Celsius to Fahrenheit");
	printf("\n [4] Fahrenheit to Celsius");
	printf("\n [5] Exit");
	
	printf("\n\nEnter Selection > ");
	scanf("%d", &sel);

    if(sel == 1){
		printf("\nEnter distance in Miles > ");
		scanf("%f", &mi);

		km = mi * 1.609 ;

		printf("\nDistance in Kilometers: %.3f", km);
	}

	if(sel == 2){
		printf("\nEnter distance in Kilometers > ");
		scanf("%f", &km);

		mi = km / 1.609 ;

		printf("\nDistance in Miles: %.3f", mi);
	}
        
	if(sel == 3){
		printf("\nEnter temperature in Celsius > ");
		scanf("%f", &c);

		f = (c * 9 / 5 ) + 32.0;

		printf("\nTemperature in Fahrenheit: %.3f", f);
	}

	if(sel == 4){
		printf("\nEnter temperature in Fahrenheit >");
		scanf("%f", &f);

		c = (f - 32.0) * 5.0 / 9.0;

		printf("\nTemperature in Celcius: %.3f", c);
	}

	if(sel == 5){

		printf("\n\nGoodbye.");
	}
    
	if((sel<1)||(sel>5)){
		printf("\nInvalid Entry.");
        printf("\n\nEnd run.\n");
		return 1;
	}

	printf("\n\nEnd run.\n");
	return 0;
}
    