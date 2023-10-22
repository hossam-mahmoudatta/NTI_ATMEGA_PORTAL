/******************************************************************************
 *
 * Module: GPIO (General Purpose I/O)
 *
 * File Name: GPIO_CONFIG.h
 * uPDATED ON: MAY 6TH
 * Description: Header file for the AVR GPIO Driver TO INCLUDE THE INITIAL DEFINITIONS
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/


#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

// All internal driver typedefs
// All driver macros
// All driver functions prototypes

/*******************************************************************************
 *                                								Definitions                                  					      *
 *******************************************************************************/

#define PORT_A								0
#define PORT_B								1
#define PORT_C								2
#define PORT_D								3

#define PIN_0									0
#define PIN_1									1
#define PIN_2									2
#define PIN_3									3
#define PIN_4									4
#define PIN_5									5
#define PIN_6									6
#define PIN_7									7

#define NUM_OF_PORTS					4
#define NUM_OF_PINS_PER_PORT		8


/*******************************************************************************
 *                               						Enums Declaration                            						  *
 *******************************************************************************/

typedef enum {
	PIN_INPUT, PIN_OUTPUT
} GPIO_PinDirectionType;

typedef enum {
	PORT_INPUT, PORT_OUTPUT = 0xFF
} GPIO_PortDirectionType;

typedef enum GPIO_Error_t {
	GPIO_OK,
	GPIO_WRONG_PIN_NUMBER,
	GPIO_WRONG_PORT_NUMBER,
	GPIO_WRONG_DIRECTION
} GPIO_Error_t;

#endif /* GPIO_CONFIG_H_ */
