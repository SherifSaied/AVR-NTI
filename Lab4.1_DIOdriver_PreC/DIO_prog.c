/*
 * DIO_prog.c
 *
 *  Created on: Apr 25, 2023
 *      Author: Sherif Ahmed
 */
//step2.here low level design
#include "stdint.h"
#include "errorStates.h"

#include "DIO_priv.h"
#include "DIO_config.h"

ES_t DIO_enuInit(void)
{
	ES_t local_enuErrorstate = ES_NOK ;
	//for init as start
	DDRA = CONC(PA_PIN7_DIR,PA_PIN6_DIR,PA_PIN5_DIR,PA_PIN4_DIR,
				PA_PIN3_DIR,PA_PIN2_DIR,PA_PIN1_DIR,PA_PIN0_DIR) ;

	DDRB = CONC(PB_PIN7_DIR,PB_PIN6_DIR,PB_PIN5_DIR,PB_PIN4_DIR,
				PB_PIN3_DIR,PB_PIN2_DIR,PB_PIN1_DIR,PB_PIN0_DIR) ;

	DDRC = CONC(PC_PIN7_DIR,PC_PIN6_DIR,PC_PIN5_DIR,PC_PIN4_DIR,
				PC_PIN3_DIR,PC_PIN2_DIR,PC_PIN1_DIR,PC_PIN0_DIR) ;

	DDRD = CONC(PD_PIN7_DIR,PD_PIN6_DIR,PD_PIN5_DIR,PD_PIN4_DIR,
				PD_PIN3_DIR,PD_PIN2_DIR,PD_PIN1_DIR,PD_PIN0_DIR) ;

	PORTA = CONC(PA_PIN7_VAL,PA_PIN6_VAL,PA_PIN5_VAL,PA_PIN4_VAL,
				 PA_PIN3_VAL,PA_PIN2_VAL,PA_PIN1_VAL,PA_PIN0_VAL) ;

	PORTB = CONC(PB_PIN7_VAL,PB_PIN6_VAL,PB_PIN5_VAL,PB_PIN4_VAL,
				 PB_PIN3_VAL,PB_PIN2_VAL,PB_PIN1_VAL,PB_PIN0_VAL) ;

	PORTC = CONC(PC_PIN7_VAL,PC_PIN6_VAL,PC_PIN5_VAL,PC_PIN4_VAL,
				 PC_PIN3_VAL,PC_PIN2_VAL,PC_PIN1_VAL,PC_PIN0_VAL) ;

	PORTD = CONC(PD_PIN7_VAL,PD_PIN6_VAL,PD_PIN5_VAL,PD_PIN4_VAL,
				 PD_PIN3_VAL,PD_PIN2_VAL,PD_PIN1_VAL,PD_PIN0_VAL) ;

	local_enuErrorstate = ES_OK;
	return local_enuErrorstate;
}

ES_t DIO_enuSetPortDirection(u8 copy_u8PortID, u8 copy_u8Value)
{
	ES_t local_enuErrorstate = ES_NOK ;
	//check for range of ID
	if (copy_u8PortID <= DIO_PORTD)
	{
		switch (copy_u8PortID)
		{
		case DIO_PORTA:
			DDRA = copy_u8Value;
			break;
		case DIO_PORTB:
			DDRB = copy_u8Value;
			break;
		case DIO_PORTC:
			DDRC = copy_u8Value;
			break;
		case DIO_PORTD:
			DDRD = copy_u8Value;
			break;
		}
		local_enuErrorstate = ES_OK;
	}
	else
	{
		local_enuErrorstate = ES_OUT_OF_RANGE;
	}

	return local_enuErrorstate;
}

ES_t DIO_enuSetPortValue(u8 copy_u8PortID, u8 copy_u8Value)
{
	ES_t local_enuErrorstate = ES_NOK ;

	//check for range of ID
	if (copy_u8PortID <= DIO_PORTD)
	{
		switch (copy_u8PortID)
		{
		case DIO_PORTA:
			PORTA = copy_u8Value;
			break;
		case DIO_PORTB:
			PORTB = copy_u8Value;
			break;
		case DIO_PORTC:
			PORTC = copy_u8Value;
			break;
		case DIO_PORTD:
			PORTD = copy_u8Value;
			break;
		}
		local_enuErrorstate = ES_OK;
	}
	else
	{
		local_enuErrorstate = ES_OUT_OF_RANGE;
	}

	return local_enuErrorstate;
}

ES_t DIO_enuTogPortValue(u8 copy_u8PortID)
{
	ES_t local_enuErrorstate = ES_NOK ;

	//check for range of ID FIRST
	if (copy_u8PortID <= DIO_PORTD)
	{
		switch (copy_u8PortID)
		{
		case DIO_PORTA:
			PORTA = ~PORTA;
			break;
		case DIO_PORTB:
			PORTB = ~PORTB;
			break;
		case DIO_PORTC:
			PORTC = ~PORTC;
			break;
		case DIO_PORTD:
			PORTD = ~PORTD;
			break;
		}
		local_enuErrorstate = ES_OK;
	}
	else
	{
		local_enuErrorstate = ES_OUT_OF_RANGE;
	}

	return local_enuErrorstate;
}

