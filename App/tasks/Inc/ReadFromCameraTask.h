#ifndef READ_FROM_CAMERA_TASK_H
#define READ_FROM_CAMERA_TASK_H

#include "FreeRTOS.h"
#include "task.h"

// Creates the task and returns its handle, or nullptr if creation failed
TaskHandle_t createReadFromCameraTask();

#endif /* READ_FROM_CAMERA_TASK_H */
