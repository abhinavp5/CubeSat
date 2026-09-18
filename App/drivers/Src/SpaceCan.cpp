#include "cstdint.h"
#include "SpaceConfig.h"
#include "FreeRTOS.h"
#include "Drivers/STM32G4xx_HAL_Driver/Inc/stm32g4xx_hal_fdcan.h"
#include "main.h"
#include "Clock.h"



SpaceCan::SpaceCan(FDCAN_HandleTypeDef * hfdcan, uint8_t node_id){
    this->hfdcan = hfdcan;
    this->initalized = true;

    // setting up correct TX Packet
    txHeader.Identifier = node_id;
    txHeader.IdType = FDCAN_STANDARD_ID;          // 11-bit CAN ID
    txHeader.TxFrameType = FDCAN_DATA_FRAME;     // normal data frame
    txHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    txHeader.BitRateSwitch = FDCAN_BRS_OFF;       // no faster data phase
    txHeader.FDFormat = FDCAN_CLASSIC_CAN;        // Classic CAN, NOT CAN-FD
    txHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    txHeader.MessageMarker = 0;
    
    lock = xSemaphoreCreateMutex();
}

void SpaceCan::Start(){
    HAL_FDCAN_Start(&hfdcan); // Starting the peripheral

}
uint8_t SpaceCan::write(const SeralizedCanMessage *msg){
    if (!initalized){
        return 1;
    }
    txHeader.DataLength = bytesToDlc(msg->DataLength);
    xSemaphoreTake(lock, portMAX_DELAY); // Acquire the lock
    HAL_StatusTypeDef status =
        HAL_FDCAN_AddMessageToTxFifoQ(
            &hfdcan,
            &txHeader,
            msg->data
    );
    xSemaphoreGive(lock);
    if (status != HAL_OK){
        return 1;
    }
    return 0;
}
uint8_t SpaceCan::read(SerializedCanMessage * msg){
    if (!initalized){
        return 1;
    }

}


uint32_t SpaceCan::bytesToDlc(uint8_t len) const
{
    // Clamp to 8 bytes; extend if you move to CAN FD later.
    if (len > 8) {
        len = 8;
    }

    switch (len) {
    case 0: return FDCAN_DLC_BYTES_0;
    case 1: return FDCAN_DLC_BYTES_1;
    case 2: return FDCAN_DLC_BYTES_2;
    case 3: return FDCAN_DLC_BYTES_3;
    case 4: return FDCAN_DLC_BYTES_4;
    case 5: return FDCAN_DLC_BYTES_5;
    case 6: return FDCAN_DLC_BYTES_6;
    case 7: return FDCAN_DLC_BYTES_7;
    case 8: return FDCAN_DLC_BYTES_8;
    default: return FDCAN_DLC_BYTES_8;
    }
}

uint8_t SpaceCan::dlcToBytes(uint32_t dlc) const
{
    switch (dlc) {
    case FDCAN_DLC_BYTES_0: return 0;
    case FDCAN_DLC_BYTES_1: return 1;
    case FDCAN_DLC_BYTES_2: return 2;
    case FDCAN_DLC_BYTES_3: return 3;
    case FDCAN_DLC_BYTES_4: return 4;
    case FDCAN_DLC_BYTES_5: return 5;
    case FDCAN_DLC_BYTES_6: return 6;
    case FDCAN_DLC_BYTES_7: return 7;
    case FDCAN_DLC_BYTES_8: return 8;
    default: return 8; // conservative fallback
    }
}