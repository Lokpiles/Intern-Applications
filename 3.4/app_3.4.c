/*
 * File:   app3.4.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 17 Temmuz 2021 Cumartesi, 15:58
 */


#include <xc.h>
#include "lcd.h"
#define _XTAL_FREQ 4000000


void main(void) {
    
    
	
    TRISB=0;
    TRISC=0;
	
        lcd_hazirla();
        lcd_yaz("Emircan Furkan");
        while(1){}
        

       

      
        
            
    
}
