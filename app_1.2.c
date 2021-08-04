/*
 * File:   app_1.2.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 10:41
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#define _XTAL_FREQ 4000000 // oscilator

void main(void) {
    TRISB = 0;
    PORTB=0;
    while(1){
        PORTB++; // portlar?n ç?k??lar? binary olarak kontrol edildi?inden dolay? art?rmam?z yeterli.
        __delay_ms(500);
    }
}
