/*************************************************************************/
/*************************************************************************/
/******************     Author: mohamed Sayed     ************************/
/******************     Layer: MCAL               ************************/
/******************     SWC: USART                  ************************/
/******************     Version:1.00              ************************/
/******************     Date:5-8-2022            ************************/
/*************************************************************************/
/*************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void  USART_voidInit(void);

//u8  USART_voidSendDataSynchronous(u8 Copy_u8Data);
//u8  USART_voidReceiveDataSynchronous(u8 * Copy_pu8ReceviedData);
void USART_voidSendDataSynchronous(u8 Copy_u8Data);
u8  USART_voidReceiveDataSynchronous(void);
u8  USART_u8CompareString(const char *Copy_pchString1, const char *Copy_pchString2);
u8 USART_u8SendStringSynchronous(const char * Copy_pchString);



u8 USART_u8ReceiveBufferSynchronous(u8 *Copy_pchString,u8 Copy_u8BufferSize);



u8 USART_u8ReceiveBufferAsynchronous(u8  *Copy_pchString, u32 Copy_u32BuffweSize, void(*NotificationFunc)(void));
u8 USART_u8SendStringAsynchronous(const char * Copy_pchString, void(*NotificationFunc)(void));


#endif
