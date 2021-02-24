/*
 * Keypad_PRG.c
 *
 *  Created on: Jul 13, 2020
 *      Author: Anwar
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INT.h"
#include "Keypad_Cfg.h"
#include "Keypad_INT.h"

void Keypad_vidInit(void)
{
	DIO_vidSetPinDir(PORTD,Keypad_u8Row_1,OUTPUT);
	DIO_vidSetPinDir(PORTD,Keypad_u8Row_2,OUTPUT);
	DIO_vidSetPinDir(PORTD,Keypad_u8Row_3,OUTPUT);
	DIO_vidSetPinDir(PORTD,Keypad_u8Row_4,OUTPUT);
	DIO_vidSetPinDir(PORTA,Keypad_u8Column_1,INPUT);
	DIO_vidSetPinDir(PORTA,Keypad_u8Column_2,INPUT);
	DIO_vidSetPinDir(PORTA,Keypad_u8Column_3,INPUT);
	DIO_vidSetPinDir(PORTA,Keypad_u8Column_4,INPUT);

	DIO_vidSetPinVal(PORTD,Keypad_u8Row_1,LOW);
	DIO_vidSetPinVal(PORTD,Keypad_u8Row_2,LOW);
	DIO_vidSetPinVal(PORTD,Keypad_u8Row_3,LOW);
	DIO_vidSetPinVal(PORTD,Keypad_u8Row_4,LOW);
	DIO_vidSetPinVal(PORTA,Keypad_u8Column_1,HIGH);
	DIO_vidSetPinVal(PORTA,Keypad_u8Column_2,HIGH);
	DIO_vidSetPinVal(PORTA,Keypad_u8Column_3,HIGH);
	DIO_vidSetPinVal(PORTA,Keypad_u8Column_4,HIGH);

}


u8 Keypad_u8GetKey(void)
{
	typedef union
	{
		struct
		{ //bit field
			u8 B0 : 1 ;
			u8 B1 : 1 ;
			u8 B2 : 1 ;
			u8 B3 : 1 ;
			u8 B4 : 1 ;
			u8 B5 : 1 ;
			u8 B6 : 1 ;
			u8 B7 : 1 ;
		}BIT;
		u8 BYTE ;
	}Pin_Register ;
	Pin_Register x;
	u8 temp ;

	DIO_vidSetPinVal(PORTD,Keypad_u8Row_1,LOW);
	DIO_vidSetPinVal(PORTD,Keypad_u8Row_2,HIGH);
	DIO_vidSetPinVal(PORTD,Keypad_u8Row_3,HIGH);
	DIO_vidSetPinVal(PORTD,Keypad_u8Row_4,HIGH);
	x.BIT.B4 = Dio_u8GetPinVal();
	x.BIT.B5 = Dio_u8GetPinVal();
	x.BIT.B6 = Dio_u8GetPinVal();
	x.BIT.B7 = Dio_u8GetPinVal();
	temp = x.BYTE ;
	temp &= 0xF0 ;
	switch(temp)
		{
		case 0b11100000 :
			return 1 ;
		case 0b11010000 :
			return 2 ;
		case 0b10110000 :
			return 3 ;
		case 0b01110000 :
			return '+' ;
		}
