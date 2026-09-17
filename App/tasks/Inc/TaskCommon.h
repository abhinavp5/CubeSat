#ifndef TASK_COMMON_H
#define TASK_COMMON_H

#include "FreeRTOS.h"
#include "task.h"

namespace tasks
{
    // Stack depth in words (not bytes), as xTaskCreate expects
    constexpr configSTACK_DEPTH_TYPE STACK_SIZE = 128;
    constexpr UBaseType_t DEFAULT_PRIORITY = 1;
}

#endif /* TASK_COMMON_H */
