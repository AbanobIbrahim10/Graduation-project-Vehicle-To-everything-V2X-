/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _I2C_INTERFACE_H
#define _I2C_INTERFACE_H


/********************************* Macros **********************************/
// modes
#define FAST_MODE			0x2D
#define STANDARD_MODE		0xB4

//CR1 Registers
#define I2C_CR1_PE				0
#define I2C_CR1_SMBUS			1
#define I2C_CR1_SMBTYPE			3
#define I2C_CR1_ENARP			4
#define I2C_CR1_ENPEC			5
#define I2C_CR1_ENGC			6
#define I2C_CR1_NOSTRETCH		7
#define I2C_CR1_START			8
#define I2C_CR1_STOP			9
#define I2C_CR1_ACK				10
#define I2C_CR1_POS				11
#define I2C_CR1_PEC				12
#define I2C_CR1_ALERT			13
#define I2C_CR1_SWRST			15


//SR1 Register
#define I2C_SR1_SB				0
#define I2C_SR1_ADDR			1
#define I2C_SR1_BTF				2
#define I2C_SR1_ADD10			3
#define I2C_SR1_STOPF			4
#define I2C_SR1_RXNE			6
#define I2C_SR1_TXE				7
#define I2C_SR1_BERR			8
#define I2C_SR1_ARLO			9
#define I2C_SR1_AF				10
#define I2C_SR1_OVR				11
#define I2C_SR1_PECERR			12
#define I2C_SR1_TIMEOUT			14
#define I2C_SR1_SMBALERT		15



#define I2C_ACK					0
#define I2C_NACK				1


#define I2C_TIME_OUT			25000


/******************************** Prototypes *******************************/

/*
FUNCTION NAME        : I2C_vInit
FUNCTION DESCRIPTION : initializes I2C by enabling peripherals and bits
FUNCTION INPUT       : void
FUNCTION RETURN      : void
*/
void I2C_vInit(void);

/* 
FUNCTION NAME        : I2C_vStartCond
FUNCTION DESCRIPTION : sends start condition to the bus
FUNCTION INPUT       : void
FUNCTION RETURN      : void
*/
uint8 I2C_vStartCond(void);

/*
FUNCTION NAME        : I2C_vWriteAddress
FUNCTION DESCRIPTION : select address to send data (address<<1 | RW),, RW == 0 if write & RW == 1 if read 
FUNCTION INPUT       : Copy_u8Address: selected address
FUNCTION RETURN      : void
*/
uint8 I2C_vWriteAddress(uint8 Copy_u8Address);

/*
FUNCTION NAME        : I2C_vWriteData
FUNCTION DESCRIPTION : sends data at the bus
FUNCTION INPUT       : Copy_u8Data: data to be sent
FUNCTION RETURN      : void
*/
uint8 I2C_vWriteData(uint8 Copy_u8Data);

/*
FUNCTION NAME        : I2C_vStopCond
FUNCTION DESCRIPTION : sends stop condition after the data is sent
FUNCTION INPUT       : void
FUNCTION RETURN      : void
*/
void I2C_vStopCond(void);

/*
FUNCTION NAME        : I2C_vWrite
FUNCTION DESCRIPTION : the whole process in one function
FUNCTION INPUT       : Copy_u8Address: selected address , Copy_u8Data: data to be sent , Copy_u8RW: 0 if write and 1 if read
FUNCTION RETURN      : void
*/
void I2C_vWrite(uint8 Copy_u8Address ,uint8 Copy_u8Data , uint8 Copy_u8RW);


uint8 I2C_u8ReceiveData(uint8 Copy_u8Ack_Nack);


#endif
