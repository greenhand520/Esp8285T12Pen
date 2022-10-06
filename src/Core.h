//
// Created by mdmbct on 10/1/22.
//

#ifndef ESP8285HEAT_CORE_H
#define ESP8285HEAT_CORE_H

#include <Arduino.h>
#include "Buzz.h"
#include "Storage.h"
#include "dormancy/DormancyEvent.h"
#include "temp/TempCtrler.h"
#include "ctrl/Ctrl.h"
#include "temp/TempMeasure.h"
#include "ui/UIData.h"
#include "ui/Component.h"

class Core {
private:
    Buzz *buzz;
    Ctrl *ctrl;
    DormancyEvent *dormancyEvent;
    TempMeasure *tempMeasure;
    TempCtrler *tempCtrler;
    UIData uiData;
    // 一些状态信息
    unsigned long dormancyStartTime = UINT32_MAX;

    void heat(uint16_t targetTemp);

    void work();

    void dormancy(unsigned long curTime);

//    uint16_t avgTemp(uint16_t curTemps[], uint8_t count);

public:
    Core(uint8_t buzzPin, uint8_t pwmPin, Ctrl *c, DormancyEvent *de, TempMeasure *tm, UIData uiData);

    /**
     * 在IO初始化之后调用 屏幕驱动初始化之前调用
     */
    void setup();

    /**
     * 更新UIData 控制蜂鸣器 温度检测 温控 按键检测
     */
    void loop();
};

#endif //ESP8285HEAT_CORE_H