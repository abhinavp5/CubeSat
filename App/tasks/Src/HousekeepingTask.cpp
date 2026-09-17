#include "HousekeepingTask.h"
#include "TaskCommon.h"

namespace
{
    void housekeepingTask(void *)
    {
        while (1)
        {
            // TODO: Core Task Logic
        }
    }
}

TaskHandle_t createHousekeepingTask()
{
    TaskHandle_t handle = nullptr;
    xTaskCreate(
        housekeepingTask,
        "Housekeeping Task",
        tasks::STACK_SIZE,
        nullptr,
        tasks::DEFAULT_PRIORITY,
        &handle);
    return handle;
}
