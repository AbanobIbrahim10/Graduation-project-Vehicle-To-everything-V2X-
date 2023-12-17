/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _AFIO_PRIVATE_H
#define _AFIO_PRIVATE_H

#define AFIO_BASE_ADDRESS			0x40010000

typedef struct
{
	volatile uint8 EVCR;
	volatile uint8 MAPR;
	volatile uint8 EXTICR1;
	volatile uint8 EXTICR2;
	volatile uint8 EXTICR3;
	volatile uint8 EXTICR4;
	volatile uint8 MAPR2;
}AFIO_RegDef_t;


#define AFIO		((AFIO_RegDef_t*)AFIO_BASE_ADDRESS)


#endif