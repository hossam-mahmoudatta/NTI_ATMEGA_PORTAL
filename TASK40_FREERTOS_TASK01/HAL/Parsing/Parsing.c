#include "../../ATmega32_config.h"
#if atmega32ENABLE_HAL_PARSING != 0



#include "Parsing.h"

#include "../../errorState.h"

#include "../../MCAL/UART/UART_int.h"


#define NUM_OF_BYTES_IN_FRAME 5

static enuCheckSumState LOC_aenuCheckSumState[5] = {0};

static BOOL bCompareString(const char *str1, const char *str2);

void Parsing_vidParseInput(strFrame *pstrFrameData)
{
    BOOL bCompareFlag = FALSE;
    u8 u8OpCode = pstrFrameData->id;
    switch (u8OpCode)
    {
    case 'E':
        bCompareFlag = bCompareString("time", (char *)pstrFrameData->Data);
        if (bCompareFlag == TRUE)
        {
            LOC_aenuCheckSumState[COMM_TIME] = CHECKSUM_ERROR;
        }
        bCompareFlag = bCompareString("alrm", (char *)pstrFrameData->Data);
        if (bCompareFlag == TRUE)
        {
            LOC_aenuCheckSumState[COMM_ALARM] = CHECKSUM_ERROR;
        }
        break;
        
    case 'S':
        bCompareFlag = bCompareString("time", (char *)pstrFrameData->Data);
        if (bCompareFlag == TRUE)
        {
            LOC_aenuCheckSumState[COMM_TIME] = CHECKSUM_SUCCESS;
        }
        bCompareFlag = bCompareString("alrm", (char *)pstrFrameData->Data);
        if (bCompareFlag == TRUE)
        {
            LOC_aenuCheckSumState[COMM_ALARM] = CHECKSUM_SUCCESS;
        }
        break;
    case 'A':
        if (TRUE == bCompareString("aaa0", (char *)pstrFrameData->Data))
            UART_enuTransmit("\r\nTesting Done",14, 2);
        break;
        
    default:
        break;
    }
}

void Parsing_vidResetCheckSumState(enuOutboxType enuBoxType)
{
    LOC_aenuCheckSumState[enuBoxType] = CHECKSUM_IDLE;
}
enuCheckSumState Parsing_enuGetCheckSumState(enuOutboxType enuBoxType)
{
    return LOC_aenuCheckSumState[enuBoxType];
}

static BOOL bCompareString(const char * Copy_pcStr1, const char * Copy_pcStr2)
{
    BOOL bFlag = FALSE;
    u8 u8Index = 0;
    for (u8Index =0; *(Copy_pcStr2+u8Index) != 0 ; u8Index++)
	{
		if (*(Copy_pcStr1+u8Index) != Copy_pcStr2[u8Index])
		{
            bFlag = FALSE;
			break;
		}
        else
        {
            bFlag = TRUE;
        }
	}
	return bFlag;
}
#endif