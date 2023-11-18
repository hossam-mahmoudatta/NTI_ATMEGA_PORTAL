/*
 * POV_int.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef POV_INT_H_
#define POV_INT_H_

#include "../../HAL/HexaDecoder/HexaDecoder_int.h"
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../TMU/TMU_int.h"


ES_t POV_enuInit(void);

void POV_vidDisplayTask(void);

void POV_vidSetDisplayedNumber(u8 Copy_u8Number);

void POV_vidStopDisplay(void);

void POV_vidResumeDisplay(void);

// No need
ES_t POV_enuDisplayNum(u8 Copy_u8Num);

#endif /* POV_INT_H_ */
