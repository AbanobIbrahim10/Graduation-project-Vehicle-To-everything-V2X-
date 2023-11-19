/*
 * UART_testing.c
 *
 * Created: 7/5/2023 11:20:33 AM
 * Author : SEMON
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include "USART.h"
#include "std_macros.h"
#include <util/delay.h>


int main(void)
{
	UART_vInit(9600);
	DDRB|=0x06;
	CLR_BIT(PORTB,3);
	TOG_BIT(PORTB,3);
	CLR_BIT(PORTB,1);
	CLR_BIT(PORTB,2);
	
	char x;
	while(1)
	{
		x=UART_u8ReceiveData();
		if(x=='3')
		{
				SET_BIT(PORTB,1);
				_delay_ms(3000);
				
		}
		UART_vSendData('2');
		SET_BIT(PORTB,2);
		
		
		
	}
}

