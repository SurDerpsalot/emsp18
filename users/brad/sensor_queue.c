////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our implementation for interacting with 
//the FreeRTOS queue system
////////////////////////////////////////////////////////////////////////////////

#include "sensor_queue.h"

int queueInit(QueueHandle_t * handle, int queueSize, int itemSize){
    *handle = xQueueCreate(queueSize, itemSize);
    
    if(*handle == NULL){
        return -1;
    }
    
    return 0;
}

//Adds an item to the end of the Queue
int queueSend(QueueHandle_t queue, unsigned int * itemSent){
    if(xQueueSendToBack(queue, itemSent, QUEUE_WAIT) != pdTRUE){
        return -1;
    }
    
    return 0;
}

//Retrieves an item from the beginning of the Queue
int queueReceive(QueueHandle_t queue, unsigned int * itemRec){
    if(xQueueReceive(queue, itemRec, QUEUE_WAIT) != pdTRUE){
        return -1;
    }
    
    return 0;
}


void queueDestroy(QueueHandle_t queue){
    vQueueDelete(queue);
}