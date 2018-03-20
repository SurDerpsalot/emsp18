//usart.c

#include "usart.h"

void initUSART(){
	PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
   PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_USART_1_RECEIVE);
   PLIB_USART_Enable(USART_ID_1);
   PLIB_USART_TransmitterEnable(USART_ID_1);
   PLIB_USART_ReceiverEnable(USART_ID_1);
}

void sendByte(char byte){
	while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1));
   PLIB_USART_TransmitterByteSend(USART_ID_1, byte);
}

void sendString(char * str){
	int i = 0;
	while(i < strlen(msg.payload)){
		if(!PLIB_USART_TransmitterBufferIsFull(USART_ID_1)){
			PLIB_USART_TransmitterByteSend(USART_ID_1, str[i]);
			i++;
		}
	}
}

void receiveByte(char * rec){
	rec = PLIB_USART_ReceiverByteReceive(USART_ID_1);
}