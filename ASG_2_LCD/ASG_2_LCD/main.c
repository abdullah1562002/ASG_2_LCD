/*
 * ASG_2_LCD.c
 *
 * Author : Abdullah Abdelgalel
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* HAL */
#include "LCD_interface.h"
#include "DIO_interface.h"

int main(void)
{
	LCD_init();
	u32 counter = 0;
	LCD_writeNumber(counter);
	// Button1 (increment) Port B Pin 0 >> I/O
	DIO_setPinDirection(DIO_PORTB, DIO_PIN0, DIO_PIN_INPUT);
	
	// Button2 (decrement) Port D Pin 6 >> I/O
	DIO_setPinDirection(DIO_PORTD, DIO_PIN6, DIO_PIN_INPUT);
	
	u8 B1,B2;
	
	while (1)
	{
		DIO_getPinValue(DIO_PORTB, DIO_PIN0, &B1);
		_delay_ms(2);
		if(B1 == 1 && counter < 9)
		{
			_delay_ms(2);
			++counter;
			LCD_clear();
			LCD_writeNumber(counter);
		}
		
		DIO_getPinValue(DIO_PORTD, DIO_PIN6, &B2);
		_delay_ms(2);
		if(B2 == 1 && counter > 0)
		{
			_delay_ms(2);
			--counter;
			LCD_clear();
			LCD_writeNumber(counter);
		}
	}
}

