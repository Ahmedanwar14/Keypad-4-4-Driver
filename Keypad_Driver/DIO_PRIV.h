/*
 * DIO_PRIV.h
 *
 *  Created on: Feb 15, 2020
 *      Author: Anwar
 */
#ifndef DIO_PRIV_H
#define DIO_PRIV_H
#define PORTA_reg (*(volatile u8*)0x3B)
#define DDRA_reg (*(volatile u8*)0x3A)
#define PINA_reg (*(volatile u8*)0x39)

#define PORTB_reg (*(volatile u8*)0x38)
#define DDRB_reg (*(volatile u8*)0x37)
#define PINB_reg (*(volatile u8*)0x36)

#define PORTC_reg (*(volatile u8*)0x35)
#define DDRC_reg (*(volatile u8*)0x34)
#define PINC_reg (*(volatile u8*)0x33)

#define PORTD_reg (*(volatile u8*)0x32)
#define DDRD_reg (*(volatile u8*)0x31)
#define PIND_reg (*(volatile u8*)0x30)

#endif
