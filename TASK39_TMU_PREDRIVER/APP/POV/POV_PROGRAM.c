/*
 * POV_PROGRAM.c
 *
 *  Created on: Nov 17, 2023
 *      Author: hossa
 */

#include "POV_int.h"


static u8 LOC_u8DisplayNumber;

typedef enum
{
	POV_WRITE_FIRST,
	POV_DELAY_FIRST,
	POV_WRITE_SECOND,
	POV_DELAY_SECOND,
	POV_STOP
} POV_STATE;

static POV_STATE LOC_enuPOVStateMachine = POV_WRITE_FIRST;

ES_t POV_enuInit(void)
{
	return HexaDec_enuInit();
}

void POV_vidDisplayTask(void)
{
	switch(LOC_enuPOVStateMachine)
	{
		case POV_WRITE_FIRST:
			HexaDec_enuDisableSSG(SSG_LEFT);
			HexaDec_enuDisableSSG(SSG_RIGHT);
			HexaDec_enuDisplayNum(LOC_u8DisplayNumber % 10);

			HexaDec_enuEnableSSG(SSG_RIGHT);

			LOC_enuPOVStateMachine = POV_DELAY_FIRST;
		break;
		case POV_DELAY_FIRST:
			LOC_enuPOVStateMachine = POV_WRITE_SECOND;
		break;
		case POV_WRITE_SECOND:
			HexaDec_enuDisableSSG(SSG_LEFT);
			HexaDec_enuDisableSSG(SSG_RIGHT);
			HexaDec_enuDisplayNum(LOC_u8DisplayNumber / 10);
			HexaDec_enuEnableSSG(SSG_LEFT);

			LOC_enuPOVStateMachine = POV_DELAY_SECOND;
		break;
		case POV_DELAY_SECOND:
			LOC_enuPOVStateMachine = POV_WRITE_FIRST;
		break;
		case POV_STOP:
			HexaDec_enuDisableSSG(SSG_LEFT);
			HexaDec_enuDisableSSG(SSG_RIGHT);
		break;
	}
}

void POV_vidSetDisplayedNumber(u8 Copy_u8Number)
{
	LOC_u8DisplayNumber = Copy_u8Number;
}

void POV_vidStopDisplay(void)
{
	LOC_enuPOVStateMachine = POV_STOP;
}

void POV_vidResumeDisplay(void)
{
	LOC_enuPOVStateMachine = POV_WRITE_FIRST;
}


