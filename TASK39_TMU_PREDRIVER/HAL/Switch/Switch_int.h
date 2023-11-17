/*
 * Switch_int.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef SWITCH_INT_H_
#define SWITCH_INT_H_

ES_t Switch_enuInit(void);

ES_t Switch_enuGetSwitchState(u8 Copy_u8SwitchID , u8 *Copy_pu8SwitchState);


#define SWITCH_BUTTON_0             0
#define SWITCH_BUTTON_1             1
#define SWITCH_BUTTON_2             2

#endif /* SWITCH_INT_H_ */
