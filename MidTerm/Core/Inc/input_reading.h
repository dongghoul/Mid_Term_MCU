/*
 * input_reading.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#define RESET_BUTTON 0
#define INC_BUTTON 1
#define DEC_BUTTON 2

void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_3s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
