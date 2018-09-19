/*
 * File:   main.c
 * Author: Sebas
 *
 * Created on 10 de septiembre de 2018, 02:51 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000
#include <stdio.h>
#include "flex_lcd.h"

void main(void) {
    //Variables 
    int adc;
    float voltaje;
    unsigned char buffer1[16];
    ////Oscilador Fosc=32MHz
    OSCFRQbits.HFFRQ=0b110; //32MHz HFINTOSC
    //Puertos
    ANSELD=0;//Puerto D como Digital
    ANSELE=0;//Puerto E como Digital
    ANSELAbits.ANSA5=1;//RA5 como analogico
    TRISAbits.TRISA5=1;//RA5 como entrada 
    //convertidor Analogico a digital
    ADCON0bits.ADON=1;//ADC ON
    ADCON0bits.ADCONT=0;//Operacion normal 
    ADCON0bits.ADCS=1;//Clock Source=FCR
    ADCON0bits.ADFRM=1//Justificacion derecha 
    ADREFbits.ADPREF=0;//Vred----- vss
    ADREFbits.ADPREF=0b00;//Vref+ ----Vd
    ADPCH=0b000101;// canal ANSA5
    //******LCD
    Lcd_Init();//inicializar la lcd
    Lcd_Cmd(1);//Clear LCD
    Lcd_Cmd(12);//Cursor off
    __delay_ms(100);
    //Ciclo infinito
    while(1){
        ADCON0bits.ADGO=1;//inicia la conversion 
        while(ADCON0bits.ADGO==1);//Esperra a termino de conversion
        adc=ADRESH;
        adc=adc<<8;
        adc=adc+ADRESL;
        //adc=(ADRESH<<8)|ADRESL;
        voltaje=adc*3.3/1023.0;//Conversiona voltaje 
        sprintf(buffer1,"adc=%04d",adc);
        Lcd_Out2(1,1,buffer1);
        sprintf(buffer1,"vol=%0.2f",voltaje);
        Lcd_Out2(2,1,buffer1);
        __delay_ms(500);
    }
    
    return;
}
