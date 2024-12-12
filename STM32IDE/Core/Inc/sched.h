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
#include "timer.h"

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
void SCH_Go_To_Sleep(void);
void SCH_Report_Status(void);

//--- Preprocessing ------------------------------
//- Report Errors --------------------------------
//#define SCH_REPORT_ERRORS
#define Error_port PORTA

#define RETURN_NORMAL									 99

#define RETURN_ERROR									100
#define ERROR_SCH_TOO_MANY_TASKS 						101
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK 				102
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER 103
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START 		104
#define ERROR_SCH_LOST_SLAVE 							105
#define ERROR_SCH_CAN_BUS_ERROR 						106
#define ERROR_I2C_WRITE_BYTE_AT24C64 					107
#define ERROR_SCH_CANNOT_DELETE_TASK					108


//- Utilities ------------------------------------
#define SCH_MAX_TASKS 	40
#define NO_TASK_ID 		0

#endif /* INC_SCHED_H_ */
