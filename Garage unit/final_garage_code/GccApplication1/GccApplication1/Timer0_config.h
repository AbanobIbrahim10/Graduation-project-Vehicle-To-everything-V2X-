/*
 * Timer0_config.h
 *
 *  Created on: Nov 28, 2022
 *      Author: bebob
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_
#include "Timer0_private.h"
/*there are 4 modes*/

#define normal_mode
/*put a valuer from 0 to 255*/
//comment this if you won't use preload
//#define TIMER_PreLoad 10



//#define CTC_mode
//choose a value from 0 to 255
//#define Compare_match_value 50


//#define fast_pwm_mode
//choose a value from 0 to 255  --> 0 mean about 0% duty cycle and 255 means about 100% duty cycle
//#define Compare_match_value 0




					/* this mode has a lower frequency compared with fast pwm */
					  /* but it is preferred for motor control applications */

//#define phase_correct_pwm

//choose a value from 0 to 255  --> 0 mean exact 0% duty cycle and 255 means exact 100% duty cycle
//#define Compare_match_value 5



/* select the prescaler */

/*
 * 1-Stop
 * 2-No_prescaler
 * 3-clk_dividedby_8
 * 4-clk_dividedby_64
 * 5-clk_dividedby_256
 * 6-clk_dividedby_1024
 * 7-external_clk_T0_falling_edge
 * 8-external_clk_T0_raising_edge
 */

#define PreScaler No_prescaler





#endif /* TIMER0_CONFIG_H_ */
