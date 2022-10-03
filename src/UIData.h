//
// Created by mdmbct on 10/1/22.
//

#ifndef ARDUINOESPHEATFARMWORK_UIDATA_H
#define ARDUINOESPHEATFARMWORK_UIDATA_H

#include <Arduino.h>

class UIData {
private:
    /**
     * 当前温度
     */
    uint16_t currentTemp;

    /**
     * 目标温度
     */
    uint16_t targetTemp;

    /**
     * 当前温度 / 目标温度
     */
    uint8_t percentage;

    /**
     * 加热时间
     */
    uint8_t heatMins;


};

#endif //ARDUINOESPHEATFARMWORK_UIDATA_H
