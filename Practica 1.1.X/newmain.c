// CONFIG1
	#pragma config FEXTOSC = OFF    // External Oscillator mode selection bits (Oscillator not enabled)
	#pragma config RSTOSC = HFINTPLL
	#pragma config CLKOUTEN = OFF   // Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
	#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
	#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (FSCM timer enabled)
	

	// CONFIG2
	#pragma config MCLRE = ON       // Master Clear Enable bit (MCLR pin is Master Clear function)
	#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
	#pragma config LPBOREN = OFF    // Low-Power BOR enable bit (ULPBOR disabled)
	#pragma config BOREN = ON       // Brown-out reset enable bits (Brown-out Reset Enabled, SBOREN bit is ignored)
	#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices)
	#pragma config ZCD = OFF        // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
	#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit can be cleared and set only once in software)
	#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)
	

	// CONFIG3
	#pragma config WDTCPS = WDTCPS_31// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
	#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled, SWDTEN is ignored)
	#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
	#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)
	

	// CONFIG4
	#pragma config WRT = OFF        // UserNVM self-write protection bits (Write protection off)
	#pragma config SCANE = available// Scanner Enable bit (Scanner module is available for use)
	#pragma config LVP = ON         // Low Voltage Programming Enable bit (Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.)
	

	// CONFIG5
	#pragma config CP = OFF         // UserNVM Program memory code protection bit (Program Memory code protection disabled)
	#pragma config CPD = OFF        // DataNVM code protection bit (Data EEPROM code protection disabled)




// 0.Sección de documentación 
	// main.c
	// Dispositivo: PIC16F18877
	// Práctica 1.1 
	// Autores: Gabriel Casarrubias Guerrero
	// Fecha: Agosto 14, 2018
	

	// I/O List
	//Inputs************************************************************************
	

	//Outputs***********************************************************************
	// LED en RB0
	

	// 1. Sección Directivas pre-proceso
	// Incluir librerías
	#include <xc.h>  //Esta es la librería principal del compilador
	//en ella se encuentran todas las definiciones para el microcontrolador utilizado
	#include "config.h"
	// Definiciones
	#define _XTAL_FREQ 32000000
	// Macros
	

	

	// 2. Sección de declaraciones
	//   Variables Globales
	

	

	//   Prototipos de funciones
	

	

	

	// 3. Sección de subrutinas
	// MAIN: obligatorio para un programa en C
	void main(void) {
	    
	    //Configuración del Oscilador
	    //OSCCON1bits.NOSC=0b110;
	    // OSCCON1bits.NDIV=0b000;
	    OSCFRQbits.HFFRQ=0b101; //Selecciona la frecuencia de 16MHz del INTOSC
	    //Configuración de puertos
	    PORTB=0;    //Limpia puerto B
	    TRISB=0;    //Puerto B como salidas
	    ANSELB=0;   //Puerto B como digital
	 
	//4. Inicia ciclo infinito
	    while(1){
	        LATBbits.LATB7=~LATBbits.LATB7;  //Toggle bits RB0
	        __delay_ms(1000);                //Espera 1 segundo
	    }
	    return;
	}
	

	// Subrutinas 
	

	


