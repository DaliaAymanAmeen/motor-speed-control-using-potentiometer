/*
 * adc.h
 *
 *  Created on: Sep 18, 2020
 *      Author: user
 */

#ifndef ADC_H_
#define ADC_H_

typedef enum
{
	DIVISION_FACTOR_2,DIVISION_FACTOR_2_,DIVISION_FACTOR_4,DIVISION_FACTOR_8,DIVISION_FACTOR_16,DIVISION_FACTOR_32,\
	DIVISION_FACTOR_64,DIVISION_FACTOR_128
}ADC_Clock;


typedef enum
{
	VOLT_REF_OFF,AVCC, ___ ,INTERNAL_VOLT_REF
}ADC_Volt_Refrence;


typedef struct
{
	ADC_Clock clk;
	ADC_Volt_Refrence volt_ref;
}ADC_Config;


#include "util/delay.h"
#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

void ADC_init (const ADC_Config * config_Ptr);
uint16 ADC_readChannel (uint8 ch_num);

#endif /* ADC_H_ */
