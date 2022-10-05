//
// 震动停止加热事件
// Created by mdmbct on 10/2/22.
//

#include "ShockStopEvent.h"

ShockStopEvent::ShockStopEvent(uint8_t interruptPin, uint8_t staticSecs) {
    pinMode(interruptPin, INPUT_PULLUP);
    setStaticSecs(staticSecs);
}


void ShockStopEvent::stop() {

    // todo: 待验证
    // 低电平到高电平触发一次中断开始计时
    if (staticSecs != 0) {
        // 返回Arduino板开始运行当前程序时的毫秒数
        interruptTime = millis();
    }
}

void ShockStopEvent::setStaticSecs(uint8_t _staticSecs) {
    this->staticSecs = constrain(_staticSecs, 0, 30) * 10;
}

bool ShockStopEvent::isStop() {
    // 当前时间离中断时间的间隔（处于静态的时间） 超过设定的时间 判定为停止加热
    if (staticSecs != 0 && millis() - interruptTime > staticSecs * 1000) {
        return true;
    }
    return false;
}


