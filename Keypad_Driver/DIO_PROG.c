/*
 * DIO_PROG.c
 *
 *  Created on: Feb 15, 2020
 *      Author: Anwar
 */
#include "STD_TYPES.h"
#include "DIO_INT.h"
#include "DIO_PRIV.h"
#include "BIT_MATH.h"

void DIO_vidSetPinDir(u8 u8PortId,u8 u8PinId,u8 u8Dir)
{

	if((u8PortId<=PORTD) && (u8PinId<=PIN7))
	{
		//law 3ayzen n set l pit direction
	if(u8Dir== INPUT)
		{
		switch (u8PortId)
			{
				case PORTA:CLR_BIT(DDRA_reg,u8PinId);
				break;
				case PORTB:CLR_BIT(DDRB_reg,u8PinId);
				break;
				case PORTC:CLR_BIT(DDRC_reg,u8PinId);
				break;
				case PORTD:CLR_BIT(DDRD_reg,u8PinId);
				break;
			}
		}
	else if(u8Dir==OUTPUT)
			{
		switch (u8PortId)
					{
				case PORTA:SET_BIT(DDRA_reg,u8PinId);
				break;
				case PORTB:SET_BIT(DDRB_reg,u8PinId);
				break;
				case PORTC:SET_BIT(DDRC_reg,u8PinId);
				break;
				case PORTD:SET_BIT(DDRD_reg,u8PinId);
				break;
					}
			}
	else
			{
				//wrong input Direction
			}
		}
	}

void DIO_vidSetPinVal(u8 u8PortId, u8 u8PinId,u8 u8Val)
{
	if((u8PortId<=PORTD) && (u8PinId<=PIN7))
		{
			//law 3ayzen n set l pit direction
		if(u8Val== HIGH)
			{
			switch (u8PortId)
				{
					case PORTA:SET_BIT(PORTA_reg,u8PinId);
					break;
					case PORTB:SET_BIT(PORTB_reg,u8PinId);
					break;
					case PORTC:SET_BIT(PORTC_reg,u8PinId);
					break;
					case PORTD:SET_BIT(PORTD_reg,u8PinId);
					break;
				}
			}
		else if(u8Val==LOW)
				{
			switch (u8PortId)
					{
						case PORTA:CLR_BIT(PORTA_reg,u8PinId);
						break;
						case PORTB:CLR_BIT(PORTB_reg,u8PinId);
						break;
						case PORTC:CLR_BIT(PORTC_reg,u8PinId);
						break;
						case PORTD:CLR_BIT(PORTD_reg,u8PinId);
						break;

					}
				}
		else
				{
					//wrong input Direction
				}
			}
}

u8 DIO_u8GetPinVal(u8 u8PortId,u8 u8PinId)
{
	u8 u8PinVal=IN_UNDEF;
	if((u8PortId<=PORTD) && (u8PinId<=PIN7))
		{

			switch (u8PortId)
				{
					case PORTA:
						u8PinVal=GET_BIT(PINA_reg,u8PinId);
					break;
					case PORTB:
						u8PinVal=GET_BIT(PINB_reg,u8PinId);

					break;
					case PORTC:
						u8PinVal=GET_BIT(PINC_reg,u8PinId);

					break;
					case PORTD:
						u8PinVal=GET_BIT(PIND_reg,u8PinId);
					break;
				}
			}

		else
				{
					//wrong input
				u8PinVal=IN_UNDEF;
				}
	return u8PinVal;
}

void DIO_vidTogglePin(u8 u8PortId,u8 u8PinId)
{
	if((u8PortId<=PORTD) && (u8PinId<=PIN7))
			{

				switch (u8PortId)//we need only to toggle port 3shan kda m7tag a3ml output 3ala PORT
					{
						case PORTA:
						TOG_BIT(PORTA_reg,u8PinId);
						break;
						case PORTB:
							TOG_BIT(PORTB_reg,u8PinId);
						break;
						case PORTC:
							TOG_BIT(PORTC_reg,u8PinId);
						break;
						case PORTD:
							TOG_BIT(PORTD_reg,u8PinId);
						break;
					}
				}

			else
					{
						//wrong input Direction
					}


}

void DIO_vidEnablePullUpRes(u8 u8PortId,u8 u8PinId)
{
	if((u8PortId<=PORTD) && (u8PinId<=PIN7))
			{
				//law 3ayzen n set l pit direction

				switch (u8PortId)
					{
						case PORTA:SET_BIT(PORTA_reg,u8PinId);
						break;
						case PORTB:SET_BIT(PORTB_reg,u8PinId);
						break;
						case PORTC:SET_BIT(PORTC_reg,u8PinId);
						break;
						case PORTD:SET_BIT(PORTD_reg,u8PinId);
						break;
					}
			}
}

void DIO_vidSetPortVal(u8 u8PortId,u8 u8Val)
{


		switch (u8PortId)
				{
					case PORTA:
						PORTA_reg=u8Val;
					break;
					case PORTB:
						PORTB_reg=u8Val;
					break;
					case PORTC:
						PORTC_reg=u8Val;
					break;
					case PORTD:
						PORTD_reg=u8Val;
					break;
					default: /*wrong POrtIdvalue*/
					  break;
				}


}

void DIO_vidSetPortDir(u8 u8PortId,u8 u8Dir)
{


			switch (u8PortId)
					{
						case PORTA:
							DDRA_reg=u8Dir;
						break;
						case PORTB:
							DDRB_reg=u8Dir;
						break;
						case PORTC:
							DDRC_reg=u8Dir;
						break;
						case PORTD:
							DDRD_reg=u8Dir;
						break;
						default: /*wrong POrtIdvalue*/
							break;
					}


}

