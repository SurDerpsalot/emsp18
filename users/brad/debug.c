////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our debugging function implementations.
////////////////////////////////////////////////////////////////////////////////

#include "debug.h"
#include "system_config.h"
#include "system_definitions.h"

void dbgOutputVal(unsigned int outVal){
    PLIB_PORTS_Toggle(PORTS_ID_0, PORT_CHANNEL_B, 0x8000);
    if(outVal > MAX_VAL){
        PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_B, 0x7F00);
    }
    else{
        PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_B, (0x0000 | outVal) << 8, 0x7f00);
    }
}

void dbgUARTVal(unsigned char outVal){
    
    //UART information
}

void dbgOutputLoc(unsigned int outVal){
    PLIB_PORTS_Toggle(PORTS_ID_0, PORT_CHANNEL_E, 0x80);
    if(outVal > MAX_VAL){
        PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_E, 0x7F);
    }
    else{
        PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_E, (0x00 | outVal), 0x7f);
    }
}

void dbgStopAll(unsigned int outVal){
    //PORTA = 0x0200;
    dbgOutputLoc(outVal);
    PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_B, 0xFF00);
    PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_B, 0xAA00 , 0xFF00);
    while(1){
        PLIB_PORTS_Toggle(PORTS_ID_0, PORT_CHANNEL_B, 0xFF00);
    }//other code to halt functionality
}