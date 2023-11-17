/*
 * Update_PROGRAM.c
 *
 *  Created on: Nov 17, 2023
 *      Author: hossa
 */

#include "Update_int.h"
#include "../LIB/stdTypes.h"
#include "../LIB/errorState.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/Switch/Switch_int.h"
#include "../TMU/TMU_int.h"
#include "../HAL/HexaDecoder/HexaDecoder_int.h"


void Update_vidInit(void)
{
	DIO_enuSetPinDirection(DIO_GROUP_A, DIO_PIN_0, DIO_INPUT);
	DIO_enuSetPinDirection(DIO_GROUP_A, DIO_PIN_1, DIO_INPUT);
	DIO_enuSetPinDirection(DIO_GROUP_A, DIO_PIN_2, DIO_INPUT);
}

void Update_vidIncreaseTask(void);

void Update_vidDecreaseTask(void);

u8 Update_u8GetTrafficTime(void);

