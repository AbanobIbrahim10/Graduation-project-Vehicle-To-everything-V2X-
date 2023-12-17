/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_private.h"
#include "I2C_config.h"
#include "I2C_private.h"
#include "I2C_interface.h"
#include "SYSTICK_interface.h"


/********************************************************************************************************************************************/
void I2C_vInit(void)
{
	//Enable Alternate function
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS,AFIOEN);
	//Enable I2C1
	RCC_u8EnablePeripheralClk(RCC_u8_APB1_BUS,I2C1EN);
	//No remap (SCL/PB6, SDA/PB7)
	CLR_BIT(AFIO->MAPR,AFIO_I2C1_REMAP);
	//Enable pins portB -> SCL , SDA
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS,GPIOB_EN);
	

	GPIO_vSetPinMode(GPIO_PORT_B,GPIO_PIN_6,GPIO_PIN_OUTPUT_SPD_50);
	GPIO_vSetPinConfig(GPIO_PORT_B,GPIO_PIN_6,AFIO_OPENDRAIN);
	GPIO_vSetPinMode(GPIO_PORT_B,GPIO_PIN_7,GPIO_PIN_OUTPUT_SPD_50);
	GPIO_vSetPinConfig(GPIO_PORT_B,GPIO_PIN_7,AFIO_OPENDRAIN);
	//reset the peripheral
	SET_BIT(I2C1->CR1,I2C_CR1_SWRST);
	CLR_BIT(I2C1->CR1,I2C_CR1_SWRST);
	
	I2C1->CR2 = 0x8;
	I2C1->CCR = 40;
	
	I2C1->TRISE = 0x09;		// APB1+1
	
	//enable
	SET_BIT(I2C1->CR1,I2C_CR1_PE);
	
	_delay_ms(100);
}


/********************************************************************************************************************************************/
uint8 I2C_vStartCond(void)
{
	uint16 LOC_time = 0;
	uint8 Return_value = 0;
	//set start pin and wait for the flag
	SET_BIT(I2C1->CR1,I2C_CR1_START);
	
	while(READ_BIT(I2C1->SR1,I2C_SR1_SB)==0 && LOC_time < I2C_TIME_OUT)
	{
		LOC_time ++;
	}
	(void) I2C1->SR1;
	if(LOC_time >= I2C_TIME_OUT)
	{
		Return_value = 1;
	}
	return Return_value;
}

/********************************************************************************************************************************************/


uint8 I2C_vWriteAddress(uint8 Copy_u8Address)
{
	uint8 Return_value = 0;
	uint16 LOC_time = 0;

	volatile int LOC_temp;
	I2C1->DR = Copy_u8Address;
	while(READ_BIT(I2C1->SR1,I2C_SR1_ADDR)==0 && LOC_time < I2C_TIME_OUT)
	{
		LOC_time++;
	}
	//read SR1 then SR2 to clear ADDR flag
	LOC_time = 0;
	while(READ_BIT(I2C1->SR1,I2C_SR1_ADDR)==1 && LOC_time < I2C_TIME_OUT)
	{
		LOC_temp = I2C1->SR1;
		LOC_temp = I2C1->SR2;
		LOC_time++;
	}
	if(LOC_time >= I2C_TIME_OUT)
	{
		Return_value = 1;
	}
	return Return_value;
}


/********************************************************************************************************************************************/
uint8 I2C_vWriteData(uint8 Copy_u8Data)
{
	uint8 Return_value=0;
	uint16 LOC_time = 0;
	//wait for the data register to be empty
	while(READ_BIT(I2C1->SR1,I2C_SR1_TXE)==0 && LOC_time < I2C_TIME_OUT)
	{
		LOC_time++;
	}
	I2C1->DR = Copy_u8Data;
	if(LOC_time >= I2C_TIME_OUT)
	{
		Return_value = 1;
	}
	LOC_time=0;
	//wait for the data register to be empty
	while(READ_BIT(I2C1->SR1,I2C_SR1_TXE)==0 && LOC_time < I2C_TIME_OUT)
	{
		LOC_time++;
	}
	if(LOC_time >= I2C_TIME_OUT)
	{
		Return_value = 2;
	}
	return Return_value;
}


/********************************************************************************************************************************************/


void I2C_vStopCond(void)
{
	volatile int LOC_temp;
	LOC_temp = I2C1->SR1;
	LOC_temp = I2C1->SR2;
	//send a stop cond
	SET_BIT(I2C1->CR1,I2C_CR1_STOP);
}


/********************************************************************************************************************************************/


void I2C_vWrite(uint8 Copy_u8Address ,uint8 Copy_u8Data , uint8 Copy_u8RW)
{
	I2C_vStartCond();
	I2C_vWriteAddress(Copy_u8Address|Copy_u8RW);
	I2C_vWriteData(Copy_u8Data);
	I2C_vStopCond();
}

/********************************************************************************************************************************************/

/* Copy_u8Ack_Nack == 1 if Nack (the last one) */
uint8 I2C_u8ReceiveData(uint8 Copy_u8Ack_Nack)
{
	uint8 Return_value;
	uint16 LOC_time = 0;
	//send ack
	SET_BIT(I2C1->CR1,I2C_CR1_ACK);
	//wait for the data to be received
	while(READ_BIT(I2C1->SR1,I2C_SR1_RXNE)==0 && LOC_time < I2C_TIME_OUT)
	{
		LOC_time++;
	}
	Return_value = I2C1->DR;
	if (Copy_u8Ack_Nack == I2C_NACK)
	{
		CLR_BIT(I2C1->CR1,I2C_CR1_ACK);
	}
	return Return_value;
}


/********************************************************************************************************************************************/





