//
// Created by mdmbct on 10/1/22.
//
#include "Heat.h"


Heat::Heat(uint8_t buzzPin, uint8_t pwmPin, Ctrl *c, StopEvent *se, TempMeasure *tm, uint8_t volume) {
    this->ctrl = c;
    this->stopEvent = se;
    this->tempMeasure = tm;
    this->buzz = new Buzz(buzzPin, volume);
    this->tempCtrler = TempCtrler(pwmPin);

    loadSettings(uiData.settings);
}

void Heat::setup() {
    ctrl->attachButtonInterrupt();
}

const UIData &Heat::getUiData() const {
    return uiData;
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










