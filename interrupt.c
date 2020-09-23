/*
 * interrupt.c
 *
 *  Created on: Sep 23, 2020
 *      Author: user
 */

#include "interrupt.h"
#include "lcd.h"
void Int1_init (void)
{
	SREG |= (1 << 7);
	GICR |= (1 << INT1);  // module interrupt enable
	MCUCR |= (1 << ISC11) | (1 << ISC10);
}

ISR (INT1_vect)
{
	PORTB ^= (1 << PB4);
	PORTB ^= (1 << PB5);

}
