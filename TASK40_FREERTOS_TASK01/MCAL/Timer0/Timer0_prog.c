/*
* Timer0_prog.c
*
*  Created on: May 20, 2023
*      Author: Ahmed El-Gaafrawy
*/
#include "../../ATmega32_config.h"
#if atmega32ENABLE_MCAL_TIMER0 != 0


#include "../../stdTypes.h"


#include "Timer0_config.h"
#include "Timer0_priv.h"

static void (*Timer0_pfunOvfISRFun)(void)= NULL;
static void (*Timer_pfunCallBack)(void)= NULL;
static u16 Timer0_u16OvfCounts;
static u8 Timer0_u8Preload;
static u16 Timer0_u16ISRCounter;
static u8 Timer0_u8CTCValue;

void Timer0_vidInit(void)
{
   #if TIMER0_PRESCALER == 0
       TCCR0 &=~(7<<0);
       #warning timer0 has been stopped by 0 prescaler
	#elif TIMER0_PRESCALER == 8
		TCCR0 &=~(7<<0);
		TCCR0 |= (2<<0);
   #elif TIMER0_PRESCALER == 1024
       TCCR0 &=~(7<<0);
       TCCR0 |= (5<<0);
   #endif

   #if TIMER0_MODE ==  TIMER0_OVF
       TCCR0 &= ~(9<<3);
   #elif TIMER0_MODE == TIMER0_CTC
       TCCR0 &=~(1<<6);
       TCCR0 |= (1<<3);
   #endif

   #if TIMER0_INTERRUPT_MODE == TIMER0_INTERRUPT
       #if TIMER0_MODE == TIMER0_OVF
           TIMSK |=(1<<0);
       #elif TIMER0_MODE == TIMER0_CTC
           TIMSK |=(1<<1);
       #endif
   #elif TIMER0_INTERRUPT_MODE == TIMER0_POLLING
       #if TIMER0_MODE == TIMER0_OVF
           TIMSK &=~(1<<0);
       #elif TIMER0_MODE == TIMER0_CTC
           TIMSK &=~(1<<1);
       #endif
   #endif

}

void Timer0_vidSetAschDelay(u32 Copy_u32MilliSecond , void (*Copy_pfunAppFun)(void))
{
#if TIMER0_INTERRUPT_MODE == TIMER0_INTERRUPT
   #if TIMER0_MODE == TIMER0_OVF
       if (Copy_pfunAppFun != NULL)
       {
           u32 Local_u32Counts = (16000llu * Copy_u32MilliSecond) / TIMER0_PRESCALER;
           Timer0_u16OvfCounts = (Local_u32Counts + 255) / 256;
           Timer0_u8Preload    = 256 - (Local_u32Counts % 256);
           TCNT0 = Timer0_u8Preload;
           Timer0_pfunOvfISRFun = Copy_pfunAppFun;
       }
   #elif TIMER0_MODE == TIMER0_CTC
       if (Copy_pfunAppFun != NULL)
       {
           u32 Local_u32Counts = (16000llu * Copy_u32MilliSecond) / TIMER0_PRESCALER;
           Timer0_u16OvfCounts = (Local_u32Counts + Timer0_u8CTCValue-1) / Timer0_u8CTCValue;
           Timer0_u8Preload    = Timer0_u8CTCValue - (Local_u32Counts % Timer0_u8CTCValue);
           TCNT0 = Timer0_u8Preload;
           Timer0_pfunOvfISRFun = Copy_pfunAppFun;
       }
   #endif
#endif
}

void Timer0_vidSetSychDelay(u32 Copy_u32MilliSecond)
{
#if TIMER0_INTERRUPT_MODE == TIMER0_POLLING

   u32 Local_u32Counts = (16000llu * Copy_u32MilliSecond) / TIMER0_PRESCALER;

   #if TIMER0_MODE == TIMER0_CTC
       u16 Local_u16CTCCounts = (Local_u32Counts + (Timer0_u8CTCValue - 1)) / Timer0_u8CTCValue;
       TCNT0 = Timer0_u8CTCValue - (Local_u32Counts % Timer0_u8CTCValue);

       while (Local_u16CTCCounts-- >0)
       {
           while(((TIFR >> 1) & 1) == 0 );
           TIFR |= (1<<1);
       }
   #elif TIMER0_MODE == TIMER0_OVF
       u16 Local_u16OvfCounts = (Local_u32Counts + (255)) / 256;
       TCNT0 = 256 - (Local_u32Counts % 256);

       while (Local_u16OvfCounts-- >0)
       {
           while(((TIFR >> 0) & 1) == 0 );
           TIFR |= (1<<0);
       }
   #endif
#endif
}

void Timer0_vidSetCompareCount(u8 Copy_u8CTCValue)
{
   Timer0_u8CTCValue = Copy_u8CTCValue;
   OCR0 = Copy_u8CTCValue;
}
void Timer_vidCallBack(void (*Copy_pfunCallBack)(void))
{
   if (Copy_pfunCallBack != NULL)
   {
       Timer_pfunCallBack = Copy_pfunCallBack;
   }
}
void Timer_vidSetTimerCounts(u8 Copy_u8Counts)
{
   TCNT0 = Copy_u8Counts;
}
u8 Timer_u8GetTimerCounts(void)
{
   return TCNT0;
}

void Timer_vidEnableInterrupt(void)
{
	TIMSK |=(1<<0);
}
void Timer_vidDisableInterrupt(void)
{
	TIMSK &=~(1<<0);
}

#if TIMER0_MODE == TIMER0_OVF
void __vector_11 (void)__attribute__((signal));
void __vector_11 (void)
{
   if (Timer_pfunCallBack != NULL)
   {
       Timer_pfunCallBack();
   }
   else
   {
        Timer0_u16ISRCounter ++;
        if (Timer0_u16ISRCounter == Timer0_u16OvfCounts)
        {
            TCNT0 = Timer0_u8Preload;

            Timer0_u16ISRCounter =0;
            if (Timer0_pfunOvfISRFun != NULL)
                Timer0_pfunOvfISRFun ();
        }
   }
}
#elif TIMER0_MODE == TIMER0_CTC
void __vector_10 (void)__attribute__((signal));
void __vector_10 (void)
{
   Timer0_u16ISRCounter ++;
   if (Timer0_u16ISRCounter == Timer0_u16OvfCounts)
   {
       TCNT0 = Timer0_u8Preload;

       Timer0_u16ISRCounter =0;

       Timer0_pfunOvfISRFun ();
   }
}
#endif

#endif
