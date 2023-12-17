/*
 * MPU6050_program.c
 *
 *  Created on: Apr 21, 2023
 *      Author: MERNA
 */




#include "STD_types.h"
#include "I2C_interface.h"
#include "MPU6050_reg.h"
#include "MPU6050_interface.h"
#include "math.h"

/***************************************************************************************************/


//double oldX = 0 , oldY = 0 , oldZ = 0;
//uint8 flag = 0;

/***************************************************************************************************/
void MPU6050_vInit(void)
{
	I2C_vStartCond();
		I2C_vWriteAddress(0xD0);
		I2C_vWriteData(PWR_MGMT_1);
		I2C_vWriteData(0x00);
		I2C_vStopCond();

		I2C_vStartCond();
		I2C_vWriteAddress(0xD0);
		I2C_vWriteData(CONFIG);
		I2C_vWriteData(0x01);  // LPF, bandwidth = 184(accel) and 188(gyro)
		I2C_vStopCond();

		I2C_vStartCond();
		I2C_vWriteAddress(0xD0);
		I2C_vWriteData(GYRO_CONFIG);
		I2C_vWriteData(1<<4); // gyro ADC scale: 1000 deg/s
		I2C_vStopCond();

		I2C_vStartCond();
		I2C_vWriteAddress(0xD0);
		I2C_vWriteData(ACCEL_CONFIG);
		I2C_vWriteData(0x10);
		I2C_vStopCond();

		I2C_vStartCond();
		I2C_vWriteAddress(0xD0);
		I2C_vWriteData(INT_ENABLE); //enable data ready interrupt  ->
		I2C_vWriteData(0x01);
		I2C_vStopCond();

		I2C_vStartCond();
		I2C_vWriteAddress(0xD0);
		I2C_vWriteData(SIGNAL_PATH_RESET);   //don't reset signal path
		I2C_vWriteData(0x00);
		I2C_vStopCond();

}

/***************************************************************************************************/

uint8 MPU6050_vReadRegisterValue(uint8 Copy_u8Address)
{
	uint8 Return_Value;
	I2C_vStartCond();
	I2C_vWriteAddress(0xD0);		//write register
	I2C_vWriteData(Copy_u8Address);
	I2C_vStartCond();
	I2C_vWriteAddress(0xD1);		//read register
	Return_Value = I2C_u8ReceiveData(I2C_NACK);
	I2C_vStopCond();
	return Return_Value;
}

/***************************************************************************************************/

void MPU6050_vReadGyro_X(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte)
{
	*Copy_u8HighByte = MPU6050_vReadRegisterValue(GYRO_XOUT_H);
	*Copy_u8LowByte = MPU6050_vReadRegisterValue(GYRO_XOUT_L);
}

/***************************************************************************************************/

void MPU6050_vReadGyro_Y(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte)
{
	*Copy_u8HighByte = MPU6050_vReadRegisterValue(GYRO_YOUT_H);
	*Copy_u8LowByte = MPU6050_vReadRegisterValue(GYRO_YOUT_L);
}

/***************************************************************************************************/

void MPU6050_vReadGyro_Z(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte)
{
	*Copy_u8HighByte = MPU6050_vReadRegisterValue(GYRO_ZOUT_H);
	*Copy_u8LowByte = MPU6050_vReadRegisterValue(GYRO_ZOUT_L);
}

/***************************************************************************************************/

void MPU6050_vReadAccel_X(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte)
{
	*Copy_u8HighByte = MPU6050_vReadRegisterValue(ACCEL_XOUT_H);
	*Copy_u8LowByte = MPU6050_vReadRegisterValue(ACCEL_XOUT_L);
}

/***************************************************************************************************/

void MPU6050_vReadAccel_Y(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte)
{
	*Copy_u8HighByte = MPU6050_vReadRegisterValue(ACCEL_YOUT_H);
	*Copy_u8LowByte = MPU6050_vReadRegisterValue(ACCEL_YOUT_L);
}

/***************************************************************************************************/

void MPU6050_vReadAccel_Z(uint8 *Copy_u8LowByte , uint8 *Copy_u8HighByte)
{
	*Copy_u8HighByte = MPU6050_vReadRegisterValue(ACCEL_ZOUT_H);
	*Copy_u8LowByte = MPU6050_vReadRegisterValue(ACCEL_ZOUT_L);
}

/***************************************************************************************************/

void MPU6050_vReadGyro_ALL(sint16 *Copy_u16Buffer)
{
	uint8 LOC_arr[2];
	MPU6050_vReadGyro_X(LOC_arr, LOC_arr+1);
	Copy_u16Buffer[0] = (LOC_arr[1]<<8)|(LOC_arr[0]);

	MPU6050_vReadGyro_Y(LOC_arr, LOC_arr+1);
	Copy_u16Buffer[1] = (LOC_arr[1]<<8)|(LOC_arr[0]);

	MPU6050_vReadGyro_Z(LOC_arr, LOC_arr+1);
	Copy_u16Buffer[2] = (LOC_arr[1]<<8)|(LOC_arr[0]);
}

/***************************************************************************************************/

void MPU6050_vReadAccel_ALL(sint16 *Copy_u16Buffer)
{
	uint8 LOC_arr[2];
	MPU6050_vReadAccel_X(LOC_arr, LOC_arr+1);
	Copy_u16Buffer[0] = (LOC_arr[1]<<8)|(LOC_arr[0]);

	MPU6050_vReadAccel_Y(LOC_arr, LOC_arr+1);
	Copy_u16Buffer[1] = (LOC_arr[1]<<8)|(LOC_arr[0]);

	MPU6050_vReadAccel_Z(LOC_arr, LOC_arr+1);
	Copy_u16Buffer[2] = (LOC_arr[1]<<8)|(LOC_arr[0]);
}

/***************************************************************************************************/

uint8 MPU6050_vDetectChange(double *old)
{
	sint16 accel_buff[3];
	double accelX, accelY, accelZ;
	//double deltX = 0 , deltY = 0 , deltZ = 0;

	uint8 Return_value = 0;

	MPU6050_vReadAccel_ALL(accel_buff);
	// acceleration (m/s^2)
	accelX = accel_buff[0]*9.8*8/32768;
	accelY = accel_buff[1]*9.8*8/32768;
	accelZ = accel_buff[2]*9.8*8/32768;

	/*deltX = accelX - Copy_dOldValues[0];
	deltY = accelY - Copy_dOldValues[1];
	deltZ = accelZ - Copy_dOldValues[2];*/

	/*Copy_dOldValues[0] = accelX;
	Copy_dOldValues[1] = accelY;
	Copy_dOldValues[2] = accelZ;*/


	if((accelY >= MPU_SENSITIVITY || accelZ >= MPU_SENSITIVITY) && (((accelY-old[0])>=5)||(accelZ-old[1])>=5))
	{
		Return_value = 1;
	}
	old[0]=accelY;
	old[1]=accelZ;
	return Return_value;
}
