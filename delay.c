/*
 * delay.c
 *
 * Created: 5/23/2026 11:13:06 PM
 *  Author: deepu
 */ 
#include "delay.h"

void my_delay_ms(unsigned int ms)
{
	volatile unsigned long i,j;

	for(i=0;i<ms;i++)
	{
		for(j=0;j<1000;j++);
	}
}