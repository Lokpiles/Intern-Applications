/*
 * File:   app_1.5.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 14 Temmuz 2021 Çarþamba, 11:26
 */



#include <xc.h>
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = ON

#define _XTAL_FREQ 4000000
int xc8[3][5]={0x9C,0xEB,0xF7,0xEB,0x9C,      
               0xC1,0xBE,0xBE,0xBE,0xDD,
               0xC9,0xB6,0xB6,0xB6,0xC9};
// 3 HARF YAZDIRILACAK HER HAF ICIN BELLI BIR GRUP ÇIKTI ALINMASI GEREKIYOR BU YUZDEN 2 BOYUTLU ARRAY
//

void main(void) {
    TRISD=0;
    TRISC=0;                      // ilk i döngüsü 3 harfi belirliyor.
    for(int i =0;i<3;i++){
        
        for(int j =0; j<100;j++){
            
            
            for(int k =0; k<5;k++){        //HIZLICA SÜTUNLARI TARAYARAK GEÇ?YOR ?NSAN GÖZÜ BUNU FARK ETMIYOR
                PORTD= xc8[i][k]; 
                __delay_ms(5);
                PORTC= PORTC<<1;   // ANLAMADIM
                
                
                
        
            }
            PORTC=1;
        
         }
        
    }
    
}
 