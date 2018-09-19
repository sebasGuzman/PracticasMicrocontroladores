/*
 * File:   main.c
 * Author: Sebas
 *
 * Created on 3 de septiembre de 2018, 02:44 PM
 */


#include <xc.h>
#include"config.h"
#define _XTAL_FREQ 32000000

void main(void) {
    //Oscilador
    OSCFRQbits.HFFRQ=0b110; //HFINTOSC=32MHz
    //************Puertos**********
    PORTC=0; //Limpia del puerto C
    ANSELC=0b00000000; //Puerto C como digital
    TRISC=0b00001111; //Puerto C como salida
    WPUCbits.WPUC0=1;//Pull up en RC0
    //**************************************
    
    while(1){
        //LATCbits.LATC1=LATCbits.LATC1+1;//Toggle bits
        __delay_ms(500);//Retardo de 500ms
        
        if(PORTCbits.RC0==0){
            __delay_ms(100);
            LATBbits.LATC1=1;
            
        }
        else{
            LATBbits.LATC1=0;
        }
    }
  
    return;
}
