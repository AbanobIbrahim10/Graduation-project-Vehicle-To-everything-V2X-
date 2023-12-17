/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _TIMER_PRIVATE_H
#define _TIMER_PRIVATE_H

#define TIM1_BASE_ADDRESS			0x40012C00
#define TIM2_BASE_ADDRESS			0x40000000
#define TIM3_BASE_ADDRESS			0x40000400
#define TIM4_BASE_ADDRESS			0x40000800


typedef struct 
{
	volatile uint32 CR1;
	volatile uint32	CR2;
	volatile uint32	SMCR;
	volatile uint32	DIER;
	volatile uint32	SR;
	volatile uint32	EGR;
	volatile uint32	CCMR1;
	volatile uint32	CCMR2;
	volatile uint32	CCER;
	volatile uint32	CNT;
	volatile uint32 PSC;
	volatile uint32 ARR;
	volatile uint32 RCR;
	volatile uint32 CCR1;
	volatile uint32 CCR2;
	volatile uint32 CCR3;
	volatile uint32 CCR4;
	volatile uint32 BDTR;
	volatile uint32 DCR;
	volatile uint32 DMAR;
}TIMER_Reg_t;


#define TIMER1		((TIMER_Reg_t*)TIM1_BASE_ADDRESS)
#define TIMER2		((TIMER_Reg_t*)TIM2_BASE_ADDRESS)
#define TIMER3		((TIMER_Reg_t*)TIM3_BASE_ADDRESS)
#define TIMER4		((TIMER_Reg_t*)TIM4_BASE_ADDRESS)

#endif