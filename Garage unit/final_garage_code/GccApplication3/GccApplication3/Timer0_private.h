/*
 * Timer_private.h
 *
 * Created: 9/8/2022 2:51:48 AM
 *  Author: Abanoub Ibrahim Yanni
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TIMER_uint8_TCCR0_REG    *((volatile uint8*)0x53)

#define TIMER_uint8_TCNT0_REG    *((volatile uint8*)0x52)

#define TIMER_uint8_OCR0_REG    *((volatile uint8*)0x5C)

/* interrupt registers */

#define TIMER_uint8_TIMSK_REG    *((volatile uint8*)0x59)//to mask/unmask timer interrupts

#define TIMER_uint8_TIFR_REG    *((volatile uint8*)0x58)//for pulling on the flag instead of using ISR


#define Stop                    			0
#define No_prescaler                    	1
#define clk_dividedby_8                   	2
#define clk_dividedby_64                  	3
#define clk_dividedby_256                  	4
#define clk_dividedby_1024                  5
#define external_clk_T0_falling_edge    	6
#define external_clk_T0_raising_edge		7



#endif /* TIMER0_PRIVATE_H_ */
