//
// Created by mdmbct on 10/1/22.
//

#include "TwoButtonCtrl.h"

TwoButtonCtrl::TwoButtonCtrl() = default;

void TwoButtonCtrl::init(uint8_t _previousButPin, uint8_t _nextButPin) {
    this->previousButPin = _previousButPin;
    pinMode(previousButPin, INPUT_PULLUP);
    this->nextButPin = _nextButPin;
    pinMode(nextButPin, INPUT_PULLUP);

    previousBut = OneButton(previousButPin);
    // 去抖动
    previousBut.setDebounceTicks(25);
    // 设置在检测到点击之前必须经过的毫秒数。
    previousBut.setClickTicks(30);
    // 设置在检测到长按钮按下之前必须经过的毫秒数。
    previousBut.setPressTicks(500);

    nextBut = OneButton(nextButPin);
    nextBut.setDebounceTicks(25);
    nextBut.setClickTicks(30);
    nextBut.setPressTicks(500);

}

void TwoButtonCtrl::attachButtonInterrupt() {
    previousBut.attachClick([]() {
        twoButtonCtrl.addCtrl(PREVIOUS);
    });
    previousBut.attachDoubleClick([]() {
        twoButtonCtrl.addCtrl(CONFIRM);
    });
    previousBut.attachLongPressStop([]() {
        twoButtonCtrl.addCtrl(BACK);
    });

    nextBut.attachClick([]() {
        twoButtonCtrl.addCtrl(NEXT);
    });
    nextBut.attachDoubleClick([]() {
        twoButtonCtrl.addCtrl(CONFIRM);
    });
    nextBut.attachLongPressStop([]() {
        twoButtonCtrl.addCtrl(MENU);
    });

}

