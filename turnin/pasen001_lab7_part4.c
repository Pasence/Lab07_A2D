/*	Author: Peter John Asence
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #7  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://youtu.be/7-vapDounZE 
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN | 1 << ADSC | 1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	DDRA = 0x00; PORTA = 0xFF;
    /* Insert your solution below */
	ADC_init();
       	unsigned short x;
	//unsigned char B_LEDS;
	//unsigned char D_LEDS;
	unsigned char max = 195; // about 195 depends on the intensity of the light	
    while (1) {
	x = ADC; // short = 16 bits
	//B_LEDS = (char)x;	// char = 8 bits
	//D_LEDS =(char)(x >> 8);
	//PORTB = B_LEDS;
	//PORTD = D_LEDS;
	if( x == 0) PORTB = 0x00;
	else if (x >= 194) PORTB = 0xFF;
	else if (x >= 171) PORTB = 0x7F;
	else if (x >= 147) PORTB = 0x3F;
	else if (x >= 123) PORTB = 0x1F;
	else if (x >= 99) PORTB = 0x0F;
	else if (x >= 75) PORTB = 0x07;
	else if (x >= 51) PORTB = 0x03;
	else if (x >= 6) PORTB = 0x01;
	
    }
    return 1;
}
