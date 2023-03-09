/*
 * main.c
 *
 *  Created on: Mar 7, 2023
 *      Author: Sherif Ahmed
 */
#include<stdio.h>
#include <util/delay.h>
typedef unsigned char u8 ;

#define PORTA    	*((u8*)0x3B)
#define DDRA     	*((u8*)0x3A)
#define PINA    	*((volatile u8*)0x39)

int main (void)
{
	//pin0 in DDRA is output
	*((u8*)0x3A) |= (1<<0) ;
	while (1)
	{
		PORTA |= (1<<0) ;  //pin0 in PORTA is high
		_delay_ms(1000) ;
		PORTA &= ~(1<<0) ;
		_delay_ms(1000) ;
	}
	return 0;
}
