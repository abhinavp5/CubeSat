#ifndef HOUSEKEEPING_TASK_H
#define HOUSEKEEPING_TASK_H

#include "FreeRTOS.h"
#include "task.h"

// Creates the task and returns its handle, or nullptr if creation failed
TaskHandle_t createHousekeepingTask();

#endif /* HOUSEKEEPING_TASK_H */
