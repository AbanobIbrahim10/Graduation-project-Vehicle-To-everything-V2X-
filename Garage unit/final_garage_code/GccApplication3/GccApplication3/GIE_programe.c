/*

 * GIE_programe.c
 *
 *  Created on: Oct 8, 2021
 *      Author: bebob
 */

#include "STD_Types.h"
#include "GIE_interface.h"
#include "GIE_private.h"


void GIE_VoidEnable (void){

SET_BIT(GIE_uint8_SREG_REG,7);
}
void GIE_VoidDisable (void){
CLR_BIT(GIE_uint8_SREG_REG,7);

}
