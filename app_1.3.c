/*
 * File:   app_1.3.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 10:59
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#define _XTAL_FREQ 4000000
int dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
//0-9 aras? say?lar?n yans?t?lmas?n? sa?layan hangi ledlerin aç?k veya kapal? olaca?? de?erler. hexadecimal

void main(void) {
    TRISB=0; // PORT B OUTPUT
    while(1){
        for( int i=0;i<10;i++){
            PORTB=dizi[i]; // PORTB ÇIKI?LARI DIZIDEKI DE?ERLERE GORE AKTIF YA DA PASIF OLUYOR
            __delay_ms(1000);
        }
        
    }
    
}
