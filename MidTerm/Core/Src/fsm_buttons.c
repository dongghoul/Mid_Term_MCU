/*
 * input_processing.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "fsm_buttons.h"

void increaseCounter(){
	if (counter == 9)
		counter = 0;
	else counter++;
}

void decreaseCounter(){
	if (counter == 0)
		counter = 9;
	else counter--;
}

void fsm_simple_buttons_run(void){
	switch (status){
	case BUTTONS_RELEASED:
		if(is_button_pressed(RESET_BUTTON)){
			status = RESET_BUTTON_PRESSED;
			counter = 0;
			setTimerTimeOut(TIME_OUT_DURATION);
		}
		if(is_button_pressed(INC_BUTTON)){
			status = INC_BUTTON_PRESSED;
			increaseCounter();
			setTimerTimeOut(TIME_OUT_DURATION);
		}
		if(is_button_pressed(DEC_BUTTON)){
			status = DEC_BUTTON_PRESSED;
			decreaseCounter();
			setTimerTimeOut(TIME_OUT_DURATION);
		}
		if (timerTimeOut_flag == 1){
			setTimerCountDown(COUNT_DOWN_PERIOD);
			status = COUNT_DOWN;
		}
		break;
	case RESET_BUTTON_PRESSED:
		if(!is_button_pressed(RESET_BUTTON)){
			status = BUTTONS_RELEASED;
		}
		break;
	case INC_BUTTON_PRESSED:
		if(!is_button_pressed(INC_BUTTON)){
			status = BUTTONS_RELEASED;
		} else {
			if(is_button_pressed_3s(INC_BUTTON)){
				status = INC_BUTTON_PRESSED_MORE_THAN_3_SECOND;
				increaseCounter();
				setTimerPressed3s(PERIOD_BETWEEN_INCREASE_OR_DECREASE);
				setTimerTimeOut(TIME_OUT_DURATION);
			}
		}
		break;
	case DEC_BUTTON_PRESSED:
		if(!is_button_pressed(DEC_BUTTON)){
			status = BUTTONS_RELEASED;
		} else {
			if(is_button_pressed_3s(DEC_BUTTON)){
				status = DEC_BUTTON_PRESSED_MORE_THAN_3_SECOND;
				decreaseCounter();
				setTimerPressed3s(PERIOD_BETWEEN_INCREASE_OR_DECREASE);
				setTimerTimeOut(TIME_OUT_DURATION);
			}
		}
		break;
	case INC_BUTTON_PRESSED_MORE_THAN_3_SECOND:
		if (timerPressed3s_flag == 1){
			increaseCounter();
			setTimerPressed3s(PERIOD_BETWEEN_INCREASE_OR_DECREASE);
		}
		if(!is_button_pressed(INC_BUTTON)){
			status = BUTTONS_RELEASED;
		}
		else setTimerTimeOut(TIME_OUT_DURATION);
		break;
	case DEC_BUTTON_PRESSED_MORE_THAN_3_SECOND:
		if (timerPressed3s_flag == 1){
			decreaseCounter();
			setTimerPressed3s(PERIOD_BETWEEN_INCREASE_OR_DECREASE);
		}
		if(!is_button_pressed(DEC_BUTTON)){
			status = BUTTONS_RELEASED;
		}
		else setTimerTimeOut(TIME_OUT_DURATION);
		break;
	case COUNT_DOWN:
		if (timerCountDown_flag == 1){
			if (counter > 0){
				setTimerCountDown(COUNT_DOWN_PERIOD);
				counter--;
			}
		}
		if(is_button_pressed(INC_BUTTON)){
			status = INC_BUTTON_PRESSED;
			increaseCounter();
			setTimerTimeOut(TIME_OUT_DURATION);
		}
		if(is_button_pressed(DEC_BUTTON)){
			status = DEC_BUTTON_PRESSED;
			decreaseCounter();
			setTimerTimeOut(TIME_OUT_DURATION);
		}
	default:
		break;
	}
}
