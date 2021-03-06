////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our sensor state machine and manipulation
// functions.
////////////////////////////////////////////////////////////////////////////////

#include "debug.h"

////////////////////////////////////////////////////////////////////////////////
// DEFINEs and TYPEDEFs
////////////////////////////////////////////////////////////////////////////////
typedef enum {ACQ1, ACQ2, ACQ3, ACQ4} ACQ_STATE;

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONs
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Function:    sensorAvgFSM(unsigned int inVal)
// Inputs:      Expects the input value from the sensor
// Outputs:     N/A
// Description: Implements the state machine as described for Milestone One
////////////////////////////////////////////////////////////////////////////////

unsigned int sensorAvgFSM(unsigned int inVal, unsigned int inVal2);