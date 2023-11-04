
#ifndef WDT_REGISTER_H_
#define WDT_REGISTER_H_


/* Watchdog Timer Control Register */
#define  WDTCR_REG    *((volatile uint8*)0x41)

/* Watchdog Timer Prescaler bit 0 */
#define  WDTCR_WDP0     0u
/* Watchdog Timer Prescaler bit 1 */
#define  WDTCR_WDP1     1u
/* Watchdog Timer Prescaler bit 2 */
#define  WDTCR_WDP2     2u
/* Watchdog Enable */
#define  WDTCR_WDE      3u
/* Watchdog Turn-off Enable */
#define  WDTCR_WDTOE    4u


#endif /* WDT_REGISTER_H_ */
