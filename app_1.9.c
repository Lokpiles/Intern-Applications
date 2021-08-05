/*
 * File:   app_1.9.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 16:16
 */


#include <xc.h>
#include <eeprom_routines.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#define _XTAL_FREQ 4000000
int sayac;
void interrupt kesme(void){
    if(EEIF==1){
        EEADR= 0X2F;
        RD= 1;
        PORTB= EEDATA;
    }
    EEIF=0;
}



void main(void) {
   
    EEIE =1;
    TRISB=0;
    TRISA=255;
    sayac =0;
    PORTB=0;
    
    while(1){
        if(RA0==1){
            while(RA0=1){}
            eeprom_write(1,'e');
            __delay_ms(100);

             GIE=0;
             sayac++;
             EEADR =0X2F;
             EEDATA=sayac;
             WREN=1;
             EECON2=85;
             EECON2=170;
             WR=1;
             GIE=1;
                     
                    
             
                  
         }
     }       
}
