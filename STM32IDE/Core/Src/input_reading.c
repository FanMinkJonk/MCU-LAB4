/*
 * input_reading.c
 *
 *  Created on: Oct 28, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "input_reading.h"

//--- Variables ----------------------------------

//- Local Variables ------------------------------
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

static GPIO_PinState flagForButtonPress[N0_OF_BUTTONS];

//--- Functions Definition -----------------------

void init_button_reading(void){
	for(uint8_t i = 0; i<N0_OF_BUTTONS; ++i){
		debounceButtonBuffer1[i] = 1;
		debounceButtonBuffer2[i] = 1;
		flagForButtonPress[i] = 1;
	}
}

void button_reading(void){
	for(int i = BUTTON_MODE; i < N0_OF_BUTTONS; ++i){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(INPUT_MODE_GPIO_Port, (INPUT_MODE_Pin << i));
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			flagForButtonPress[i] = debounceButtonBuffer1[i];
		}
	}
}

unsigned char is_button_pressed(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (flagForButtonPress[index] == BUTTON_STATUS_PRESSED);
}













