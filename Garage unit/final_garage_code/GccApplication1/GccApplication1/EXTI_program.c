/*
 * EXTI_prog.c

 *
 *  Created on: Oct 2, 2021
 *      Author: KeroEmad
 */
#include "STD_Types.h"

#include "DIO_interface.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
static void (*EXTI_APF[3])(void)={NULL,NULL,NULL};

uint8 EXTIinit (EXTINum_t copy_EnuEXTINum,EXTITriggerSource_t Copy_EnuTriggerSource)
{

	uint8 Local_uint8ErrorState=STD_TYPES_OK;



	switch(copy_EnuEXTINum){
		case EXIT_uint8EXIT_0:
			//DIO_uint8SetPinDirection(DIO_uint8_PORTD,DIO_uint8_PIN2,DIO_uint8_INPUT_FLOATING);
			switch (Copy_EnuTriggerSource)
				{
				case EXTI_uint8_ANY_LOGICAL_CHANGE:
					CLR_BIT(EXTI_uint8_MCUCR_REG,1);
					SET_BIT(EXTI_uint8_MCUCR_REG,0);
					SET_BIT(EXTI_uint8_GICR_REG,6);
					break;
				case EXTI_uint8_FALLING_EDGE:
					SET_BIT(EXTI_uint8_MCUCR_REG,1);
					CLR_BIT(EXTI_uint8_MCUCR_REG,0);
					SET_BIT(EXTI_uint8_GICR_REG,6);
					break;
				case EXTI_uint8_RAISSING_EDGE:
					SET_BIT(EXTI_uint8_MCUCR_REG,1);
					SET_BIT(EXTI_uint8_MCUCR_REG,0);
					SET_BIT(EXTI_uint8_GICR_REG,6);
					break;
				case EXTI_uint8_LOW_LEVEL:
					CLR_BIT(EXTI_uint8_MCUCR_REG,1);
					CLR_BIT(EXTI_uint8_MCUCR_REG,0);
					SET_BIT(EXTI_uint8_GICR_REG,6);
					break;
				default:
					Local_uint8ErrorState=STD_TYPES_NOT_OK;
					break;
				}



			break;

		case EXIT_uint8EXIT_1:



			switch (Copy_EnuTriggerSource)
				{
				case EXTI_uint8_ANY_LOGICAL_CHANGE:
					CLR_BIT(EXTI_uint8_MCUCR_REG,3);
					SET_BIT(EXTI_uint8_MCUCR_REG,2);
					SET_BIT(EXTI_uint8_GICR_REG,7);
					break;
				case EXTI_uint8_FALLING_EDGE:
					SET_BIT(EXTI_uint8_MCUCR_REG,3);
					CLR_BIT(EXTI_uint8_MCUCR_REG,2);
					SET_BIT(EXTI_uint8_GICR_REG,7);
					break;
				case EXTI_uint8_RAISSING_EDGE:
					SET_BIT(EXTI_uint8_MCUCR_REG,3);
					SET_BIT(EXTI_uint8_MCUCR_REG,2);
					SET_BIT(EXTI_uint8_GICR_REG,7);
					break;
				case EXTI_uint8_LOW_LEVEL:
					CLR_BIT(EXTI_uint8_MCUCR_REG,3);
					CLR_BIT(EXTI_uint8_MCUCR_REG,2);
					SET_BIT(EXTI_uint8_GICR_REG,7);
					break;
				default:
					Local_uint8ErrorState=STD_TYPES_NOT_OK;
					break;
				}

			break;

		case EXIT_uint8EXIT_2:
			switch (Copy_EnuTriggerSource)
				{
				case EXTI_uint8_RAISSING_EDGE:
					SET_BIT(EXTI_uint8_MCUCSR_REG,6);
					SET_BIT(EXTI_uint8_GICR_REG,5);
					break;
				case EXTI_uint8_FALLING_EDGE:
					CLR_BIT(EXTI_uint8_MCUCSR_REG,6);
					SET_BIT(EXTI_uint8_GICR_REG,5);
					break;
				default:
					Local_uint8ErrorState=STD_TYPES_NOT_OK;
					break;
				}


			break;
		default:
			Local_uint8ErrorState=STD_TYPES_NOT_OK;
			break;

	}



return Local_uint8ErrorState;
}

