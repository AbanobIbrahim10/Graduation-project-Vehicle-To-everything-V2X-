/*
 * DIO_program.c
 *
 * Created: 8/30/2022 1:54:27 AM
 *  Author: Abanoub ibrahim Yanni
 */ 

#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "STD_TYPES.h"



void DIO_voidInit(void)
{
	
	DIO_uint8_DDRA_REG=DIO_PRIVATE_uint8_CONC(DIO_uint8_PA0_DIRECTION,DIO_uint8_PA1_DIRECTION,DIO_uint8_PA2_DIRECTION,DIO_uint8_PA3_DIRECTION,DIO_uint8_PA4_DIRECTION,DIO_uint8_PA5_DIRECTION,DIO_uint8_PA6_DIRECTION,DIO_uint8_PA7_DIRECTION);
	DIO_uint8_PORTA_REG=DIO_PRIVATE_uint8_CONC(DIO_uint8_PA0_VALUE,DIO_uint8_PA1_VALUE,DIO_uint8_PA2_VALUE,DIO_uint8_PA3_VALUE,DIO_uint8_PA4_VALUE,DIO_uint8_PA5_VALUE,DIO_uint8_PA6_VALUE,DIO_uint8_PA7_VALUE);
	
	DIO_uint8_DDRB_REG=DIO_PRIVATE_uint8_CONC(DIO_uint8_PB0_DIRECTION,DIO_uint8_PB1_DIRECTION,DIO_uint8_PB2_DIRECTION,DIO_uint8_PB3_DIRECTION,DIO_uint8_PB4_DIRECTION,DIO_uint8_PB5_DIRECTION,DIO_uint8_PB6_DIRECTION,DIO_uint8_PB7_DIRECTION);
	DIO_uint8_PORTB_REG=DIO_PRIVATE_uint8_CONC(DIO_uint8_PB0_VALUE,DIO_uint8_PB1_VALUE,DIO_uint8_PB2_VALUE,DIO_uint8_PB3_VALUE,DIO_uint8_PB4_VALUE,DIO_uint8_PB5_VALUE,DIO_uint8_PB6_VALUE,DIO_uint8_PB7_VALUE);
	
	DIO_uint8_DDRC_REG=DIO_PRIVATE_uint8_CONC(DIO_uint8_PC0_DIRECTION,DIO_uint8_PC1_DIRECTION,DIO_uint8_PC2_DIRECTION,DIO_uint8_PC3_DIRECTION,DIO_uint8_PC4_DIRECTION,DIO_uint8_PC5_DIRECTION,DIO_uint8_PC6_DIRECTION,DIO_uint8_PC7_DIRECTION);
	DIO_uint8_PORTC_REG=DIO_PRIVATE_uint8_CONC(DIO_uint8_PC0_VALUE,DIO_uint8_PC1_VALUE,DIO_uint8_PC2_VALUE,DIO_uint8_PC3_VALUE,DIO_uint8_PC4_VALUE,DIO_uint8_PC5_VALUE,DIO_uint8_PC6_VALUE,DIO_uint8_PC7_VALUE);
	
	DIO_uint8_DDRD_REG=DIO_PRIVATE_uint8_CONC(DIO_uint8_PD0_DIRECTION,DIO_uint8_PD1_DIRECTION,DIO_uint8_PD2_DIRECTION,DIO_uint8_PD3_DIRECTION,DIO_uint8_PD4_DIRECTION,DIO_uint8_PD5_DIRECTION,DIO_uint8_PD6_DIRECTION,DIO_uint8_PD7_DIRECTION);
	DIO_uint8_PORTD_REG=DIO_PRIVATE_uint8_CONC(DIO_uint8_PD0_VALUE,DIO_uint8_PD1_VALUE,DIO_uint8_PD2_VALUE,DIO_uint8_PD3_VALUE,DIO_uint8_PD4_VALUE,DIO_uint8_PD5_VALUE,DIO_uint8_PD6_VALUE,DIO_uint8_PD7_VALUE);

}







