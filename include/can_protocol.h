#ifndef CAN_PROTOCOL.H
#define CAN_PROTOCOL.H
#include <stdint.h>
#include "battery.h"

#define CAN_ID_BATTERY 0x100
#define CAN_ID_STATUS 0x101
#define CAN_ID_FAULT 0X102

struct CANMessage{
    uint32_t id;
    uint8_t data[8];
    uint8_t length;
};

CANMessage createBatteryMessage(
    const BatteryData &battery
);

CANMessage createStatusMessage(
    const BatteryData &battery,const FaultStatus &faluts,BMSState state
);

#endif