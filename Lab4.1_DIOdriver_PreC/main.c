/*
 * main.c
 *
 *  Created on: Apr 25, 2023
 *      Author: Sherif Ahmed
 */
#include "stdint.h"
#include "errorStates.h"
#include "DIO_int.h"  //here include int.h
#include "util/delay.h"

int main (void)
{
	u8 segCthd[]={0x3f,0x06,0x5b,
				  0x4f,0x66,0x6d,
				  0x7d,0x07,0x7f,
				  0x6f};
	u8 i,j;
	DIO_enuInit();
	DIO_enuSetPortValue(DIO_u8PORTD,DIO_u8LOW);
	while (1)
	{
		for (i=0;i<10;i++)
		{
			DIO_enuSetPortValue(DIO_u8PORTC,segCthd[i]);
			DIO_enuSetPortValue(DIO_u8PORTD,segCthd[0]);
			for(j=0;j<10;j++)
			{
				DIO_enuSetPortValue(DIO_u8PORTD,segCthd[j]);
				_delay_ms(300);
			}
		}
	}


}

