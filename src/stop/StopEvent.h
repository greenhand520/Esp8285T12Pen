//
// 达到目标温度后 触发停止加热的事件
// Created by mdmbct on 10/2/22.
//

#ifndef ESP8285HEATFARMEWORK_STOPEVENT_H
#define ESP8285HEATFARMEWORK_STOPEVENT_H

#include <Arduino.h>

class StopEvent {
protected:
    uint8_t interruptPin;
    uint8_t interruptMode;
    // 停止加热标记 终端函数仅修改该标记
    bool stopFlag = false;

public:

    uint8_t getInterruptPin() const;

    uint8_t getInterruptMode() const;

    /**
     * 是否停止加热
     * @return
     */
    bool isStop() const;

    /**
     * 初始化停止加热事件 pin模式设置为输入 内部上拉
     * @param _interruptPin 触发硬件中断pin
     * @param _interruptMode 中断模式
     * @param 端口模式 输入类型 INPUT INPUT_PULLUP INPUT_PULLDOWN_16
     */
    virtual void init(uint8_t _interruptPin, uint8_t _interruptMode);

    /**
     * 中断函数中调用
     */
    virtual void stop() = 0;

};

#endif //ESP8285HEATFARMEWORK_STOPEVENT_H
