/*
 * main.c
 *
 *  Created on: Mar 13, 2023
 *      Author: Sherif Ahmed
 */
#include <stdio.h>
#include <util/delay.h>
#include "stdint.h"

#define PORTA    	*((u8*)0x3B)
#define DDRA     	*((u8*)0x3A)
#define PINA    	*((volatile u8*)0x39)

#define PORTB    	*((u8*)0x38)
#define DDRB     	*((u8*)0x37)
#define PINB   	 	*((volatile u8*)0x36)

#define PORTD    	*((u8*)0x32)
#define DDRD    	*((u8*)0x31)
#define PIND    	*((volatile u8*)0x30)

int main(void)
{
	//sevSeg with common cathode
	u8 segCthd[] = {0x3F, 0x06, 0x5B,
					0x4F, 0x66, 0x6D,
					0x7D, 0x07, 0x7F,
					0x6F};
	u8 pinState,one,deci ;
	u8 counter= 0;
	//output for PORTA
	DDRA = 0xff ;
	//output for pin0 and pin1 portB
	DDRB |= (1<<0) ;
	DDRB |= (1<<1) ;
	//normal mode is 0
	PORTA= 0x3f ;
	//output for PORTB
	//DDRB = 0xff ;
	//normal mode is 0
	//PORTB= 0x3f ;
	//set pin 0 in PORTD as input
	DDRD &= ~(1<<0) ;
	//activate internally pull up
	PORTD |= (1<<0) ;
	while(1)
	{
		pinState= ((PIND>>0) & 1) ; //read this pin 0
		//for two seven seg from 0 to 99

			if (pinState == 0)
			{
				counter++ ;
				while (((PIND>>0) & 1) == 0) ; //read pin for long push

			}
			one = counter%10 ;
			deci= counter/10 ;

			PORTB &= ~(1<<1) ; //enable right 7seg
			PORTB |= (1<<0) ; //Dis left 7seg
			PORTA = segCthd[one] ;

			_delay_ms(1) ;

			PORTB |= (1<<1) ; //disable right 7seg
			PORTB &= ~(1<<0) ; //enable left 7seg
			PORTA = segCthd[deci] ;

			_delay_ms(1) ;

			if (counter > 99)
			{
				counter=0;
			}
	}

}
