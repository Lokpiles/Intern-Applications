/*
 * File:   app_1.7.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 12:16
 */


#include <xc.h>
//AKTIF OLMASI ICIN PORTB'NIN 4,5,6,7 BITLERINDEN EN AZ BIRINDE LOGIC DEGISIKLIK OLMASI GEREKIR
//CALISMASI ICIN GIE BITI 1 RBIE BITI 1 OLMALI
//CALISTIGINDA RBIF 1 OLUR
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#define _XTAL_FREQ 4000000

void interrupt KESME(void){
    if((RBIF == 1)&((RB4==1)|(RB5==1)|(RB6==1)|(RB7==1))  ){
        RA0=1;
    __delay_ms(2000);
    RA0=0;
    }
    
    RBIF=0;
    
           
}
void main(void) {
    GIE =1;
    RBIE=1;
    TRISB= 0xF0;
    TRISA= 0;
    PORTA =0;
    
    while(1){
        RB1=0;
        __delay_ms(100);
        RB1=1;
        __delay_ms(100);
    }
   
}
