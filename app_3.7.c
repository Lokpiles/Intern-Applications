/*
 * File:   app_3.7.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 15 Temmuz 2021 Cumartesi, 17:14
 */


#include <xc.h>
#include "lcd.h"

const float oran=5/1024.0;
int c;
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
    int ham=(ADRESH*256+ADRESL);

    c=(int)((((ADRESH*256+ADRESL)*oran*100)-50)*10);
    lcd_gotoxy(1,5);
    
    if(c>=0){
        veri_yolla(c/1000+48);
        veri_yolla(c%1000/100+48);
        veri_yolla(c%100/10+48);
        veri_yolla('.');
        veri_yolla(c%10+48);
        veri_yolla(0xDF);
        veri_yolla('C');
        
        
    }
    else{
        
        lcd_yaz("-");
        c=c*(-1);
        
        veri_yolla(c%1000/100+48);
        veri_yolla(c%100/10+48);
        veri_yolla('.');
        veri_yolla(c%10+48);
        veri_yolla(0xDF);
        veri_yolla('C');
    }
    lcd_gotoxy(0,0);
    lcd_yaz("ham deger= ");
            lcdintbas(ham,4);

    
}
}
