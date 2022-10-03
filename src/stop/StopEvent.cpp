//
// Created by mdmbct on 10/2/22.
//

#include "StopEvent.h"

uint8_t StopEvent::getInterruptPin() const {
    return interruptPin;
}

uint8_t StopEvent::getInterruptMode() const {
    return interruptMode;
}

void StopEvent::init(uint8_t _interruptPin, uint8_t _interruptMode) {
    this->interruptPin = _interruptPin;
    this->interruptMode = _interruptMode;
    pinMode(interruptPin, INPUT_PULLUP);
}

bool StopEvent::isStop() const {
    return stopFlag;
}




