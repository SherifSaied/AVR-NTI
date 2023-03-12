/*
 * main.c
 *
 *  Created on: Mar 9, 2023
 *      Author: Sherif Ahmed
 */
#include<stdio.h>
#include <util/delay.h>
typedef unsigned char u8 ;
#define PORTA    	*((u8*)0x3B)
#define DDRA     	*((u8*)0x3A)
#define PINA    	*((volatile u8*)0x39)
int main()
{
	DDRA = 0xff ; //direction of 8 bits as output
	PORTA = 0 ;
	while (1)
	{
	for(int i = 7 ; i>=0 ; i--)
		{
			PORTA |= (1<<i) ;
			_delay_ms(500) ;
		}
	for(int i = 7 ; i>=0 ; i--)
		{
			PORTA &= ~(1<<i) ;
			_delay_ms(500) ;
		}
	}


}

