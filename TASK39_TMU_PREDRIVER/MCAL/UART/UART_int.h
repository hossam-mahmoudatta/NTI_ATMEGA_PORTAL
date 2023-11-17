/*
 * UART_int.h
 *
 *  Created on: Sep 27, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef UART_INT_H_
#define UART_INT_H_

ES_t UART_enuInit(void);

ES_t UART_enuSendChar(u8 Copy_u8Data);

ES_t UART_enuRecieveChar(u8 *Copy_pu8Data);

ES_t UART_enuSendString(const char* Copy_pcData);
ES_t UART_enuTransmit(u8 * Copy_pu8Buffer , u8 Copy_u8Size , u8 Copy_u8Timeout);


ES_t UART_enuRecieveString(char * Copy_pcData);

ES_t UART_enuReceive_IT(u8 * Copy_pu8Buffer , u8 Copy_u8BufferSize);

ES_t UART_enuGetReceiveITState(void);


#endif /* UART_INT_H_ */
