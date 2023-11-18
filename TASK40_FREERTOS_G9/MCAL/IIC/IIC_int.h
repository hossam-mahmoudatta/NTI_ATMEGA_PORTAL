/*
 * IIC_int.h
 *
 *  Created on: Sep 30, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef IIC_INT_H_
#define IIC_INT_H_

ES_t IIC_enuInit(void);

ES_t IIC_enuStartCondition(void);

ES_t IIC_enuRepeatedStartCondition(void);

ES_t IIC_enuStopCondition(void);

ES_t IIC_enuWriteSlaveAddress(u8 Copy_u8SlaveAddress , u8 Copy_u8Operation);

ES_t IIC_enuWriteData(u8 Copy_u8Data);

ES_t IIC_enuCheckMyAddress(void);

ES_t IIC_enuReadData(u8 * Copy_pu8Data);


#endif /* IIC_INT_H_ */
