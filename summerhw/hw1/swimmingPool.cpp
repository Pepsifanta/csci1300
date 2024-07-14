#include "swimmingPool.h"
#include <iostream>
using namespace std;
// function to set the length, width, depth, waterFlowInRate, waterFlowOutRate and amountOfWaterInPool
swimmingPool::swimmingPool(double l, double w, double d, double fi, double fo, double wInPool)
{
this->length = l;
this->width = w;
this->depth = d;
this->waterFlowInRate = fi;
this->waterFlowOutRate = fo;
this->amountOfWaterInPool = wInPool;
}

void swimmingPool:: set(double l, double w, double d ,
double fi, double fo , double wInPool)
{
    length = l; // feet
    width = w; // feet
    depth = d; // feet
    waterFlowInRate = fi; // gallons per minute
    waterFlowOutRate = fo; // gallons per minute
    amountOfWaterInPool= wInPool; // in gallons
}
// function to set the length
void swimmingPool:: setLength(double l)
{
    length = l;
}
// function to set the width
void swimmingPool:: setWidth(double w)
{
    width = w;
}
// function to set the depth
void swimmingPool:: setDepth(double d)
{
    depth = d;
}
// function to set waterFlowInRate
void swimmingPool:: setWaterFlowRateIn(double fi)
{
    waterFlowInRate = fi;
}
// function to set waterFlowOutRate
void swimmingPool:: setWaterFlowRateOut(double fo)
{
    waterFlowOutRate = fo;
}
// function to add water to the pool
void swimmingPool:: addWater(double time, double fillRate)
{
    // calculate the amount of water to add in gallons
    double waterToAdd = time*fillRate*GALLONS_IN_A_CUBIC_FEET;
    // check if adding the water will cause overflow, then display message and set amountOfWaterInPool to pool capacity
    if((amountOfWaterInPool+waterToAdd) > poolTotalWaterCapacity()){
    cout<<"Pool overflow"<<endl;
    amountOfWaterInPool = poolTotalWaterCapacity();
    }
    else
    amountOfWaterInPool += waterToAdd; // else add that amount of water to pool
}
// function to drain water from the pool

void swimmingPool:: drainWater(double time, double drainRate)
{
    // calculate the amount of water to drain in gallons
    double waterToDrain = time*drainRate*GALLONS_IN_A_CUBIC_FEET;
    amountOfWaterInPool -= waterToDrain; // subtract that amount from current amount of water in pool
    // if negative, set it to 0
    if(amountOfWaterInPool <= 0)
    {
    amountOfWaterInPool = 0;
    }
    else{
        amountOfWaterInPool-=waterToDrain;
    }
}
// function to calculate and return the total capacity of pool in gallons
double swimmingPool:: poolTotalWaterCapacity()
{
    return(length*width*depth*GALLONS_IN_A_CUBIC_FEET);
}
// function to return the length
double swimmingPool:: getLength()
{
    return length;
}
// function to return the width
double swimmingPool:: getWidth()
{
    return width;
}
// function to return the depth
double swimmingPool:: getDepth()
{
    return depth;
}
// function to return the waterFlowInRate
double swimmingPool:: getWaterFlowRateIn()
{
    return waterFlowInRate;
}
// function to return the waterFlowOutRate
double swimmingPool:: getWaterFlowRateOut()
{
    return waterFlowOutRate;
}
// function to return the amount of water in pool
double swimmingPool:: getTotalWaterInPool()
{
    return amountOfWaterInPool;
}
// function to calculate the time to completely fill the pool (in minutes)
int swimmingPool:: timeToFillThePool()
{
    double remainingWater = waterNeededToFillThePool(); // get the total amount of water that can be added to the pool
    
    if(waterFlowInRate > 0)
    return remainingWater/waterFlowInRate;
    return 0; 
}

int swimmingPool:: timeToDrainThePool()
{
    if(waterFlowOutRate > 0) 
    return amountOfWaterInPool/waterFlowOutRate;
    return 0; 
}

double swimmingPool:: waterNeededToFillThePool()
{
    return(poolTotalWaterCapacity()-amountOfWaterInPool);
}

