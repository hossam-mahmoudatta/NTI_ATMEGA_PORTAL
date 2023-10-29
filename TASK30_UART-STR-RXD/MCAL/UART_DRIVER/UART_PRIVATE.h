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

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "../GPIO_DRIVER/GPIO_INTERFACE.h"

/*******************************************************************************
 *                              							UART Registers					              			     	   *
 *******************************************************************************/
typedef struct {
	u8 MPCM: 	1;		// Multi Processor Communication Mode
	u8 U2X: 		1;		// Double the Speed of the UART
	u8 PE: 		1;		// Parity Error
	u8 DOR: 		1;		// Data OverRun
	u8 FE: 		1;		// Frame Error
	u8 UDRE: 	1;		// Data Register Empty Flag
	u8 TXC: 		1;		// Transmit Complete Flag
	u8 RXC: 		1;		// Receive Complete Flag
} UCSRA;
#define UCSRA_REG		((volatile UCSRA*) 0x2B)

typedef struct {
	u8 TXB8: 		1;		// Transmit Data bit 8
	u8 RXB8: 		1;		// Receive Data bit 8
	u8 UCSZ2: 	1;		// Choose Character Size
	u8 TXEN: 		1;		// Transmitter Enable
	u8 RXEN: 		1;		// Receiver Enable
	u8 UDRIE: 		1;		// Data Register Empty Interrupt Enable
	u8 TXCIE: 		1;		// Tx Complete Interrupt Enable
	u8 RXCIE: 		1;		// Rx Complete Interrupt Enable
} UCSRB;
#define UCSRB_REG		((volatile UCSRB*) 0x2A)

#define UCSRC_URSEL	7
#define UCSRC_UMSEL	6
#define UCSRC_UPM1		5
#define UCSRC_UPM0		4
#define UCSRC_USBS		3
#define UCSRC_UCSZ1	2
#define UCSRC_UCSZ0	1
#define UCSRC_UCPOL	0
#define UCSRC_REG		(*((volatile u8*) 0x40))

// 2 Registers but sharing the same address
#define UDR_REG				( *((volatile u8*)0x2C))
#define UBRRL_REG		( *((volatile u8*)0x29))
#define UBRRH_REG		( *((volatile u8*) 0x40))


#endif /* UART_PRIVATE_H_ */
