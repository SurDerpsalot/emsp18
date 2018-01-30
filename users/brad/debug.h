////////////////////////////////////////////////////////////////////////////////
// Embedded Team 18
// Author(s):   Dow Perkins, Brad Finagin
// Date:        1/25/18
// Description: This file is contains our debugging functions for use throughout
// the rest of our project. See individual function declarations for details on
// specific functions.
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// DEFINEs
////////////////////////////////////////////////////////////////////////////////
#define MAX_VAL 127

#define INVALID_OUT_VAL 0

#define INVALID_OUT_LOC 0
#define WHILE_ENTER 1
#define TASK_ENTER 2
#define TQ_PRE_SEND 3
#define TQ_PRE_REC 4
#define TQ_POS_SEND 5
#define TQ_POS_REC 6
#define TASK_EXIT 7
#define ISR_ENTER 8
#define IQ_PRE_SEND 9
#define IQ_PRE_REC 10
#define IQ_POS_SEND 11
#define IQ_POS_REC 12
#define ISR_EXIT 13
#define QUEUE_INIT 14
#define TASK_INIT 15
#define QUEUE_SEND_FAILURE 16
#define FAILURE 126

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONs
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Function:    dbgOutputVal(unsigned int outVal)
// Inputs:      Expects an outVal <= 127 that will be written to 7 pins of an 
// IO port(PORTB)
// Outputs:     Not applicable
// Description: Generates an output value on an IO port for debugging purposes.
// Can be called from anywhere within our code.
////////////////////////////////////////////////////////////////////////////////

void dbgOutputVal(unsigned int outVal);

////////////////////////////////////////////////////////////////////////////////
// Function:    dbgUARTVal(unsigned char outVal)
// Inputs:      Any valid unsigned char value
// Outputs:     Not applicable
// Description: Generates and output value on the UART for debugging purposes. 
// To be called from within the state_machine.
////////////////////////////////////////////////////////////////////////////////

void dbgUARTVal(unsigned char outVal);

////////////////////////////////////////////////////////////////////////////////
// Function:    dbgOutputLoc(unsigned int outVal)
// Inputs:      Expects an outVal <= 127 that will be written to 7 pins of an 
// IO port(PORTE) -- a different port than dbgOutputVal
// Outputs:     Not applicable
// Description: Generates an output value on an IO port for debugging purposes.
// Can be called from anywhere within our code. Input values must be defined
// constants (see top) which specify given locations in the code.
////////////////////////////////////////////////////////////////////////////////

void dbgOutputLoc(unsigned int outVal);

////////////////////////////////////////////////////////////////////////////////
// Function:    dbgStopAll(unsigned int outVal)
// Inputs:      Expects an outVal which reflects return value of various
// functions.
// Outputs:     Not applicable
// Description: Can be called from anywhere within our code. Stops execution for
// entire program and blinks an LED (PORTA - RA9). Additionally, calls 
//dbgOutputLoc for directed debugging.
////////////////////////////////////////////////////////////////////////////////

void dbgStopAll(unsigned int outVal);