/*
 * Update_int.h
 *
 *  Created on: Oct 7, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef APP_TRAFFIC_UPDATE_INT_H_
#define APP_TRAFFIC_UPDATE_INT_H_

void Update_vidInit(void);

void Update_vidIncreaseTask(void);

void Update_vidDecreaseTask(void);

void Update_vidSetTrafficTime(u8 Copy_u8Time);

u8 Update_u8GetTrafficTime(void);

BOOL Update_bIsIncButtonReleased(void);

BOOL Update_bIsDecButtonReleased(void);

#endif /* APP_TRAFFIC_UPDATE_INT_H_ */
