/*
 * input_reading.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */


#include "main.h"
//we aim to work with more than one buttons
#define N0_OF_BUTTONS 				       3
//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   300
#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET
//the buffer that the final result is stored after
//debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
//we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[N0_OF_BUTTONS];
//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress3s[N0_OF_BUTTONS];
//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonPress3s[N0_OF_BUTTONS];

GPIO_TypeDef* buttonPortNumber[N0_OF_BUTTONS] = {BUTTON1_GPIO_Port
												,BUTTON2_GPIO_Port
												,BUTTON3_GPIO_Port};
uint16_t buttonPinNumber[N0_OF_BUTTONS] = {BUTTON1_Pin
										  ,BUTTON2_Pin
										  ,BUTTON3_Pin};

void button_reading(void){
	for(int i = 0; i < N0_OF_BUTTONS; i ++){
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(buttonPortNumber[i], buttonPinNumber[i]);
		if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i] &&
			debounceButtonBuffer2[i] == debounceButtonBuffer3[i]){
			buttonBuffer[i] = debounceButtonBuffer1[i];
			if(buttonBuffer[i] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress3s[i] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress3s[i]++;
				} else {
				//the flag is turned on when 3 second has passed
				//since the button is pressed.
					flagForButtonPress3s[i] = 1;
					//todo
				}
			} else {
				counterForButtonPress3s[i] = 0;
				flagForButtonPress3s[i] = 0;
			}
		}
	}
}

unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_3s(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xff;
	return (flagForButtonPress3s[index] == 1);
}