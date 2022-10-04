//
// Created by mdmbct on 10/1/22.
//
#include "Heat.h"


Heat::Heat(uint8_t pwmPin, Ctrl c, StopEvent se, TempMeasure tm) {
    this->ctrl = &c;
    this->stopEvent = &se;
    this->tempMeasure = &tm;
    this->storage = Storage();
    this->tempCtrler = TempCtrler(pwmPin);

    storage.loadSettings();
}

/**
 * 添加已经初始化的蜂鸣器
 * @param _buzz
 */
void Heat::setBuzz(Buzz *_buzz) {
    Heat::buzz = _buzz;
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
            if (buzz != nullptr) {
                buzz->setMelody(ClickMelody);
            }
            break;
        case NEXT:
            if (buzz != nullptr) {
                buzz->setMelody(ClickMelody);
            }
            break;
        case MENU:
            if (buzz != nullptr) {
                buzz->setMelody(MMenuClickedMelody);
            }
            break;
        case CONFIRM:
            if (buzz != nullptr) {
                buzz->setMelody(ConfirmClickedMelody);
            }
            break;
        default:
            break;
    }

    // todo:更新屏幕


    buzz->play();


}










