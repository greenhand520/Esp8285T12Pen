//
// Created by mdmbct on 10/1/22.
//

#include "TempCtrler.h"

TempCtrler::TempCtrler(uint8_t pwmPin, bool _isPMOS) {
    this->pwmPin = pwmPin;
    pinMode(pwmPin, OUTPUT);
    this->isPMOS = _isPMOS;
}

void TempCtrler::stopHeat() const {
    if (isPMOS) {
        digitalWrite(pwmPin, HIGH);
    } else {
        digitalWrite(pwmPin, LOW);
    }
}

void TempCtrler::heat(uint16_t *temps, uint8_t count) {
    // todo: PID调温
    uint16_t pwmOut = 0;
    if (isPMOS) {
        digitalWrite(pwmPin, 255 - pwmOut);
    } else {
        digitalWrite(pwmPin, pwmOut);
    }
}

uint16_t TempCtrler::getAvgTemp() {
    return avgTemp;
}

