/*
 * ma in.c
 *
 *  Created on: Dec 12, 2022
 *      Author: Abanoub
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "Timer0_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "LCD_interface.h"
#include "ultrasonic_interface.h"
#define F_CPU 1000000UL
#include <avr/delay.h>


u32 cntreveryov=0;
u32 distance=0;
uint8 globalflag=0;
uint8 globalflag2=0;
uint8 temp=0;


void overflow ();
void echo ();

int i=0;

int main ()
{
DIO_voidInit();
GIE_VoidEnable();
EXTI_SetCallBack(EXIT_uint8EXIT_0,echo);
EXTIinit(EXIT_uint8EXIT_0,EXTI_uint8_ANY_LOGICAL_CHANGE);
TimerVoidSetCallBackForOvrf(overflow);
_delay_ms(100);
LCD_vidInit();
Timer0VoidInit();

//LCD_vidWriteString("distance",sizeof("distance"));
//LCD_voidWriteNumber(distance);
while(1)
{

//DIO_uint8SetPinValue(DIO_uint8_PORTA,DIO_uint8_PIN1,DIO_uint8_HIGH);
//_delay_ms(1000);
//DIO_uint8SetPinValue(DIO_uint8_PORTA,DIO_uint8_PIN1,DIO_uint8_LOW);
//_delay_ms(1000);
	//LCD_vidWriteCharctr('m');
	//_delay_ms(10);
	//LCD_vidWriteCharctr('A');
	//_delay_ms(10);
	if(globalflag==0)
	{


		if (i>3)
			i=0;
		DIO_uint8SetPinValue(DIO_uint8_PORTC,DIO_uint8_PIN0,GET_BIT(i,0));
		DIO_uint8SetPinValue(DIO_uint8_PORTC,DIO_uint8_PIN1,GET_BIT(i,1));


		DIO_uint8SetPinValue(DIO_uint8_PORTD,DIO_uint8_PIN7,DIO_uint8_HIGH);
		_delay_us(20);
		DIO_uint8SetPinValue(DIO_uint8_PORTD,DIO_uint8_PIN7,DIO_uint8_LOW);
		globalflag=1;


	}

}




return 0;
}


void echo ()
{
	if(globalflag==1)
	{
		if(globalflag2==0)
		{
			cntreveryov=0;
			Timer0_u8PreLoder(0);
			globalflag2=1;


			//LCD_vidWriteCharctr('H');

		}
		else
		{

			temp=Timer0uint8_getRegisterValue();
			distance=(cntreveryov*256+temp)/58;
			//LCD_vidSendCommand(1);
			//Gotoxy(1,1);
			switch(i)
			{
			case 0:
				Gotoxy(1,1);
				LCD_vidWriteCharctr('L');
				LCD_vidWriteCharctr('1');
				LCD_vidWriteCharctr(':');

							break;
			case 1:
				Gotoxy(1,9);
				LCD_vidWriteCharctr('L');
				LCD_vidWriteCharctr('2');
				LCD_vidWriteCharctr(':');
					break;
			case 2:
				Gotoxy(2,1);
				LCD_vidWriteCharctr('L');
				LCD_vidWriteCharctr('3');
				LCD_vidWriteCharctr(':');
									break;
			case 3:
				Gotoxy(2,9);
				LCD_vidWriteCharctr('L');
				LCD_vidWriteCharctr('4');
				LCD_vidWriteCharctr(':');
									break;

			}
			LCD_voidWriteNumber(distance);
			LCD_vidWriteCharctr(' ');
			LCD_vidWriteCharctr(' ');
			_delay_ms(50);
			globalflag2=0;
			_delay_ms(1);
			globalflag=0;

		}

	}
}





int cntrof_i=0;
void overflow ()
{

cntreveryov++;
if(cntreveryov>71)  // 17 overflow = 300cm
{
	cntreveryov=0;
	globalflag=0;
	globalflag2=0;

	Timer0_u8PreLoder(0x00);

}
cntrof_i++;
if(cntrof_i>500){
	i++;
	//Gotoxy(1,1);
	//LCD_voidWriteNumber(i);
	cntrof_i=0;
}

}
