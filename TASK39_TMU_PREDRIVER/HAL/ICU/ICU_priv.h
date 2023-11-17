/*
 * ICU_priv.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_ICU_ICU_PRIV_H_
#define HAL_ICU_ICU_PRIV_H_

static void vidReadingTask(void);
static void vidTimerCallBack(void);



typedef struct 
{
    u8 u8TonCounts;
    u8 u8TcCounts;
    u16 u8TonOvfCounts;
    u16 u8TcOvfCounts;
}ICU_t;

typedef enum
{
    ICU_FIRST_RISING,
    ICU_FALLING,
    ICU_SECOND_RISING,
    IDLE,
}ICU_State_t;

#endif /* HAL_ICU_ICU_PRIV_H_ */
