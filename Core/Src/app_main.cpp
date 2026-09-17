#include "app_main.h"
#include "cmsis_os2.h"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "startup.h"

#define STACK_SIZE 128

/*
Sensors to wire
- ADCS --> current attitude x: y: z: w/ CAN from ADCS board


FROM ADCS
heading vectors as quaternions –– testament from the ADCS group

- calibrated imu on the plate tells us the current position so that we can also what what
    true gravity south is

- also camera --> seralizer on 2nd pcb --> flex wire --> main pcb deserialize -->
- encoder tells
- based on adcs data and current imu data --> tells motor driver how to move to stablize,

1. x and y motor controls and controller positions
    -
2. Camera controller
    - might be on the CM4
3. SPI NOR flash
    - SPI interface
4. Motor Drivers
5. CAN Communication
6. external crystal
7. cm4 – 

*/

/* FreeRTOS Tasks*/
TaskFunction_t CanTask()
{
    while (1)
    {
        //TODO: Core Task Logic
    }

    // Should never reach here
    vTaskDelete(NULL);
}

TaskFunction_t WriteToFlash() {
    while (1)
    {
        //TODO: Core Task Logic
    }

    // Should never reach here
    vTaskDelete(NULL);
}
TaskFunction_t ReadFromCamera() {
    while (1)
    {
        //TODO: Core Task Logic
    }

    // Should never reach here
    vTaskDelete(NULL);
}
TaskFunction_t MotorController() {
    while (1)
    {
        //TODO: Core Task Logic
    }

    // Should never reach here
    vTaskDelete(NULL);
}
TaskFunction_t ModeManager() {
    while (1)
    {
        //TODO: Core Task Logic
    }

    // Should never reach here
    vTaskDelete(NULL);
}
TaskFunction_t SpaceCANController() {
    while (1)
    {
        //TODO: Core Task Logic
    }

    // Should never reach here
    vTaskDelete(NULL);
}
TaskFunction_t Housekeeping() {
    while (1)
    {
        //TODO: Core Task Logic
    }

    // Should never reach here
    vTaskDelete(NULL);
}
TaskFunction_t Downlink() {
    while (1)
    {
        //TODO: Core Task Logic
    }

    // Should never reach here
    vTaskDelete(NULL);
}

/* Task Creation Functions*/

void CreateCanTask()
{
    xTaskCreate(

    )
}

void CreateWriteToFlashTask()
{
    TaskHandle_t xTaskHandle;
    BaseType_t xTaskReturned = xTaskCreate(
        WriteToFlash,
        "Write to Flash Task",
        STACK_SIZE,
        nullptr,
        1,
        &xTaskHandle);

    if (xTaskReturned == pdPASS)
    {
        // TODO: Serial task created succesfully
    }
}
void CreateReadFromCameraTask()
{
    TaskHandle_t xTaskHandle;
    BaseType_t xTaskReturned = xTaskCreate(
        ReadFromCamera,
        "Read from Camera Task",
        STACK_SIZE,
        nullptr,
        1,
        &xTaskHandle);
    if (xTaskReturned == pdPASS)
    {
        // TODO: Serial task created succesfully
    }
}
void CreateMotorControllerTask()
{
    TaskHandle_t xTaskHandle;
    BaseType_t xTaskReturned = xTaskCreate(
        MotorController,
        "Motor Controller Task",
        STACK_SIZE,
        nullptr,
        1,
        &xTaskHandle);
    if (xTaskReturned == pdPASS)
    {
        // TODO: Serial task created succesfully
    }
}
void CreateModeManagerTask()
{
    TaskHandle_t xTaskHandle;
    BaseType_t xTaskReturned = xTaskCreate(
        ModeManager,
        "Mode Manager Task",
        STACK_SIZE,
        nullptr,
        1,
        &xTaskHandle);
    if (xTaskReturned == pdPASS)
    {
        // TODO: Serial task created succesfully
    }
}
void CreateSpaceCANController()
{
    TaskHandle_t xTaskHandle;
    BaseType_t xTaskReturned = xTaskCreate(
        SpaceCANController,
        "Space CAN Controller Task",
        STACK_SIZE,
        nullptr,
        1,
        &xTaskHandle);
    if (xTaskReturned == pdPASS)
    {
        // TODO: Serial task created succesfully
    }
}
void CreateHousekeepingTask()
{
    TaskHandle_t xTaskHandle;
    BaseType_t xTaskReturned = xTaskCreate(
        Housekeeping,
        "Housekeeping Task",
        STACK_SIZE,
        nullptr,
        1,
        &xTaskHandle);
    if (xTaskReturned == pdPASS)
    {
        // TODO: Serial task created succesfully
    }
}
void CreateDownlinkTask()
{
    TaskHandle_t xTaskHandle;
    BaseType_t xTaskReturned = xTaskCreate(
        Downlink,
        "Downlink Task",
        STACK_SIZE,
        nullptr,
        1,
        &xTaskHandle);
    if (xTaskReturned == pdPASS)
    {
        // TODO: Serial task created succesfully
    }
}

void app_main()
{

    createQueues();
    createMutexes();

    createImuTask();
    createWriteToFlashTask();
    createReadFromCameraTask();
    createMotorControllerTask();
    createModeManagerTask();
    createSpaceCanController();
    createHousekeepingTask();
    createDownlinkTask();



    vTaskStartScheduler();
}