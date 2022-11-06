/*
 * timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "timer.h"

#define TIMER_CYCLE 10

int timerBlinkingLedRed_flag = 0;
int timerBlinkingLedRed_counter = 0;
int timerPressed3s_flag = 0;
int timerPressed3s_counter = 0;
int timerTimeOut_flag = 0;
int timerTimeOut_counter = 0;
int timerCountDown_flag = 0;
int timerCountDown_counter = 0;
int timer5_flag = 0;
int timer5_counter = 0;

void setTimerBlinkingLedRed(int duration){
	timerBlinkingLedRed_flag = 0;
	timerBlinkingLedRed_counter = duration / TIMER_CYCLE;
}

void setTimerPressed3s(int duration){
	timerPressed3s_flag = 0;
	timerPressed3s_counter = duration / TIMER_CYCLE;
}

void setTimerTimeOut(int duration){
	timerTimeOut_flag = 0;
	timerTimeOut_counter = duration / TIMER_CYCLE;
}

void setTimerCountDown(int duration){
	timerCountDown_flag = 0;
	timerCountDown_counter = duration / TIMER_CYCLE;
}

void setTimer5(int duration){
	timer5_flag = 0;
	timer5_counter = duration / TIMER_CYCLE;
}

void timerRun(){
	if (timerTimeOut_counter > 0){
		timerTimeOut_counter--;
		if (timerTimeOut_counter == 0)
			timerTimeOut_flag = 1;
	}
	if (timerCountDown_counter > 0){
		timerCountDown_counter--;
		if (timerCountDown_counter == 0)
			timerCountDown_flag = 1;
	}
	if (timer5_counter > 0){
		timer5_counter--;
		if (timer5_counter == 0)
			timer5_flag = 1;
	}
	if (timerPressed3s_counter > 0){
		timerPressed3s_counter--;
		if (timerPressed3s_counter == 0)
			timerPressed3s_flag = 1;
	}
	if (timerBlinkingLedRed_counter > 0){
		timerBlinkingLedRed_counter--;
		if (timerBlinkingLedRed_counter == 0)
			timerBlinkingLedRed_flag = 1;
	}
}
