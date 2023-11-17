/*
 * POV_PROGRAM.c
 *
 *  Created on: Nov 17, 2023
 *      Author: hossa
 */

#include "../LIB/stdTypes.h"
#include "../LIB/errorState.h"

#include "POV_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/Switch/Switch_int.h"
#include "../TMU/TMU_int.h"
#include "../HAL/HexaDecoder/HexaDecoder_int.h"

static u8 LOC_u8POVState;
static u8 LOC_u8DisplayNumber;

typedef enum
{
	POV_WRITE_FIRST,
	POV_DELAY_FIRST,
	POV_WRITE_SECOND,
	POV_DELAY_SECOND,
	POV_STOP
} POV_STATE;

ES_t POV_enuInit(void)
{
	return HexaDec_enuInit();
}

void POV_vidDisplayTask(void)
{
	switch(LOC_u8POVState)
	{
		case POV_WRITE_FIRST:
			HexaDec_enuDisableSSG(SSG_LEFT);
			HexaDec_enuDisableSSG(SSG_RIGHT);
			HexaDec_enuDisplayNum(LOC_u8DisplayNumber % 10);

			HexaDec_enuEnableSSG(SSG_RIGHT);

			LOC_u8POVState = POV_DELAY_FIRST;
		break;
		case POV_DELAY_FIRST:
			LOC_u8POVState = POV_WRITE_SECOND;
		break;
		case POV_WRITE_SECOND:
			HexaDec_enuDisplayNum(LOC_u8DisplayNumber / 10);

			HexaDec_enuEnableSSG(SSG_LEFT);

			LOC_u8POVState = POV_DELAY_SECOND;
		break;
		case POV_DELAY_SECOND:
			LOC_u8POVState = POV_WRITE_FIRST;
		break;
		case POV_STOP:
			POV_vidStopDisplay();
		break;
	}
}

void POV_vidSetDisplayedNumber(u8 Copy_u8Number)
{
	LOC_u8DisplayNumber = Copy_u8Number;
}

void POV_vidStopDisplay(void)
{
	HexaDec_enuDisableSSG(SSG_LEFT);
	HexaDec_enuDisableSSG(SSG_RIGHT);
}

void POV_vidResumeDisplay(void)
{
	LOC_u8POVState = POV_WRITE_FIRST;
}


