/*
 * main.c

 *
 *  Created on: Apr 24, 2023
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

#define PORTC    	*((u8*)0x35)
#define DDRC    	*((u8*)0x34)
#define PINC    	*((volatile u8*)0x33)

#define PORTD    	*((u8*)0x32)
#define DDRD    	*((u8*)0x31)
#define PIND    	*((volatile u8*)0x30)

int main (void)
{
	//set direction pin0 , pin1 as input for push button
	DDRA &= ~(1<<0) ;
	DDRA &= ~(1<<1) ;
	//activate pull-up for push button
	PORTA |= (1<<0) ;
	PORTA |= (1<<1) ;
	//set direction for mpxsevSeg1 as output on PORTC
	DDRC = 0xff ;
	//set direction for mpxsevSeg2 as output on PORTD
	DDRD = 0xff ;
	//normal mode is off for mpxsevSeg1 , mpxsevSeg2
	PORTC = 0x00 ;
	PORTD = 0x00 ;
	//arrSevenSeg common cathod
	u8 segCthd[]={0x3f,0x06,0x5b,
				  0x4f,0x66,0x6d,
				  0x7d,0x07,0x7f,
				  0x6f} ;
	u8 pinStatus1, pinStatus2;
	//when start display display 50
	u8 counter=50 ;
	u8 one,deci;
	while(1)
	{

		pinStatus1 = ((PINA>>0)&1) ;
		pinStatus2 = ((PINA>>1)&1) ;
		if (pinStatus1 == 0)
		{
			counter++ ;
			while (((PINA>>0)&1)==0) ;
		}
		if (pinStatus2 == 0)
		{
			counter-- ;
			while (((PINA>>1)&1)==0) ;
		}
		one=counter%10 ;
		deci=counter/10 ;

		PORTC = segCthd[deci] ;
		PORTD = segCthd[one] ;
		if (counter > 99)
		{
			counter = 0 ;
		}

	}

}
