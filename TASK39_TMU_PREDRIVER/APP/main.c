/*
 * main.c
 *
 *  Created on: Sep 1, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#include "../LIB/stdTypes.h"
#include "../LIB/errorState.h"

#include "POV/POV_int.h"
#include "Traffic/light_int.h"
#include "Traffic/Update_int.h"

#include "../TMU/TMU_int.h"
#include "../HAL/Communication/Communication.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/Switch/Switch_int.h"
#include "../HAL/Keypad/Keypad_int.h"
#include "../HAL/ICU/ICU_int.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/UART/UART_int.h"
#include "../MCAL/SPI/SPI_int.h"

// void inc (void)
// {
// 	static u8 x =0;
// 	x++;
// 	POV_vidSetDisplayedNumber(x);
// }

int
main(int argc, char const *argv[])
{
	// Comm_vidInit();

	POV_enuInit();
	Light_vidInit();
	Update_vidInit();
	TMU_vidInit();

	TMU_vidCreateTask(POV_vidDisplayTask,  1 , 0);
	TMU_vidCreateTask(Light_vidTrafficTask,  50 , 1);
	TMU_vidCreateTask(Update_vidDecreaseTask, 1 , 2);
	TMU_vidCreateTask(Update_vidIncreaseTask , 1 , 3);

	TMU_vidStartScheduler();

	return 0;
}


	//TMU_vidCreateTask((void(*)(void*))Comm_vidTask, NULL , 1 , 0);
