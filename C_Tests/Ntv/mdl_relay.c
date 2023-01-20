#include <stdint.h>
#include "mdl_relay.h"
#include "mdl_do.h"

#if (DO_index_NUMBER != DI_index_NUMBER)
#error "Number of inputs not equal to number of outputs. Each relay must have 1 input and 1 output!"
#endif

static void ReportError(int error);

// typedef struct Relay_Type
// {
//     uint32_t input;
//     uint32_t output;
// } Relay_Type;

// static Relay_Type relays[DO_index_NUMBER];
static DO_state_E relay_output[DO_index_NUMBER];

void Relay_Init(void)
{
    for (uint_fast8_t i = 0u; i < DO_index_NUMBER; i++)
    {
        relay_output[i] = 0u;
    }
}

/*
Requirement assumption: Set all relays to safe state DO_state_OFF
*/
void Relay_Deinit(void)
{
}

void Relay_Main(void)
{
}

/*
Requirement: Controls (opens or closes) the relay over the digital output of the system.
*/
void DO_setOutputState(DO_index_E index, DO_state_E state)
{
    if (index < DO_index_NUMBER)
    {
        if (state < DO_state_NUMBER)
        {
            relay_output[index] = state;
        }
        else
        {
            ReportError(1);
        }
    }
    else
    {
        ReportError(2);
    }
}

static void ReportError(int error)
{
}