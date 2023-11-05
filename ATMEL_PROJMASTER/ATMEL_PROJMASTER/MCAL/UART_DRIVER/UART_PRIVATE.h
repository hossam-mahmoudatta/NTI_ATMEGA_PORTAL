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

#define	UCSRA_MPCM	0		// Multi Processor Communication Mode
#define	UCSRA_U2X	1		// Double the Speed of the UART
#define	UCSRA_PE	2		// Parity Error
#define	UCSRA_DOR	3		// Data OverRun
#define	UCSRA_FE	4		// Frame Error
#define	UCSRA_UDRE	5		// Data Register Empty Flag
#define	UCSRA_TXC	6		// Transmit Complete Flag
#define	UCSRA_RXC	7		// Receive Complete Flag
#define UCSRA_REG		*((volatile u8*) 0x2B)


#define UCSRB_TXB8	0		// Transmit Data bit 8
#define UCSRB_RXB8	1		// Receive Data bit 8
#define UCSRB_UCSZ2	2		// Choose Character Size
#define UCSRB_TXEN	3		// Transmitter Enable
#define UCSRB_RXEN	4		// Receiver Enable
#define UCSRB_UDRIE	5		// Data Register Empty Interrupt Enable
#define UCSRB_TXCIE	6		// Tx Complete Interrupt Enable
#define UCSRB_RXCIE	7		// Rx Complete Interrupt Enable
#define UCSRB_REG		*((volatile u8*) 0x2A)

#define UCSRC_UCPOL	0
#define UCSRC_UCSZ0	1
#define UCSRC_UCSZ1	2
#define UCSRC_USBS	3
#define UCSRC_UPM0	4
#define UCSRC_UPM1	5
#define UCSRC_UMSEL	6
#define UCSRC_URSEL	7
#define UCSRC_REG		(*((volatile u8*) 0x40))

// 2 Registers but sharing the same address
#define UDR_REG			(*((volatile u8*) 0x2C))
#define UBRRL_REG		(*((volatile u8*) 0x29))
#define UBRRH_REG		(*((volatile u8*) 0x40))


#endif /* UART_PRIVATE_H_ */
