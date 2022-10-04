// 震动开关
// Created by mdmbct on 10/2/22.
//

#ifndef ESP8285HEAT_SHOCKEVENT_H
#define ESP8285HEAT_SHOCKEVENT_H

#include <Arduino.h>
#include "StopEvent.h"


class ShockStopEvent : public StopEvent {
private:
    uint8_t shockCount{};

public:

    ShockStopEvent(uint8_t interruptPin, uint8_t interruptMode);

    void stop() override;

    ShockStopEvent(int shockPin, int interruptMode);
};

#endif //ESP8285HEAT_SHOCKEVENT_H