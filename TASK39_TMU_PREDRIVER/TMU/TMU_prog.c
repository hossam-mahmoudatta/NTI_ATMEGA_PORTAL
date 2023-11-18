/*
 * TMU_prog.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../LIB/stdTypes.h"

#include "TMU_config.h"
#include "TMU_priv.h"

static u16 LOC_u16OVfCounts = 0;
static u16 LOC_u16ISRCounts = 0;
static u8 LOC_u8Preload = 0;

static u32 LOC_u32FreeRunningOsTicks =0;
static TCB_t LOC_astrAllTasks [ TMU_MAX_NUM_TASKS ] ={{0}};

void TMU_vidInit(void)
{
//    *((u8*)0x3A) = 0xff;
    #if TMU_TIMER_CHANNEL == TIMER0
        #if TMU_OS_TICK >=1 && TMU_OS_TICK <=200
            //OVf, 1024 , Dis OC0
            TCCR0 = 0x05;
            u32 u32TimerTickCounter = ((u32)TMU_OS_TICK * TMU_CPU_FREQ) / 1024UL;

            LOC_u16OVfCounts = (u32TimerTickCounter+(255))/(256UL);
            LOC_u16ISRCounts = LOC_u16OVfCounts;
            LOC_u8Preload = (u8)(256 - (u32TimerTickCounter % 256));

            TCNT0 = LOC_u8Preload;

            TIMSK |= (1<<0);

        #else
            #error TMU OS Tick value is Invalid
        #endif
    #elif TMU_TIMER_CHANNEL == TIMER1
    #elif TMU_TIMER_CHANNEL == TIMER2
    #else
        #error TMU Timer channel is Invalid
    #endif

}


void TMU_vidCreateTask(void(*Copy_pfunAppFun)(void), u16 Copy_u16Periodicity , u8 Copy_u8Priority)
{
    if (Copy_u8Priority < TMU_MAX_NUM_TASKS)
    {
        LOC_astrAllTasks[ Copy_u8Priority ].schedTask = Copy_pfunAppFun;
        LOC_astrAllTasks[ Copy_u8Priority ].u16Periodicty = Copy_u16Periodicity;
    }
}


void TMU_vidStartScheduler(void)
{
    u32 u32FreeRunningTemp = 0;
    asm("SEI");
    while(1)
    {
        if (LOC_u32FreeRunningOsTicks != u32FreeRunningTemp)
        {
            u32FreeRunningTemp = LOC_u32FreeRunningOsTicks;
            // for (u8 i = 0 ; i< TMU_MAX_NUM_TASKS ;i++)
            for (s8 s8Priority = (TMU_MAX_NUM_TASKS - 1); s8Priority >= 0 ; s8Priority--)
            {
                if (LOC_astrAllTasks[s8Priority].schedTask != NULL &&
                    (LOC_u32FreeRunningOsTicks % LOC_astrAllTasks[s8Priority].u16Periodicty) == 0)
                {
                    LOC_astrAllTasks[s8Priority].schedTask ();
                }
            }
        }
    }
}


void __vector_11 (void)__attribute__((signal));
void __vector_11 (void)
{
    LOC_u16ISRCounts--;
    if (! LOC_u16ISRCounts)
    {
        TCNT0 = LOC_u8Preload;
         
        LOC_u32FreeRunningOsTicks ++ ;

        LOC_u16ISRCounts = LOC_u16OVfCounts;
    }
}
