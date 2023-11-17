/*
 * HexaDecoder_int.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HEXADECODER_INT_H_
#define HEXADECODER_INT_H_


#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "HexaDecoder_config.h"
#include "HexaDecoder_priv.h"


ES_t HexaDec_enuInit(void);

ES_t HexaDec_enuDisplayNum(u8 Copy_u8Num);

ES_t HexaDec_enuEnableSSG(u8 Copy_u8SSGNum);

ES_t HexaDec_enuDisableSSG(u8 Copy_u8SSGNum);

ES_t HexaDec_enuStopDisplay(void);


#define SSG_RIGHT           98
#define SSG_LEFT            45

#endif /* HEXADECODER_INT_H_ */