uint8 DIO_uint8SetPinDirection(uint8 Copy_uint8PortId,uint8 Copy_uint8PinId,uint8 Copy_uint8Direction)
{
		uint8 LOCAL_uint8ErrorState=STD_TYPES_OK;
		if(Copy_uint8PortId <=DIO_uint8_PORTD && Copy_uint8PinId <= DIO_uint8_PIN7 )
		{
			switch(Copy_uint8PortId)
			{
				
				case DIO_uint8_PORTA:
					switch(Copy_uint8Direction)
					{
						case DIO_uint8_OUTPUT:
							SET_BIT(DIO_uint8_DDRA_REG,Copy_uint8PinId);
							break;
						case DIO_uint8_INPUT_FLOATING:
							CLR_BIT(DIO_uint8_DDRA_REG,Copy_uint8PinId);
							break;
						
						case DIO_uint8_INPUT_PULL_UP:
							CLR_BIT(DIO_uint8_DDRA_REG,Copy_uint8PinId);
							SET_BIT(DIO_uint8_PORTA_REG,Copy_uint8PinId);
							break;
						
						default:
							LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
							break;
							
					}
					break;
				
				case DIO_uint8_PORTB:
					switch(Copy_uint8Direction)
					{
						case DIO_uint8_OUTPUT:
						SET_BIT(DIO_uint8_DDRB_REG,Copy_uint8PinId);
						break;
						case DIO_uint8_INPUT_FLOATING:
						CLR_BIT(DIO_uint8_DDRB_REG,Copy_uint8PinId);
						break;
					
						case DIO_uint8_INPUT_PULL_UP:
						CLR_BIT(DIO_uint8_DDRB_REG,Copy_uint8PinId);
						SET_BIT(DIO_uint8_PORTB_REG,Copy_uint8PinId);
						break;
					
						default:
						LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
						break;
					
					}
					break;				
				
				case DIO_uint8_PORTC:
					switch(Copy_uint8Direction)
					{
						case DIO_uint8_OUTPUT:
						SET_BIT(DIO_uint8_DDRC_REG,Copy_uint8PinId);
						break;
						case DIO_uint8_INPUT_FLOATING:
						CLR_BIT(DIO_uint8_DDRC_REG,Copy_uint8PinId);
						break;
					
						case DIO_uint8_INPUT_PULL_UP:
						CLR_BIT(DIO_uint8_DDRC_REG,Copy_uint8PinId);
						SET_BIT(DIO_uint8_PORTC_REG,Copy_uint8PinId);
						break;
					
						default:
						LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
						break;
					
					}
					break;
				
				case DIO_uint8_PORTD:
					switch(Copy_uint8Direction)
					{
						case DIO_uint8_OUTPUT:
						SET_BIT(DIO_uint8_DDRD_REG,Copy_uint8PinId);
						break;
						case DIO_uint8_INPUT_FLOATING:
						CLR_BIT(DIO_uint8_DDRD_REG,Copy_uint8PinId);
						break;
					
						case DIO_uint8_INPUT_PULL_UP:
						CLR_BIT(DIO_uint8_DDRD_REG,Copy_uint8PinId);
						SET_BIT(DIO_uint8_PORTD_REG,Copy_uint8PinId);
						break;
					
						default:
						LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
						break;
					
					}
					break;
					
				default:
					LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
					break;
			}					
			

		}
		else
		{
			LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
		}	
		
		
	return LOCAL_uint8ErrorState;
	
}

