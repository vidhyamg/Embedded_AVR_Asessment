/*
 * LM35_ADC.c
 *
 * Created: 5/22/2026 9:53:10 PM
 * Author : deepu
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "adc.h"
#include "uart.h"
#include "delay.h"

int main(void)
{
	
	uint16_t adc_value;
	float temperature;
	adc_init();
	lcd_init();
	uart_init();
	char buffer[20];
    while (1) 
    {
		adc_value = adc_read(0); //read ADC channel 0
		temperature = adc_value * 0.488;
		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_print("Temperature:");
		lcd_set_cursor(1,0);
		lcd_print_float(temperature);
		lcd_data(0XDF); //Hex value for degree celsius sympol
		lcd_print("C");
		my_delay_ms(500);
		
		
		/*uart output*/
		uart_string("Temperature");
		uart_string(buffer);
		uart_string("\n");
		my_delay_ms(500);
		
		/*LED Blink*/
		PORTB^= (1<<PB0);
		my_delay_ms(500);
		
}
}

