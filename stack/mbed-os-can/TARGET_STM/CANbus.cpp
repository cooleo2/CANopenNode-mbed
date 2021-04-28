#include "CANbus.h"
#if defined(TARGET_STM32F0)
#include "stm32f0xx_hal_can.h"
#elif defined(TARGET_STM32L4)
#include "stm32l4xx_hal_can_legacy.h" //note: use legacy HAL for this chip-family in mbed-os
/**
 * From DS11585
 * ------------
 * The two CANs are compliant with the 2.0A and B (active) specifications with 
 * a bit rate up to 1Mbit/s. They can receive and transmit standard frames with 
 * 11-bit identifiers as well as extended frames with 29-bit identifiers. 
 * Each CAN has three transmit mailboxes, two receive FIFOS with 3 stages and 
 * 28 shared scalable filter banks (all of them can be used even if one CAN 
 * is used). 256 bytes of SRAM are allocated for each CAN.
*/
#else
#error "CANOpenNode target unsupported! \n"
#endif

CANbus::CANbus(PinName rd, PinName td) :
    mbed::CAN(rd, td)
{
}

CANbus::CANbus(PinName rd, PinName td, int hz) :
    mbed::CAN(rd, td, hz)
{
}

void CANbus::clearSendingMessages()
{
    lock();
    if(!(__HAL_CAN_TRANSMIT_STATUS(&_can.CanHandle, CAN_TXMAILBOX_0)))
        __HAL_CAN_CANCEL_TRANSMIT(&_can.CanHandle, CAN_TXMAILBOX_0);
    if(!(__HAL_CAN_TRANSMIT_STATUS(&_can.CanHandle, CAN_TXMAILBOX_1)))
        __HAL_CAN_CANCEL_TRANSMIT(&_can.CanHandle, CAN_TXMAILBOX_1);
    if(!(__HAL_CAN_TRANSMIT_STATUS(&_can.CanHandle, CAN_TXMAILBOX_2)))
        __HAL_CAN_CANCEL_TRANSMIT(&_can.CanHandle, CAN_TXMAILBOX_2);
    unlock();
}

bool CANbus::rxOverrunFlagSet()
{
    bool fifo0 = (bool) __HAL_CAN_GET_FLAG(&_can.CanHandle, CAN_FLAG_FOV0);
    bool fifo1 = (bool) __HAL_CAN_GET_FLAG(&_can.CanHandle, CAN_FLAG_FOV1);
    return (fifo0 || fifo1 ? true : false);
}

int CANbus::read_Nonblocking(mbed::CANMessage &msg, int handle)
{
    return can_read(&_can, &msg, handle);
}


int CANbus::write_Nonblocking(mbed::CANMessage &msg)
{
    return can_write(&_can, msg, 0);
}