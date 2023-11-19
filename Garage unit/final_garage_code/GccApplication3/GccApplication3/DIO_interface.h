/*
 * DIO_interface.h
 *
 * Created: 8/30/2022 1:53:54 AM
 *  Author: bebob
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"


/* MACROS FOR PORT ID */
#define DIO_uint8_PORTA   0 
#define DIO_uint8_PORTB   1
#define DIO_uint8_PORTC   2
#define DIO_uint8_PORTD   3

/* MACROS FOR PIN ID */

#define DIO_uint8_PIN0    0
#define DIO_uint8_PIN1    1
#define DIO_uint8_PIN2    2
#define DIO_uint8_PIN3    3
#define DIO_uint8_PIN4    4
#define DIO_uint8_PIN5    5
#define DIO_uint8_PIN6    6
#define DIO_uint8_PIN7    7



/* MACROS FOR PIN DIRECTION */

#define DIO_uint8_OUTPUT             0
#define DIO_uint8_INPUT_FLOATING	 1
#define DIO_uint8_INPUT_PULL_UP		 2

/* MACROS FOR OUTPUT  */
#define DIO_uint8_HIGH   1
#define DIO_uint8_LOW    0



/* PROTOTYPES OF THE PUBLIC FUNCTIONS */

void DIO_voidInit(void);
uint8 DIO_uint8SetPinDirection(uint8 Copy_uint8PortId,uint8 Copy_uint8PinId,uint8 Copy_uint8Direction);
uint8 DIO_uint8SetPinValue(uint8 Copy_uint8PortId,uint8 Copy_uint8PinId,uint8 Copy_uint8PinValue);
uint8 DIO_uint8ReadPinValue(uint8 Copy_uint8PortId,uint8 Copy_uint8PinId,uint8* Copy_Puint8ReturnedValue);
uint8 DIO_uint8SetPortValue(uint8 Copy_u8PortId, uint8 Copy_u8PortValue);

#endif /* DIO_INTERFACE_H_ */
