/*
 * File:   app_2.3.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 15 Temmuz 2021 Cuma, 11:11
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#define _XTAL_FREQ 4000000

int adim[8]={7,3,11,9,13,12,14,6};

void main(void) {
    int i =0;
    TRISB=0;
    TRISA=1;
    while(1){
        PORTB=adim[i];
        __delay_ms(2000);
        if(RA0==0){
            if(i==7){
                i=-1;
            }
            i++;
        }
        else{
            if(i==0){
                i=8;
            }
            i--;
        }
    }
    
}
