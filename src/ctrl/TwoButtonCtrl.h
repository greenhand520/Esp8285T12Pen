// 2按钮操作
// 按钮      单击               双击          长按
// ◄    温度- 上一个选项         确认温度        返回
// ►    温度+ 上一个选项         确认温度        菜单
// Created by mdmbct on 10/1/22.
//

#ifndef ARDUINOESPHEATFARMWORK_THREEBUTTONCTRL_H
#define ARDUINOESPHEATFARMWORK_THREEBUTTONCTRL_H

#include "Ctrl.h"

class TwoButtonCtrl : public Ctrl {
private:
    uint8_t previousButPin;
    uint8_t nextButPin;

    OneButton previousBut;
    OneButton nextBut;
public:

    TwoButtonCtrl();

    /**
     * @param _previousButPin
     * @param _nextButPin
     * @param pinMode 输入类型 INPUT INPUT_PULLUP INPUT_PULLDOWN_16
     */
    void init(uint8_t _previousButPin, uint8_t _nextButPin);

    void attachButtonInterrupt() override;

};

extern TwoButtonCtrl twoButtonCtrl;


#endif //ARDUINOESPHEATFARMWORK_THREEBUTTONCTRL_H
