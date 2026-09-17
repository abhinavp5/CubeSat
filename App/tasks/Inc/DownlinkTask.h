#ifndef DOWNLINK_TASK_H
#define DOWNLINK_TASK_H

#include "FreeRTOS.h"
#include "task.h"

// Creates the task and returns its handle, or nullptr if creation failed
TaskHandle_t createDownlinkTask();

#endif /* DOWNLINK_TASK_H */
