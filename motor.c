/*
 * motor.c
 *
 *  Created on: Sep 22, 2020
 *      Author: user
 */

#include "motor.h"

void motor_init(void)
{
	DDRB |= (1 << PB4) | (1 << PB5); // 2 output pins

	// clk wise
	PORTB |= (1 << PB4);
	PORTB &= ~(1 << PB5);

}
