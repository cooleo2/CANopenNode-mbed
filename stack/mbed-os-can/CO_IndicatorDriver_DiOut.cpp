#include "CO_IndicatorDriver_DiOut.h"

#if MBED_CONF_CANOPENNODE_USE_CO_IND_DIGOUT
    //in case there is a separate output pin for the leds, define here the outputs
    static CO_IndicatorDriver_DiOut co_ind_driver_digitalOuts(MBED_CONF_CANOPENNODE_RUN_LED, MBED_CONF_CANOPENNODE_ERROR_LED);
    CO_IndicatorDriver* co_ind_driver = &co_ind_driver_digitalOuts;
#endif

CO_IndicatorDriver_DiOut::CO_IndicatorDriver_DiOut(PinName pinRunLed, PinName pinErrorLed) :
    runLed(pinRunLed, 0),
    errorLed(pinErrorLed, 0)
{
}

CO_IndicatorDriver_DiOut::~CO_IndicatorDriver_DiOut()
{
}

void CO_IndicatorDriver_DiOut::setRunLed(CO_LedState_t state)
{
    if ( runLed.is_connected()) // => if pin is not NC
        runLed.write(state); 
}

void CO_IndicatorDriver_DiOut::setErrorLed(CO_LedState_t state)
{
    if ( errorLed.is_connected()) // => if pin is not NC
        errorLed.write(state);
}

void CO_IndicatorDriver_DiOut::resetLeds()
{
    setRunLed(CO_LEDSTATE_OFF);
    setErrorLed(CO_LEDSTATE_OFF);
}