#ifndef COMM_H_
#define COMM_H_

#include "../../LIB/stdTypes.h"

typedef enum
{
    COMM_TIME,
    COMM_ALARM,
    COMM_ERROR,
    COMM_SUCCESS
} enuOutboxType;

typedef struct _strFrame
{
    u8 id;
    u8 RemainingBytes;
    u8 Spare;
    u8 Data[4];
    u8 CheckSum;
} strFrame;

void Comm_vidInit(void);

void Comm_vidTask(void);

void Comm_vidSendOutbox(u8 *pu8DataBuffer, enuOutboxType enuBoxType);

#endif
