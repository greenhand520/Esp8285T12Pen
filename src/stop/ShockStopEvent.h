// 震动开关
// Created by mdmbct on 10/2/22.
//

#ifndef ESP8285HEATFARMEWORK_SHOCKEVENT_H
#define ESP8285HEATFARMEWORK_SHOCKEVENT_H

#include <Arduino.h>
#include "StopEvent.h"


class ShockStopEvent : public StopEvent {
private:
    uint8_t shockCount{};
public:

    ShockStopEvent();

    void init(uint8_t interruptPin, uint8_t interruptMode) override;

    void stop() override;

};

#endif //ESP8285HEATFARMEWORK_SHOCKEVENT_H
