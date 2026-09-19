#include "cstdint.h"

struct CanMsg
{
    uint16_t id; // 11 bit identifier
    uint8_t len; // num of bytes in the payload
    uint8_t data[8];
}

class SpaceCan
{
public:
    SpaceCan(FDCAN_HandleTypeDef *hfdcan, uint8_t node_id);
    void start();
    uint8_t write(const SeralizedCanMessage);
    uint8_t read(SerializedCanMessage *msg);
    static SpaceCan *fromHandle(FDCAN_HandleTypeDef *H);
    void handleRxInterrupt();

private:
    static SpaceCan *instances[2];
    uint8_t CAN_ID;
    FDCAN_HandleTypeDef *hfdcan;
    FDCAN_TxHeaderTypeDef txHeader;
    FDCAN_RxHeaderTypeDef rxHeader;
    SemaphoreHandle_t lock;
    bool initalized;
    uint32_t bytesToDlc(uint8_t len) const;
    uint8_t dlcToBytes(uint32_t dlc) const;
}