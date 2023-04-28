/*
 * main.c
 *
 *  Created on: Apr 23, 2023
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

int main (void)
{
	//set direction pin0 , pin1 as input for push button
	DDRA &= ~(1<<0) ;
	DDRA &= ~(1<<1) ;
	//activate pull-up for push button
	PORTA |= (1<<0) ;
	PORTA |= (1<<1) ;
	//set direction for sevSeg as output on PORTD
	DDRD = (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) ;
	//normal mode is off for sevSeg
	PORTD = 0x00 ;
	u8 pinStatus1,pinStatus2 ;
	u8 counter=0 ;
	//arrSevenSeg common cathod
	u8 segCthd[]={0x3f,0x06,0x5b,
				  0x4f,0x66,0x6d,
				  0x7d,0x07,0x7f,
				  0x6f} ;


	while(1)
	{
		pinStatus1 = ((PINA>>0)&1) ; //get read push button1
		pinStatus2 = ((PINA>>1)&1) ; //get read push button2
		//counter increase and when reach 9 do nothing
		if (pinStatus1 == 0 && counter < 9)
		{
			counter++ ;
			while (((PINA>>0)&1) == 0) ; //busy wait long press

		}
		//counter decrease and when reach 0 do nothing
		if (pinStatus2 == 0 && counter > 0)
		{
			counter-- ;
			while (((PINA>>1)&1) == 0) ; //busy wait long press

		}
		//display counter on sevSeg
		PORTD = segCthd[counter] ;

	}



}

