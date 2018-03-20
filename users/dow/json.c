//json.c
#include "json.h"

void parse(JSON * j, char * str){
	int i = 0;
	int key_count = 0;
	int data_count = 0;
	char key[16] = "";
	char value[48] = "";
	PARSE_STATE state = PARSE_INIT;
	while(i < strlen(str)){
		switch(state){
			case PARSE_INIT:
				if(str[i] == '{'){
					state = PARSE_BEGIN;
				}
				else{
					createJSON(j, ERROR_KEY, ERROR_SYN);
					j->unf = 1;
					state = PARSE_ERROR;
				}
				break;
			case PARSE_BEGIN:
				if(str[i] == '"'){
					state = PARSE_KEY;
				}
				else{
					createJSON(j, ERROR_KEY, ERROR_SYN);
					j->unf = 1;
					state = PARSE_ERROR;
				}
				break;
			case PARSE_KEY:
				if(str[i] == '"'){
					state = PARSE_CLOSE_K;
				}
				else if(((str[i] >= 0x30) && (str[i] <= 0x39)) || 
						((str[i] >= 0x41) && (str[i] <= 0x5A)) || 
						((str[i] >= 0x61) && (str[i] <= 0x7A))){
					if(key_count > 15){
						createJSON(j, ERROR_KEY, ERROR_KLE);
						j->unf = 1;
						state = PARSE_ERROR;
					}
					else{
						key[key_count] = str[i];
						key_count++;
					}
				}
				else{
					createJSON(j, ERROR_KEY, ERROR_SYN);
					j->unf = 1;
					state = PARSE_ERROR;
				}
				break;
			case PARSE_CLOSE_K:
				if(str[i] == ':'){
					state = PARSE_COLON;
				}
				else{
					createJSON(j, ERROR_KEY, ERROR_SYN);
					j->unf = 1;
					state = PARSE_ERROR;
				}
				break;
			case PARSE_COLON:
				if(str[i] == '"'){
					state = PARSE_VALUE;
				}
				else{
					createJSON(j, ERROR_KEY, ERROR_SYN);
					j->unf = 1;
					state = PARSE_ERROR;
				}
				break;
			case PARSE_VALUE:
				if(str[i] == '"'){
					state = PARSE_END;
				}
				else if(((str[i] >= 0x30) && (str[i] <= 0x39)) || 
						((str[i] >= 0x41) && (str[i] <= 0x5A)) || 
						((str[i] >= 0x61) && (str[i] <= 0x7A)) ||
						(str[i] == 0x2E)){
					if(data_count > 47){
						createJSON(j, ERROR_KEY, ERROR_DAT);
						j->unf = 1;
						state = PARSE_ERROR;
					}
					else{
						value[data_count] = str[i];
					}
				}
				else{
					createJSON(j, ERROR_KEY, ERROR_SYN);
					j->unf = 1;
					state = PARSE_ERROR;
				}
				break;
			case PARSE_END:
				if(str[i] == '}'){
					createJSON(j, key, value);
					j->unf = 1;
					state = PARSE_DONE;
				}
				else{
					createJSON(j, ERROR_KEY, ERROR_SYN);
					j->unf = 1;
					state = PARSE_ERROR;
				}
				break;
			case PARSE_DONE:
				return;
			case PARSE_ERROR:
				return;
			default:
				createJSON(j, ERROR_KEY, ERROR_DEF);
				j->unf = 1;
				state = PARSE_ERROR;
				break;
		}
		i++;
	}

	if((j->unf == 0) || ((strlen(j->key) == 0) && (strlen(j->value) == 0))){
		createJSON(j, ERROR_KEY, ERROR_UNF);
		return;
	}
}

void createJSON(JSON * j, char * key, char * value){
	int i;
	int k;
	for(i = 0; i <= strlen(key); i++){
		j->key[i] = key[i];
	}
	for(k = 0; k <= strlen(value); k++){
		j->value[k] = value[k];
	}
}

void printJSON(JSON j){
	printf("JSON received: %s:%s\n", j.key, j.value);
}

int valueToInt(char * value){
	int retval = -1;

	if(sscanf(value, "%d", &retval) == 0){
		return -1;
	}
	else{
		return retval;
	}
}

double valueToDouble(char * value){
	float retval = -1.0;

	if(sscanf(value, "%f", &retval) == 0){
		return -1.0;
	}
	else{
		return (double)retval;
	}
}