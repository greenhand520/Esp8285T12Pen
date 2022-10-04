//
// Created by mdmbct on 10/1/22.
//
#include "Heat.h"


Heat::Heat(uint8_t pwmPin, Ctrl c, StopEvent se, TempMeasure tm, Buzz buzz) {
    this->ctrl = &c;
    this->stopEvent = &se;
    this->tempMeasure = &tm;
    this->buzz = &buzz;
    this->storage = Storage();
    this->tempCtrler = TempCtrler(pwmPin);

    storage.loadSettings();
}

void Heat::setup() {
    ctrl->attachButtonInterrupt();
}

void Heat::loop() {


    // 停止加热
    if (stopEvent->isStop()) {
        tempCtrler.stopHeat();
        // todo：更新屏幕
    }

    // 取操作
    CtrlType ct = ctrl->popCtrl();
    switch (ct) {
        case PREVIOUS:
            buzz->setMelody(ClickMelody);
            break;
        case NEXT:
            buzz->setMelody(ClickMelody);
            break;
        case MENU:
            buzz->setMelody(MMenuClickedMelody);
            break;
        case CONFIRM:
            buzz->setMelody(ConfirmClickedMelody);
            break;
        default:
            break;
    }

    // todo:更新屏幕


    buzz->play();


}










