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
#define DDRD    	*((u8*)0x31)


int main(void)
{
	//sevSeg with common cathode
	u8 segCthd[] = {0x3F, 0x06, 0x5B,
					0x4F, 0x66, 0x6D,
					0x7D, 0x07, 0x7F,
					0x6F};
	//output for PORTA
	DDRA = 0xff ;
	//normal mode is off
	PORTA= 0 ;
	//output for PORTB
	DDRB = 0xff ;
	//normal mode is off
	PORTB= 0 ;
	while(1)
	{
		//for two seven seg from 0 to 99
		for (int j=0 ; j<=9 ; j++)
		{
			PORTA = segCthd[j] ;
			for (int i=0 ; i<=9 ; i++)
			{
				PORTB = segCthd[i] ;
				_delay_ms(400) ;
			}
		}
	}



}
