////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our sensor state machine and manipulation
// implementation.
////////////////////////////////////////////////////////////////////////////////

#include "sensor_state.h"

unsigned int sensorAvgFSM(unsigned int inVal, unsigned int inVal2){
    static ACQ_STATE state = ACQ1;
    unsigned int value = 0;
    switch(state){
        case ACQ1:
            value = 40;
            //dbgOutputVal(inVal);
            //dbgOutputLoc(inVal2);
            state = ACQ2;
            break;
        case ACQ2:
            value = 60;
          //  dbgOutputVal(inVal);
            //dbgOutputLoc(inVal2);
            state = ACQ3;
            break;
        case ACQ3:
            value = 80;
           // dbgOutputVal(inVal);
            //dbgOutputLoc(inVal2);
            state = ACQ4;
            break;
        case ACQ4:
            value = 100;
            //dbgOutputVal(inVal);
            //dbgOutputLoc(inVal2);
            state = ACQ1;
            break;
        default:
            dbgStopAll(1); //change hardcode to output LOC macro
            break;
    }
    return value;
}