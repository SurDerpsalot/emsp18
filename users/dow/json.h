//json.h

#include <stdio.h>
#include <string.h>

#define ERROR_KEY "err_key"
#define ERROR_DEF "err_default"
#define ERROR_SYN "err_syntax"
#define ERROR_KLE "err_keylength"
#define ERROR_DAT "err_datalength"
#define ERROR_UNF "err_unformed"

typedef struct {
    char key[16];
    char value[48];
    int unf;
} JSON;

typedef enum {PARSE_INIT, PARSE_BEGIN, PARSE_KEY, PARSE_COLON, PARSE_CLOSE_K 
				PARSE_VALUE, PARSE_END, PARSE_DONE, PARSE_ERROR} PARSE_STATE;

void parse(JSON * j, char * str);
void createJSON(JSON * j, char * key, char * value);
void printJSON(JSON j);
int valueToInt(char * value);
double valueToDouble(char * value);