/*
 * ULTRA_program.c
 *
 *  Created on: May 2, 2023
 *      Author: MERNA
 */


#include "STD_types.h"
#include "BIT_math.h"
#include "RCC_interface.h"
#include "TIMER_private.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "ULTRA_config.h"
#include "ULTRA_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_interface.h"

static void ULTRA_vSendTrigger(void)
{
	#if ULTRA_TRIG_PORT == GPIO_PORT_A
	GPIOA->ODR |= (1<<ULTRA_TRIG_PIN);
	TIMER2->ARR = 50;
	TIMER2->CR1 |= (1<<0);
	while(READ_BIT(TIMER2->SR,0)==0);
	TIMER2->CR1 &= ~(1<<0);
	CLR_BIT(TIMER2->SR,0);
	GPIOA->ODR &= ~(1<<ULTRA_TRIG_PIN);

	#elif ULTRA_TRIG_PORT == GPIO_PORT_B
	GPIOB->ODR |= (1<<ULTRA_TRIG_PIN);
	TIMER2->ARR = 50;
	TIMER2->CR1 |= (1<<0);
	while(READ_BIT(TIMER2->SR,0)==0);
	TIMER2->CR1 &= ~(1<<0);
	CLR_BIT(TIMER2->SR,0);
	GPIOB->ODR &= ~(1<<ULTRA_TRIG_PIN);

	#elif ULTRA_TRIG_PORT == GPIO_PORT_C
	GPIOC->ODR |= (1<<ULTRA_TRIG_PIN);
	TIMER2->ARR = 50;
	TIMER2->CR1 |= (1<<0);
	while(READ_BIT(TIMER2->SR,0)==0);
	TIMER2->CR1 &= ~(1<<0);
	CLR_BIT(TIMER2->SR,0);
	GPIOC->ODR &= ~(1<<ULTRA_TRIG_PIN);
	#endif
}
void ULTRA_vInit(void)
{
	/* Initialize TIM2 */

	//Enable TIMER2
	RCC_u8EnablePeripheralClk(RCC_u8_APB1_BUS, TIM2EN);
	TIMER2->PSC = 8-1 ;	//prescaler = 8

	/* enable trigger port */
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, ULTRA_TRIG_RCC_EN);

	/* enable echo port */
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, ULTRA_ECHO_RCC_EN);

	/* define echo pin as input */
	GPIO_vSetPinMode(ULTRA_ECHO_PORT, ULTRA_ECHO_PIN , GPIO_PIN_INPUT);
	GPIO_vSetPinConfig(ULTRA_ECHO_PORT, ULTRA_ECHO_PIN, GPIO_IN_PULL);

	/* define trigger pin as output */
	GPIO_vSetPinMode(ULTRA_TRIG_PORT, ULTRA_TRIG_PIN, GPIO_PIN_OUTPUT_SPD_50);
	GPIO_vSetPinConfig(ULTRA_TRIG_PORT, ULTRA_TRIG_PIN, GPIO_OUT_PUSHPULL);
}

uint16 ULTRA_u16GetDistance(void)
{
	uint32 LOC_time = 0;
	uint32 LOC_FirstChange = 0 , LOC_SecChange = 0;
	uint16 Return_distance = 0;

	STK->LOAD = 0x00FFFFFF;
	//start timer
	SET_BIT(STK->CTRL,STK_ENABLE);

	ULTRA_vSendTrigger();

	while(GPIO_u8GetPinValue(ULTRA_ECHO_PORT, ULTRA_ECHO_PIN) == 0 && LOC_time < ULTRA_TIMEOUT_TRIG)
	{
		LOC_time++;
	}
	LOC_FirstChange = SYSTICK_u32GetElapsedTime();
	while(GPIO_u8GetPinValue(ULTRA_ECHO_PORT, ULTRA_ECHO_PIN) == 1 && LOC_time < ULTRA_TIMEOUT_ECHO)
	{
		LOC_time++;
	}
	LOC_SecChange = SYSTICK_u32GetElapsedTime();
	//stop timer
	CLR_BIT(STK->CTRL,STK_ENABLE);
	STK->LOAD=0;
	STK->VAL=0;

	Return_distance = SOUND_SPEED*(LOC_SecChange-LOC_FirstChange)/(1000000*2);

	if (LOC_time >= ULTRA_TIMEOUT_ECHO)
	{
		Return_distance=0xFFFF;
	}
	return Return_distance;

}

