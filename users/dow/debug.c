////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our debugging function implementations.
////////////////////////////////////////////////////////////////////////////////

#include "debug.h"

void dbgOutputVal(unsigned int outVal){
    PORTBINV = 0x8000;
    if(outVal > MAX_VAL){
        PORTBCLR = 0x7F00;
    }
    else{
        PORTBSET = (0x0000 | outVal) << 8;
    }
}

void dbgUARTVal(unsigned char outVal){
    //UART information
}

void dbgOutputLoc(unsigned int outVal){
    PORTEINV = 0x80;
    if(outVal > MAX_VAL){
        PORTECLR = 0x7F;
    }
    else{
        PORTESET = 0x00 | outVal;
    }
}

void dbgStopAll(unsigned int outVal){
    PORTA = 0x0200;
    //other code to halt functionality
}