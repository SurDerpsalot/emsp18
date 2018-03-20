//message.h

//includes
#include "usart.h"
#include "json.h"

// struct for the custom messages with JSON payload
typedef struct {
    unsigned char start;
    unsigned char type;
    unsigned char seq;
    unsigned char sot;
    char payload[64];
    unsigned char eot;
    unsigned char check;
    unsigned char end;
    
} MESSAGE;

// enums for task states and message types
typedef enum { MSG_POST, MSG_REPL, MSG_ACKN, MSG_NACK} MSG_TYPE;

void createMessage(MESSAGE * msg, MSG_TYPE mType, char * payload);
void sendMessage(MESSAGE msg);
void receiveMessage(char * buffer, char byte, int * iter, int clear);
int parseMessage(char * buffer);
unsigned char checkSum(char * str);
int messageCompare(MESSAGE msg1, MESSAGE msg2);
void resetBuffer(char * buffer);