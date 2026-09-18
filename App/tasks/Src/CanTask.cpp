#include "CanTask.h"
#include "Nodes.h"
#include "TaskCommon.h"
#include <cstdint.h>

namespace CanTask
{

    void canTask(void *)
    {
        while (1)
        {
            // TODO: Core Task Logic
        }
    }
}

TaskHandle_t createCanTask()
{
    TaskHandle_t handle = nullptr;
    xTaskCreate(
        canTask,
        "CAN Task",
        tasks::STACK_SIZE,
        nullptr,
        tasks::DEFAULT_PRIORITY,
        &handle);
    return handle;
}
