//message.c

#include "message.h"

void createMessage(MESSAGE * msg, MSG_TYPE mType, char * payload){
    msg->start = 0x8F;
    unsigned char temp;
    int i;
    switch(mType){
        case MSG_POST:
            temp = 0x01;
            break;
        case MSG_REPL:
            temp = 0x02;
            break;
        case MSG_ACKN:
            temp = 0x04;
            break;
        case MSG_NACK:
            temp = 0x08;
            break;
        default:
            temp = 0xFF;
            break;
    }
    
    msg->type = temp;
    msg->seq = (unsigned char)strlen(payload);
    msg->sot = 0x02;
    //for loop for payload
    for(i = 0; i < strlen(payload); i++){
        msg->payload[i] = payload[i];
    }
    msg->eot = 0x03;
    msg->check = checkSum(payload);
    msg->end = 0xCF;
}

void sendMessage(MESSAGE msg){
    int i;
    while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1));
    PLIB_USART_TransmitterByteSend(USART_ID_1, msg.start);
    
    while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1));
    PLIB_USART_TransmitterByteSend(USART_ID_1, msg.type);
    
    while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1));
    PLIB_USART_TransmitterByteSend(USART_ID_1, msg.seq);
    
    while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1));
    PLIB_USART_TransmitterByteSend(USART_ID_1, msg.sot);
    
    while(i < strlen(msg.payload)){
        if(!PLIB_USART_TransmitterBufferIsFull(USART_ID_1)){
            PLIB_USART_TransmitterByteSend(USART_ID_1, msg.payload[i]);
            i++;
        }
    }
    
    while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1));
    PLIB_USART_TransmitterByteSend(USART_ID_1, msg.eot);
    
    while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1));
    PLIB_USART_TransmitterByteSend(USART_ID_1, msg.check);
    
    while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1));
    PLIB_USART_TransmitterByteSend(USART_ID_1, msg.end);
}

void receiveMessage(char * buffer, char byte, int * iter, int clear){
	//
}

unsigned char checkSum(char * str){
    int i = 0;
    unsigned char sum = 0x00;
    for(i = 0; i < strlen(str); i++){
        sum = sum ^ str[i];
    }
    
    return sum;
}

int messageCompare(MESSAGE msg1, MESSAGE msg2){
    if(msg1.start != msg2.start){
        return -1;
    }
    else if(msg1.type != msg2.type){
        return -1;
    }
    else if(msg1.seq != msg2.seq){
        return -1;
    }
    else if(msg1.sot != msg2.sot){
        return -1;
    }
    else if(strcmp(msg1.payload, msg2.payload) != 0){
        return -1;
    }
    else if(msg1.eot != msg2.eot){
        return -1;
    }
    else if(msg1.check != msg2.check){
        return -1;
    }
    else{
        return 0;
    }
    
}