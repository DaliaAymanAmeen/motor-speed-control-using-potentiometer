#include "adc.h"
#include "lcd.h"
#include "motor.h"
#include "pwm_timer0.h"
#include "interrupt.h"


int main(void)
{
	DDRA &= ~(1 << PA0); // input pin for the potentiometer
	DDRD &= ~(1 << PD3); // input pin for the push button (interrupt)
	ADC_Config config= {DIVISION_FACTOR_8, VOLT_REF_OFF};

	motor_init();
	ADC_init(&config);
	LCD_init();
	Int1_init();

	uint32 data = 0;



	LCD_displayString("ADC Value = ");

	while (1)
	{
		data = ADC_readChannel (0x00000) ; // ADC0 channel_0
		LCD_goToRowColumn(0, 12);
		LCD_intgerToString(data);
		PWM_Timer0_Init(data/4);
	}


}
