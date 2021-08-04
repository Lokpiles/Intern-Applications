/*
 * File:   app_1.12.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 13 Temmuz 2021 Çarþamba, 18:08
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

void main(void) {
    TRISC=0;
    CCP1M3=1;
    CCP1M2=1;
    PR2=249;
    T2CKPS1=0;
    T2CKPS0=1;
    CCPR1L=125;
    TMR2ON=1;
    while(1){}
}
