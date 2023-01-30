#include <stdio.h>
#include <math.h>

/*
Program: Lab 2 Part 1
Author: nsw
Date: 2023/01/30
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab2
MOTD: Silver carp are easily frightened by boats, which cause them to leap up to 2.5-3 meters into the air.

*/

int main(){

    int A, B, result;
    
    printf("\nPlease insert the first integer between -2000 to 2000 > ");
    scanf("%i",&A);

    printf("\nPlease insert the second integer between -2000 to 2000 > ");
    scanf("%i",&B);

    if(((A<2000) && (A>-2000)) && ((B<2000) && (B>-2000))){
        
        result = ((A+25)*2+B)+(A-(B+25));

        printf("\n\nResult of calculation = %i\n", result);
        return 0;
    }

    else{
        
        printf("\n\nInvalid integer values\n");
        return 1;
    }
}