//
// Created by mdmbct on 10/1/22.
//
#include "Core.h"


Core::Core(uint8_t buzzPin, uint8_t pwmPin, Ctrl *c, DormancyEvent *de, TempMeasure *tm, UIData uiData) {
    this->ctrl = c;
    this->dormancyEvent = de;
    this->tempMeasure = tm;
    this->buzz = new Buzz(buzzPin, uiData.settings.volume);
    this->tempCtrler = new TempCtrler(pwmPin, true);

    loadSettings(uiData.settings);
}

void Core::setup() {
    ctrl->attachButtonInterrupt();
}

void Core::loop() {


    // 停止加热 休眠
    if (dormancyEvent->isStartDormancy()) {
        tempCtrler->stopHeat();
        buzz->setMelody(DormancyMelody);
    } else {
        // 调温
        tempCtrler->heat(tempMeasure->getTemps(10), 10);
        // 更新UI数据
        uiData.currentTemp = tempCtrler->getAvgTemp();
        // 取操作 到屏幕显示时候 再删除当前操作
    }
    CtrlType ct = ctrl->curCtrl();
    switch (ct) {
        case PREVIOUS:
            buzz->setMelody(ClickMelody);
            break;
        case NEXT:
            buzz->setMelody(ClickMelody);
            break;
        case MENU:
            buzz->setMelody(MenuClickedMelody);
            break;
        case CONFIRM:
            buzz->setMelody(ConfirmClickedMelody);
            break;
        case BACK:
            buzz->setMelody(ClickMelody);
            break;
        default:
            break;
    }
    // 播放声音
    buzz->play();
}










