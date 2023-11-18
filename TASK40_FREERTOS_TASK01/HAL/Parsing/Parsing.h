#ifndef PARSING_H_
#define PARSING_H_

#include "../Communication/Communication.h"

typedef enum
{
    CHECKSUM_IDLE,
    CHECKSUM_ERROR,
    CHECKSUM_SUCCESS,
} enuCheckSumState;


void Parsing_vidParseInput(strFrame *pstrFrameData);

void Parsing_vidResetCheckSumState(enuOutboxType enuBoxType);
enuCheckSumState Parsing_enuGetCheckSumState(enuOutboxType enuBoxType);


#endif
