/*
 * uart.c
 *
 * Created: 5/23/2026 10:56:03 PM
 *  Author: deepu
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "uart.h"

void uart_init()
{
	/*load baud rate=9600
	F_CPU=16,000,000
	Baud_rate=9600
	value to be load = F_CPU /(16 * baud_rate)-1=104.9166 -1*/
	
	UBRR0H=0;
	UBRR0L=103;
	
/* Enable transmitter and receiver*/

UCSR0B |= ((1<< TXEN0) | (RXEN0));

/*choosing data frame format*/
UCSR0B &= ~(1<<UCSZ02);
UCSR0C |= ((1<< UCSZ01) | (1<<UCSZ00));

/*parity select bit*/
UCSR0C &= ~ ((1<<UPM00) |(1<<UPM01));

/*stop bit select*/
UCSR0C &= ~(1<< USBS0);
}

/*function to transmit data*/


void uart_transmit(char data)
{
	/*checking buffer is ready to transmit data*/
	while(UCSR0A &(1<<UDRE0));
	/*feed data to data buffer*/
	UDR0=data;
}
void uart_string(char *str)
{
	while(*str)
	{
		uart_transmit(*str++);
	}
}