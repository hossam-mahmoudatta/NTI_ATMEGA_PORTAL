/*
 * light_PROGRAM.c
 *
 *  Created on: Nov 17, 2023
 *      Author: hossa
 */

#include "light_int.h"
#include "../../MCAL/DIO/DIO_int.h"

typedef enum
{
	LIGHT_GREEN,
}LIGHTS;

void Light_vidInit(void)
{
	DIO_enuSetPinDirection(DIO_GROUP_A, DIO_PIN_0, DIO_OUTPUT);
	DIO_enuSetPinDirection(DIO_GROUP_A, DIO_PIN_1, DIO_OUTPUT);
	DIO_enuSetPinDirection(DIO_GROUP_A, DIO_PIN_2, DIO_OUTPUT);

	DIO_enuSetPinValue(DIO_GROUP_A, DIO_PIN_2);
}


void Light_vidTrafficTask(void)
{




}
