/*
 * main.c
 *
 *  Created on: Sep 1, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#include "stdTypes.h"
#include "errorState.h"

#include "FreeRTOS.h"
#include "projdefs.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "event_groups.h"

#include "APP/POV/POV_int.h"
#include "APP/Traffic/light_int.h"
#include "APP/Traffic/Update_int.h"
#include "APP/Project/Project.h"


#include "HAL/Communication/Communication.h"
#include "HAL/LCD/LCD_int.h"
#include "HAL/Switch/Switch_int.h"
#include "HAL/Keypad/Keypad_int.h"
#include "HAL/ICU/ICU_int.h"

#include "MCAL/DIO/DIO_int.h"
#include "MCAL/GIE/GIE_int.h"
#include "MCAL/EXTI/EXTI_int.h"
#include "MCAL/ADC/ADC_int.h"
#include "MCAL/UART/UART_int.h"
#include "MCAL/SPI/SPI_int.h"

void vTask01Function(void* pvParameters);
void vTask02Function(void* pvParameters);

int
main(int argc, char const *argv[])
{
	Project_vidInit();

	xTaskCreate(vTask01Function, 					NULL,		110,	NULL,	5,	NULL);
	xTaskCreate(vTask02Function, 					NULL,		80,		NULL,	4,	NULL);


//	xTaskCreate(Project_vidLight   , 					NULL,		80,		NULL,	3,	NULL);
//	xTaskCreate(Project_vidIncrease, 				NULL,		180,	NULL,	2,	NULL);
//	xTaskCreate(Project_vidDecrease, 			NULL,		180,	NULL,	2,	NULL);

	vTaskStartScheduler();

	return 0;
}

void vTask01Function(void* pvParameters) {
    // Task behavior goes here
    for (;;) {
    	DIO_enuTogglePinValue(DIO_GROUP_A, DIO_PIN_0);
    	vTaskDelay(1000);
    }
}

void vTask02Function(void* pvParameters) {
    // Task behavior goes here
    for (;;) {
    	DIO_enuTogglePinValue(DIO_GROUP_A, DIO_PIN_1);
    	vTaskDelay(1500);
    }
}
