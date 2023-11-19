
#include "std_types.h"
#include "std_macros.h"
#include <avr/io.h>
void UART_Init(void)
{
  // Set BaudRate -> 9600/16MhZ
  UBRRL = 102;
  UBRRH = 0;
  // Set Frame Format -> 8 data, 1 stop, No Parity
  UCSRC = 0x86;
  // Enable RX and TX
  UCSRB = 0x18;
}

void UART_SendChar(uint8 data)
{
  // Wait until transmission Register Empty
  while((UCSRA&0x20) == 0x00);
  UDR = data;
}

uint8 UART_GetChar(void)
{
  uint8 Result;
  // Wait until Reception Complete
  while((UCSRA&0x80) == 0x00);
  Result = UDR;
  
  /* Clear Flag */
  SET_BIT(UCSRA,7);
  return 1;
  
}

/*uint8 UART_GetString(char* ptr)
{
	uint8 local_i=0;
	while((UCSRA&0x80) == 0x00);
	ptr[local_i] = UDR;
	
	while(ptr[local_i]!='\0')
	{
		  while((UCSRA&0x80) == 0x00);
		  local_i++;
		  ptr[local_i] = UDR;
		  
		  /* Clear Flag */
		  //SET_BIT(UCSRA,7);
//	}
//}

