/*
 * DIO_int.h
 *
 *  Created on: Apr 25, 2023
 *      Author: Sherif Ahmed
 */


#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "stdint.h"
#include "errorStates.h"

/*define PORTS and PINS, for user in main function*/
#define DIO_u8PORTA      0
#define DIO_u8PORTB      1
#define DIO_u8PORTC      2
#define DIO_u8PORTD      3

#define DIO_u8PIN0       0
#define DIO_u8PIN1       1
#define DIO_u8PIN2       2
#define DIO_u8PIN3       3
#define DIO_u8PIN4       4
#define DIO_u8PIN5       5
#define DIO_u8PIN6       6
#define DIO_u8PIN7       7
/*define HIGH, LOW, INPUT,OUTPUT,PULLUP,FLOAT for user in main function*/
#define DIO_u8HIGH         1
#define DIO_u8LOW          0

#define DIO_u8INPUT        0
#define DIO_u8OUTPUT       1

#define DIO_u8FLOAT        0
#define DIO_u8PULLUP       1

/*step1.Highu8 level design ...declare your APIs*/
ES_t DIO_enuInit(void);

ES_t DIO_enuSetPortDirection(u8 copy_u8PortID, u8 copy_u8Value);

ES_t DIO_enuSetPortValue(u8 copy_u8PortID, u8 copy_u8Value);

ES_t DIO_enuTogPortValue(u8 copy_u8PortID);

ES_t DIO_enuGetPortValue(u8 copy_u8PortID, u8 * copy_pu8Value);

//the same for pins

ES_t DIO_enuSetPinDirection(u8 copy_u8PortID,u8 copy_u8PinID, u8 copy_u8Value);

ES_t DIO_enuSetPinValue(u8 copy_u8PortID,u8 copy_u8PinID, u8 copy_u8Value);

ES_t DIO_enuTogPinValue(u8 copy_u8PortID,u8 copy_u8PinID);

ES_t DIO_enuGetPinValue(u8 copy_u8PortID,u8 copy_u8PinID, u8 * copy_pu8Value);

#endif /* DIO_INT_H_ */
