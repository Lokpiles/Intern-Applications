/*
 * File:   app_3.2.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 17 Temmuz 2021 Cumartesi, 10:24
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
#define sut1 RB2
#define sut2 RB1
#define sut3 RB0
int tus;
int sayi[11]={63,6,91,79,102,109,125,7,127,103,0};

void main(void) {
TRISB=0X7;
TRISD=0;
PORTD=0;
while(1){
    PORTB=8;
    if(sut1){tus=1;}
    if(sut2){tus=2;}
    if(sut3){tus=3;}
    PORTB=16;
    if(sut1){tus=4;}
    if(sut2){tus=5;}
    if(sut3){tus=6;}
    PORTB=32;
    if(sut1){tus=7;}
    if(sut2){tus=8;}
    if(sut3){tus=9;}
    PORTB=64;
    
    if(sut2){tus=0;}
  
    PORTD=sayi[tus];
    __delay_ms(20);
    tus=11;
    
}
}
