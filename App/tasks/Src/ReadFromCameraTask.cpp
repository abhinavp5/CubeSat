#include "ReadFromCameraTask.h"
#include "TaskCommon.h"

namespace
{
    void readFromCameraTask(void *)
    {
        while (1)
        {
            // TODO: Core Task Logic
        }
    }
}

TaskHandle_t createReadFromCameraTask()
{
    TaskHandle_t handle = nullptr;
    xTaskCreate(
        readFromCameraTask,
        "Read from Camera Task",
        tasks::STACK_SIZE,
        nullptr,
        tasks::DEFAULT_PRIORITY,
        &handle);
    return handle;
}
