#ifndef CO_INDICATORS_H
#define CO_INDICATORS_H

#include <stddef.h>         /* for 'NULL' */
#include <stdint.h>         /* for 'int8_t' to 'uint64_t' */
#include <stdbool.h>        /* for 'true', 'false' */

typedef enum 
{
    CO_LEDSTATE_OFF = 0,
    CO_LEDSTATE_ON  = 1
} CO_LedState_t;

/**
 * Pure abstract c++ class which acts as API interface for 
 * setting CANopen status/error LEDs. The abstraction
 * allows for used defined implementations, for example
 * we could set LEDs directly through GPIO's, or in 
 * some other cases there may be LED controller in use.
 */ 
class CO_IndicatorDriver
{
public:
    virtual void setRunLed(CO_LedState_t state) = 0;
    virtual void setErrorLed(CO_LedState_t state) = 0;
    virtual void resetLeds() = 0;
};

// global pointer to canopen LED driver implementation
extern CO_IndicatorDriver* co_ind_driver;

void CO_Indicators_process(void* nmtPtr);

#endif //CO_INDICATORS_H