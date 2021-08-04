#include "SPI_lib.h"
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = ON
#define _XTAL_FREQ 4000000
void spi_hazirla(void){
    SMP=1;
    SSPBUF=0;
    BF=0;
    CKE=1;
    CKP=0;
    WCOL=0;
    SSPOV=0;
    SSPM3=0;
    SSPM2=0;
    SSPM1=0;
    SSPM0=0;
    SSPEN=1;
}

void spi_veri_yolla(unsigned char veri){
    BF=0;
    SSPBUF=veri;
    while(!BF);
}


unsigned char spi_veri_al(unsigned char veri){
    BF=0;
    SSPBUF=veri;
    while(!BF);
    return SSPBUF;
}