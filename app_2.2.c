/*
 * File:   app_2.2.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 16 Temmuz 2021 Cuma, 10:28
 */


#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#define _XTAL_FREQ 4000000
int i;
int adim45[4]={9,3,6,12};
int adim90[4]={1,2,4,8};

void main(void) {
    i=0;
    TRISB=0;
    TRISA=7;
    while(1){
        if(RA1==1){
            PORTB=adim45[i];
        __delay_ms(2000);
        if(RA0==0){
            if(i==3){
                i=-1;
                
                
            }
            i++;
        }
        else{
            if(i==0){
                i=4;
            }
            i--;
        }
            
        }
        if(RA2==1){
             PORTB=adim90[i];
        __delay_ms(2000);
        if(RA0==0){
            if(i==3){
                i=-1;
                
                
            }
            i++;
        }
        else{
            if(i==0){
                i=4;
            }
            i--;
        }
        }
        
        
    }
    
}
