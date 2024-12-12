/*
 * timer.h
 *
 *  Created on: Oct 27, 2024
 *      Author: ACER
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

//--- Private Include ----------------------------

#include "main.h"
#include "global.h"

//--- Variables ----------------------------------

extern int TIMECYCLE;

//--- Functions Declaration ----------------------

void timer_init(uint32_t HCLK, uint32_t Prescaler, uint32_t Period);

//--- Private Defines ----------------------------




#endif /* INC_TIMER_H_ */
