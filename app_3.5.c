/*
 * File:   app_3.6.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 17 Temmuz 2021 Cumartesi, 15:58
 */


#include <xc.h>
#include "lcd.h"
#define _XTAL_FREQ 4000000
#define sut1 RD2
#define sut2 RD1
#define sut3 RD0
char tus;

void main(void) {
    
    TRISD=0X7;
    TRISB=0;
    TRISC=0;
        while(1){
        PORTD=8;
        if(sut1){tus="1";}
        if(sut2){tus="2";}
        if(sut3){tus="3";}
        PORTD=16;
        if(sut1){tus="4";}
        if(sut2){tus="5";}
        if(sut3){tus="6";}
        PORTD=32;
        if(sut1){tus="7";}
        if(sut2){tus="8";}
        if(sut3){tus="9";}
        PORTD=64;

        if(sut2){tus="0";}

        lcd_hazirla();
        lcd_yaz("----->");
        lcd_yaz(tus);
        
            
    } 
}
