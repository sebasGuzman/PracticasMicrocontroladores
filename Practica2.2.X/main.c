/*
 * File:   main.c
 * Author: Sebas
 *
 * Created on 5 de septiembre de 2018, 10:51 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

#define boton1 PORTCbits.RC1
#define Led1 PORTCbits.RC2
#define boton2 PORTDbits.RD1
#define Led2 PORTDbits.RD2




void main(void) {
    
    OSCFRQbits.HFFRQ =0b110;
    PORTC = 0;
    PORTD = 0;
    ANSELC = 0b00000000;
    ANSELD = 0b00000000;
    TRISCbits.TRISC1 =1;
    TRISCbits.TRISC2 =0;
    TRISDbits.TRISD1 =1;
    TRISDbits.TRISD2 =0;
    
    
    while(1){
        
        if (boton1 ==0){
            __delay_ms(300);
            Led1 = Led1 + 1;
        }
        if (boton2 ==0){
            __delay_ms(300);
            Led2=Led2 +1;
        }
            
        }
    
    
    
    return;
}

