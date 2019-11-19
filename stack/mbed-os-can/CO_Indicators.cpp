#include "CO_Indicators.h"
#include "mbed.h"

#include "CANopen.h"


static DigitalOut runLed(MBED_CONF_CANOPENNODE_RUN_LED, 0);
static DigitalOut errorLed(MBED_CONF_CANOPENNODE_ERROR_LED, 0);

void setRunLed(CO_LedState_t state)
{
    runLed.write(state);
}

void setErrorLed(CO_LedState_t state)
{
    errorLed.write(state);
}

void resetLeds()
{
    setRunLed(CO_LEDSTATE_OFF);
    setErrorLed(CO_LEDSTATE_OFF);
}

void CO_Indicators_process(void* nmtPtr)
{
    CO_NMT_t* nmt = (CO_NMT_t*)nmtPtr;

    if(LED_GREEN_RUN(nmt))
        setRunLed(CO_LEDSTATE_ON);
    else
        setRunLed(CO_LEDSTATE_OFF);
    
    if(LED_RED_ERROR(nmt))
        setErrorLed(CO_LEDSTATE_ON);
    else
        setErrorLed(CO_LEDSTATE_OFF);
    
}