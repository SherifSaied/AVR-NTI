/*
 * main.c
 *
 *  Created on: Mar 11, 2023
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
	//set dipSw as input
	DDRA = 0 ;
	//activate dipSw pull up internally
	PORTA = 255 ;  //0xff , 0b11111111
	//set led as output
	DDRB |= (1<<1) ;
	//normal mode for led is off
	PORTB &= ~(1<<1) ;


	while (1)
	{
		u8 swState = ~(PINA) ; // to be more logic with user as on and off
		DDRD = swState ; // for debugging
			if (swState == 73)
		{
			_delay_ms(500) ;
			if (swState == 73) // delay and recheck for solve bouncing
			{
				PORTB |=(1<<1) ;
			}
		}
		else
		{
			PORTB &= ~(1<<1) ;
		}

	}



}
