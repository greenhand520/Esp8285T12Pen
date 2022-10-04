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

class Heat {
private:
    Buzz *buzz;
    Ctrl *ctrl;
    StopEvent *stopEvent;
    TempMeasure *tempMeasure;
    Storage storage;
    TempCtrler tempCtrler = NULL;
    UIData uiData;
public:
    Heat(uint8_t pwmPin, Ctrl c, StopEvent se, TempMeasure tm, Buzz buzz);

    void setup();

    void loop();
};

#endif //ESP8285HEAT_HEAT_H