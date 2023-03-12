/*
 * main.c
 *
 *  Created on: Mar 11, 2023
 *      Author: Sherif Ahmed
 */
#include<stdio.h>
#include <util/delay.h>
#include "stdint.h"

#define PORTA    	*((u8*)0x3B)
#define DDRA     	*((u8*)0x3A)
#define PINA    	*((volatile u8*)0x39)

int main()
{
	//sw pin3 as input
	DDRA &= ~(1<<3) ;
	//activate sw internal pull-up resistor
	PORTA |= (1<<3) ;
	//set leds pin 5,7 as output
	DDRA |=(1<<5) ;
	DDRA |=(1<<7) ;
	//normal mode leds are off
	PORTA &=~ (1<<7) ;
	PORTA &=~ (1<<5) ;
	while (1)
	{
		if(((PINA>>3) & 1 )==0) //sw is closed
		{
			PORTA |= (1<<5)  ;
			PORTA &=~ (1<<7) ;
		}
		else if (((PINA>>3) & 1 )==1) //sw is open
		{
			PORTA |= (1<<7)  ;
			PORTA &=~ (1<<5) ;
		}
	}


}
