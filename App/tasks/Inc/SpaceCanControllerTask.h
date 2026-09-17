#ifndef SPACE_CAN_CONTROLLER_TASK_H
#define SPACE_CAN_CONTROLLER_TASK_H

#include "FreeRTOS.h"
#include "task.h"

// Creates the task and returns its handle, or nullptr if creation failed
TaskHandle_t createSpaceCanControllerTask();

#endif /* SPACE_CAN_CONTROLLER_TASK_H */
