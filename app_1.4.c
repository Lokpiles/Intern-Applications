/*
 * File:   app_1.5
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 11:03
 */




#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#define _XTAL_FREQ 4000000
int dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};

void main(void) {
    TRISB=0;
    TRISA=0;
    while(1){
        for( int i=0;i<10;i++){        // i döngüsü onlar basama??n? kontrol ediyor
            
            
            for( int j=0;j<10;j++){    // j döngüsü birler basama??n? kontrol ediyor
               
                
                for( int k=0;k<10;k++){  //birler ve onlr basama??n? yans?tan göstergelerin uçlar? ayn? ç?k??lara ba?l? oldu?u için
                                        // k döngüsü birler ve onlar basama??n? kontrol ediyor
                                        // birisi aktifken di?eri pasif oluyor böylece ayn? say? yans?t?lmam?? oluyor
                    
                    RA0=1;
                    RA1=0;
                    PORTB=dizi[i];
                    __delay_ms(100);
                    RA0=0;
                    RA1=1;
                    PORTB=dizi[j];
                    __delay_ms(100);
                    
                    
           
        }
           
        }
           
        }
        
    }
    
}