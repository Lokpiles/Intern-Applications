/*
 * File:   app_3.6.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 17 Temmuz 2021 Cumartesi, 16:55
 */


#include <xc.h>
#include <pic16f877.h>
#include "lcd.h"
int v;
float oran=5.0/1023.0;

unsigned int ham=0;

void lcdintbas(unsigned int veri,unsigned char hane)
{
    switch(hane)
    {
        case 5: veri_yolla(veri/10000%10+48);
        case 4: veri_yolla(veri/1000%10+48);
        case 3: veri_yolla(veri/100%10+48);
        case 2: veri_yolla(veri/10%10+48);
        case 1: veri_yolla(veri%10+48);
    }
}

/******************************/
void main(void) {
    TRISA=255;
    TRISB=0;
    TRISC=0;
    ADCON0=1;
    ADCON1=128;
    lcd_hazirla();
    while(1){
        GO_DONE=1;
        while(GO_DONE){};
        
        ham = (ADRESH*256 + ADRESL);
        v=(int)(ham*oran*100.0);
        lcd_gotoxy(0,0);
        veri_yolla((v%1000)/100+48);
        veri_yolla('.');
        veri_yolla((v%100)/10+48);
        veri_yolla((v%10+48));
        veri_yolla('V');
        
        lcd_gotoxy(0,1);
        lcd_yaz("Ham deger:");
        lcdintbas(ham,4);
    }
}
