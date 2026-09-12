#ifndef FAULT_H
#define FAULT_H

#include "battery.h"
struct BMSLimits{
    float maxVoltage;
    float minVoltage;
    float maxCurrent;
    float maxTemperature;
    float minTemperature;
};

void checkFaults(
    const BatteryData &battery,
    const BMSLimits &limits,
    FaultStatus &faults
);

BMSState determineState(const FaultStatus &faults);

#endif