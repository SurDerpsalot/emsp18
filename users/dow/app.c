/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

JSON json1;
JSON json2;

MSG_TYPE msg1;
MSG_TYPE msg2;

//extern USART_STATE uState;

QueueHandle_t transmitQueue;
//QueueHandle_t receiveQueue;
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    transmitQueue = xQueueCreate(2, 4);
    PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
    PLIB_USART_Enable(USART_ID_1);
    PLIB_USART_TransmitterEnable(USART_ID_1);
    
    /* Place the App state machine in its initial state. */
    //
    jsonInit(&json1, "key1", "data1");
    jsonInit(&json2, "key2", "data2");
    
    PLIB_USART_TransmitterBreakSend(USART_ID_1);
    PLIB_USART_TransmitterBreakSend(USART_ID_1);
    //uState = USART_WAIT;

    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    /* Check the application's current state. */
    while(1){
        
    }
    
}

void writeString(char * str){
    int i;
    for(i = 0; i < strlen(str); i++){
        if(!PLIB_USART_TransmitterBufferIsFull(USART_ID_1)){
            PLIB_USART_TransmitterByteSend(USART_ID_1, str[i]);
        }
    }
}

void writeJson(JSON msg){
    int i, j;
    if(!PLIB_USART_TransmitterBufferIsFull(USART_ID_1)){
        PLIB_USART_TransmitterByteSend(USART_ID_1, msg.open[0]);
    }
    
    for(i = 0; i < strlen(msg.key); i++){
        if(!PLIB_USART_TransmitterBufferIsFull(USART_ID_1)){
            PLIB_USART_TransmitterByteSend(USART_ID_1, msg.key[i]);
        }
    }
    
    if(!PLIB_USART_TransmitterBufferIsFull(USART_ID_1)){
        PLIB_USART_TransmitterByteSend(USART_ID_1, msg.sep[0]);
    }
    
    for(j = 0; j < strlen(msg.data); j++){
        if(!PLIB_USART_TransmitterBufferIsFull(USART_ID_1)){
            PLIB_USART_TransmitterByteSend(USART_ID_1, msg.data[j]);
        }
    }
    
    if(!PLIB_USART_TransmitterBufferIsFull(USART_ID_1)){
        PLIB_USART_TransmitterByteSend(USART_ID_1, msg.close[0]);
    }
}

void jsonInit(JSON * msg, char * key, char * data){
    msg->open = OPEN;
    msg->close = CLOSE;
    msg->sep = SEP;
    msg->key = key;
    msg->data = data;
}
/*******************************************************************************
 End of File
 */
