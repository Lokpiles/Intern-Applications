/*
 * File:   app_5.1.c
 * Author: Emircan Furkan Bayendur
 *
 * Created on 26 Temmuz 2021 Pazartesi, 09:19
 */


#include <xc.h>
#include "lcd.h"
#define _XTAL_FREQ 4000000

#define EEPROM_Address_R  0xA1
#define EEPROM_Address_W  0xA0

void bekle(void){
    while((SSPCON2 & 0X1F)||(SSPSTATbits.R_W))
    continue;
    
        
}
    
 void basla(void){
    SSPCON2bits.SEN=1;
    while(SEN);
}

    void dur(void){
    SSPCON2bits.PEN=1;
    __delay_ms(10);
    while(PEN);
}



signed char yaz(unsigned char veri){
    bekle();
    SSPBUF=veri;
    return(ACKSTAT);
}

signed char oku(void){
    bekle();
    RCEN=1;
    bekle();
    while(SSPSTATbits.BF);
    bekle();
    return(SSPBUF);
}

void tekrar_basla(){
    bekle();
    RSEN=1;
}

void eeprom_yaz(unsigned char adres, unsigned char veri){
    basla();
    yaz(0xA0);
    yaz(adres);
    yaz(veri);
    dur();
    __delay_ms(20);
    
}

unsigned char eeprom_oku(unsigned char adres){
    unsigned char veri;
    basla();
    yaz(0xA0);
    yaz(adres);
    tekrar_basla();
    veri=oku();
    dur();
    __delay_ms(20);
    return(veri);
}



void I2C_Master_Init(const unsigned long baud)
{
    SSPCON = 0b00101000;
    SSPCON2 = 0;
    SSPADD = (_XTAL_FREQ/(4*baud))-1;
    SSPSTAT = 0;
    TRISC3 = 1;
    TRISC4 = 1;
}
void I2C_Master_Wait()
{
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}
void I2C_Master_Start()
{
    I2C_Master_Wait();
    SEN = 1;
}
void I2C_Master_RepeatedStart()
{
    I2C_Master_Wait();
    RSEN = 1;
}
void I2C_Master_Stop()
{
    I2C_Master_Wait();
    PEN = 1;
}
unsigned char I2C_Master_Write(unsigned char data)
{
    I2C_Master_Wait();
    SSPBUF = data;
    while(!SSPIF);  // Wait Until Completion
	SSPIF = 0;
    return ACKSTAT;
}
unsigned char I2C_Read_Byte(void)
{
    //---[ Receive & Return A Byte ]---
	I2C_Master_Wait();
    RCEN = 1;		  // Enable & Start Reception
	while(!SSPIF);	  // Wait Until Completion
	SSPIF = 0;		  // Clear The Interrupt Flag Bit
    I2C_Master_Wait();
    return SSPBUF;	  // Return The Received Byte
}
void I2C_ACK(void)
{
	ACKDT = 0;			// 0 -> ACK
	I2C_Master_Wait();
    ACKEN = 1;			// Send ACK
}
void I2C_NACK(void)
{
	ACKDT = 1;			// 1 -> NACK
    I2C_Master_Wait();
	ACKEN = 1;			// Send NACK
}
//======================================================

//---------------[ I2C EEPROM Routines ]----------------
//------------------------------------------------------
//-----[ Write Operations ]-----
// EEPROM Write Byte
void EEPROM_Write(unsigned int add, unsigned char data)
{
   I2C_Master_Start();
   
   // Wait Until EEPROM Is IDLE
   while(I2C_Master_Write(EEPROM_Address_W))
     I2C_Master_RepeatedStart();
   
   I2C_Master_Write(add>>8);
   I2C_Master_Write((unsigned char)add);
   I2C_Master_Write(data);
   I2C_Master_Stop();
}
// EEPROM Write Page
void EEPROM_Write_Page(unsigned int add, unsigned char* data, unsigned char len)
{
   I2C_Master_Start();
   
   // Wait Until EEPROM Is IDLE
   while(I2C_Master_Write(EEPROM_Address_W))
     I2C_Master_RepeatedStart();

   I2C_Master_Write(add>>8);
   I2C_Master_Write((unsigned char)add);
   for(unsigned int i=0; i<len; i++)
       I2C_Master_Write(data[i]);
   I2C_Master_Stop();
}
//-----------------------------
//-----[ Read Operations ]-----
//---[ Byte Read ]---
unsigned char EEPROM_Read(unsigned int add)
{
   unsigned char Data;
   I2C_Master_Start();
   
   // Wait Until EEPROM Is IDLE
   while(I2C_Master_Write(EEPROM_Address_W))
     I2C_Master_RepeatedStart();

   I2C_Master_Write(add>>8);
   I2C_Master_Write((unsigned char)add);
   I2C_Master_RepeatedStart();
   
   I2C_Master_Write(EEPROM_Address_R);
   Data = I2C_Read_Byte();
   I2C_NACK();
   I2C_Master_Stop();
   
   return Data;
}

void EEPROM_Read_Page(unsigned int add, unsigned char* data, unsigned int len)
{
   I2C_Master_Start();
  
   // Wait Until EEPROM Is IDLE
   while(I2C_Master_Write(EEPROM_Address_W))
     I2C_Master_RepeatedStart();
   
   I2C_Master_Write(add>>8);
   I2C_Master_Write((unsigned char)add);  
   I2C_Master_RepeatedStart();
   I2C_Master_Write(EEPROM_Address_R);
   for(unsigned int i=0; i<len; i++)
   {
       data[i] = I2C_Read_Byte();
       I2C_ACK();
   }
   I2C_Master_Stop();
}

void main(void) {
TRISC=0XFF;
TRISB=0;
TRISD=0;
PORTB=0;
PORTD=0;

      I2C_Master_Init(100000);
    __delay_ms(300);
        lcd_hazirla();
    lcd_yaz("CBU");
    lcd_gotoxy(0,1);
    unsigned int Address = 0x1; // Some Random Address
    unsigned char Data = 0x01;     // Some Random Data To Write
    
     __delay_ms(10);
    EEPROM_Write(0,101);
    __delay_ms(10);
    EEPROM_Write(1,109);
    __delay_ms(10);
    EEPROM_Write(2,105);
    __delay_ms(10);
    EEPROM_Write(3,114);
    __delay_ms(10);
    EEPROM_Write(4,99);
    __delay_ms(10);
    EEPROM_Write(5,97);
     __delay_ms(10);
    EEPROM_Write(6,110);
    __delay_ms(10);
    
     __delay_ms(10);
       veri_yolla(EEPROM_Read(0));
       __delay_ms(10);
        veri_yolla(EEPROM_Read(1));
               __delay_ms(10);
        veri_yolla(EEPROM_Read(2));
               __delay_ms(10);
        veri_yolla(EEPROM_Read(3));
               __delay_ms(10);     
        veri_yolla(EEPROM_Read(4));
        __delay_ms(10);
        veri_yolla(EEPROM_Read(5));
        __delay_ms(10);
         veri_yolla(EEPROM_Read(6));
        __delay_ms(10);

    
    while(1){
        
        
    }
  
}
