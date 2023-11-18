/*
 * Update_prog.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_APP_UPDATE != 0

#include "../../stdTypes.h"
#include "../../errorState.h"

#include "../../HAL/Switch/Switch_int.h"
#include "Update_config.h"

static u8 LOC_u8SystemTime = 15;
static BOOL LOC_bIncFirstPress = FALSE;
static BOOL LOC_bIncHoldPress = FALSE;

static BOOL LOC_bDecFirstPress = FALSE;
static BOOL LOC_bDecHoldPress = FALSE;

void Update_vidInit(void)
{
	Switch_enuInit();
}

void Update_vidIncreaseTask(void)
{
	u8 Local_u8SwitchVal;
	Switch_enuGetSwitchState(SWITCH_BUTTON_0 , &Local_u8SwitchVal);
	if ((Local_u8SwitchVal == FALSE) && (LOC_bIncFirstPress == FALSE) )
	{
		LOC_bIncFirstPress = TRUE;
	}
	else if ((Local_u8SwitchVal == TRUE) && (LOC_bIncFirstPress == TRUE) && (LOC_bIncHoldPress == FALSE))
	{
		LOC_u8SystemTime = (LOC_u8SystemTime < 99 )? (LOC_u8SystemTime + 1): (LOC_u8SystemTime);
		LOC_bIncHoldPress = TRUE;
	}
	else if ((Local_u8SwitchVal == TRUE) && (LOC_bIncFirstPress == TRUE) && (LOC_bIncHoldPress == TRUE))
	{
		LOC_bIncFirstPress = FALSE;
		LOC_bIncHoldPress = FALSE;
	}
	else
	{

	}
	

}

void Update_vidDecreaseTask(void)
{
	u8 Local_u8SwitchVal;
	Switch_enuGetSwitchState(SWITCH_BUTTON_1 , &Local_u8SwitchVal);
	if ((Local_u8SwitchVal == FALSE) && (LOC_bDecFirstPress == FALSE) )
	{
		LOC_bDecFirstPress = TRUE;
	}
	else if ((Local_u8SwitchVal == TRUE) && (LOC_bDecFirstPress == TRUE) && (LOC_bDecHoldPress == FALSE))
	{
		LOC_u8SystemTime = (LOC_u8SystemTime > 15 )? (LOC_u8SystemTime - 1): (LOC_u8SystemTime);
		LOC_bDecHoldPress = TRUE;
	}
	else if ((Local_u8SwitchVal == TRUE) && (LOC_bDecFirstPress == TRUE) && (LOC_bDecHoldPress == TRUE))
	{
		LOC_bDecFirstPress = FALSE;
		LOC_bDecHoldPress = FALSE;
	}
	else
	{

	}
}

void Update_vidSetTrafficTime(u8 Copy_u8Time)
{
	if ((Copy_u8Time >= 15) && (Copy_u8Time <= 99))
	{
		LOC_u8SystemTime = Copy_u8Time;
	}
}

u8 Update_u8GetTrafficTime(void)
{
	return LOC_u8SystemTime;
}
BOOL Update_bIsIncButtonReleased(void)
{
	BOOL bFlag = FALSE;
	if ((LOC_bIncFirstPress == FALSE) && (LOC_bIncHoldPress == FALSE))
	{
		bFlag = TRUE;
	}
	return bFlag;
}

BOOL Update_bIsDecButtonReleased(void)
{
	BOOL bFlag = FALSE;
	if ((LOC_bDecFirstPress == FALSE) && (LOC_bDecFirstPress == FALSE))
	{
		bFlag = TRUE;
	}
	return bFlag;
}

#endif
