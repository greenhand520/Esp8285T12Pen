//
// 温度控制
// Created by mdmbct on 10/1/22.
//

#ifndef ESPHEAT_TEMPREG_H
#define ESPHEAT_TEMPREG_H

#include <Arduino.h>

class TempCtrler {
private:
    uint8_t pwmPin;

public:

    TempCtrler(uint8_t _pwmPin);

    void stopHeat();
};

#endif //ESPHEAT_TEMPREG_H
