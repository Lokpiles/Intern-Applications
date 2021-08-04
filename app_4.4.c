/*
 * File:   app_4.4.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 24 Temmuz 2021 Cumartesi, 16:50
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#pragma config BOREN = OFF
#pragma config LVP = ON
#pragma config CPD = OFF
#pragma config WRT = ON
#define _XTAL_FREQ 4000000
int rakam[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
int i;

void bekle(void){
    while((SSPCON2& 0X1F)||(SSPSTATbits.R_W)){

        continue;
    }
}

void basla(void){
    SSPCON2bits.SEN=1;
    while(SEN);
}

void dur(void){
    SSPCON2bits.PEN=1;
    while(PEN);
}

signed char yaz(unsigned char veri){
    bekle();
    SSPBUF=veri;
    return(ACKSTAT);
}

void main(void) {
    TRISC=0XFF;
    SSPCON=0X38;
    SSPADD=9;
    SSPSTAT=0X80;
    SSPCON2=0X00;
    SSPSTATbits.R_W=0;
    while(1){
        for(i=0;i<10;i++){
            basla();
            yaz(0x70);
            yaz(0x01);
            yaz(rakam[i]);
            dur();
            __delay_ms(500);
            
        }
    }
}
