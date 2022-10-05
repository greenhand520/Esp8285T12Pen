//
// 震动停止加热事件
// Created by mdmbct on 10/2/22.
//

#include "ShockDormancyEvent.h"

ShockDormancyEvent::ShockDormancyEvent(uint8_t _shockPin, uint8_t waitSecs) : DormancyEvent(waitSecs) {
    this->shockPin = _shockPin;
    pinMode(shockPin, INPUT_PULLUP);
}

bool ShockDormancyEvent::isDormancy(unsigned long curTime) {
    return dormancyFlag;
}

void ShockDormancyEvent::checkState() {
    // waitSecs = 0 => 不自动休眠状态
    // 和上次获取到的IO状态不一样 => 开始设定第一次触发休眠/工作时间
    // 和上次获取到的IO状态一致 => 计算当前时间和开始触发休眠/工作的时间差 大于设定的等待时间 => 确定状态
    if (waitSecs == 0) {
        dormancyFlag = false;
    } else if (digitalRead(shockPin) != lastShockPinValue) {
        // 取反
        lastShockPinValue = ~lastShockPinValue;
        if (lastShockPinValue) {
            attachDormancyTime = millis();
        } else {
            attachWorkTime = millis();
        }
    } else {
        if (lastShockPinValue && millis() - attachDormancyTime > waitSecs * 1000) {
            dormancyFlag = true;
        } else if (!lastShockPinValue && millis() - attachWorkTime > waitSecs * 1000) {
            dormancyFlag = false;
        }
    }
}


