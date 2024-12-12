/*
 * fsm_traffic_mode.h
 *
 *  Created on: Oct 29, 2024
 *      Author: ACER
 */

#ifndef INC_FSM_TRAFFIC_MODE_H_
#define INC_FSM_TRAFFIC_MODE_H_

//--- Private Include ----------------------------

#include "main.h"
#include "global.h"
#include "timer.h"
#include "led_7_segment.h"
#include "sched.h"

//--- Variables ----------------------------------

extern uint8_t traffic_mode;
extern uint8_t light_mode;

//--- Functions Declaration ----------------------

void one_sec_count(void);
void blinky_led(void);
void blinky_7_seg(void);

void init_fsm_traffic_mode(void);
void fsm_traffic_mode(void);
void fsm_traffic_auto(void);

#endif /* INC_FSM_TRAFFIC_MODE_H_ */





