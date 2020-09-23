/*
 * adc.c
 *
 *  Created on: Sep 18, 2020
 *      Author: user
 */

#include "adc.h"

void ADC_init (const ADC_Config * config_Ptr)  //
{
	ADMUX &= ~(1 << ADLAR); // to adjust data reg

	ADMUX = (ADMUX & 0x3F) | (config_Ptr->volt_ref << 6); // ref_volt

	ADCSRA = (ADCSRA & 0xF8) | (config_Ptr->clk) ; //clock

	ADCSRA |= (1 << ADEN);  // ADC enable bit


}

uint16 ADC_readChannel (uint8 ch_num)
{

	ADMUX = (ADMUX & 0XE0) | (ch_num & 0X1F); // select channel
	ADCSRA |= (1 << ADSC);  // start conversion bit
	while (!(ADCSRA & (1<<ADIF))) //polling
	{}
	ADCSRA |= (1 << ADIF);  // clear flag
	return ADC;  // data register
}
