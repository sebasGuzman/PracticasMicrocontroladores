#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000//Fosc
#include "flex_lcd.h" // Libreria LCD
#include <stdio.h>   // standar I/O

void main(void) {
    unsigned char i, j;
    unsigned char buffer1[16];
    unsigned int meca=0;
    //Oscilador*********************
    OSCFRQbits.HFFRQ=0b110;//32MHz
    //Puertos****************
    ANSELA=0;// puerto d como digital
    
    //*******************************
    //LCD**********************
    Lcd_Init();///iniciar Lcd
    Lcd_Cmd(LCD_CLEAR);///Limpiar Lcd
    Lcd_Cmd(LCD_CURSOR_OFF);/// Apagar el cuersor
    
    __delay_ms(1000);///Esperar 100ms 
    
  Lcd_Cmd(LCD_BLINK_CURSOR_ON);
    __delay_ms(1000);
    

    
    Lcd_Cmd(LCD_UNDERLINE_ON);
    __delay_ms(1000);
    
   
    while(1){
    for (i=0; i<13; i++){
        Lcd_Out (1,i+3, "Mecatronica");
        __delay_ms(500);
        Lcd_Cmd(LCD_CLEAR);
        sprintf(buffer1,"contador %03d",i); //guardamos en el string
        Lcd_Out2(2, 3, buffer1); //escribimos en el renglon
        //__delay_ms(500); // esperamos 100ms y repetimos
      
       
    
    }
    }
    
    // ciclo infinito
  
    
    return;
}
