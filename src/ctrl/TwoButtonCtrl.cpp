//
// Created by mdmbct on 10/1/22.
//

#include "TwoButtonCtrl.h"

TwoButtonCtrl::TwoButtonCtrl(uint8_t previousButPin, uint8_t nextButPin) : previousButPin(previousButPin),
                                                                           nextButPin(nextButPin) {
    pinMode(previousButPin, INPUT_PULLUP);
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
        twoButtonCtrl.pushCtrl(PREVIOUS);
    });
    previousBut.attachDoubleClick([]() {
        twoButtonCtrl.pushCtrl(CONFIRM);
    });
    previousBut.attachLongPressStop([]() {
        twoButtonCtrl.pushCtrl(BACK);
    });

    nextBut.attachClick([]() {
        twoButtonCtrl.pushCtrl(NEXT);
    });
    nextBut.attachDoubleClick([]() {
        twoButtonCtrl.pushCtrl(CONFIRM);
    });
    nextBut.attachLongPressStop([]() {
        twoButtonCtrl.pushCtrl(MENU);
    });

}

