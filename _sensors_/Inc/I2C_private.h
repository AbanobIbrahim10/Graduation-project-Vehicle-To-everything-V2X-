/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _I2C_PRIVATE_H
#define _I2C_PRIVATE_H


#define I2C1_BASE_ADDRESS			(0x40005400)


typedef struct
{
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 OAR1;
	volatile uint32 OAR2;
	volatile uint32 DR;
	volatile uint32 SR1;
	volatile uint32 SR2;
	volatile uint32 CCR;
	volatile uint32 TRISE;
}I2C_t;


#define I2C1			((I2C_t*)(I2C1_BASE_ADDRESS))

#endif