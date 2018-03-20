//usart.h

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "system_config.h"
#include "system_definitions.h"

void initUSART();

void sendByte(char byte);

void sendString(char * str);

void receiveByte(char * rec);