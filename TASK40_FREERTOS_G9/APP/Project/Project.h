/*
 * Project.h
 *
 *  Created on: Nov 16, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef APP_PROJECT_PROJECT_H_
#define APP_PROJECT_PROJECT_H_

void Project_vidInit(void);

void Project_vidDisplayTask(void*pv);

void Project_vidLight(void*pv);

void Project_vidIncrease(void*pv);

void Project_vidDecrease(void*pv);

void Project_vidUpdateByUART(void*pv);


#endif /* APP_PROJECT_PROJECT_H_ */
