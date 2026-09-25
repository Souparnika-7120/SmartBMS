#include "validation.h"

bool validateBatteryData(const BatteryData &battery){
    if(battery.voltage <0.0 || battery.voltage>20.0){
        return false;
    }
    if(battery.current<-10.0 || battery.current>10.0){
        return false;
    }
    if(battery.temperature<-40.0 ||battery.temperature>100.0){
        return false;
    }
    if(battery.soc<0.0 ||battery.soc>100.0){
        return false;
    }
    return true;
}