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
    SpaceCan(FDCAN_HandleTypeDef *hfdcan);
    void start();
    uint8_t write(const SeralizedCanMessage);
    uint8_t read(SerializedCanMessage *msg);

private:
    FDCAN_HandleTypeDef *hfdcan;
    FDCAN_TxHeaderTypeDef txHeader;
    FDCAN_RxHeaderTypeDef rxHeader;
    SemaphoreHandle_t lock;
    bool initalized;
    uint32_t bytesToDlc(uint8_t len) const;
    uint8_t dlcToBytes(uint32_t dlc) const;
}