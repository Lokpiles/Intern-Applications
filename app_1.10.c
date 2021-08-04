/*
 * File:   app_1.10.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 17:17
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#define _XTAL_FREQ 4000000
int sayac, zaman;
void interrupt kesme (void){
    if(TMR1IF==1){
        sayac++;
    }
    if(CCP1IF==1){
        zaman=(sayac*65536+CCPR1)/1000000;
        if(zaman>=255){
            zaman=0;
            sayac=0;
        }
        PORTB=zaman;
        sayac=0;
        
               
    }
    TMR1IF=0;
    CCP1IF=0;
    TMR1=0;
}

void main(void) {
    sayac=0;
    GIE=1;
    PEIE=1;
    TMR1IE=1;
    TMR1CS=0;
    T1CKPS1=0;
    T1CKPS0=0;
    TMR1ON  =1;      
    TMR1=0;
    TRISB=0;
    PORTB=0;
    TRISC=255;
    CCP1M0=1;
    CCP1M1=0;
    CCP1M2=1;
    CCP1M3=0;
    CCP1IE=1;
    while(1){}
    
}
