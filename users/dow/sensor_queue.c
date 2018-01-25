////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our implementation for interacting with 
//the FreeRTOS queue system
////////////////////////////////////////////////////////////////////////////////

#include "sensor_queue.h"

QueueHandle_t queueInit(int queueSize, int itemSize){
    QueueHandle_t handle = xQueueCreate(queueSize, itemSize);
    
    if(handle == NULL){
        dbgStopAll(1); //change hardcoded value
    }
}

void queueSend(QueueHandle_t queue, unsigned int itemSent){
    if(xQueueSend(queue, itemSent, 25) != pdTRUE){ //change hardcoded wait time
        dbgStopAll(1); //change hardcoded value
    }
}

unsigned int queueReceive(QueueHandle_t queue){
    unsigned int * valueReceived;
    if(xQueueReceive(queue, valueReceived, 25) != pdTRUE){ //change hardcode
        dbgStopAll(1); //change hardcode
    }
    
    return *valueReceived;
}

void queueDestroy(QueueHandle_t queue){
    vQueueDelete(queue);
}