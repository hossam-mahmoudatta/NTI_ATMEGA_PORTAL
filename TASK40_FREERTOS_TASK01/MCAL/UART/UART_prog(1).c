/*
 * UART_prog.c
 *
 *  Created on: Sep 27, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_MCAL_UART != 0



#include "../../stdTypes.h"
#include "../../errorState.h"

#include "UART_priv.h"
#include "UART_config.h"

static void (*LOC_pfunISRCallBack)(void) = NULL;
static BOOL LOC_bIsCallBackAcessed = FALSE;

static BOOL LOC_bOneTimeAccessReceiveConfig = FALSE;
static BOOL LOC_bWaitFlagUntilFillBuffer = FALSE;
static u8 * LOC_pu8ReceiveBuffer = NULL;
static u8 LOC_u8ReceiveBufferSize = 0;
static u8 LOC_u8ReceiveBufferIndex = 0;
static ES_t LOC_enuCompleteReceiveBuffer = ES_NOK;

ES_t UART_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	#if SPEED_MODE == NORMAL
		UCSRA &=~(1<<1);
	#elif SPEED_MODE == DOUBLE
		UCSRA |= (1<<1);
	#endif

	#if UART_MODE == TRANSCIEVER
		UCSRB |=(3<<3);
		UCSRB |= (1<<RXC);
	#endif
    
    u8 Local_u8UCSRC=0;

	#if DATA_LEN == EIGHT
		Local_u8UCSRC |= (3<<1);
	#endif

	#if PARITY_STATE == NO_PARITY
		Local_u8UCSRC &= ~ (3<<4);
	#endif

	#if STOP_STATE == ONE_STOP_BIT
		Local_u8UCSRC &= ~(1<<3);
	#endif

	#if CLOCK_MODE == ASYCH
		Local_u8UCSRC &=~(1<<6);
	#endif
	Local_u8UCSRC |=(1<<7);
	UCSRC = Local_u8UCSRC;

	u16 Local_u16UBRR = BAUD_CALCULATOR(BAUDRATE);

	Local_u16UBRR &=~(1<<15);

	UBRRL  = (u8)Local_u16UBRR;
	UBRRH  = (u8)(Local_u16UBRR>>8);

	return Local_enuErrorState;
}

ES_t UART_enuReceive_IT(u8 * Copy_pu8Buffer , u8 Copy_u8BufferSize)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (LOC_bWaitFlagUntilFillBuffer == FALSE)
	{
		LOC_u8ReceiveBufferSize = Copy_u8BufferSize;
		LOC_pu8ReceiveBuffer = Copy_pu8Buffer;
		LOC_u8ReceiveBufferIndex =0;
		Local_enuErrorState = ES_WAIT;
		LOC_bWaitFlagUntilFillBuffer = TRUE;
		LOC_bOneTimeAccessReceiveConfig = FALSE;
	}
	else 
	{
		Local_enuErrorState = ES_WAIT;
	}

	if (LOC_u8ReceiveBufferSize == 0)
	{
		Local_enuErrorState = ES_OK;
		LOC_bWaitFlagUntilFillBuffer = FALSE;
		UCSRB &=~(1<<RXC);
	}


	if (LOC_bOneTimeAccessReceiveConfig == FALSE)
	{
		LOC_bOneTimeAccessReceiveConfig = TRUE ;
		LOC_enuCompleteReceiveBuffer = ES_NOK;
		UCSRB |= (1<<RXC);
	}
	return Local_enuErrorState;
}

ES_t UART_enuGetReceiveITState(void)
{
	ES_t Local_enuReceiveState = ES_NOK;
	if (LOC_enuCompleteReceiveBuffer != ES_OK)
	{
		Local_enuReceiveState = LOC_enuCompleteReceiveBuffer;
	}
	else
	{
		Local_enuReceiveState = ES_OK;
		LOC_bWaitFlagUntilFillBuffer = FALSE;
		LOC_enuCompleteReceiveBuffer = ES_NOK;
	}
	return Local_enuReceiveState;
}

ES_t UART_enuSetRxCallBack(void(*Copy_pfunAppFun)(void))
{
	if (Copy_pfunAppFun != NULL)
	{
		UCSRB |= (1<<RXC);
		LOC_bIsCallBackAcessed = TRUE;
		LOC_pfunISRCallBack = Copy_pfunAppFun;
	}
	return ES_OK;
}
u8 UART_u8GetRxBufferFromISR(void)
{
	u8 data = 0xff;
	// if (LOC_bIsCallBackAcessed == TRUE)
	// {
		data = UDR;
	// }
	return data;
}

ES_t UART_enuTransmit(u8 * Copy_pu8Buffer , u8 Copy_u8Size , u8 Copy_u8Timeout)
{
	ES_t Local_enuErrorState = ES_NOK;
    u32 Local_u32Timeout = Copy_u8Timeout * CLOCK_CYCLE_TO_MS;
    u8 Local_u8Index =0;
	while ((Local_u8Index < Copy_u8Size) && (Local_u32Timeout > 3))
	{
		while (!((UCSRA>>UDRE)&1) && (Local_u32Timeout-- > 3));
		UDR = Copy_pu8Buffer[Local_u8Index++];
	}

	return Local_enuErrorState;
}

ES_t UART_enuSendChar(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	while (!((UCSRA>>UDRE)&1));
	UDR = Copy_u8Data;

	/*
	 * UDR = Copy_u8Data;
	 * while( ! ((UCSRA>>TXC) & 1 ) );
	 * UCSRA |= (1<<TXC);
	 */
	return Local_enuErrorState;
}