ES_t DIO_enuGetPortValue(u8 copy_u8PortID, u8 * copy_pu8Value)
{
	ES_t local_enuErrorstate = ES_NOK ;
	//check pointer it's not NULL first
	if (copy_pu8Value != NULL)
	{
		if (copy_u8PortID <= DIO_PORTD)
		{
			switch (copy_u8PortID)
			{
			case DIO_PORTA:
				*copy_pu8Value = PINA;
				break;
			case DIO_PORTB:
				*copy_pu8Value = PINB;
				break;
			case DIO_PORTC:
				*copy_pu8Value = PINC;
				break;
			case DIO_PORTD:
				*copy_pu8Value = PIND;
				break;
			}

			local_enuErrorstate = ES_OK;
		}
		else
		{
			local_enuErrorstate = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		local_enuErrorstate = ES_NULL_POINTER;
	}


	return local_enuErrorstate;
}


ES_t DIO_enuSetPinDirection(u8 copy_u8PortID,u8 copy_u8PinID, u8 copy_u8Value)
{
	ES_t local_enuErrorstate = ES_NOK ;

	if (copy_u8PortID <= DIO_PORTD &&
		copy_u8PinID <= DIO_PIN7 &&
		copy_u8Value <= OUTPUT)
	{
		switch (copy_u8PortID)
		{
		case DIO_PORTA:
			DDRA &= ~(DIO_MASK_BIT<<copy_u8PinID);  //masking for specfic pin first
			DDRA |= (copy_u8Value<<copy_u8PinID); //then set pin
			break;
		case DIO_PORTB:
			DDRB &= ~(DIO_MASK_BIT<<copy_u8PinID);
			DDRB |= (copy_u8Value<<copy_u8PinID);
			break;
		case DIO_PORTC:
			DDRC &= ~(DIO_MASK_BIT<<copy_u8PinID);
			DDRC |= (copy_u8Value<<copy_u8PinID);
			break;
		case DIO_PORTD:
			DDRD &= ~(DIO_MASK_BIT<<copy_u8PinID);
			DDRD |= (copy_u8Value<<copy_u8PinID);
			break;
		}

		local_enuErrorstate = ES_OK ;
	}
	else
	{
		local_enuErrorstate = ES_OUT_OF_RANGE ;
	}

	return local_enuErrorstate;
}

ES_t DIO_enuSetPinValue(u8 copy_u8PortID,u8 copy_u8PinID, u8 copy_u8Value)
{
	ES_t local_enuErrorstate = ES_NOK ;

	if (copy_u8PortID <= DIO_PORTD &&
		copy_u8PinID <= DIO_PIN7 &&
		copy_u8Value <= OUTPUT)
	{
		switch (copy_u8PortID)
		{
		case DIO_PORTA:
			PORTA &= ~(DIO_MASK_BIT<<copy_u8PinID);  //masking for specfic pin first
			PORTA |= (copy_u8Value<<copy_u8PinID); //then set pin
			break;
		case DIO_PORTB:
			PORTB &= ~(DIO_MASK_BIT<<copy_u8PinID);
			PORTB |= (copy_u8Value<<copy_u8PinID);
			break;
		case DIO_PORTC:
			PORTC &= ~(DIO_MASK_BIT<<copy_u8PinID);
			PORTC |= (copy_u8Value<<copy_u8PinID);
			break;
		case DIO_PORTD:
			PORTD &= ~(DIO_MASK_BIT<<copy_u8PinID);
			PORTD |= (copy_u8Value<<copy_u8PinID);
			break;
		}

		local_enuErrorstate = ES_OK ;
	}
	else
	{
		local_enuErrorstate = ES_OUT_OF_RANGE ;
	}

	return local_enuErrorstate;
}

ES_t DIO_enuTogPinValue(u8 copy_u8PortID,u8 copy_u8PinID)
{
	ES_t local_enuErrorstate = ES_NOK ;

	if (copy_u8PortID <= DIO_PORTD &&
		copy_u8PinID <= DIO_PIN7)
	{
		switch (copy_u8PortID)
		{
		case DIO_PORTA:
			PORTA ^= (DIO_MASK_BIT<<copy_u8PinID);
			break;
		case DIO_PORTB:
			PORTB ^= (DIO_MASK_BIT<<copy_u8PinID);
			break;
		case DIO_PORTC:
			PORTC ^= (DIO_MASK_BIT<<copy_u8PinID);
			break;
		case DIO_PORTD:
			PORTD ^= (DIO_MASK_BIT<<copy_u8PinID);
			break;
		}

		local_enuErrorstate = ES_OK ;
	}
	else
	{
		local_enuErrorstate = ES_OUT_OF_RANGE ;
	}

	return local_enuErrorstate;
}

ES_t DIO_enuGetPinValue(u8 copy_u8PortID,u8 copy_u8PinID, u8 * copy_pu8Value)
{
	ES_t local_enuErrorstate = ES_NOK ;
	//check pointer it's not NULL first
	if (copy_pu8Value != NULL)
	{
		if (copy_u8PortID <= DIO_PORTD && copy_u8PinID <= DIO_PIN7)
		{
			switch (copy_u8PortID)
			{
			case DIO_PORTA:
				*copy_pu8Value = ((PINA>>copy_u8PinID)&DIO_MASK_BIT);
				break;
			case DIO_PORTB:
				*copy_pu8Value = ((PINB>>copy_u8PinID)&DIO_MASK_BIT);
				break;
			case DIO_PORTC:
				*copy_pu8Value = ((PINC>>copy_u8PinID)&DIO_MASK_BIT);
				break;
			case DIO_PORTD:
				*copy_pu8Value = ((PIND>>copy_u8PinID)&DIO_MASK_BIT);
				break;
			}

			local_enuErrorstate = ES_OK;
		}
		else
		{
			local_enuErrorstate = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		local_enuErrorstate = ES_NULL_POINTER;
	}


	return local_enuErrorstate;
}

