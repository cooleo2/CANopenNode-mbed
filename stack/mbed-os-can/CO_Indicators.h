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

void setRunLed(CO_LedState_t state);
void setErrorLed(CO_LedState_t state);
void resetLeds();
void CO_Indicators_process(void* nmtPtr);

#endif //CO_INDICATORS_H