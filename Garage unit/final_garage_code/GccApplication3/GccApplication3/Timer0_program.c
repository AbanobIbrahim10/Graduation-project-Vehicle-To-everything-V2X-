/*
 * Timer0_program.c
 *
 * Created: 9/8/2022 1:19:37 AM
 *  Author: Abanoub Ibrahim Yanni
 */ 


#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "Timer0_interface.h"
#include "Timer0_config.h"
#include "DIO_interface.h"
#include "Timer0_private.h"

//extern unsigned int x;


static void (*APF_TimerInterrupts[2]) (void) = {NULL,NULL};

void Timer0VoidInit(void)
{

#ifdef normal_mode

	//Normal Mode
	CLR_BIT(TIMER_uint8_TCCR0_REG,3);
	CLR_BIT(TIMER_uint8_TCCR0_REG,6);
	/* turn on timer maskable interrupt flag */
	SET_BIT(TIMER_uint8_TIMSK_REG,0);
	//preloading timer0 register by zero by default
	TIMER_uint8_TCNT0_REG=0;
#ifdef TIMER_PreLoad
	/* if we want to count from a aspecific number */
	TIMER_uint8_TCNT0_REG= TIMER_PreLoad ;
#endif
#endif

#ifdef CTC_mode

	//CTC MOde
	SET_BIT(TIMER_uint8_TCCR0_REG,3);
	CLR_BIT(TIMER_uint8_TCCR0_REG,6);
	//output on compare match
	/*DIO_uint8SetPinDirection(DIO_uint8_PORTB,DIO_uint8_PIN3,DIO_uint8_OUTPUT);
	  CLR_BIT(TIMER_uint8_TCCR0_REG,4);
	SET_BIT(TIMER_uint8_TCCR0_REG,5);
	 */
	//enable the compare match inturrpt from TIMSK register
	SET_BIT(TIMER_uint8_TIMSK_REG,1);
	//put value on compare match register (OCR0)
	TIMER_uint8_OCR0_REG=Compare_match_value;


#endif
#ifdef fast_pwm_mode

	//fast pwm MOde
	SET_BIT(TIMER_uint8_TCCR0_REG,3);
	SET_BIT(TIMER_uint8_TCCR0_REG,6);
	//in order to use pin OC0 to generate fast PWM
	DIO_uint8SetPinDirection(DIO_uint8_PORTB,DIO_uint8_PIN3,DIO_uint8_OUTPUT);
	//choosing the shape of output waveform from OC0
	//set on compare match clear on overflow
	CLR_BIT(TIMER_uint8_TCCR0_REG,4);
	SET_BIT(TIMER_uint8_TCCR0_REG,5);
	//put the value of the compare match register
	TIMER_uint8_OCR0_REG=Compare_match_value;
//in case you want to use ISR during generating PWM
/*
	//enable the compare match inturrpt from TIMSK register
		SET_BIT(TIMER_uint8_TIMSK_REG,1);
	//enable the overflow inturrpt from TIMSK register
		SET_BIT(TIMER_uint8_TIMSK_REG,0);
*/
#endif

#ifdef phase_correct_pwm

	//fast pwm MOde
	CLR_BIT(TIMER_uint8_TCCR0_REG,3);
	SET_BIT(TIMER_uint8_TCCR0_REG,6);
	//in order to use pin OC0 to generate fast PWM
	DIO_uint8SetPinDirection(DIO_uint8_PORTB,DIO_uint8_PIN3,DIO_uint8_OUTPUT);
	//put the value of the compare match register
	TIMER_uint8_OCR0_REG=Compare_match_value;
	//Set OC0 on compare match when up-counting, Clear OC0 on compare match when downcounting.
	CLR_BIT(TIMER_uint8_TCCR0_REG,4);
	SET_BIT(TIMER_uint8_TCCR0_REG,5);
	/*
		//enable the compare match inturrpt from TIMSK register
			SET_BIT(TIMER_uint8_TIMSK_REG,1);*/
		//enable the overflow inturrpt from TIMSK register
			SET_BIT(TIMER_uint8_TIMSK_REG,0);

#endif





#if  (PreScaler==Stop)
	//start timer by set prescaler
	CLR_BIT(TIMER_uint8_TCCR0_REG,0);
	CLR_BIT(TIMER_uint8_TCCR0_REG,1);
	CLR_BIT(TIMER_uint8_TCCR0_REG,2);
#elif  (PreScaler==No_prescaler)
	//start timer by set prescaler
	SET_BIT(TIMER_uint8_TCCR0_REG,0);
	CLR_BIT(TIMER_uint8_TCCR0_REG,1);
	CLR_BIT(TIMER_uint8_TCCR0_REG,2);
#elif  (PreScaler==clk_dividedby_256)
	//start timer by set prescaler
	CLR_BIT(TIMER_uint8_TCCR0_REG,0);
	CLR_BIT(TIMER_uint8_TCCR0_REG,1);
	SET_BIT(TIMER_uint8_TCCR0_REG,2);
#elif  (PreScaler==clk_dividedby_1024)
	//start timer by set prescaler
	SET_BIT(TIMER_uint8_TCCR0_REG,0);
	CLR_BIT(TIMER_uint8_TCCR0_REG,1);
	SET_BIT(TIMER_uint8_TCCR0_REG,2);

#elif  (PreScaler==clk_dividedby_8)
	//start timer by set prescaler
	CLR_BIT(TIMER_uint8_TCCR0_REG,0);
	SET_BIT(TIMER_uint8_TCCR0_REG,1);
	CLR_BIT(TIMER_uint8_TCCR0_REG,2);
#elif  (PreScaler==clk_dividedby_64)
	//start timer by set prescaler
	SET_BIT(TIMER_uint8_TCCR0_REG,0);
	SET_BIT(TIMER_uint8_TCCR0_REG,1);
	CLR_BIT(TIMER_uint8_TCCR0_REG,2);
#elif  (PreScaler==external_clk_T0_falling_edge)
	//start timer by set prescaler
	CLR_BIT(TIMER_uint8_TCCR0_REG,0);
	SET_BIT(TIMER_uint8_TCCR0_REG,1);
	SET_BIT(TIMER_uint8_TCCR0_REG,2);
	#ifdef TIMER_PreLoad
	TIMER_uint8_TCNT0_REG= TIMER_PreLoad ;
	#endif
#elif  (PreScaler==external_clk_T0_raising_edge)
	//start timer by set prescaler
	SET_BIT(TIMER_uint8_TCCR0_REG,0);
	SET_BIT(TIMER_uint8_TCCR0_REG,1);
	SET_BIT(TIMER_uint8_TCCR0_REG,2);
	#ifdef TIMER_PreLoad
	TIMER_uint8_TCNT0_REG= TIMER_PreLoad ;
	#endif


#endif


}

void Timer0_u8PreLoder(uint8 Copy_u8Preloader)
{
	TIMER_uint8_TCNT0_REG=Copy_u8Preloader;
}

void TimerVoidSetCallBackForOvrf (void (*CopyPF_TMRCallBack) (void))
{
	/* put the address from the user into my pointer to function */

	APF_TimerInterrupts[0]=CopyPF_TMRCallBack;
}
void TimerVoidSetCallBackForCompM (void (*CopyPF_TMRCallBack) (void))
{
	/* put the address from the user into my pointer to function */
	APF_TimerInterrupts[1]=CopyPF_TMRCallBack;
}


uint8 Timer0uint8_getRegisterValue(void)
{
	uint8 x=TIMER_uint8_TCNT0_REG;

	return x;
}



/* interrupt service routine which call a function in upper layers using call back concept */


ISR(TIMER0_OVF_vect)
{


	APF_TimerInterrupts[0]();



#ifdef TIMER_PreLoad
	// if we want to count from a aspecific number
	TIMER_uint8_TCNT0_REG= TIMER_PreLoad ;
#endif


}

//compare match interrupt service routine
void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{


}


