//
// Created by mdmbct on 10/2/22.
//

#include "StopEvent.h"

StopEvent::StopEvent(uint8_t interruptPin, uint8_t interruptMode) {
    pinMode(interruptPin, INPUT_PULLUP);
}


//uint8_t StopEvent::getInterruptPin() const {
//    return interruptPin;
//}
//
//uint8_t StopEvent::getInterruptMode() const {
//    return interruptMode;
//}

bool StopEvent::isStop() const {
    return stopFlag;
}



