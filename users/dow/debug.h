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
#define WHILE_ENTER 0
#define TASK_ENTER 1
#define TQ_PRE_SEND 2
#define TQ_PRE_REC 3
#define TQ_POS_SEND 4
#define TQ_POS_REC 5
#define TASK_EXIT 6
#define ISR_ENTER 7
#define IQ_PRE_SEND 8
#define IQ_PRE_REC 9
#define IQ_POS_SEND 10
#define IQ_POS_REC 11
#define ISR_EXIT 12


////////////////////////////////////////////////////////////////////////////////
// FUNCTIONs
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Function:    dbgOutputVal(unsigned int outVal)
// Inputs:      Expects an outVal <= 127 that will be written to 7 pins of an 
// IO port(PORTXXXX)
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
// IO port(PORTXXXY) -- a different port than dbgOutputVal
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
// entire program and blinks an LED (LEDX). Additionally, calls dbgOutputLoc for
// directed debugging.
////////////////////////////////////////////////////////////////////////////////

void dbgStopAll(unsigned int outVal);