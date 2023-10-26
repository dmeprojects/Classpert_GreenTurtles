/*
 * app.c
 *
 *  Created on: Oct 26, 2023
 *      Author: nick_
 */

#include "app.h"
#include "main.h"

#include "usb_device.h"

#include "custom_pindefines.h"
#include "state_defines.h"

extern ledState LedState;

void mainApp (void)
{

	unsigned char previousLedState = ROTATE;
	unsigned char i;

	  if( LedState != previousLedState)
	  {
		  //Turn all LEDS off before beginning a new pattern
		  HAL_GPIO_WritePin(GPIOD, LED_ORANGE, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOD, LED_RED, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOD, LED_BLUE, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOD, LED_GREEN, GPIO_PIN_RESET);

		  previousLedState = LedState;
	  }

	  switch (LedState)
	  {
	  case ROTATE:
		  /*Rotate LEDs with 100ms time between*/
		  HAL_GPIO_TogglePin(GPIOD, LED_ORANGE);
		  HAL_Delay(100);
		  HAL_GPIO_TogglePin(GPIOD, LED_RED);
		  HAL_Delay(100);
		  HAL_GPIO_TogglePin(GPIOD, LED_BLUE);
		  HAL_Delay(100);
		  HAL_GPIO_TogglePin(GPIOD, LED_GREEN);
		  HAL_Delay(100);
		  break;
	  case POLICE:
		  for (i = 0; i<4; i++)
		  {
			  HAL_GPIO_TogglePin(GPIOD, LED_BLUE);
			  HAL_Delay(100);
		  }
		  for (i = 0; i<4; i++)
		  {
			  HAL_GPIO_TogglePin(GPIOD, LED_RED);
			  HAL_Delay(100);
		  }
		  break;
	  case STROBE:
		  HAL_GPIO_TogglePin(GPIOD, LED_ORANGE);
		  HAL_GPIO_TogglePin(GPIOD, LED_RED);
		  HAL_GPIO_TogglePin(GPIOD, LED_BLUE);
		  HAL_GPIO_TogglePin(GPIOD, LED_GREEN);
		  HAL_Delay(50);
		  break;
	  case MAXFUNCTIONS:
		  LedState = ROTATE;
		  break;
	  }
}
