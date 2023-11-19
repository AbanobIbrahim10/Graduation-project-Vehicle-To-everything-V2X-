/*
 * GccApplication4.c
 *
 * Created: 7/4/2023 1:09:38 PM
 * Author : LENOVO
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include"DIO.h"
#include"UART.h"
#include"std_macros.h"
#include"std_types.h"

int main(void)
{
	UART_Init();
	DIO_vsetPINDir('A',0,1);
	//DIO_vsetPINDir('A',1,1);
	//DIO_vsetPINDir('A',2,1);
	//DIO_vsetPINDir('A',3,1);
	DIO_write('A',0,1);
	//DIO_write('A',1,1);
	//DIO_write('A',2,1);
	//DIO_write('A',3,1);
	//uint8 local_u8recive1;
	//uint8 local_i=0;
    /* Replace with your application code */
    while (1) 
    {
		
		if(UART_GetChar()== '1')
		{
			DIO_write('A',0,0);
			_delay_ms(5000);
		}
		
    }
}

