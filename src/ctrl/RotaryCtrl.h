// 旋转编码器操作
// 参考：https://zhuanlan.zhihu.com/p/349824627?utm_id=0
// Created by mdmbct on 10/1/22.
//

#ifndef ARDUINOESPHEATFARMWORK_ROTARYCTRL_H
#define ARDUINOESPHEATFARMWORK_ROTARYCTRL_H

#include "Ctrl.h"
#include <RotaryEncoder.h>

class RotaryCtrl : public Ctrl {

private:
    uint8_t buttonPin;
    uint8_t aOutPin;
    uint8_t bOutPin;
    OneButton button;
    /**
     * 脉冲计数
     */
    int count;

public:
    void init(uint8_t _buttonPin, uint8_t _aOutPin, uint8_t _bOutPin);

    void attachButtonInterrupt() override;
};

extern RotaryCtrl rotaryCtrl;


#endif //ARDUINOESPHEATFARMWORK_ROTARYCTRL_H
