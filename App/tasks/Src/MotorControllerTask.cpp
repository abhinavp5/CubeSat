#include "MotorControllerTask.h"
#include "TaskCommon.h"

namespace
{
    void motorControllerTask(void *)
    {
        while (1)
        {
            // TODO: Core Task Logic
        }
    }
}

TaskHandle_t createMotorControllerTask()
{
    TaskHandle_t handle = nullptr;
    xTaskCreate(
        motorControllerTask,
        "Motor Controller Task",
        tasks::STACK_SIZE,
        nullptr,
        tasks::DEFAULT_PRIORITY,
        &handle);
    return handle;
}
