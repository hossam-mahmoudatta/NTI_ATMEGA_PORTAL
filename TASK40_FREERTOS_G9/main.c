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

int
main(int argc, char const *argv[])
{
	Project_vidInit();

	xTaskCreate(Project_vidDisplayTask, NULL,110,NULL,5,NULL);
	xTaskCreate(Project_vidUpdateByUART, NULL,80,NULL,4,NULL);
	xTaskCreate(Project_vidLight   , NULL,80,NULL,3,NULL);
	xTaskCreate(Project_vidIncrease, NULL,180,NULL,2,NULL);
	xTaskCreate(Project_vidDecrease, NULL,180,NULL,2,NULL);

	vTaskStartScheduler();

	return 0;
}
