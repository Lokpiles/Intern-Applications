/*
 * File:   app_4.3.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 24 Temmuz 2021 Cumartesi, 14:40
 */


#include <xc.h>
#include "SPI_lib.h"
#include "lcd.h"
#define CE RC6

void tc72_hazirla(void){
    spi_hazirla();
    CE=1;
    spi_veri_yolla(0x80);
    __delay_ms(100);
    spi_veri_yolla(0x04);
    CE=0;
    
    
}

unsigned char tc72_msb(){
    unsigned char sonuc;
    CE=1;
    spi_veri_yolla(0x02);
    sonuc=spi_veri_al(0XFF);
    CE=0;
    return sonuc;
}

void main(void) {    
   int c;
   TRISB=0;
   TRISD=0;
   TRISC=16;
   lcd_hazirla();
   tc72_hazirla();
   lcd_yaz("SICAKLIK = ");
   while(1){
       c=tc72_msb()*10;
       if(c>1250){
           c=2560-c;
           lcd_gotoxy(1,11);
           
           veri_yolla('-');
       }
       else{
           lcd_gotoxy(1,11);
           veri_yolla('+');
           
           
       }
       
       veri_yolla(c/1000+48);
       veri_yolla((c%1000)/100+48);
       veri_yolla((c%100)/10+48);
       veri_yolla('C');
   }
   
}
