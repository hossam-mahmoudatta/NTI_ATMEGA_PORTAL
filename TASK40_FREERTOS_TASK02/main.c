/*
 * main.c
 *
 *  Created on: Sep 1, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#include "STD_TYPES.h"
//#include "errorState.h"

/*Include OS Headers */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

//#include "APP/POV/POV_int.h"
//#include "APP/Traffic/light_int.h"
//#include "APP/Traffic/Update_int.h"
//#include "APP/Project/Project.h"


//#include "HAL/Communication/Communication.h"
//#include "HAL/LCD/LCD_int.h"
//#include "HAL/Switch/Switch_int.h"
//#include "HAL/Keypad/Keypad_int.h"
//#include "HAL/ICU/ICU_int.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
//#include "MCAL/GIE/GIE_int.h"
//#include "MCAL/EXTI/EXTI_int.h"
//#include "MCAL/ADC/ADC_int.h"
//#include "MCAL/UART/UART_int.h"
//#include "MCAL/SPI/SPI_int.h"

void vTask01Function(void* pvParameters);
void vTask02Function(void* pvParameters);
void system_init(void);

int
main(int argc, char const *argv[])
{
	//Project_vidInit();
	system_init();

	xTaskCreate(vTask01Function, 					NULL,		100,	NULL,	1,	NULL);
	xTaskCreate(vTask02Function, 					NULL,		100,		NULL,	2,	NULL);

//	xTaskCreate(Project_vidLight   , 					NULL,		80,		NULL,	3,	NULL);
//	xTaskCreate(Project_vidIncrease, 				NULL,		180,	NULL,	2,	NULL);
//	xTaskCreate(Project_vidDecrease, 			NULL,		180,	NULL,	2,	NULL);

	vTaskStartScheduler();

	return 0;
}

void vTask01Function(void* pvParameters) {
    // Task behavior goes here
    while(1){
    	DIO_u8TogglePinValue(DIO_u8PORTA, DIO_u8PIN0);
    	vTaskDelay(1000);
    }
}

void vTask02Function(void* pvParameters) {
    // Task behavior goes here
    while(1){
    	DIO_u8TogglePinValue(DIO_u8PORTA, DIO_u8PIN1);
    	vTaskDelay(1500);
    }
}

void system_init(void)
{
	PORT_voidInit();
}
