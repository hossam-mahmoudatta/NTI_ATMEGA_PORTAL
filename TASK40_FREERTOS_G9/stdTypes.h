/*
 * stdTypes.h
 *
 *  Created on	: Mar 31, 2020
 *  Version		: 1.0.0
 *  Author		: Ahmed El-Gaafarwy
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

/*typedef <dataType> <newName>*/
typedef enum{
    FALSE,
    TRUE
}BOOL;


typedef unsigned char         u8   ;
typedef unsigned short int    u16  ;
typedef unsigned long int     u32  ;
typedef unsigned long long    u64  ;

typedef signed char           s8   ;
typedef signed short int      s16  ;
typedef signed long int       s32  ;
typedef signed long long      s64  ;

typedef float                 f32  ;
typedef double                f64  ;
typedef long double           f80  ;

#define NULL			((void*)0)

#endif /* STDTYPES_H_ */
