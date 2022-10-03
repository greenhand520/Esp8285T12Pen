//
// Created by mdmbct on 10/1/22.
//
#include "HeatFramework.h"


HeatFramework::HeatFramework() = default;

void HeatFramework::init(uint8_t tempPwmPin) {
    // 关中断
    noInterrupts();
    storage.loadSettings();
    tempCtrler.init(tempPwmPin);
}

/**
 * 添加已经初始化的蜂鸣器
 * @param _buzz
 */
void HeatFramework::setBuzz(Buzz *_buzz) {
    HeatFramework::buzz = _buzz;
}

/**
 * 添加已经初始化的控制方式
 * @param _ctrl
 */
void HeatFramework::setCtrl(Ctrl *_ctrl) {
    HeatFramework::ctrl = _ctrl;
}

/**
 * 添加已经初始化的停止事件
 * @param _stopEvent
 */
void HeatFramework::setStopEvent(StopEvent *_stopEvent) {
    HeatFramework::stopEvent = _stopEvent;
}








