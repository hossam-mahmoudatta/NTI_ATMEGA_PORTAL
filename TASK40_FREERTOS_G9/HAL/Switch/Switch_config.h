/*
 * Switch_config.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

#define SWITCH_MAX_NUM          3

typedef struct 
{
    u8 swGrp;
    u8 swPin;
    u8 swState;
}Switch_t;

#endif /* SWITCH_CONFIG_H_ */
