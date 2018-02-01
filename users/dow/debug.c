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
    PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_7);
    if(outVal > MAX_VAL){
        PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2);
        PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_9);
        PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_13);
        PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_1);
        PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_13);
        PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_14);
        PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_9);
    }
    else{
        PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_9,((outVal&0x40)>>6));
        PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_13,((outVal&0x20)>>5));
        PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2,((outVal&0x10)>>4));
        PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_13,((outVal&0x08)>>3));
        PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_1,((outVal&0x04)>>2));
         PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_9, ((outVal&0x02)>>1));
        PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_14,(outVal&0x01));
       
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
        PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_E, 0x7f);
        PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_E, (outVal), 0x7f);
    }
}

void dbgStopAll(unsigned int outVal){
    //PORTA = 0x0200;
    dbgOutputLoc(outVal);
    while(1){
        dbgOutputVal(FAILURE);
    }//other code to halt functionality
}