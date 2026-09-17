#include "SpaceCanControllerTask.h"
#include "TaskCommon.h"

namespace
{
    void spaceCanControllerTask(void *)
    {
        while (1)
        {
            // TODO: Core Task Logic
        }
    }
}

TaskHandle_t createSpaceCanControllerTask()
{
    TaskHandle_t handle = nullptr;
    xTaskCreate(
        spaceCanControllerTask,
        "Space CAN Controller Task",
        tasks::STACK_SIZE,
        nullptr,
        tasks::DEFAULT_PRIORITY,
        &handle);
    return handle;
}
