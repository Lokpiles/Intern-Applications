/*
 * File:   app_4.1.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 24 Temmuz 2021 Cumartesi, 10:31
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


char usart_hazirla(const long int baudrate){
    unsigned int x;
    x = (_XTAL_FREQ - baudrate*16)/(baudrate*16);
    BRGH = 1;
    if(x<256){
        SPBRG=x;
        SYNC=0;
        SPEN=1;
        TRISC7=1;
        TRISC6=0;
        CREN=1;
        TXEN=1;
        return 1;
        
        
    }
    return 0;
    
}

void usart_yolla(char veri){
    while(TRMT){
        TXREG=veri;
    }
}

char usart_tsr_kontrol(){
    return TRMT;
}

void usart_yolla_text(char *text){
    
    for(int i=0;text[i]!='\0';i++){
        usart_yolla(text[i]);
    }

}

char usart_veri_alim_kontrol(){
    return RCIF;
}


char usart_veri_oku(){
    while(!RCIF);
    return RCREG;
}
int i;
void interrupt kesme(void){
    if(INTF==1){
        while(RB0=1);
        i++;
        usart_yolla(i);
       
       
    }
    INTF =0;
}
void main(void) {
    GIE=1;
    INTE=1;
    TRISB=1;
    i=0;
    usart_hazirla(9600);
    while(1);
    
    
    
}
