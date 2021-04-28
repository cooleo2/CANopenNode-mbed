#ifndef CO_CANBUS_H
#define CO_CANBUS_H

#include "CAN.h"

class CANbus : public mbed::CAN {

public:
    CANbus(PinName rd, PinName td);
    CANbus(PinName rd, PinName td, int hz);

    void clearSendingMessages();
    bool rxOverrunFlagSet();

    int read_Nonblocking(mbed::CANMessage &msg, int handle = 0);
    /**
     * Write to CAN module without using mutexes.
     * Mbed-os STM API's will automatically look for an empty transmit mailbox.
     * If all mailboxes are occupied the function returns 0.
     * If a mailbox is available it will be used for sending and the function returns 1.
     */
    int write_Nonblocking(mbed::CANMessage &msg);

};

#endif //CO_CANBUS_H