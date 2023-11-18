#include "../../ATmega32_config.h"
#if atmega32ENABLE_HAL_COMMUNICATION != 0

#include "../../stdTypes.h"
#include "../../errorState.h"

#include "../../MCAL/UART/UART_int.h"

#include "../Parsing/Parsing.h"

#include "Communication.h"

#define CHECKSUM_INDEX 7
#define BUFFER_SIZE 8

static strFrame LOC_strReceivedBuffer = {0};

static ES_t LOC_enuCommunicationStatus = ES_NOK;

static u8 LOC_au8Buffer[BUFFER_SIZE] = {0};

static BOOL LOC_bRecievingDone = FALSE;

static void vidResetStateMachine(void);
static void vidFlowControl(u8 *pu8Buffer);
static u8 u8CalcCheckSum(u8 *pu8Data);


void Comm_vidInit(void)
{
    vidResetStateMachine();
    UART_enuInit();
}

void Comm_vidTask(void)
{
    LOC_enuCommunicationStatus = UART_enuGetReceiveITState();
    if (LOC_enuCommunicationStatus == ES_OK)
    {
        vidFlowControl(LOC_au8Buffer);
        if (LOC_bRecievingDone == TRUE)
        {
            Parsing_vidParseInput(&LOC_strReceivedBuffer);
        }
        vidResetStateMachine();
    }
    UART_enuReceive_IT(LOC_au8Buffer, BUFFER_SIZE);
}

void Comm_vidSendOutbox(u8 *pu8DataBuffer, enuOutboxType enuBoxType)
{
    strFrame strFrameData = {0};
    switch (enuBoxType)
    {
    case COMM_ERROR:

        strFrameData.id = 'E';
        strFrameData.RemainingBytes = 5;
        strFrameData.Spare   = *(pu8DataBuffer + 0);
        strFrameData.Data[0] = *(pu8DataBuffer + 1);
        strFrameData.Data[1] = *(pu8DataBuffer + 2);
        strFrameData.Data[2] = *(pu8DataBuffer + 3);
        strFrameData.Data[3] = *(pu8DataBuffer + 4);

        strFrameData.CheckSum = u8CalcCheckSum((u8 *)&strFrameData);

        UART_enuTransmit( (u8 *)&strFrameData , 8 , 2);

        break;
    case COMM_SUCCESS:

        strFrameData.id = 'S';
        strFrameData.RemainingBytes = 5;
        strFrameData.Spare   = *(pu8DataBuffer + 0);
        strFrameData.Data[0] = *(pu8DataBuffer + 1);
        strFrameData.Data[1] = *(pu8DataBuffer + 2);
        strFrameData.Data[2] = *(pu8DataBuffer + 3);
        strFrameData.Data[3] = *(pu8DataBuffer + 4);

        strFrameData.CheckSum = u8CalcCheckSum((u8 *)&strFrameData);

        UART_enuTransmit( (u8 *)&strFrameData , 8 , 2);
        break;

    default:
        break;
    }
}

static u8 u8CalcCheckSum(u8 *pu8Data)
{
    u16 u16CheckSum = 0;
    for (u8 u8Iter = 0; u8Iter < 7; u8Iter++)
    {
        u16CheckSum += (u16)pu8Data[u8Iter];
    }
    u16CheckSum = (~u16CheckSum) + 1;

    return (u8)u16CheckSum;
}

static void vidFlowControl(u8 *pu8Buffer)
{
    if (pu8Buffer[7] == u8CalcCheckSum(pu8Buffer))
    {
        LOC_strReceivedBuffer.id = pu8Buffer[0];
        LOC_strReceivedBuffer.RemainingBytes = pu8Buffer[1];
        LOC_strReceivedBuffer.Spare   = pu8Buffer[2];
        LOC_strReceivedBuffer.Data[0] = pu8Buffer[3];
        LOC_strReceivedBuffer.Data[1] = pu8Buffer[4];
        LOC_strReceivedBuffer.Data[2] = pu8Buffer[5];
        LOC_strReceivedBuffer.Data[3] = pu8Buffer[6];

        LOC_bRecievingDone = TRUE;

        switch (LOC_strReceivedBuffer.id)
        {
        case 'A':
            Comm_vidSendOutbox((u8*)"Sdata", COMM_SUCCESS);
            break;
        }
    }
    else
    {
        switch (LOC_strReceivedBuffer.id)
        {
        case 'A':
            Comm_vidSendOutbox((u8*)"Edata", COMM_ERROR);
            break;
        }
    }
}
static void vidResetStateMachine(void)
{
    LOC_bRecievingDone = FALSE;
    LOC_enuCommunicationStatus = ES_NOK;
}
#endif