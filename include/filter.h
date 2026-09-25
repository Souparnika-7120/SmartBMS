#ifndef FILTER_H
#define FILTER_H

struct MovingAverageFilter{
    float values[5];
    int index;
    int count;
};
void initializeFilter(MovingAverageFilter &filter);

float updateFilter(
    MovingAverageFilter &filter,float newValue);

#endif