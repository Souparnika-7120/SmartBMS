#include "filter.h"
void initializeFilter(MovingAverageFilter &filter){
    filter.index=0;
    filter.count=0;
    for(int i=0;i<5;i++){
        filter.values[i]=0.0;
    }
}
float updateFilter(
    MovingAverageFilter &filter,
    float newValue
)
{
    filter.values[filter.index] = newValue;

    filter.index++;

    if (filter.index >= 5)
    {
        filter.index = 0;
    }

    if (filter.count < 5)
    {
        filter.count++;
    }

    float sum = 0.0;

    for (int i = 0; i < filter.count; i++)
    {
        sum += filter.values[i];
    }

    return sum / filter.count;
}