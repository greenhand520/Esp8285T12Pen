//
// Created by mdmbct on 10/1/22.
//

#include "TempCtrler.h"

TempCtrler::TempCtrler(uint8_t _pwmPin) {
    this->pwmPin = _pwmPin;
    pinMode(pwmPin, OUTPUT);
}

void TempCtrler::stopHeat() {
    digitalWrite(pwmPin, 0);
}
