#include "cstdint.h"
#include "SpaceConfig.h"
#include "FreeRTOS.h"
#include "SpaceCan.h"
#include "Drivers/STM32G4xx_HAL_Driver/Inc/stm32g4xx_hal_fdcan.h"
#include "main.h"
#include "Clock.h"

SpaceCan *SpaceCan::instances[2] = {nullptr, nullptr};
SpaceCan::SpaceCan(FDCAN_HandleTypeDef *hfdcan, uint8_t node_id = 0x05)
{
    CAN_ID = node_id;
    this->hfdcan = &hfdcan;
    this->initalized = true;
    // setting up correct TX Packet
    txHeader.Identifier = node_id;
    txHeader.IdType = FDCAN_STANDARD_ID;     // 11-bit CAN ID
    txHeader.TxFrameType = FDCAN_DATA_FRAME; // normal data frame
    txHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    txHeader.BitRateSwitch = FDCAN_BRS_OFF; // no faster data phase
    txHeader.FDFormat = FDCAN_CLASSIC_CAN;  // Classic CAN, NOT CAN-FD
    txHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    txHeader.MessageMarker = 0;
    instances[hfdcan->Instance == FDCAN1 ? 0 : 1] = this;
    lock = xSemaphoreCreateMutex();
}

SpaceCan *SpaceCan::fromHandle(FDCAN_HandleTypeDef *handle)
{
    return instances[handle->Instance == FDCAN1 ? 0 : 1];
}
uint8_t SpaceCan::Start(uint8_t bus)
{
    // Setup the filter to only accept to current address (0x05 for Sci Board)
    FDCAN_FilterTypeDef filter{};
    filter.IdType = FDCAN_STANDARD_ID;
    filter.FilterIndex = 0;
    filter.FilterType = FDCAN_FILTER_MASK;
    filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    filter.FilterID1 = this.node_id; // ID to match
    filter.FilterID2 = 0x7FF;        // compare all 11 ID bits

    if (HAL_FDCAN_ConfigFilter(&hfdcan1, &filter) != HAL_OK)
    {
        return 1;
    }

    // Global Filter
    HAL_FDCAN_ConfigGlobalFilter(
        &hfdcan,
        FDCAN_REJECT,
        FDCAN_REJECT,
        FDCAN_REJECT_REMOTE,
        FDCAN_REJECT_REMOTE);

    // Start CAN peripheral
    if (HAL_FDCAN_Start(&hfdcan) != HAL_OK)
    {
        return 1;
    }

    // Enable Callback Notifications
    if (HAL_FDCAN_ActivateNotification(
            &hfdcan1,
            FDCAN_IT_RX_FIFO0_NEW_MESSAGE,
            0) != HAL_OK)
    {
        Error_Handler();
    }

    return 0;
}

uint8_t SpaceCan::write(const SeralizedCanMessage *msg)
{
    if (!initalized)
    {
        return 1;
    }
    txHeader.DataLength = bytesToDlc(msg->DataLength);
    xSemaphoreTake(lock, portMAX_DELAY); // Acquire the lock
    HAL_StatusTypeDef status =
        HAL_FDCAN_AddMessageToTxFifoQ(
            &hfdcan,
            &txHeader,
            msg->data);
    xSemaphoreGive(lock);
    if (status != HAL_OK)
    {
        return 1;
    }
    return 0;
}

uint8_t SpaceCan::read(SerializedCanMessage *msg)
{
    if (!initalized)
    {
        return 1;
    }
    xSempahoreTake(lock, portMAX_DELAY);

    xSempaphoreGive(lock);
}

void SpaceCan::handleRxInterrupt()
{
    FDCAN_RxHeaderTypeDef header{};
    uint8_t data[8];

    if (HAL_FDCAN_GetRxMessage(
            &hfdcan,
            FDCAN_RX_FIFO0,
            &header,
            data) != HAL_OK)
    {
        return;
    }

    // TODO: place the CAN messages in a FreeRTOS queue
}
uint32_t SpaceCan::bytesToDlc(uint8_t len) const
{
    // Clamp to 8 bytes; extend if you move to CAN FD later.
    if (len > 8)
    {
        len = 8;
    }

    switch (len)
    {
    case 0:
        return FDCAN_DLC_BYTES_0;
    case 1:
        return FDCAN_DLC_BYTES_1;
    case 2:
        return FDCAN_DLC_BYTES_2;
    case 3:
        return FDCAN_DLC_BYTES_3;
    case 4:
        return FDCAN_DLC_BYTES_4;
    case 5:
        return FDCAN_DLC_BYTES_5;
    case 6:
        return FDCAN_DLC_BYTES_6;
    case 7:
        return FDCAN_DLC_BYTES_7;
    case 8:
        return FDCAN_DLC_BYTES_8;
    default:
        return FDCAN_DLC_BYTES_8;
    }
}

uint8_t SpaceCan::dlcToBytes(uint32_t dlc) const
{
    switch (dlc)
    {
    case FDCAN_DLC_BYTES_0:
        return 0;
    case FDCAN_DLC_BYTES_1:
        return 1;
    case FDCAN_DLC_BYTES_2:
        return 2;
    case FDCAN_DLC_BYTES_3:
        return 3;
    case FDCAN_DLC_BYTES_4:
        return 4;
    case FDCAN_DLC_BYTES_5:
        return 5;
    case FDCAN_DLC_BYTES_6:
        return 6;
    case FDCAN_DLC_BYTES_7:
        return 7;
    case FDCAN_DLC_BYTES_8:
        return 8;
    default:
        return 8; // conservative fallback
    }
}

extern "C"
{
    /*
    CAN Interupt
    */
    void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
    {
        if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) == 0)
        {
            return;
        }
        if (SpaceCan *bus = SpaceCan::fromHandle(hfdcan))
        {
            bus->handleRxInterrupt();
        }
    }
}