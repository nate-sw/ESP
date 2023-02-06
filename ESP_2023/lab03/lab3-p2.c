#include <stdio.h>
#include <math.h>


/*
Program: Lab 3 Part 2
Author: nsw
Date: 2023/02/06
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab3
MOTD: The heaviest Sunfish ever caught weighed approximately 2745kg.

Program: The purpose of the following program is to perform 
basic logic decisions using if() statements.

*/

int main(){

    float v, i, r, p;
	
	printf("\n\nEnter Voltage (volts) > ");
	scanf("%f", &v);
	
	printf("\nEnter Current (amps) > ");
	scanf("%f", &i);
	
	printf("\nEnter Resistance (ohms) > ");
	scanf("%f", &r);
	
	
	if(v == 0.0){
		v = i * r;
		p = (i*i) * r;

		printf("\nCircuit Voltage: %.3fV", v);
	}

	if(i == 0.0){
		i = v / r;
		p = (v*v) / r;

		printf("\nCircuit Current: %.3fA", i);
	}

	if(r == 0.0){
		r = v / i;
		p = v * i;

		printf("\nCircuit Resistance: %.3fR", r);
	}

	printf("\nCircuit Power: %.3fW\n", p);
	
	return 0;
}