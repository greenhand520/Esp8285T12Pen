// 震动开关 低电平到高电平后xx秒休眠
// Created by mdmbct on 10/2/22.
//

#ifndef ESP8285HEAT_SHOCKEVENT_H
#define ESP8285HEAT_SHOCKEVENT_H

#include <Arduino.h>
#include "DormancyEvent.h"


class ShockDormancyEvent : public DormancyEvent {
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
    ShockDormancyEvent(uint8_t interruptPin, uint8_t staticSecs);

    void attach() override;

    bool isStartDormancy() override;

    /**
     * 静态多少秒后开始休眠
     * @param staticSecs
     */
    void setStaticSecs(uint8_t staticSecs);



};

#endif //ESP8285HEAT_SHOCKEVENT_H
