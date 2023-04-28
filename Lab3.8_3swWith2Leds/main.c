/*
 * main.c
 *
 *  Created on: Apr 22, 2023
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
	//set direction pin0 , pin1 as output for led
	DDRA |= (1<<0) ;
	DDRA |= (1<<1) ;
	//set value off in normal mode for leds
	PORTA &= ~(1<<0) ;
	PORTA &= ~(1<<1) ;
	//set direction for button as input pin0,1,2
	DDRB &= ~(1<<0) ;
	DDRB &= ~(1<<1) ;
	DDRB &= ~(1<<2) ;
	//activate pull-up mode for push button
	PORTB |= (1<<0) ;
	PORTB |= (1<<1) ;
	PORTB |= (1<<2) ;
	u8 pinStatus1,pinStatus2,pinStatus3 ;
	while (1)
	{
		/*while (((PINB>>0)&1) ==0) ;
		while (((PINB>>1)&1) ==0) ;
		while (((PINB>>2)&1) ==0) ;*/
		pinStatus1 = ((PINB>>0)&1) ;
		pinStatus2 = ((PINB>>1)&1) ;
		pinStatus3 = ((PINB>>2)&1) ;
		if (pinStatus1==0)
		{
			PORTA |= (1<<0) ; //turn on led1 only
		}
		if (pinStatus2==0)
		{
			PORTA |= (1<<1) ; //turn on led2 only
		}
		if (pinStatus3==0)
		{
			PORTA |= (1<<0) ; //turn on led1
			PORTA |= (1<<1) ; //turn on led2
		}
		if (pinStatus1==0 && pinStatus2==0 )
		{
			PORTA |= (1<<0) ; //turn on led1
			PORTA |= (1<<1) ; //turn on led2
		}
		else
		{
			PORTA &= ~(1<<0) ;
			PORTA &= ~(1<<1) ;
		}
	}



}
