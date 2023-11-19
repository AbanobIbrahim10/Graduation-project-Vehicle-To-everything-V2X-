/*
 * STD.h
 *
 * Created: 8/30/2022 2:25:13 AM
 *  Author: Abanoub ibrahim Yanni
 */ 


#ifndef STD_H_
#define STD_H_

typedef unsigned char uint8;
typedef unsigned long int u32;




#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7



#define SET_BIT(VAR,BITNO)     (VAR)|=(1<<(BITNO))
#define CLR_BIT(VAR,BITNO)     (VAR)&=~(1<<(BITNO))
#define TOG_BIT(VAR,BITNO)     (VAR)^=(1<<(BITNO))
#define GET_BIT(VAR,BITNO)     (((VAR)>>(BITNO)) & (0x01))









#define STD_TYPES_OK  1
#define STD_TYPES_NOT_OK  0

#define NULL ((volatile void*)0)


#endif /* STD_H_ */
