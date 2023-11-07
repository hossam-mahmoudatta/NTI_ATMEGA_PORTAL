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
void UART_voidSendByte_Polling(u8 copy_u8Data);

// Responsible for the USART to receive a byte
u8 UART_voidReceiveByte_Polling(void);

// Responsible for the USART to send a byte using ISR
void UART_voidSendByte_ISR(u8 copy_u8Data);

// Responsible for the USART to receive a byte
u8 UART_voidReceiveByte_ISR(void);

// Responsible for the USART to send an array of bytes, a string
void UART_voidSendString(const u8 *str);

// Responsible for the USART to receive an array of bytes, a string
void UART_voidReceiveString(u8 *str);

// UART RXC Callback Function
void UART_CallBackFunction_RXC(void (*Ptr_UART_RXC)(void));

// UART UDRE Callback Function
void UART_CallBackFunction_UDRE(void (*Ptr_UART_UDRE)(void));

// UART TXC Callback Function
void UART_CallBackFunction_TXC(void (*Ptr_UART_TXC)(void));

#endif /* USART_H_ */
