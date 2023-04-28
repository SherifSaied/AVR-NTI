/*
 * DIO_priv.h
 *
 *  Created on: Apr 25, 2023
 *      Author: Sherif Ahmed
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/*masking for 1<< for bits to avoid magic num*/
#define DIO_MASK_BIT   1

/*define PORTS and pins for you only to avoid magic num*/
#define DIO_PORTA      0
#define DIO_PORTB      1
#define DIO_PORTC      2
#define DIO_PORTD      3

#define DIO_PIN0      0
#define DIO_PIN1      1
#define DIO_PIN2      2
#define DIO_PIN3      3
#define DIO_PIN4      4
#define DIO_PIN5      5
#define DIO_PIN6      6
#define DIO_PIN7      7

/*define here INPUT and OUTPUT for you to avoid magic num */
#define INPUT        0
#define OUTPUT       1

/*define value as LOW,HIGH,FLOAT,PULL_UP to avoid magic num*/
#define LOW           0
#define HIGH 		  1
#define FLOAT         0
#define PULLUP        1

/*step3.here we need addresses of registers DIO*/
#define PORTA    	*((u8*)0x3B)
#define DDRA     	*((u8*)0x3A)
#define PINA    	*((volatile u8*)0x39)

#define PORTB    	*((u8*)0x38)
#define DDRB     	*((u8*)0x37)
#define PINB   	 	*((volatile u8*)0x36)

#define PORTC    	*((u8*)0x35)
#define DDRC    	*((u8*)0x34)
#define PINC    	*((volatile u8*)0x33)

#define PORTD    	*((u8*)0x32)
#define DDRD    	*((u8*)0x31)
#define PIND    	*((volatile u8*)0x30)





/*step4.concatinations here*/

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)     0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)		   CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

#endif /* DIO_PRIV_H_ */
