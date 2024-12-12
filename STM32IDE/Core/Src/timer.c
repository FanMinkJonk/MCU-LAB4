/*
 * timer.c
 *
 *  Created on: Oct 27, 2024
 *      Author: ACER
 */

//--- main header --------------------------------

#include "timer.h"

//--- Variables ----------------------------------

//- Local Variables ------------------------------
int TIMECYCLE = 0;

//--- Functions Definition -----------------------

void timer_init(uint32_t HCLK, uint32_t Prescaler, uint32_t Period){
	TIMECYCLE = ((1000 * (Prescaler + 1) * (Period + 1)) / (HCLK));
}












