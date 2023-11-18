#ifndef _WDTIMER_H_
#define _WDTIMER_H_

void WDT_vidEnable(u8 Copy_u8WDTimeSet);

void WDT_vidStop(void);

#define _16_MS            0
#define _32_MS            1
#define _65_MS            2
#define _130_MS           3
#define _260_MS           4
#define _520_MS           5
#define _1000_MS          6
#define _2100_MS          7

#endif