uint8 DIO_uint8SetPinValue(uint8 Copy_uint8PortId,uint8 Copy_uint8PinId,uint8 Copy_uint8PinValue)
{
	
	uint8 LOCAL_uint8ErrorState=STD_TYPES_OK;
	if(Copy_uint8PortId <=DIO_uint8_PORTD && Copy_uint8PinId <= DIO_uint8_PIN7 )
	{
		switch(Copy_uint8PortId)
		{
			
			case DIO_uint8_PORTA:
			switch(Copy_uint8PinValue)
			{
				case DIO_uint8_HIGH:
				SET_BIT(DIO_uint8_PORTA_REG,Copy_uint8PinId);
				break;
				case DIO_uint8_LOW:
				CLR_BIT(DIO_uint8_PORTA_REG,Copy_uint8PinId);
				break;
				
				default:
				LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
				break;
				
			}
			break;
			
			case DIO_uint8_PORTB:
			switch(Copy_uint8PinValue)
			{
				case DIO_uint8_HIGH:
				SET_BIT(DIO_uint8_PORTB_REG,Copy_uint8PinId);
				break;
				case DIO_uint8_LOW:
				CLR_BIT(DIO_uint8_PORTB_REG,Copy_uint8PinId);
				break;
				
				default:
				LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
				break;
				
			}
			break;
			
			
			
			case DIO_uint8_PORTC:
			switch(Copy_uint8PinValue)
			{
				case DIO_uint8_HIGH:
				SET_BIT(DIO_uint8_PORTC_REG,Copy_uint8PinId);
				break;
				case DIO_uint8_LOW:
				CLR_BIT(DIO_uint8_PORTC_REG,Copy_uint8PinId);
				break;
				
				default:
				LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
				break;
				
			}
			break;
			
			
			case DIO_uint8_PORTD:
			switch(Copy_uint8PinValue)
			{
				case DIO_uint8_HIGH:
				SET_BIT(DIO_uint8_PORTD_REG,Copy_uint8PinId);
				break;
				case DIO_uint8_LOW:
				CLR_BIT(DIO_uint8_PORTD_REG,Copy_uint8PinId);
				break;
				
				default:
				LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
				break;
				
			}
			break;
			
			
			default:
			LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
			break;
		}
		

	}
	else
	{
		LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
	}
	
	
	return LOCAL_uint8ErrorState;
	
}
uint8 DIO_uint8ReadPinValue(uint8 Copy_uint8PortId,uint8 Copy_uint8PinId,uint8* Copy_Puint8ReturnedValue)
{
	uint8 LOCAL_uint8ErrorState=STD_TYPES_OK;
	if( Copy_uint8PinId <= DIO_uint8_PIN7 && Copy_Puint8ReturnedValue!=NULL)
	{
		switch(Copy_uint8PortId)
		{
			
			case DIO_uint8_PORTA:
			*Copy_Puint8ReturnedValue=GET_BIT(DIO_uint8_PINA_REG,Copy_uint8PinId);
			break;
			
			case DIO_uint8_PORTB:
			*Copy_Puint8ReturnedValue=GET_BIT(DIO_uint8_PINB_REG,Copy_uint8PinId);
			break;
			
			case DIO_uint8_PORTC:
			*Copy_Puint8ReturnedValue=GET_BIT(DIO_uint8_PINC_REG,Copy_uint8PinId);
			break;
			
			case DIO_uint8_PORTD:
			*Copy_Puint8ReturnedValue=GET_BIT(DIO_uint8_PIND_REG,Copy_uint8PinId);
			break;
			
			
			default:
			LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
			break;
		}
		

	}
	else
	{
		LOCAL_uint8ErrorState=STD_TYPES_NOT_OK;
	}
	
	
	return LOCAL_uint8ErrorState;		
}

uint8 DIO_uint8SetPortValue(uint8 Copy_u8PortId, uint8 Copy_u8PortValue) {
	uint8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Copy_u8PortId) {
	case DIO_uint8_PORTA:
		DIO_uint8_PORTA_REG = Copy_u8PortValue;
		break;
	case DIO_uint8_PORTB:
		DIO_uint8_PORTB_REG = Copy_u8PortValue;
		break;
	case DIO_uint8_PORTC:
		DIO_uint8_PORTC_REG = Copy_u8PortValue;
		break;
	case DIO_uint8_PORTD:
		DIO_uint8_PORTD_REG = Copy_u8PortValue;
		break;
	default:
		Local_u8ErrorState = STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState;
}

