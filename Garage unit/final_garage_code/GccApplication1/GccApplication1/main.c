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
#include <util/delay.h>

//void reserve ();
u32 cntreveryov=0;
u32 distance=0;
uint8 globalflag=0;
uint8 globalflag2=0;
uint8 temp=0;


void overflow ();
void echo ();

int i=0;
uint8 compare1;
uint8 compare2;

unsigned int arr_slots[4];
int main ()
{
	int Number_of_available_slots=0, sys_is_ready=0;
DIO_voidInit();
GIE_VoidEnable();
EXTI_SetCallBack(EXIT_uint8EXIT_0,echo);
//EXTI_SetCallBack(EXIT_uint8EXIT_1,reserve);

EXTIinit(EXIT_uint8EXIT_0,EXTI_uint8_ANY_LOGICAL_CHANGE);
//EXTIinit(EXIT_uint8EXIT_1,EXTI_uint8_ANY_LOGICAL_CHANGE);

TimerVoidSetCallBackForOvrf(overflow);
_delay_ms(1000);
LCD_vidInit();
Timer0VoidInit();
/*to display the reading of ultrasonics*/
/*Gotoxy(1,1);
LCD_vidWriteCharctr('L');
LCD_vidWriteCharctr('1');
LCD_vidWriteCharctr(':');
Gotoxy(1,9);
LCD_vidWriteCharctr('L');
LCD_vidWriteCharctr('2');
LCD_vidWriteCharctr(':');
Gotoxy(2,1);
LCD_vidWriteCharctr('L');
LCD_vidWriteCharctr('3');
LCD_vidWriteCharctr(':');
Gotoxy(2,9);
LCD_vidWriteCharctr('L');
LCD_vidWriteCharctr('4');
LCD_vidWriteCharctr(':');
*/
Gotoxy(1,1);
LCD_vidWriteCharctr('S');
LCD_vidWriteCharctr('l');
LCD_vidWriteCharctr('o');
LCD_vidWriteCharctr('t');
LCD_vidWriteCharctr('s');
LCD_vidWriteCharctr('=');

DIO_uint8SetPinDirection(DIO_uint8_PORTC,DIO_uint8_PIN2,DIO_uint8_OUTPUT);
DIO_uint8SetPinDirection(DIO_uint8_PORTC,DIO_uint8_PIN3,DIO_uint8_OUTPUT);

//DIO_uint8SetPinValue(DIO_uint8_PORTC,DIO_uint8_PIN2,DIO_uint8_LOW);

//int reservation_flag;
while(1)
{
	
	DIO_uint8SetPinValue(DIO_uint8_PORTC,DIO_uint8_PIN2,GET_BIT(Number_of_available_slots,0));
	DIO_uint8SetPinValue(DIO_uint8_PORTC,DIO_uint8_PIN3,GET_BIT(Number_of_available_slots,1));
	
	//DIO_uint8ReadPinValue(DIO_uint8_PORTC,DIO_uint8_PIN3,reservation_flag);
	
	if(globalflag==0)
	{


		if (i>3){
			sys_is_ready++;
			i=0;
		}
		DIO_uint8SetPinValue(DIO_uint8_PORTC,DIO_uint8_PIN0,GET_BIT(i,0));
		DIO_uint8SetPinValue(DIO_uint8_PORTC,DIO_uint8_PIN1,GET_BIT(i,1));


		DIO_uint8SetPinValue(DIO_uint8_PORTD,DIO_uint8_PIN7,DIO_uint8_HIGH);
		_delay_us(20);
		DIO_uint8SetPinValue(DIO_uint8_PORTD,DIO_uint8_PIN7,DIO_uint8_LOW);
		globalflag=1;


	}
	if(sys_is_ready>2)
	{
		sys_is_ready=0;
		for(int j=0;j<4;j++)
		{
			if(arr_slots[j]>10)
				Number_of_available_slots++;
		}
		Gotoxy(1,8);
		LCD_voidWriteNumber(Number_of_available_slots);
		Number_of_available_slots=0;
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
			DIO_uint8ReadPinValue(DIO_uint8_PORTC,DIO_uint8_PIN0,&compare1);
			DIO_uint8ReadPinValue(DIO_uint8_PORTC,DIO_uint8_PIN1,&compare2);
			if (i == ((compare2<<1)|compare1))
			{
			arr_slots[i]=distance;
			/*if you want to display the reading of all ultrasonics */
		/*	switch(i)
			{
			case 0:
				Gotoxy(1,4);
							break;
			case 1:
				Gotoxy(1,12);
					break;
			case 2:
				Gotoxy(2,4);
									break;
			case 3:
				Gotoxy(2,12);
									break;

			}
			LCD_voidWriteNumber(distance);
			LCD_vidWriteCharctr(' ');
			LCD_vidWriteCharctr(' ');*/
			}
			_delay_ms(10);
			globalflag2=0;
			_delay_ms(1);
			globalflag=0;
			cntreveryov=0;

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
if(cntrof_i>150){
	i++;
	//Gotoxy(1,1);
	//LCD_voidWriteNumber(i);
	cntrof_i=0;
}

}
/*void reserve ()
{	
	Number_of_available_slots--;
}*/