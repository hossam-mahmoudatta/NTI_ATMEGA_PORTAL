/*
 * Update_PROGRAM.c
 *
 *  Created on: Nov 17, 2023
 *      Author: hossa
 */


/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "Update_int.h"
#include "../LIB/stdTypes.h"
#include "../LIB/errorState.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/Switch/Switch_int.h"
#include "../TMU/TMU_int.h"
#include "../HAL/HexaDecoder/HexaDecoder_int.h"

static u8 		LOC_u8SystemTime = 15;
static BOOL	LOC_bIncrementFirstPress = FALSE;
static BOOL	LOC_bIncrementHoldPress = FALSE;

static BOOL	LOC_bDecrementFirstPress = FALSE;
static BOOL	LOC_bDecrementHoldPress = FALSE;

/*******************************************************************************
 *                              				FUNCTION IMPLEMENTATIONS				                   	   *
 *******************************************************************************/

void Update_vidInit(void)
{
	Switch_enuInit();
}

void Update_vidIncreaseTask(void)
{
	u8 LOC_u8SwitchVal;
	Switch_enuGetSwitchState(SWITCH_BUTTON_0, &LOC_u8SwitchVal);

	if((TRUE == LOC_u8SwitchVal) && (FALSE == LOC_bIncrementFirstPress))
	{
		LOC_bIncrementFirstPress = TRUE;
	}
	else if (TRUE == LOC_u8SwitchVal && TRUE == LOC_bIncrementFirstPress && FALSE == LOC_bIncrementHoldPress)
	{
		LOC_u8SystemTime = (LOC_u8SystemTime < 99) ? (LOC_u8SystemTime + 1) : (LOC_u8SystemTime);
	}
	else if ((TRUE == LOC_u8SwitchVal) && (TRUE == LOC_bIncrementFirstPress) && (TRUE == LOC_bIncrementHoldPress))
	{
		LOC_bIncrementFirstPress = FALSE;
		LOC_bIncrementHoldPress = FALSE;
	}
	else
	{

	}
}



void Update_vidDecreaseTask(void)
{
	if(LOC_bIncrementHoldPress == TRUE)
	{
		u8 LOC_u8SwitchVal;
		Switch_enuGetSwitchState(SWITCH_BUTTON_1, &LOC_u8SwitchVal);

	    if((TRUE == LOC_u8SwitchVal) && (FALSE == LOC_bDecrementFirstPress))
	    {
	    	LOC_bDecrementFirstPress = TRUE;
	    }
	    else if (TRUE == LOC_u8SwitchVal && TRUE == LOC_bDecrementFirstPress && FALSE == LOC_bDecrementHoldPress)
	    {
	    	LOC_u8SystemTime = (LOC_u8SystemTime > 15) ? (LOC_u8SystemTime - 1) : (LOC_u8SystemTime);
	    }
	    else if ((TRUE == LOC_u8SwitchVal) && (TRUE == LOC_bDecrementFirstPress) && (TRUE == LOC_bDecrementHoldPress))
		{
	    	LOC_bDecrementFirstPress = FALSE;
			LOC_bDecrementHoldPress = FALSE;
		}
	    else
	    {

	    }
	}
	else
	{
    	LOC_bDecrementFirstPress = FALSE;
		LOC_bDecrementHoldPress = FALSE;
	}
}



u8 Update_u8GetTrafficTime(void)
{
	return LOC_u8SystemTime;
}










