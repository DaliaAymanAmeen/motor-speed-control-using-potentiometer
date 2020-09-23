/*
 * pwm_timer0.h
 *
 *  Created on: Sep 22, 2020
 *      Author: user
 */

#ifndef PWM_TIMER0_H_
#define PWM_TIMER0_H_

#include "util/delay.h"
#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

void PWM_Timer0_Init(uint8 set_duty_cycle);

#endif /* PWM_TIMER0_H_ */
