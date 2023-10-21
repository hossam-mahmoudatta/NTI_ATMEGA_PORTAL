 /******************************************************************************
 *
 * Module File: Common Standard - Platform Types Abstraction
 *
 * File Name: STD_TYPES.h
 *
 * Description: Datatypes for AVR
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Values */
#ifndef FALSE
	#define FALSE      (0u)
#endif

#ifndef TRUE
	#define TRUE        (1u)
#endif

#define LOGIC_HIGH					1 //(1u)
#define LOGIC_LOW					0 //(0u)

#define NULL							((void*)0x00)


/* Boolean Data Type */
typedef unsigned char				boolean;
typedef unsigned char				u8_t;          /*           0 .. 255              */
typedef signed char           		s8_t;          /*        -128 .. +127             */
typedef unsigned short			u16_t;         /*           0 .. 65535            */
typedef signed short          		s16_t;         /*      -32768 .. +32767           */
typedef unsigned long         		u32_t;         /*           0 .. 4294967295       */
typedef signed long           		s32_t;         /* -2147483648 .. +2147483647      */
typedef unsigned long long		u64_t;         /*       0 .. 18446744073709551615  */
typedef signed long long			s64_t;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float							float32_t;
typedef double							float64_t;

#endif /* STD_TYPE_H_ */
