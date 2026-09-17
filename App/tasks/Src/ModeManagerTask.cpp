#include "ModeManagerTask.h"
#include "TaskCommon.h"

namespace
{
    void modeManagerTask(void *)
    {
        while (1)
        {
            // TODO: Core Task Logic
        }
    }
}

TaskHandle_t createModeManagerTask()
{
    TaskHandle_t handle = nullptr;
    xTaskCreate(
        modeManagerTask,
        "Mode Manager Task",
        tasks::STACK_SIZE,
        nullptr,
        tasks::DEFAULT_PRIORITY,
        &handle);
    return handle;
}
