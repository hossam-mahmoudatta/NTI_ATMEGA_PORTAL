/*
 * EXTI_config.h
 *
 *  Created on: Sep 16, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

#define EXTI_NUM_PINS           3

typedef struct 
{
    u8 intPin;
    u8 senseLevel;
    u8 intMode;
}EXTI_t;


#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
