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

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/


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
    UBaseType_t qSize = 1;
    UBaseType_t qLength = 20;
    messageQueue = queueInit(qSize, qLength);
    if(messageQueue == NULL)
    {
        dbgStopAll(QUEUE_INIT);
    }
   DRV_OC0_PulseWidthSet(480);
   DRV_OC1_PulseWidthSet(480);
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
int i=0;
void APP_Tasks ( void )
{
    //799 is top
    //
    //460 is 10%
   unsigned int motorSpeed = 50;
   struct Encoders Values;
   unsigned int rps1= 0;
   unsigned int rps2=0;
   while(1) {
   
     /*if(uxQueueMessagesWaiting( messageQueue )){
         queueReceive(messageQueue, &Values);
         rps1 = Values.encoder1;
         rps2 = Values.encoder2;
         dbgOutputLoc(5);
         dbgOutputLoc(rps1);
         dbgOutputLoc(15);
         dbgOutputLoc(rps2);
         dbgOutputLoc(5);
     }*/
       
     if(i < 1500000){
        i++;
    }
    else if(i < 3000000 && i > 1499999){
        i++;
        setMotor(motorSpeed,0,1);
        setMotor(motorSpeed,0,0);
    }
    else if(i < 4500000 && i > 2999999){
        i++;
        setMotor((motorSpeed+20),1,1);
        setMotor((motorSpeed+20),1,0);
    }
    else if(i < 6000000 && i > 4499999){
        i++;
        setMotor((motorSpeed),0,1);
        setMotor((motorSpeed),1,0);
    }
    else if(i < 7500000 && i > 5999999){
        i++;
        setMotor((motorSpeed+20),1,1);
        setMotor((motorSpeed+20),0,0);
    }
    else{
        motorSpeed = motorSpeed + 30;
        if(motorSpeed == 80){
           dbgOutputLoc(100);
       }
        if(motorSpeed == 110){
            motorSpeed = 50;
        }
        i = 0;
    }
     
   }
}

 

/*******************************************************************************
 End of File
 */
