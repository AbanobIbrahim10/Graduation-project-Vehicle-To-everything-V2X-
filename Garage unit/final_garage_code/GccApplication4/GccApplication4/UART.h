

#ifndef UART_H_
#define UART_H_

#include"std_types.h"

void UART_Init(void);

void UART_SendChar(uint8 data);

uint8 UART_GetChar(void);

#endif /* UART_H_ */
