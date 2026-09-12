#ifndef BATTERY_H
#define BATTERY_H

struct BatteryData{
    float voltage;
    float current;
    float temperature;
    float soc;
};

struct FaultStatus{
    bool overVoltage;
    bool underVoltage;
    bool overCurrent;
    bool overTemperature;
    bool underTemperature;
};

enum BMSState{
    INIT,
    NORMAL,
    WARNING,
    FAULT,
    RECOVERY
};

#endif
