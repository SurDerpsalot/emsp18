////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our sensor state machine and manipulation
// implementation.
////////////////////////////////////////////////////////////////////////////////

#include "sensor_state.h"

void sensorAvgFSM(unsigned int inVal){
    static ACQ_STATE state = ACQ1;
    static unsigned int value = 0;
    
    switch(state){
        case ACQ1:
            value = inVal;
            dbgOutputVal(inVal);
            state = ACQ2;
            break;
        case ACQ2:
            value = value + inVal;
            dbgOutputVal(inVal);
            state = ACQ3;
            break;
        case ACQ3:
            value = value + inVal;
            dbgOutputVal(inVal);
            state = ACQ4;
            break;
        case ACQ4:
            value = value + inVal;
            value = value / 4;
            dbgOutputVal(inVal);
            dbgUARTVal((unsigned char)value);
            value = 0;
            state = ACQ1;
            break;
        default:
            dbgStopAll(1); //change hardcode to output LOC macro
            break;
    }
}