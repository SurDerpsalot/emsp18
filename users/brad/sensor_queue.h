////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our API for interacting with the FreeRTOS
// queue system
////////////////////////////////////////////////////////////////////////////////
#include "FreeRTOS.h"
#include "queue.h"
struct Encoders{
    unsigned int encoder1;
    unsigned int encoder2;
};
/* Define the queue parameters. */
#define QUEUE_LENGTH 16
#define QUEUE_ITEM_SIZE sizeof( unsigned int )

////////////////////////////////////////////////////////////////////////////////
// DEFINEs
////////////////////////////////////////////////////////////////////////////////

#define QUEUE_WAIT 25

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONs
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Function:    queueInit(QueueHandle_t * handle, int queueSize, int itemSize)
// Inputs:      expects two ints, one is the queue size in words, one is the 
// item size in bytes, and handle pointer
// Outputs:     Integer containing error value. 0 on success.
// Description: Creates a FreeRTOS queue using the API functions provided.
////////////////////////////////////////////////////////////////////////////////

QueueHandle_t queueInit(UBaseType_t queueSize, UBaseType_t itemSize);

////////////////////////////////////////////////////////////////////////////////
// Function:    queueSend(QueueHandle_t queue, unsigned int * itemSent)
// Inputs:      Expects handle to queue to send to, and the item to send
// Outputs:     Integer containing error value. 0 on success.
// Description: Sends a value to the FreeRTOS queue using the API functions
// provided.
////////////////////////////////////////////////////////////////////////////////

int queueSend(QueueHandle_t queue, struct Encoders  itemSent, BaseType_t * check);
////////////////////////////////////////////////////////////////////////////////
// Function:    queueReceive(QueueHandle_t queue, unsigned int * itemRec)
// Inputs:      Expects the handle of the queue to receive from and a pointer to
// the value received.
// Outputs:     Integer containing error value. 0 on success.
// Description: Receives a value from the FreeRTOS queue using the API functions
// provided.
////////////////////////////////////////////////////////////////////////////////

int queueReceive(QueueHandle_t queue, struct Encoders * itemRec);

////////////////////////////////////////////////////////////////////////////////
// Function:    queueDestroy(QueueHandle_t queue);
// Inputs:      Expects the handle of the queue to destroy
// Outputs:     N/A
// Description: Destroys a FreeRTOS queue using the API functions provided
////////////////////////////////////////////////////////////////////////////////

void queueDestroy(QueueHandle_t queue);
