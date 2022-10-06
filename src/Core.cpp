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
    uiData.targetTemp = uiData.settings.initTemp;
//    uiData.currentTemp = avgTemp(tempMeasure->getTemps(10), 10);
}

void Core::heat(uint16_t targetTemp) {
    if (targetTemp == 0) {
        tempCtrler->stopHeat();
    } else {
        // 调温
        tempCtrler->heat(tempMeasure->getTemps(10), 10, targetTemp);
    }
    // 更新UI数据
    uiData.currentTemp = tempCtrler->getAvgTemp();
}

void Core::work() {
    uiData.onScreen = true;
    dormancyStartTime = UINT32_MAX;
    // 展示休眠图标
    uiData.showDormancyIco = false;
    heat(uiData.targetTemp);
}

void Core::dormancy(unsigned long curTime) {
    if (curTime - dormancyStartTime > uiData.settings.dormancyMins * 60000) {
        // 停止加热
        heat(0);
        buzz->setMelody(DormancyMelody);
        // 关闭屏幕
        uiData.onScreen = false;
    } else {
        // 展示休眠图标
        uiData.showDormancyIco = true;
        heat(uiData.settings.dormancyTemp);
    }
}

void Core::loop() {
    // 检查状态
    unsigned long curTime = millis();
    if (dormancyEvent->isDormancy(curTime)) {
        if (dormancyStartTime == UINT32_MAX) {
            // 刚触发 经过设定的等待时间后）
            dormancyStartTime = curTime;
            buzz->setMelody(DormancyMelody);
        }
        dormancy(curTime);
    } else {
        work();
    }

    // 取操作 到屏幕显示时候 再删除当前操作
    CtrlType ct = ctrl->curCtrl();
//    switch (ct) {
//        case PREVIOUS:
//            buzz->setMelody(ClickMelody);
//            break;
//        case NEXT:
//            buzz->setMelody(ClickMelody);
//            break;
//        case MENU:
//            buzz->setMelody(MenuClickedMelody);
//            break;
//        case CONFIRM:
//            buzz->setMelody(ConfirmClickedMelody);
//            break;
//        case BACK:
//            buzz->setMelody(ClickMelody);
//            break;
//        default:
//            break;
//    }
    buzz->setMelody(ClickMelody);
    components[uiData.curCompIndex].uiDataUpdater(ct);
    // 播放声音
    buzz->play();
}

//uint16_t Core::avgTemp(uint16_t curTemps[], uint8_t count) {
//
//}












