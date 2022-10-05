// 震动开关
// Created by mdmbct on 10/2/22.
//

#ifndef ESP8285HEAT_SHOCKEVENT_H
#define ESP8285HEAT_SHOCKEVENT_H

#include <Arduino.h>
#include "StopEvent.h"


class ShockStopEvent : public StopEvent {
private:
    /**
     * 静态多少秒后开始休眠
     */
    uint8_t staticSecs = 5;
    unsigned long interruptTime = 0;

public:
    /**
  * 初始化停止加热事件 pin模式设置为输入 内部上拉
  * @param _interruptPin 触发硬件中断pin
  * @param _interruptMode 中断模式
  */
    ShockStopEvent(uint8_t interruptPin, uint8_t staticSecs);

    void stop() override;

    bool isStop() override;

    /**
     * 静态多少秒后开始休眠
     * @param staticSecs
     */
    void setStaticSecs(uint8_t staticSecs);



};

#endif //ESP8285HEAT_SHOCKEVENT_H