uint8 EXTI_SetCallBack(EXTINum_t Copy_EnuEXTINum,void (*Copy_Pf)(void))
{
	uint8 Localuint8ErrorState=STD_TYPES_OK;
	if(Copy_EnuEXTINum>=0 && Copy_EnuEXTINum<=2 )
		EXTI_APF[Copy_EnuEXTINum]=Copy_Pf;
	else
	{
		Localuint8ErrorState=STD_TYPES_NOT_OK;
	}
	return Localuint8ErrorState;
}



//ISR of EXI0
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	if(EXTI_APF[0]!=NULL)
		EXTI_APF[0]();
}
//ISR of EXI1
void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	if(EXTI_APF[1]!=NULL)
		EXTI_APF[1]();
}
//ISR of EXI2
void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	if(EXTI_APF[2]!=NULL)
		EXTI_APF[2]();
}
//u8 EXTI_u8Enable (EXTINum_t CopyEnuEXTINum){
//	u8 Local_u8ErrorState=STD_TYPES_OK;
//	switch(CopyEnuEXTINum){
//
//
//	case EXIT_u8EXIT_0:SET_BIT(EXTI_u8_GICR_REG,6);break;
//	case EXIT_u8EXIT_1:SET_BIT(EXTI_u8_GICR_REG,7);break;
//	case EXIT_u8EXIT_2:SET_BIT(EXTI_u8_GICR_REG,5);break;
//
//	default : Local_u8ErrorState=STD_TYPES_NOK;break;
//
//
//
//
//}
//
//return Local_u8ErrorState;
//
//}
//
//
//u8 EXTI_u8Disable (EXTINum_t CopyEnuEXTINum){
//	u8 Local_u8ErrorState=STD_TYPES_OK;
//	switch(CopyEnuEXTINum){
//
//
//	case EXIT_u8EXIT_0:CLR_BIT(EXTI_u8_GICR_REG,6);break;
//	case EXIT_u8EXIT_1:CLR_BIT(EXTI_u8_GICR_REG,7);break;
//	case EXIT_u8EXIT_2:CLR_BIT(EXTI_u8_GICR_REG,5);break;
//
//	default : Local_u8ErrorState=STD_TYPES_NOK;break;
//
//
//
//
//}
//
//return Local_u8ErrorState;
//
//}
//u8 EXTI_SetCallBack(EXTINum_t Copy_EnuEXTINum,void (*Copy_Pf)(void)){
//
//	u8 Local_u8ErrorState=STD_TYPES_OK;
//
//	if ((Copy_Pf != NULL) && (Copy_EnuEXTINum >= EXIT_u8EXIT_0) && (Copy_EnuEXTINum <= EXIT_u8EXIT_2)){
//		EXTI_APF[Copy_EnuEXTINum]=Copy_Pf;
//
//
//
//
//
//
//	}
//
//	return Local_u8ErrorState;
//
//}
//
//void __vector_1(void) __attribute__((signal));
//void __vector_1(void){
//
//	if (EXTI_APF[EXIT_u8EXIT_0] != NULL){
//		EXTI_APF[EXIT_u8EXIT_0]();
//	}
//
//
//}
//
//void __vector_2(void) __attribute__((signal));
//void __vector_2(void){
//
//	if (EXTI_APF[EXIT_u8EXIT_1] != NULL){
//		EXTI_APF[EXIT_u8EXIT_1]();
//	}
//
//
//}
//
//void __vector_3(void) __attribute__((signal));
//void __vector_3(void){
//
//	if (EXTI_APF[EXIT_u8EXIT_2] != NULL){
//		EXTI_APF[EXIT_u8EXIT_2]();
//	}
//
//
//}
//
