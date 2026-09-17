#include "DownlinkTask.h"
#include "TaskCommon.h"

namespace
{
    void downlinkTask(void *)
    {
        while (1)
        {
            // TODO: Core Task Logic
        }
    }
}

TaskHandle_t createDownlinkTask()
{
    TaskHandle_t handle = nullptr;
    xTaskCreate(
        downlinkTask,
        "Downlink Task",
        tasks::STACK_SIZE,
        nullptr,
        tasks::DEFAULT_PRIORITY,
        &handle);
    return handle;
}
