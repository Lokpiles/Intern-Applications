/*
 * File:   app_1.1.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 10:08
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF

void main(void) {
    TRISB = 0; // portB TÜMÜ OUTPUT
    
    TRISA = 255;  // PORTA TÜMÜ ?NPUT
    while(1){
        if(RA0==1){ // E?ER RA0 INPUTU 1 ISE PORT B'N,N BELL? DE?ERLER? AKT?F OLACAK
            // HEXADECIMAL
            PORTB= 0x0F;
            
        }
        if(RA0 == 0){ // E?ER RA0 INPUTU 1 ISE PORTB' NIN BELLI DE?ERLERI AKTIF OLACAK
            //HEXADECIMAL
            PORTB = 0xF0;
        }
    }
}
