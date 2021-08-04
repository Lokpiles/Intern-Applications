/*
 * File:   app_1.8.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 15:49
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#define _XTAL_FREQ 4000000
int sayac;

void interrupt kesme(void){
    if(T0IF == 1){
        sayac--;
        if(sayac==0){
            sayac=9;
            RB0=RB0^1;
        }
    }
    TMR0 =19;
    T0IF =0;
}


void main(void) {
    GIE=1;
    T0IE=1;
    TRISB=0;
    OPTION_REG =0x07;
    TMR0 =39;
    sayac=9;
    PORTB =0;
    while(1){}
    
}
