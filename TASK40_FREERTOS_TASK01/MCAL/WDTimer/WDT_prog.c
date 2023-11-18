#include "../../ATmega32_config.h"
#if atmega32ENABLE_MCAL_WDT != 0



#include "../../stdTypes.h"
#include"WDT_int.h"

#define WDTCR       *((u8*)0x41)

void WDT_vidEnable(u8 Copy_u8WDTimeSet)
{
    if (Copy_u8WDTimeSet <= _2100_MS)
    {
        WDTCR &= ~(7<<0);
        WDTCR |= (Copy_u8WDTimeSet<<0);

        WDTCR |= (1<<3);
    }
}

void WDT_vidStop(void)
{
    WDTCR |= (3<<3);
    WDTCR = 0;
}

#endif