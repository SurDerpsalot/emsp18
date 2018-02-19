////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our implementation for interacting with 
//the FreeRTOS queue system
////////////////////////////////////////////////////////////////////////////////

#include "sensor_queue.h"
#include "debug.h"




QueueHandle_t queueInit(UBaseType_t queueSize, UBaseType_t itemSize){
    
   // PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_E, 0x55, 0xff);
   // dbgOutputLoc(TASK_EXIT);
    return xQueueCreate(queueSize, itemSize);
}

//Adds an item to the end of the Queue
int queueSend(QueueHandle_t queue, struct Encoders itemSent, BaseType_t * check){
   // dbgOutputLoc(QUEUE_SEND_ENTER);
    xQueueSendToBackFromISR(queue, &itemSent, check);
   // dbgOutputLoc(QUEUE_SEND_EXIT);
    return 0;
}

//Retrieves an item from the beginning of the Queue
int queueReceive(QueueHandle_t queue, struct Encoders * itemRec){
    
   // while(uxQueueMessagesWaiting(queue) == 0){}
    //dbgOutputLoc(QUEUE_RECEIVE_ENTER);
        if(xQueueReceive(queue, itemRec, portMAX_DELAY)==pdPASS){
            return 0;
        }
    //dbgOutputLoc(QUEUE_RECEIVE_EXIT);
    
    return 1;
}
