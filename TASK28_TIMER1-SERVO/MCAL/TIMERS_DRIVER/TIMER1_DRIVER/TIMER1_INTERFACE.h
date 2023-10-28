/*
 * timer.h
 *
 * Created: 8/19/2022 3:44:17 AM
 *  Author: Administrator
 */ 



#ifndef TIMER_H_
#define TIMER_H_

#include "../DIO_DRIVER/DIO.h"
#include "TIMER_PRIVATE.h"

#define PRESCALER_NO   1
#define PRESCALER_1024 1024
#define PRESCALER_256  256
#define PRESCALER_64   64
#define PRESCALER_8    8
#define PRESCALER_0    0 
#define CPU_FREQ	   1000000

typedef enum EN_TIMER_Error_t {
	TIMER_OK,
	TIMER_WRONG_PRESCALER,
	TIMER_WRONG_DELAYVALUE
} EN_TIMER_Error_t;


EN_TIMER_Error_t TIMER_Init(uint32_t prescaler);

EN_TIMER_Error_t TIMER_DelaySet(uint32_t prescaler, float timeDelay);

void TIMER_CheckStatus(uint8_t pinNumber, uint8_t portNumber);

void TIMER_Start(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

uint8_t TIMER_Read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

#endif /* TIMER_H_ */