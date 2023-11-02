 /******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: COMMON_MACROS.h
 *
 * Description: Commonly used Macros
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef COMMON_MACROS
#define COMMON_MACROS

/* Set a certain bit in any register */
#define SET_BIT(VAR, BIT) (VAR |= (1 << BIT))

/* Clear a certain bit in any register */
#define CLR_BIT(VAR, BIT) (VAR &= (~(1 << BIT)))

/* Toggle a certain bit in any register */
#define TOG_BIT(VAR, BIT) (VAR ^= (1 << BIT))

/* Get a certain bit in any register */
#define GET_BIT(VAR, BIT) (((VAR) >> (BIT)) & 0x01)
// #define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT ) // Another Algorithm

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(VAR, BIT) (VAR & (1 << BIT))

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLR(VAR, BIT) ( !(VAR & (1 << BIT)))

/* Rotate right the register value with specific number of rotates */
#define ROR(VAR, NUM) (VAR = (VAR >> NUM) | (VAR << (8 - NUM)))

/* Rotate left the register value with specific number of rotates */
#define ROL(VAR, NUM) (VAR = (VAR << NUM) | (VAR >> (8 - NUM)))


#endif
