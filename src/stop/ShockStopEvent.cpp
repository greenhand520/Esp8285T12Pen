//
// 震动停止加热事件
// Created by mdmbct on 10/2/22.
//

#include "ShockStopEvent.h"

ShockStopEvent::ShockStopEvent(uint8_t interruptPin, uint8_t interruptMode) : StopEvent(interruptPin, interruptMode) {

}

void ShockStopEvent::stop() {
    shockCount++;
    if (shockCount >= 5) {
        shockCount = 0;
        stopFlag = true;
    }
}


