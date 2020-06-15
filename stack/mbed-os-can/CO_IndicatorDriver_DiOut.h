#ifndef CO_INDICATORDRIVER_DIOUT_H
#define CO_INDICATORDRIVER_DIOUT_H

#include "CO_Indicators.h"
#include "DigitalOut.h"

/**
 * Implementation of CO_IndicatorDriver which uses
 * mbed::DigitalOut to drive the LED's
 */ 
class CO_IndicatorDriver_DiOut : public CO_IndicatorDriver
{
public:
    CO_IndicatorDriver_DiOut(PinName pinRunLed, PinName pinErrorLed);
    virtual ~CO_IndicatorDriver_DiOut();
    void setRunLed(CO_LedState_t state); //override
    void setErrorLed(CO_LedState_t state); //override
    void resetLeds(); //override
private:
    mbed::DigitalOut runLed;
    mbed::DigitalOut errorLed;
};

#endif //CO_INDICATORDRIVER_DIOUT_H