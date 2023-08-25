/*
 * main.c
 *
 *  Created on: Aug 22, 2023
 *      Author: user
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_private.h"


#include "../HAL/LED/LED_interface.h"
#include "../HAL/LED/LED_private.h"

#include "../HAL/CLCD/CLCD_private.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/CLCD/CLCD_config.h"


#include "../HAL/KPD/KPD_interface.h"


#include <avr/delay.h>

LED_CONFIG LED1={LED_PORTC, LED_PIN0, LED_ACTIVE_HIGH};
LED_CONFIG LED2={LED_PORTC, LED_PIN1, LED_ACTIVE_HIGH};
LED_CONFIG LED3={LED_PORTC, LED_PIN2, LED_ACTIVE_HIGH};
LED_CONFIG LED4={LED_PORTC, LED_PIN3, LED_ACTIVE_HIGH};

int main()
{
	HLED_voidLEDIntialization(LED1);
	HLED_voidLEDIntialization(LED2);
	HLED_voidLEDIntialization(LED3);
	HLED_voidLEDIntialization(LED4);

	CLCD_voidInitialization();
	HKPD_voidInitialization();
	CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COLUMN_1);
	CLCD_voidSendString("Choose the mode");
	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COLUMN_1);
	CLCD_voidSendString("lighting the led");
	_delay_ms(10);
	CLCD_voidClearScreen();
	CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COLUMN_1);
	CLCD_voidSendString("1-TOG  2-LTR");
	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COLUMN_1);
	_delay_ms(10);
	CLCD_voidClearScreen();
	CLCD_voidSendString("3-RTL  4-BingBong");
	u8 keyPressed;
	while(1)
	{
		keyPressed=HKPD_u8GetPressedKey();
		if(keyPressed=='1')
		{
			HLED_voidLEDToggle(LED1);
			_delay_ms(50);
			HLED_voidLEDToggle(LED2);
			_delay_ms(50);
			HLED_voidLEDToggle(LED3);
			_delay_ms(50);
			HLED_voidLEDToggle(LED4);
			_delay_ms(50);
		}
		if(keyPressed=='2')
		{
			HLED_voidLEDOn(LED1);
			_delay_ms(50);
			HLED_voidLEDOn(LED2);
			_delay_ms(50);
			HLED_voidLEDOn(LED3);
			_delay_ms(50);
			HLED_voidLEDOn(LED4);
			_delay_ms(10);
			HLED_voidLEDOff(LED1);
			_delay_ms(10);
			HLED_voidLEDOff(LED2);
			_delay_ms(10);
			HLED_voidLEDOff(LED3);
			_delay_ms(10);
			HLED_voidLEDOff(LED4);
			_delay_ms(10);

		}

		if(keyPressed=='3')
		{
			HLED_voidLEDOn(LED1);
			_delay_ms(50);
			HLED_voidLEDOn(LED2);
			_delay_ms(50);
			HLED_voidLEDOn(LED3);
			_delay_ms(50);
			HLED_voidLEDOn(LED4);
			_delay_ms(10);
			HLED_voidLEDOff(LED4);
			_delay_ms(10);
			HLED_voidLEDOff(LED3);
			_delay_ms(10);
			HLED_voidLEDOff(LED2);
			_delay_ms(10);
			HLED_voidLEDOff(LED1);
			_delay_ms(10);

		}
		if(keyPressed=='4')
		{
			HLED_voidLEDOn(LED1);
			_delay_ms(50);
			HLED_voidLEDOff(LED2);
			_delay_ms(50);
			HLED_voidLEDOff(LED3);
			_delay_ms(50);
			HLED_voidLEDOn(LED4);
			_delay_ms(10);
			HLED_voidLEDOff(LED1);
			_delay_ms(10);
			HLED_voidLEDOn(LED2);
			_delay_ms(10);
			HLED_voidLEDOn(LED3);
			_delay_ms(10);
			HLED_voidLEDOff(LED4);
			_delay_ms(10);

		}
	}

	return 0;

}
