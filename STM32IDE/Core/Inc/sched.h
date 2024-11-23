/*
 * sched.h
 *
 *  Created on: Nov 21, 2024
 *      Author: ACER
 */

#ifndef INC_SCHED_H_
#define INC_SCHED_H_

//--- Private Include ----------------------------

#include "main.h"

//--- Variables ----------------------------------
//- Private Struct -------------------------------
typedef struct{
	void(*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} sTask;

//--- Functions Declaration ----------------------
//- Global Functions -----------------------------
void SCH_Init(void);
void SCH_Update(void);
unsigned char SCH_Add_Task(void(*pFunction)(), unsigned int DELAY, unsigned int PERIOD);
unsigned char SCH_Delete_Task(const unsigned char TASK_INDEX);
void SCH_Dispatch_Tasks(void);
void SCH_Go_to_Sleep(void);
void SCH_Report_Status();

//--- Preprocessing ------------------------------
//- Report Errors --------------------------------
//#define SCH_REPORT_ERRORS
#ifdef SCH_REPORT_ERRORS
#define Error_port PORTA

#define ERROR_SCH_TOO_MANY_TASKS 						1
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK 				2
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER 3
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START 		4
#define ERROR_SCH_LOST_SLAVE 							5
#define ERROR_SCH_CAN_BUS_ERROR 						6
#define ERROR_I2C_WRITE_BYTE_AT24C64 					7
#define ERROR_SCH_CANNOT_DELETE_TASK					8
#endif

//- Utilities ------------------------------------
#define SCH_MAX_TASKS 	40
#define NO_TASK_ID 		0

#endif /* INC_SCHED_H_ */
