#include "soc.h"

float estimateSOC(float voltage){
    if(voltage<=10.0){
        return 0.0;
    }
    if(voltage>=12.6){
        return 100.0;
    }
    float soc=((voltage-10.0)/(12.6-10.0))*100.0;
    return soc;
}