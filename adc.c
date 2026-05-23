/*
 * adc.c
 *
 * Created: 5/22/2026 9:56:56 PM
 *  Author: deepu
 */
#define F_CPU 16000000UL 
#include <avr/io.h>
#include "adc.h"
void adc_init(void)
{
	ADMUX |= (1<< REFS0);//set Aref=AVcc=5v
	ADCSRA |= (1<<ADEN) | (1<< ADPS0)|(1<<ADPS1)|(1<<ADPS2);//ADC enabled;preascalr set to 128->adc freq=125Khz		
}

uint16_t adc_read(uint8_t channel)
{
	channel &= 0x07; //channel limited to 7;
	ADMUX = (ADMUX &0xF8); //selected channel without affecting other bits of ADMUX
	ADCSRA |=(1<<ADSC); // start conversion
	while(ADCSRA &(1<<ADSC)); // wait until conversion
	return(ADC);
}