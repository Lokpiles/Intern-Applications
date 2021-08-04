/*
 * File:  app_5.2.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 26 Temmuz 2021 Pazartesi, 10:35
 */


#include <xc.h>
#include "GLCD_lib.h"

int i;

void main(void) {
    TRISB=0;
    PORTB=0;
    glcd_hazirla();
    while(1){
        for(i=0;i<64;i++){
            ekrana_yaz(1,i,0,0x01);
            ekrana_yaz(1,i,1,0x03);
            ekrana_yaz(1,i,2,0x07);
            ekrana_yaz(1,i,3,0x0F);
            ekrana_yaz(1,i,4,0x1F);
            ekrana_yaz(1,i,5,0x3F);
            ekrana_yaz(1,i,6,0x7F);
            ekrana_yaz(1,i,7,0xFF);
            
            ekrana_yaz(2,i,0,0x01);
            ekrana_yaz(2,i,1,0x03);
            ekrana_yaz(2,i,2,0x07);
            ekrana_yaz(2,i,3,0x0F);
            ekrana_yaz(2,i,4,0x1F);
            ekrana_yaz(2,i,5,0x3F);
            ekrana_yaz(2,i,6,0x7F);
            ekrana_yaz(2,i,7,0xFF);
        }
    }
}
