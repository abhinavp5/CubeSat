#ifndef MODE_MANAGER_TASK_H
#define MODE_MANAGER_TASK_H

#include "FreeRTOS.h"
#include "task.h"

// Creates the task and returns its handle, or nullptr if creation failed
TaskHandle_t createModeManagerTask();

#endif /* MODE_MANAGER_TASK_H */
