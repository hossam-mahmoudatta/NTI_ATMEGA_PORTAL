/*
 * POV_int.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef POV_INT_H_
#define POV_INT_H_

ES_t POV_enuInit(void);

void POV_vidDisplayTask(void);

void POV_vidSetDisplayedNumber(u8 Copy_u8Number);

void POV_vidStopDisplay(void);

void POV_vidResumeDisplay(void);


ES_t POV_enuDisplayNum(u8 Copy_u8Num);

#endif /* POV_INT_H_ */
