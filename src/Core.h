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
#include "ui/Display.h"

class Core {
private:
    Buzz *buzz;
    Ctrl *ctrl;
    DormancyEvent *dormancyEvent;
    TempMeasure *tempMeasure;
    TempCtrler *tempCtrler;
    UIData uiData;
public:
    Core(uint8_t buzzPin, uint8_t pwmPin, Ctrl *c, DormancyEvent *de, TempMeasure *tm, UIData uiData);

    void setup();

    /**
     * 更新UIData 控制蜂鸣器 温度检测 温控 按键检测
     */
    void loop();

};

#endif //ESP8285HEAT_CORE_H