/*
 * MPU6050_interface.h
 *
 *  Created on: Apr 21, 2023
 *      Author: MERNA
 */

#ifndef MPU6050_INTERFACE_H_
#define MPU6050_INTERFACE_H_


#define MPU_SENSITIVITY		6

void MPU6050_vInit(void);

uint8 MPU6050_vReadRegisterValue(uint8 Copy_u8Address);

void MPU6050_vReadGyro_X(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte);

void MPU6050_vReadGyro_Y(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte);

void MPU6050_vReadGyro_Z(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte);

void MPU6050_vReadAccel_X(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte);

void MPU6050_vReadAccel_Y(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte);

void MPU6050_vReadAccel_Z(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte);

void MPU6050_vReadGyro_ALL(sint16 *Copy_u16Buffer);

void MPU6050_vReadAccel_ALL(sint16 *Copy_u16Buffer);

uint8 MPU6050_vDetectChange(double *old);


#endif /* MPU6050_INTERFACE_H_ */
