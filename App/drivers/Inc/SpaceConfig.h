
enum class CAN_ID_TYPE{
    OBC = 0x01, 
    ADCS = 0x02,
    COMM = 0x03,
    EPS = 0x04,
    PAYLOAD1 = 0x05,
    PAYLOAD2 = 0x06
};

enum class HAB_OPERATIONAL_MODE{ 
    INHIBITED, // Payload 1 OFF
    SAFE,       // Payl oad 1 OFF
    STANDBY_NO_COMMS, // Payload 1 OFF
    FLIGHT_COMMS, // Payload 1 ON
    FLIGHT_NO_COMMS, // Payload 1 ON
    BLOCKED,  // Payload 1 OFF
    RF_TEST
};

namespace SpaceCanConfig{
    
}