#ifndef MOTOR_CONTROLLER_TASK_H
#define MOTOR_CONTROLLER_TASK_H

#include "FreeRTOS.h"
#include "task.h"

// Creates the task and returns its handle, or nullptr if creation failed
TaskHandle_t createMotorControllerTask();

#endif /* MOTOR_CONTROLLER_TASK_H */
