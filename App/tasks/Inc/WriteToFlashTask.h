#ifndef WRITE_TO_FLASH_TASK_H
#define WRITE_TO_FLASH_TASK_H

#include "FreeRTOS.h"
#include "task.h"

// Creates the task and returns its handle, or nullptr if creation failed
TaskHandle_t createWriteToFlashTask();

#endif /* WRITE_TO_FLASH_TASK_H */
