#include <stdio.h>
#include <math.h>

/*
Program: Lab 2 Part 4
Author: nsw
Date: 2023/01/30
Github Location: https://github.com/nate-sw/ESP/ESP_2023/lab2
MOTD: Silver carp are easily frightened by boats, which cause them to leap up to 2.5-3 meters into the air.

*/

int main(){

    char lc, uc;

    printf("\nPlease insert a lower case letter > ");
    scanf("%c", &lc);
    
    if(lc>='a' && lc<='z'){
        
        uc = lc - 0x20;

        printf("\n\nResulting upper case letter: %c\n", uc);
        return 0;
    }

    else{
        
        printf("\n\nInvalid character\n");
        return 1;
    }
}