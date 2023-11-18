/*
 * Update_int.h
 *
 *  Created on: Oct 7, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef APP_TRAFFIC_UPDATE_INT_H_
#define APP_TRAFFIC_UPDATE_INT_H_

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../HAL/Switch/Switch_int.h"
#include "../../TMU/TMU_int.h"


void Update_vidInit(void);

void Update_vidIncreaseTask(void);

void Update_vidDecreaseTask(void);

u8 Update_u8GetTrafficTime(void);

#endif /* APP_TRAFFIC_UPDATE_INT_H_ */
