////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our implementation for interacting with 
//the FreeRTOS queue system
////////////////////////////////////////////////////////////////////////////////

#include "sensor_queue.h"
#include "debug.h"




int queueInit(QueueHandle_t * handle, UBaseType_t queueSize, UBaseType_t itemSize){
    
   // PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_E, 0x55, 0xff);
    handle = xQueueCreate(queueSize, itemSize);
    
    //PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_E, 0xff, 0xff);
    if(*handle == NULL){
        return -1;
    }
    
    return 0;
}

//Adds an item to the end of the Queue
int queueSend(QueueHandle_t queue, unsigned int itemSent, BaseType_t * check){
    dbgOutputLoc(QUEUE_SEND_FAILURE);
    xQueueSendToBackFromISR(queue, &itemSent, 0);
    return 0;
}

//Retrieves an item from the beginning of the Queue
int queueReceive(QueueHandle_t queue, unsigned int * itemRec){
    if(xQueueReceive(queue, itemRec, portMAX_DELAY) != pdTRUE){
        return -1;
    }
    
    return 0;
}


void queueDestroy(QueueHandle_t queue){
    vQueueDelete(queue);
}