ES_t UART_enuRecieveChar(u8 *Copy_pu8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	while (!((UCSRA>>RXC)&1));
	*Copy_pu8Data = UDR;

	return Local_enuErrorState;
}

ES_t UART_enuSendString(const char* Copy_pcData)
{
	ES_t Local_enuErrorState = ES_NOK;

	while (*Copy_pcData != '\0')
	{
		while (!((UCSRA>>UDRE)&1));
		UDR = *Copy_pcData;
		Copy_pcData++;
	}

	return Local_enuErrorState;
}


ES_t UART_enuRecieveString(char * Copy_pcData)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Data=0 , Local_u8Index=0;

	while (1)
	{
		while (!((UCSRA>>RXC)&1));
		Local_u8Data = UDR;

		if (Local_u8Data == '\r' || Local_u8Data == '\n' || Local_u8Data == '\0')
		{
			Copy_pcData[Local_u8Index]='\0';
			break;
		}
		Copy_pcData[Local_u8Index]=Local_u8Data;
		Local_u8Index++;
	}


	return Local_enuErrorState;
}

// void __vector_13 (void)__attribute__((signal));
// void __vector_13 (void)
// {
// 	if ((LOC_u8ReceiveBufferSize > 0) && (LOC_bIsCallBackAcessed == FALSE))
// 	{
// 		LOC_enuCompleteReceiveBuffer = ES_WAIT;
// 		LOC_pu8ReceiveBuffer[LOC_u8ReceiveBufferIndex] = UDR;
// 		if ((LOC_pu8ReceiveBuffer[LOC_u8ReceiveBufferIndex] == BACKSPACE_ASCII) && (LOC_u8ReceiveBufferIndex > 0))
// 		{
// 			LOC_u8ReceiveBufferIndex--;
// 			LOC_u8ReceiveBufferSize++;
// 		}
// 		else if ((LOC_pu8ReceiveBuffer[LOC_u8ReceiveBufferIndex] != BACKSPACE_ASCII))
// 		{
// 			LOC_u8ReceiveBufferIndex++;
// 			LOC_u8ReceiveBufferSize--;
// 		}
// 		if (LOC_u8ReceiveBufferSize == 0)
// 		{
// 			LOC_enuCompleteReceiveBuffer = ES_OK;
// 		}
// 	}
// 	else
// 	{
// 		if (LOC_pfunISRCallBack != NULL)
// 		{
// 			LOC_pfunISRCallBack();
// 		}
// 	}
// }

#endif
/*
ES_t UART_enuRecieveStringUntil(char * Copy_pcData, char Copy_cTerminator)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Data=0 , Local_u8Index=0;

	while (1)
	{
		while (!((UCSRA>>RXC)&1));
		Local_u8Data = UDR;

		if (Local_u8Data == Copy_cTerminator)
		{
			Copy_pcData[Local_u8Index]='\0';
			break;
		}
		Copy_pcData[Local_u8Index]=Local_u8Data;
		Local_u8Index++;
	}


	return Local_enuErrorState;
}
*/



/*  \r =13 , \n */
/*
ES_t UART_enuRecieveString(char * Copy_pcData)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Data=0 , Local_u8Index=0;
	u8 Local_u8Termination;

	while (!((UCSRA>>RXC)&1));
		Local_u8Termination = UDR;

	while (1)
	{
		while (!((UCSRA>>RXC)&1));
		Local_u8Data = UDR;

		if (Local_u8Data == Local_u8Termination)
		{
			Copy_pcData[Local_u8Index]='\0';
			break;
		}
		Copy_pcData[Local_u8Index]=Local_u8Data;
		Local_u8Index++;
	}


	return Local_enuErrorState;
}
*/

// ES_t UART_enuTransmit(const u8* Copy_pu8Buffer , u8 Copy_u8BufferSize , u16 Copy_u16TimeOut)
