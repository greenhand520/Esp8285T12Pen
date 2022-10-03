//
// Created by mdmbct on 10/1/22.
//

#include "RotaryCtrl.h"

void RotaryCtrl::init(uint8_t _buttonPin, uint8_t _aOutPin, uint8_t _bOutPin) {
    this->buttonPin = _buttonPin;
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(_aOutPin, INPUT_PULLUP);
    pinMode(_bOutPin, INPUT_PULLUP);

    this->button = OneButton(buttonPin);
    button.setDebounceTicks(25);
    button.setClickTicks(30);
    button.setPressTicks(500);

}

void RotaryCtrl::attachButtonInterrupt() {
    button.attachClick([]() {
        rotaryCtrl.addCtrl(CONFIRM);
    });
    button.attachDoubleClick([]() {
        rotaryCtrl.addCtrl(BACK);
    });
    button.attachLongPressStop([]() {
        rotaryCtrl.addCtrl(MENU);
    });

//    attachButtonInterrupt(aOutPin, []() {
//
//    }, CHANGE);
}


