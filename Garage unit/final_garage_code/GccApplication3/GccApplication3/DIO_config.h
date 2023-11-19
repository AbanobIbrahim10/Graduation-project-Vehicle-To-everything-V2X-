/*
 * DIO_config.h
 *
 * Created: 11/7/2022 1:53:28 AM
 *  Author: Abanoub yanni
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/* Direction options */
//1-DIO_uint8_INPUT_INIT
//2-DIO_uint8_OUTPUT_INIT

#define DIO_uint8_PA0_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PA1_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PA2_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PA3_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PA4_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PA5_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PA6_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PA7_DIRECTION			DIO_uint8_OUTPUT_INIT

#define DIO_uint8_PB0_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PB1_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PB2_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PB3_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PB4_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PB5_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PB6_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PB7_DIRECTION			DIO_uint8_OUTPUT_INIT
										
#define DIO_uint8_PC0_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PC1_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PC2_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PC3_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PC4_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PC5_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PC6_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PC7_DIRECTION			DIO_uint8_OUTPUT_INIT
										
#define DIO_uint8_PD0_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PD1_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PD2_DIRECTION			DIO_uint8_INPUT_INIT
#define DIO_uint8_PD3_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PD4_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PD5_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PD6_DIRECTION			DIO_uint8_OUTPUT_INIT
#define DIO_uint8_PD7_DIRECTION			DIO_uint8_OUTPUT_INIT


/* options for output mode */
//1-DIO_uint8_VALUE_HIGH
//2-DIO_uint8_VALUE_LOW

/* options for input mode */
//1-DIO_uint8_input_Floating
//2-DIO_uint8_input_PULLED_UP

#define DIO_uint8_PA0_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PA1_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PA2_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PA3_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PA4_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PA5_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PA6_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PA7_VALUE				DIO_uint8_VALUE_HIGH

#define DIO_uint8_PB0_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PB1_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PB2_VALUE				DIO_uint8_input_Floating
#define DIO_uint8_PB3_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PB4_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PB5_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PB6_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PB7_VALUE				DIO_uint8_VALUE_HIGH

#define DIO_uint8_PC0_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PC1_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PC2_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PC3_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PC4_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PC5_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PC6_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PC7_VALUE				DIO_uint8_VALUE_HIGH

#define DIO_uint8_PD0_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PD1_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PD2_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PD3_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PD4_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PD5_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PD6_VALUE				DIO_uint8_VALUE_HIGH
#define DIO_uint8_PD7_VALUE				DIO_uint8_VALUE_LOW

#endif /* DIO_CONFIG_H_ */
