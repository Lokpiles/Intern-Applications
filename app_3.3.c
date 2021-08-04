/*
 * File:   app_3.3.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 17 Temmuz 2021 Cumartesi, 10:52
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#define _XTAL_FREQ 4000000
void main(void) {
    CMCON=2;
    TRISA =0X0F;
    TRISB=0;
    while(1){
        RB0=C1OUT;
    }
}
