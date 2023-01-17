#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	printf("\nLab1 Part 1.2");
	printf("\nBy: Nathanael Simard-White");
	
	float fahrenheit;
	float celcius;
	
	fahrenheit = -20.0;
	celcius = (fahrenheit - 32.0) * 5.0 / 9.0;
	
	printf("\nTemperature in Farenheit = %f", fahrenheit);
	printf("\nTemperature in Celcius = %f", celcius);
	
	return 0;
}
