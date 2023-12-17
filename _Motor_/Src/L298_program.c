/*
 * L298_program.c
 *
 *  Created on: Apr 13, 2023
 *      Author: MERNA
 */

#include "STD_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "L298_interface.h"


/*****************************************************************************************/

void L298_vInit(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin)
{
	//Enable peripheral
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS,Copy_u8Port+2);
	//set IN pins as output
	GPIO_vSetPinMode(Copy_u8Port,Copy_u8IN1Pin,GPIO_PIN_OUTPUT_SPD_50);
	GPIO_vSetPinMode(Copy_u8Port,Copy_u8IN2Pin,GPIO_PIN_OUTPUT_SPD_50);

	GPIO_vSetPinConfig(Copy_u8Port,Copy_u8IN1Pin,GPIO_OUT_PUSHPULL);
	GPIO_vSetPinConfig(Copy_u8Port,Copy_u8IN2Pin,GPIO_OUT_PUSHPULL);
}

/*****************************************************************************************/

void L298_vMoveForward(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin)
{
	GPIO_vSetPinValue(Copy_u8Port,Copy_u8IN2Pin,0);
	GPIO_vSetPinValue(Copy_u8Port,Copy_u8IN1Pin,1);
}

/*****************************************************************************************/

void L298_vMoveBackward(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin)
{
	GPIO_vSetPinValue(Copy_u8Port,Copy_u8IN1Pin,0);
	GPIO_vSetPinValue(Copy_u8Port,Copy_u8IN2Pin,1);
}

/*****************************************************************************************/

void L298_vStop(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin)
{
	GPIO_vSetPinValue(Copy_u8Port,Copy_u8IN1Pin,0);
	GPIO_vSetPinValue(Copy_u8Port,Copy_u8IN2Pin,0);
}

/*****************************************************************************************/

void CAR_vMoveForward(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin , uint8 Copy_u8IN3Pin , uint8 Copy_u8IN4Pin)
{
	L298_vMoveForward(Copy_u8Port,Copy_u8IN1Pin,Copy_u8IN2Pin);
	L298_vMoveForward(Copy_u8Port,Copy_u8IN3Pin,Copy_u8IN4Pin);
}


/*****************************************************************************************/
void CAR_vMoveBackward(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin , uint8 Copy_u8IN3Pin , uint8 Copy_u8IN4Pin)
{
	L298_vMoveBackward(Copy_u8Port,Copy_u8IN1Pin,Copy_u8IN2Pin);
	L298_vMoveBackward(Copy_u8Port,Copy_u8IN3Pin,Copy_u8IN4Pin);
}


/*****************************************************************************************/


void CAR_vMoveLeft(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin , uint8 Copy_u8IN3Pin , uint8 Copy_u8IN4Pin)
{
	L298_vStop(Copy_u8Port,Copy_u8IN1Pin,Copy_u8IN2Pin);
	L298_vMoveForward(Copy_u8Port,Copy_u8IN3Pin,Copy_u8IN4Pin);
}

/*****************************************************************************************/

void CAR_vMoveRight(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin , uint8 Copy_u8IN3Pin , uint8 Copy_u8IN4Pin)
{
	L298_vStop(Copy_u8Port,Copy_u8IN3Pin,Copy_u8IN4Pin);
	L298_vMoveForward(Copy_u8Port,Copy_u8IN1Pin,Copy_u8IN2Pin);
}

/*****************************************************************************************/


void CAR_vStop(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin , uint8 Copy_u8IN3Pin , uint8 Copy_u8IN4Pin)
{
	L298_vStop(Copy_u8Port,Copy_u8IN1Pin,Copy_u8IN2Pin);
	L298_vStop(Copy_u8Port,Copy_u8IN3Pin,Copy_u8IN4Pin);
}

/*****************************************************************************************/
