#include "fault.h"

void checkFaults(
    const BatteryData &battery,
    const BMSLimits &limits,
    FaultStatus &faults
)
{
    faults.overVoltage=battery.voltage>limits.maxVoltage;
    faults.underVoltage=battery.voltage<limits.minVoltage;
    faults.overCurrent=battery.current>limits.maxCurrent;
    faults.overTemperature=battery.temperature>limits.maxTemperature;
    faults.underTemperature=battery.temperature<limits.minTemperature;
}

BMSState determineState(const FaultStatus &faults){
    if(faults.overVoltage||faults.underVoltage||faults.overCurrent||faults.overTemperature||faults.underTemperature){
        return FAULT;
    }
    return NORMAL;
}
