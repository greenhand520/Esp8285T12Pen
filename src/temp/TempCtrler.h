//
// 温度控制
// Created by mdmbct on 10/1/22.
//

#ifndef ARDUINOESPHEATFARMWORK_TEMPREG_H
#define ARDUINOESPHEATFARMWORK_TEMPREG_H

#include <Arduino.h>

class TempCtrler {
private:
    uint8_t pwmPin;

public:
    void init(uint8_t _pwmPin);

    void stopHeat();
};

#endif //ARDUINOESPHEATFARMWORK_TEMPREG_H
