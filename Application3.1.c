/*
 * File:   app_3.1.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 17 Temmuz 2021 Cumartesi, 09:46
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
int v;
int a;
int i;
void pwm(int a){
    RB0=1;
    __delay_ms(1);
    for(i=0; i<a;i++){
        __delay_ms(0.1);
        
    }
    RB0=0;
    for(i=0;i<10-a;i++){
        __delay_ms(0.1);
        
    }
}

void main(void) {
    TRISA=255;
    TRISB=0;
    ADCON0=1;
    ADCON1=128;
    PORTB=0;
    while(1){
        GO_DONE=1;
        while(GO_DONE){};
        v=(ADRESH*256+ADRESL);
        a=(int)( v/102.3);
        pwm(a);
    }
}
