/*
 * File:   app_1.1.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 17:43
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = ON
#define _XTAL_FREQ 4000000

void interrupt kesme(void){
    if(CCP1IF=1){
        RC2=RC2^1;
    }
    CCP1IF=0;
}

void main(void) {
    GIE=1;
    PEIE=1;
    TMR1CS=1;
    T1OSCEN=1;
    TMR1ON=1;
    CCPR1=10;
    TMR1=1;
    TRISC=1;
    CCP1M0=1;
    CCP1M1=1;  
    CCP1M2=0;
    CCP1M3=1;
    CCP1IE=1;
    RC2=0;
    while(1){}
            
}
