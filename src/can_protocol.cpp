#include "can_protocol.h"
CANMessage createBatteryMessage(
    const BatteryData &battery
){
    CANMessage message;
    message.id=CAN_ID_BATTERY;
    message.length=8;
    uint16_t voltage=(uint16_t)(battery.voltage*100);
    uint16_t current=(uint16_t)(battery.current*100);
    int16_t temperature=(int16_t)(battery.temperature*100);
    uint16_t soc=(uint16_t)(battery.soc*100);
    
    message.data[0]=voltage & 0xFF;
    message.data[1]=(voltage>>8)& 0xFF;

    message.data[2]=current & 0xFF;
    message.data[3]=(current>>8) & 0xFF;

    message.data[4]=temperature & 0xFF;
    message.data[5]=(temperature >> 8)& 0xFF;

    message.data[6]=soc & 0xFF;
    message.data[7]=(soc >>8 )& 0xFF;

    return message;
}

CANMessage createStatusMessage(const BatteryData &battery, const FaultStatus &faults,BMSState state){
    CANMessage message;
    message.id=CAN_ID_STATUS;
    message.length=8;
    message.data[0]=(uint8_t)state;
    message.data[1]=faults.overVoltage ? 1:0;
    message.data[2]=faults.underVoltage ? 1:0;
    message.data[3] =
        faults.overCurrent ? 1 : 0;

    message.data[4] =
        faults.overTemperature ? 1 : 0;

    message.data[5] =
        faults.underTemperature ? 1 : 0;


    // Warning flags
    uint8_t warningFlags = 0;

    if (faults.voltageWarning)
    {
        warningFlags |= (1 << 0);
    }

    if (faults.currentWarning)
    {
        warningFlags |= (1 << 1);
    }

    if (faults.temperatureWarning)
    {
        warningFlags |= (1 << 2);
    }

    message.data[6] = warningFlags;


    // Reserved byte
    message.data[7] = 0;


    return message;

}