#include "CO_Indicators.h"
<<<<<<< HEAD
#include "CANopen.h"

=======
#include "mbed.h"
#include "CANopen.h"

//in case there is a separate output pin for the leds, define here the outputs
static DigitalOut runLed(MBED_CONF_CANOPENNODE_RUN_LED, 0);
static DigitalOut errorLed(MBED_CONF_CANOPENNODE_ERROR_LED, 0);

void setRunLed(CO_LedState_t state)
{
    if ( runLed.is_connected()) // => if pin is not NC
        runLed.write(state);
}

void setErrorLed(CO_LedState_t state)
{
    if ( errorLed.is_connected()){
        // => if pin is not NC
        errorLed.write(state);
    }       
}

void resetLeds()
{
    setRunLed(CO_LEDSTATE_OFF);
    setErrorLed(CO_LEDSTATE_OFF);
}
>>>>>>> origin/mbedSTM32

void CO_Indicators_process(void* nmtPtr)
{
    CO_NMT_t* nmt = (CO_NMT_t*)nmtPtr;

    if(LED_GREEN_RUN(nmt)){
<<<<<<< HEAD
        co_ind_driver->setRunLed(CO_LEDSTATE_ON);
    }
    else{
        co_ind_driver->setRunLed(CO_LEDSTATE_OFF);
=======
        setRunLed(CO_LEDSTATE_ON);
    }
    else{
        setRunLed(CO_LEDSTATE_OFF);
>>>>>>> origin/mbedSTM32
    }

    if(LED_RED_ERROR(nmt))
        co_ind_driver->setErrorLed(CO_LEDSTATE_ON);
    else
<<<<<<< HEAD
        co_ind_driver->setErrorLed(CO_LEDSTATE_OFF);  
=======
        setErrorLed(CO_LEDSTATE_OFF);  
>>>>>>> origin/mbedSTM32
}