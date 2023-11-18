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
	LIGHT_YELLOW,
	LIGHT_RED,
} LIGHT_STATE;

static LIGHT_STATE LOC_enuLIGHTStateMachine = LIGHT_GREEN;

static LIGHT_STATE LOC_enuLIGHTPreviousStateMachine;

static u8		LOC_u8SystemTime;
static u16	LOC_u16TimeQualifier;
static BOOL LOC_bOneTimeAccess = FALSE;


void Light_vidInit(void)
{
	DIO_enuSetPinDirection(GREEN_LED, DIO_OUTPUT);
	DIO_enuSetPinDirection(YELLOW_LED, DIO_OUTPUT);
	DIO_enuSetPinDirection(RED_LED, DIO_OUTPUT);

	DIO_enuSetPinValue(GREEN_LED, DIO_LOW);
	DIO_enuSetPinValue(YELLOW_LED, DIO_LOW);
	DIO_enuSetPinValue(RED_LED, DIO_LOW);
}



void Light_vidTrafficTask(void)
{
	switch(LOC_enuLIGHTStateMachine)
	{
	case LIGHT_GREEN:
		if(LOC_bOneTimeAccess == FALSE)
		{
			DIO_enuSetPinValue(GREEN_LED, DIO_HIGH);
			DIO_enuSetPinValue(YELLOW_LED, DIO_LOW);
			DIO_enuSetPinValue(RED_LED, DIO_LOW);
			LOC_u8SystemTime = Update_u8GetTrafficTime();

			POV_vidSetDisplayedNumber(LOC_u8SystemTime);
			LOC_u16TimeQualifier = ((LOC_u8SystemTime - 3) * 4) - 1;

			LOC_bOneTimeAccess = TRUE;
		}
		else
		{
			LOC_u16TimeQualifier--;
			POV_vidSetDisplayedNumber((LOC_u16TimeQualifier + 12 + 1 + 3) / 4);

			if(LOC_u16TimeQualifier == 0)
			{
				LOC_bOneTimeAccess = FALSE;
				LOC_enuLIGHTPreviousStateMachine = LIGHT_GREEN;
				LOC_enuLIGHTStateMachine = LIGHT_YELLOW;
				LOC_u16TimeQualifier = 12;
			}
		}
		break;

		case LIGHT_YELLOW:
			LOC_u16TimeQualifier--;
			DIO_enuTogglePinValue(YELLOW_LED);
			if(LOC_u16TimeQualifier == 0)
			{
				if(LOC_enuLIGHTPreviousStateMachine == LIGHT_GREEN)
				{
					LOC_enuLIGHTStateMachine = LIGHT_RED;
				}
				else if(LOC_enuLIGHTPreviousStateMachine == LIGHT_RED)
				{
					LOC_enuLIGHTStateMachine = LIGHT_GREEN;
				}
			}
			break;

		case LIGHT_RED:
				if(LOC_bOneTimeAccess == FALSE)
				{
					DIO_enuSetPinValue(GREEN_LED, DIO_LOW);
					DIO_enuSetPinValue(YELLOW_LED, DIO_LOW);
					DIO_enuSetPinValue(RED_LED, DIO_HIGH);
					LOC_u8SystemTime = Update_u8GetTrafficTime();

					POV_vidSetDisplayedNumber(LOC_u8SystemTime);
					LOC_u16TimeQualifier = ((LOC_u8SystemTime - 3) * 4) - 1;
					LOC_bOneTimeAccess = TRUE;
				}
				else
				{
					LOC_u16TimeQualifier--;
					POV_vidSetDisplayedNumber((LOC_u16TimeQualifier + 12 + 1 + 3) / 4);

					if(LOC_u16TimeQualifier == 0)
					{
						LOC_bOneTimeAccess = FALSE;
						LOC_enuLIGHTPreviousStateMachine = LIGHT_RED;
						LOC_enuLIGHTStateMachine = LIGHT_YELLOW;
						LOC_u16TimeQualifier = 12;
					}
				}
				break;
	}
}
