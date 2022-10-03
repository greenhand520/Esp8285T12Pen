//
// Created by mdmbct on 10/1/22.
//

#ifndef ESP8285HEATFARMWORK_HEATFARMWORK_H
#define ESP8285HEATFARMWORK_HEATFARMWORK_H

#include <Arduino.h>
#include "Buzz.h"
#include "Storage.h"
#include "stop/StopEvent.h"
#include "temp/TempCtrler.h"
#include "ctrl/Ctrl.h"

extern Storage storage;
extern TempCtrler tempCtrler;
//extern Ctrl twoButtonCtrl;
//extern StopEvent stopEvent;

class HeatFramework {
private:
    Buzz *buzz;
    Ctrl *ctrl;
    StopEvent *stopEvent;
public:
    HeatFramework();

    void init(uint8_t tempPwmPin);

    void setBuzz(Buzz *buzz);

    void setCtrl(Ctrl *ctrl);

    void setStopEvent(StopEvent *stopEvent);


};

#endif //ESP8285HEATFARMWORK_HEATFARMWORK_H