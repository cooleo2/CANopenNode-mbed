#include "CO_Indicators.h"
#include "CANopen.h"


void CO_Indicators_process(void* nmtPtr)
{
    CO_NMT_t* nmt = (CO_NMT_t*)nmtPtr;

    if(LED_GREEN_RUN(nmt)){
        co_ind_driver->setRunLed(CO_LEDSTATE_ON);
    }
    else{
        co_ind_driver->setRunLed(CO_LEDSTATE_OFF);
    }

    if(LED_RED_ERROR(nmt))
        co_ind_driver->setErrorLed(CO_LEDSTATE_ON);
    else
        co_ind_driver->setErrorLed(CO_LEDSTATE_OFF);  
}