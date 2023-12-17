/*
 * ULTRA_interface.h
 *
 *  Created on: May 2, 2023
 *      Author: MERNA
 */

#ifndef ULTRA_INTERFACE_H_
#define ULTRA_INTERFACE_H_

#define SOUND_SPEED		34000

#define ULTRA_TIMEOUT_TRIG		20000
#define ULTRA_TIMEOUT_ECHO		2000000

void ULTRA_vInit(void);

uint16 ULTRA_u16GetDistance(void);


#endif /* ULTRA_INTERFACE_H_ */
