 /******************************************************************************
 *
 * Module: USART (Universal Synchronous Asynchronous Receiver Transmitter)
 *
 * File Name: USART.h
 *
 * Description: Header file for the AVR USART Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef USART_H_
#define USART_H_

#include "UART_CONFIG.h"

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the USART Module to start functionality
void UART_Initialization(void);

// Responsible for the USART to send a byte
void UART_voidSendByte_Polling(const u8 data);

// Responsible for the USART to receive a byte
u8 UART_voidReceiveByte_Polling(void);

// Responsible for the USART to send an array of bytes, a string
void UART_voidSendString(const u8 *str);

// Responsible for the USART to receive an array of bytes, a string
void UART_voidReceiveString(u8 *str);

#endif /* USART_H_ */
