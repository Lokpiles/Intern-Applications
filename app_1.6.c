/*
 * File:   app_1.6.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 11:56
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#define _XTAL_FREQ 4000000 // RB0 KESMESININ AKTIF OLMASI ICIN GIE VE INTE BITLERI 1 YAPILMALI
//RB0 GIRIS OLMALI VE RB0'IN DE?ERININ DEGISMESI GEREKIR
//KESME AKTIF OLDUGUNDA INTF 1 OLUR
//KESMEDEN CIKARKEN INTF 0 YAPILMAZSA SONSUZ DONGUYE GIRER SUREKLI KESMEYE GIRER
void interrupt KESME(void){
    if(INTF==1){
        PORTA=255;
        __delay_ms(2000);
        
    }
    INTF =0;
    PORTA=0;
    
}
void main(void) {
    GIE=1;
    INTE=1;
    TRISB = 1;
    TRISA = 0;
    PORTA = 0;
     
    while(1){
        RB1=0;
        __delay_ms(1000);
        RB1=1;
        __delay_ms(1000);
    }
           
    
}
