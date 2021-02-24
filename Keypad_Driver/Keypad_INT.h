/*
 * Keypad_INT.h
 *
 *  Created on: Jul 13, 2020
 *      Author: Anwar
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#define KEYPAD_u8NO_KEY 0xFF

void Keypad_vidInit(void);
u8   Keypad_u8GetKey(void);


#endif /* KEYPAD_INT_H_ */
