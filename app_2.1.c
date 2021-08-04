/*
 * File:   app_2.1.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 16 Temmuz 2021 Cuma, 09:14
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
    if(RB5==0){
        PORTD=40;
    }
    else{
        PORTD=80;
    }
    if(RB6==1){
        if(CCPR1L>240){
            CCPR1L=1;
        }
        CCPR1L=CCPR1L+5;
    }
    if(RB7==1){
        if(CCPR1L==0){
            CCPR1L=240;
        }
        CCPR1L=CCPR1L-5;
        
    }
    RBIF=0;
}

void main(void) {
    GIE=1;
    RBIE=1;
    TRISB=255;
    TRISC=0;
    TRISD=0;
    PORTD=40;
    CCP1M3=1;
    CCP1M2=1;
    PR2=249;
    T2CKPS1=0;
    T2CKPS0=1;
    CCPR1L=125;
    TMR2ON=1;
    while(1){}
}
