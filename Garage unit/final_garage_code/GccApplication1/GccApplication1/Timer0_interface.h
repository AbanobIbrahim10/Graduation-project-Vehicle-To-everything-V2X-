/*
 * Timer0_interface.h
 *
 * Created: 9/8/2022 1:20:02 AM
 *  Author: Abanoub Ibrahim Yanni
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


void Timer0VoidInit(void);
void TimerVoidSetCallBackForCompM (void (*CopyPF_TMRCallBack) (void));
void TimerVoidSetCallBackForOvrf (void (*CopyPF_TMRCallBack) (void));

void Timer0_u8PreLoder(uint8 Copy_u8Preloader);

uint8 Timer0uint8_getRegisterValue(void);


#endif /* TIMER0_INTERFACE_H_ */
