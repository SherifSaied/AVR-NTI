/*
 * main.c
 *
 *  Created on: Mar 10, 2023
 *      Author: Sherif Ahmed
 */
#include<stdio.h>
#include <util/delay.h>

typedef unsigned char u8 ;
#define PORTA    	*((u8*)0x3B)
#define DDRA     	*((u8*)0x3A)
#define PINA    	*((volatile u8*)0x39)

//0 0 0 1 1 0 0 0   4,3
//0 0 1 1 1 1 0 0	5,2
//0 1 1 1 1 1 1 0	6,1
//1 1 1 1 1 1 1 1	7,0
//0 1 1 1 1 1 1 0
//...etc
int main()
{
	DDRA = 0xff ;
	PORTA = 0 ;
	while(1)
	{
		for (int i= 4,j= 3 ; i <=7 ; i++, j--)
		{
			PORTA |= (1<<i) ;
			PORTA |= (1<<j) ;
			_delay_ms(500) ;
		}


		for (int i= 7, j= 0 ; i >4 ; i--, j++)
		{
			PORTA &= ~(1<<i) ;
			PORTA &= ~(1<<j) ;
			_delay_ms(500) ;
		}
	}
	return 0 ;
}
