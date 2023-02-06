#include <stdio.h>
#include <math.h>

/*
Program: Lab 2 Part 3
Author: nsw
Date: 2023/01/30
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab2
MOTD: Silver carp are easily frightened by boats, which cause them to leap up to 2.5-3 meters into the air.
*/

int main(){

    unsigned long int A, B, sers, para;

	printf("\nPlease insert the value of the first resistor> ");
	scanf("%lu", &A);
	
	printf("\nPlease insert the value of the second resistor > ");
	scanf("%lu", &B);
	


    if(((A<=82000) && (A>=1)) && ((B<=82000) && (B>=1))){
       	
        sers = A + B;
	    para = (A * B)/(A + B);
	
	    printf("\n\nTotal resistance in series = %lu", sers);
	    printf("\nTotal resistance in parallel = %lu\n", para);
	    return 0;
    }

    else{
        
        printf("\n\nInvalid resistor value\n");
        return 1;
    }
}