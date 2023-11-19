/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

/********************************** Header Files INCLUSIONS ****************************/

#include "STD_TYPES.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_Extra.h"
/***************************************************************************************/

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */

/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position
#define LCD_uint8_DATA_PORT DIO_uint8_PORTB
#define LCD_uint8_LINE1 1
#define LCD_uint8_LINE2 2

/***************************************************************************************/
/********************************** Constant Variables *********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void)
{
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Return Home  */
	LCD_vidSendCommand(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(2);

}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(uint8 u8CmdCpy)
{

	/* Set RS to LOW */
	DIO_uint8SetPinValue(DIO_uint8_PORTA, 0, DIO_uint8_LOW);

	/* Set R/W to LOW */
	DIO_uint8SetPinValue(DIO_uint8_PORTA, 1, DIO_uint8_LOW);

	/* Set E to HIGH  */
	DIO_uint8SetPinValue(DIO_uint8_PORTA, 2, DIO_uint8_HIGH);

	/* Load Command on Data bus */
	DIO_uint8SetPortValue(LCD_uint8_DATA_PORT,u8CmdCpy);

	/* Set E to LOW */
	DIO_uint8SetPinValue(DIO_uint8_PORTA, 2, DIO_uint8_LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_uint8SetPinValue(DIO_uint8_PORTA, 2, DIO_uint8_HIGH);

	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(uint8 u8DataCpy)
{
	/* Set RS to HIG */
	DIO_uint8SetPinValue(DIO_uint8_PORTA, 0, DIO_uint8_HIGH);

	/* Set R/W to LOW */
	DIO_uint8SetPinValue(DIO_uint8_PORTA, 1, DIO_uint8_LOW);

	/* Set E to HIGH */
	DIO_uint8SetPinValue(DIO_uint8_PORTA, 2, DIO_uint8_HIGH);

	/* Load Command on Data bus */
	DIO_uint8SetPortValue(LCD_uint8_DATA_PORT, u8DataCpy);

	/* Set E to LOW */
	DIO_uint8SetPinValue(DIO_uint8_PORTA, 2, DIO_uint8_LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_uint8SetPinValue(DIO_uint8_PORTA, 2, DIO_uint8_HIGH);

	/* Delay to let the LCD Display the character */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (uint8* pu8StringCpy, uint8 u8Index)
{

//	/* Local loop index */
//	uint8 u8Index = 0;
	uint8 iteration=0;
//	while (pu8StringCpy[u8Index] != '\0')
	for (iteration=0; iteration<u8Index ; iteration++)
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr(pu8StringCpy[iteration]);

//		/* Increment local loop index */
//		u8Index++;

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}

}

/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void Gotoxy (uint8 Y,uint8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	LCD_vidSendCommand(X+127);
		    break;
		    case 2:
		    	LCD_vidSendCommand(X+191);
		    break;
		    default:
		    break;
	    }
	}
}

/***************************************************************************************/
/* Description! Interface to write extra characters saved in the CGRAM                 */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteExtraChar (uint8 Y,uint8 X)
{
    uint8 iteration1,iteration2;

    /*DDRAM-->CGRAM*/
    LCD_vidSendCommand(64);
	for(iteration1=0 ; iteration1<64 ; iteration1++)
	{
		LCD_vidWriteCharctr(ExtraChar[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_vidSendCommand(128);
	Gotoxy(Y,X);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_vidWriteCharctr(iteration2);

		_delay_ms(5);
	}
}
void LCD_voidWriteNumber(u32 Copy_u32Number){
	if(Copy_u32Number!=0){
		u32 Local_u32Help=1;
		while(Copy_u32Number !=0){
			Local_u32Help=Local_u32Help*10+Copy_u32Number%10;
			Copy_u32Number/=10;
		}

		while (Local_u32Help !=1){

			LCD_vidWriteCharctr(48+Local_u32Help%10);
			Local_u32Help/=10;
		}

	}
	else{
		LCD_vidWriteCharctr('0');
	}
}

uint8 LCD_voidGoToXY (uint8 Copy_u8LineNum,uint8 Copy_u8CharLocation){
	uint8 Local_u8ErrorState=STD_TYPES_OK;
	switch (Copy_u8LineNum){

	case LCD_uint8_LINE1:
		LCD_vidSendCommand(0x80+Copy_u8CharLocation);
		break;
	case LCD_uint8_LINE2 :
		LCD_vidSendCommand(0xC0+Copy_u8CharLocation);
	    break;
	default :
		Local_u8ErrorState=STD_TYPES_NOT_OK;

	}
	return Local_u8ErrorState;

}
