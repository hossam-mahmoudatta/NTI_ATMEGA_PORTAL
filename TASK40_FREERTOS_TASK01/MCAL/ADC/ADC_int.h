/*
 * ADC_int.h
 *
 *  Created on: Sep 23, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

ES_t ADC_enuInit(void);

ES_t ADC_enuReadPolling(u8 Copy_u8Channel , u16 * Copy_pu16ADCRead);


ES_t ADC_enuStartConversion(void);

ES_t ADC_enuSetADCChannel(u8 Copy_u8Channel);

ES_t ADC_enuRead(u16 * Copy_pu16ADCRead);

ES_t ADC_enuReadHigh(u8 * Copy_pu8ADCRead);

ES_t ADC_enuSetTriggerSource(u8 Copy_u8TriggerSource);
ES_t ADC_enuClearTriggerSource(void);

ES_t ADC_enuSetCallBack(void (*Copy_pfunAppFun)(void*), void * Copy_pvidParameter);


ES_t ADC_enuEnableInterrupt(void);
ES_t ADC_enuDisableInterrupt(void);

ES_t ADC_enuEnable(void);
ES_t ADC_enuDisable(void);

enum 
{
    ADC0 , ADC0_ADC0_10x,
};

#endif /* MCAL_ADC_ADC_INT_H_ */
