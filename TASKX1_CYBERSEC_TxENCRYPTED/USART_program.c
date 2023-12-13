#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"
#include <string.h>


void  USART_voidInit(void)
{

	/*Local Variable to hold the required value of UCSRC register */
	u8 Local_u8UCSRCVal = 0;

	/*Choose the UCSRC register*/
	SET_BIT(Local_u8UCSRCVal, UCSRC_URSEL);

	/*Character Size :8 bits*/
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);


	/*Assign the UCSRC required in one operation*/
	UCSRC=Local_u8UCSRCVal;

	/*Set baudrate to 9600bps for 8MHZ system frequency */
	UBRRL=51;

	/*Transmitter Enable*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	/*Receiver Enable*/
	SET_BIT(UCSRB,UCSRB_RXEN);
}

void  USART_voidSendDataSynchronous(u8 Copy_u8Data)
{
	//Wait until the transmit buffer is empty and ready
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);

	//Send the data
	UDR=Copy_u8Data;


}
u8  USART_voidReceiveDataSynchronous(void)
{
	//wait until receive complete event happens
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);

	return UDR;
}

u8 USART_u8SendStringSynchronous(const char * Copy_pchString)
{
	u8 Local_u8ErrorState=OK;
	u32 Local_u32Counter=0;
	if (Copy_pchString != NULL)
	{
		while(Copy_pchString[Local_u32Counter] != '\0')
		{
			USART_voidSendDataSynchronous(Copy_pchString[Local_u32Counter]);
			Local_u32Counter++;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}

u8 USART_u8ReceiveBufferSynchronous(u8 *Copy_pchString,u8 Copy_u8BufferSize)
{
	u8 Local_u8ErrorState=OK;
	u32 Local_u32Counter=0;
	if(Copy_pchString != NULL)
	{
		while(Local_u32Counter<Copy_u8BufferSize)
		{

			 Copy_pchString[Local_u32Counter]=USART_voidReceiveDataSynchronous();
			Local_u32Counter++;
		}
		Copy_pchString[Local_u32Counter] = '\0';
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}

u8  USART_u8CompareString(const char *Copy_pchString1, const char *Copy_pchString2)
{





	if(strcmp(Copy_pchString1,Copy_pchString2)==0){



		return Correct; // the strings compare

	}


	else{



		return Incorrect;

	}


}


/*
u8  USART_voidSendDataSynchronous(u8 Copy_u8Data)
{
	u8 Local_u8ErrorState=OK;
	u32 Local_u32Counter=0;

	//Wait until the transmit buffer is empty and ready
	while((GET_BIT(UCSRA,UCSRA_UDRE)==0) && (Local_u32Counter<USART_u8TIMEOUT))
	{
		Local_u32Counter++;
	}
	if(Local_u32Counter==USART_u8TIMEOUT)
	{
		Local_u8ErrorState=TIMEOUT_STATE;
	}
	else
	{
		//Send the data
		UDR=Copy_u8Data;
	}
	return Local_u8ErrorState;
}*/
/*
u8  USART_voidReceiveDataSynchronous(u8 * Copy_pu8ReceviedData)
{
	u8 Local_u8ErrorState=OK;
	u32 Local_u32Counter=0;
	if(Copy_pu8ReceviedData!=NULL)
	{

	if(Local_u32Counter==USART_u8TIMEOUT)
	{
		Local_u8ErrorState=TIMEOUT_STATE;
	}

	else
	{
		//Send the data
 *Copy_pu8ReceviedData=UDR;
	}
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;




}*/


