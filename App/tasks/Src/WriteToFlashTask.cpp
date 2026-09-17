#include "WriteToFlashTask.h"
#include "TaskCommon.h"

namespace
{
    void writeToFlashTask(void *)
    {
        while (1)
        {
            // TODO: Core Task Logic
        }
    }
}

TaskHandle_t createWriteToFlashTask()
{
    TaskHandle_t handle = nullptr;
    xTaskCreate(
        writeToFlashTask,
        "Write to Flash Task",
        tasks::STACK_SIZE,
        nullptr,
        tasks::DEFAULT_PRIORITY,
        &handle);
    return handle;
}
