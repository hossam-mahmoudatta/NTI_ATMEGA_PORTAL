/*
 * GIE_prog.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_MCAL_GIE != 0


#include "../../stdTypes.h"


static s8 LOC_s8DisableGIECounter = 0;
static BOOL LOC_bIsStartupAccessed = FALSE;


void GIE_vidEnable(void)
{
	if (LOC_bIsStartupAccessed == FALSE)
	{
		asm("sei");
		LOC_bIsStartupAccessed = TRUE;
	}
	else
	{
		if (LOC_s8DisableGIECounter > 0)
		{
			LOC_s8DisableGIECounter--;
			LOC_bIsStartupAccessed = TRUE;
			if (LOC_s8DisableGIECounter <= 0)
			{
				asm("sei");
			}
		}
	}
}

void GIE_vidDisable(void)
{
	asm("cli");
	LOC_s8DisableGIECounter++;
	LOC_bIsStartupAccessed = TRUE;
}
#endif

/*

enable GIE can be also enabled by these methods:

	//#define SREG 		*((volatile unsigned char*)0x5F)
	//	SREG |= (1<<7);
	
	//	__asm("sei");
	
	//	__asm__("sei");
*/
