/*
 * EXTI_interface.h
 *
 *  Created on: Oct 2, 2021
 *      Author: KeroEmad
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void EXTI_voidEnable(void);

typedef enum {

	EXIT_uint8EXIT_0=0,
	EXIT_uint8EXIT_1,
	EXIT_uint8EXIT_2





}EXTINum_t;
typedef enum {

	EXTI_uint8_FALLING_EDGE=0,
	EXTI_uint8_RAISSING_EDGE,
	EXTI_uint8_ANY_LOGICAL_CHANGE,
	EXTI_uint8_LOW_LEVEL





}EXTITriggerSource_t;



uint8 EXTIinit (EXTINum_t copy_EnuEXTINum,EXTITriggerSource_t Copy_EnuTriggerSource);
//uint8 EXTI_u8Enable (EXTINum_t CopyEnuEXTINum);
//uint8 EXTI_u8Disable (EXTINum_t CopyEnuEXTINum);
uint8 EXTI_SetCallBack(EXTINum_t Copy_EnuEXTINum,void (*Copy_Pf)(void));
//u8 EXIT_u8Enable(,);

#endif /* EXTI_INTERFACE_H_ */
