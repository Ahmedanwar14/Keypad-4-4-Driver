/*
 * DIO_INT.h
 *
 *  Created on: Feb 15, 2020
 *      Author: Anwar
 */
#ifndef DIO_INT_H
#define DIO_INT_H

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//directions
#define INPUT 0x00
#define OUTPUT 0xFF
//Values
#define HIGH 0xFF
#define LOW 0x00
//PIN Readings
#define IN_HIGH 0x01
#define IN_LOW  0X00
#define IN_UNDEF 0XFF
//PIN SErvices
void DIO_vidSetPinDir(u8 u8PortId,u8 u8PinId,u8 u8Dir);//setting the DDRx (Input or Output)
void DIO_vidSetPinVal(u8 u8PortId, u8 u8PinId,u8 u8Val);
u8 DIO_u8GetPinVal(u8 u8PortId,u8 u8PinId);
void DIO_vidEnablePullUpRes(u8 u8PortId,u8 u8PinId);
void DIO_vidTogglePin(u8 u8PortId,u8 u8PinId);
//PORT SErvices
void DIO_vidSetPortVal(u8 u8PortId,u8 u8Val);
void DIO_vidSetPortDir(u8 u8PortId,u8 u8Dir);



#endif


