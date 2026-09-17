#ifndef CAN_TASK_H
#define CAN_TASK_H

#include "FreeRTOS.h"
#include "task.h"

// Creates the task and returns its handle, or nullptr if creation failed
TaskHandle_t createCanTask();

#endif /* CAN_TASK_H */
