// 震动开关 低电平到高电平后xx秒休眠
// Created by mdmbct on 10/2/22.
//

#ifndef ESP8285HEAT_SHOCKEVENT_H
#define ESP8285HEAT_SHOCKEVENT_H

#include <Arduino.h>
#include "core/DormancyEvent.h"


class ShockDormancyEvent : public DormancyEvent {
private:
    uint8_t shockPin;

    /**
     * 第一次触发休眠的时间
     */
    unsigned long attachDormancyTime = UINT32_MAX;

    /**
     * 第一次触发工作的时间
     */
    unsigned long attachWorkTime = UINT32_MAX;

    // 初始状态表示震动开关接通 处于工作状态
    uint8_t lastShockPinValue = LOW;

    bool dormancyFlag = false;

public:
    /**
  * 初始化停止加热事件 pin模式设置为输入 内部上拉
  * @param waitSecs 第一次触发引脚电平变化到状态改变需要的时间 => 调节灵敏度 0 ～ 30 0：关闭休眠
  * @param shockPin 震动开关连接的引脚
  */
    ShockDormancyEvent(uint8_t waitSecs, uint8_t shockPin);

    void checkState();

    bool isDormancy(unsigned long curTime) override;

//    bool isWork(unsigned long curTime) override;
};

#endif //ESP8285HEAT_SHOCKEVENT_H
