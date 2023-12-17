/*
 * L298_interface.h
 *
 *  Created on: Apr 13, 2023
 *      Author: MERNA
 */

#ifndef L298_INTERFACE_H_
#define L298_INTERFACE_H_


/********************************** Macros *****************************************/
#define L298_PORTA			0
#define L298_PORTB			1
#define L298_PORTC			2


#define L298_RCC_PORTA_EN		2
#define L298_RCC_PORTB_EN		3
#define L298_RCC_PORTC_EN		4




/*********************************** Prototypes ****************************************/


void L298_vInit(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin);

void L298_vMoveForward(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin);

void L298_vMoveBackward(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin);

void L298_vStop(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin);

void CAR_vMoveForward(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin , uint8 Copy_u8IN3Pin , uint8 Copy_u8IN4Pin);

void CAR_vMoveBackward(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin , uint8 Copy_u8IN3Pin , uint8 Copy_u8IN4Pin);

void CAR_vMoveLeft(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin , uint8 Copy_u8IN3Pin , uint8 Copy_u8IN4Pin);

void CAR_vMoveRight(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin , uint8 Copy_u8IN3Pin , uint8 Copy_u8IN4Pin);

void CAR_vStop(uint8 Copy_u8Port , uint8 Copy_u8IN1Pin , uint8 Copy_u8IN2Pin , uint8 Copy_u8IN3Pin , uint8 Copy_u8IN4Pin);




#endif /* L298_INTERFACE_H_ */
