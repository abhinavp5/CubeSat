#include "app_main.h"

#include "CanTask.h"
#include "DownlinkTask.h"
#include "HousekeepingTask.h"
#include "ModeManagerTask.h"
#include "MotorControllerTask.h"
#include "ReadFromCameraTask.h"
#include "SpaceCanControllerTask.h"
#include "WriteToFlashTask.h"

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

// Called once from StartDefaultTask (Core/Src/app_freertos.c) after the
// scheduler is already running, so tasks created here start immediately.
void app_main()
{
    // TODO: implement these when nessecary
    //  createQueues();
    //  createMutexes();

    createCanTask();
    createWriteToFlashTask();
    createReadFromCameraTask();
    createMotorControllerTask();
    createModeManagerTask();
    createSpaceCanControllerTask();
    createHousekeepingTask();
    createDownlinkTask();
}
