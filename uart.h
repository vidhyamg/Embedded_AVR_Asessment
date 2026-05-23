/*
 * uart.h
 *
 * Created: 5/23/2026 10:55:44 PM
 *  Author: deepu
 */ 


#ifndef UART_H_
#define UART_H_

void uart_init();
void uart_transmit(char data);
void uart_string(char *str);


#endif /* UART_H_ */