//
// Created by mdmbct on 10/1/22.
//

#ifndef ESP8285HEAT_HEAT_H
#define ESP8285HEAT_HEAT_H

#include <Arduino.h>
#include "Buzz.h"
#include "Storage.h"
#include "stop/StopEvent.h"
#include "temp/TempCtrler.h"
#include "ctrl/Ctrl.h"
#include "temp/TempMeasure.h"
#include "ui/UIData.h"
#include "ui/Display.h"

class Heat {
private:
    Buzz *buzz;
    Ctrl *ctrl;
    StopEvent *stopEvent;
    TempMeasure *tempMeasure;
    TempCtrler tempCtrler = NULL;
    UIData uiData = {};
public:
    Heat(uint8_t buzzPin, uint8_t pwmPin, Ctrl *c, StopEvent *se, TempMeasure *tm, uint8_t volume);

    void setup();

    /**
     * 更新UIData 控制蜂鸣器 温度检测 温控 按键检测
     */
    void loop();

    [[nodiscard]] const UIData &getUiData() const;
};

#endif //ESP8285HEAT_HEAT_H