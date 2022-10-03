//
// 震动停止加热事件
// Created by mdmbct on 10/2/22.
//

#include "ShockStopEvent.h"

ShockStopEvent::ShockStopEvent() = default;

/**
 * 震动开关触发硬件中断 然后停止加热
 * @param _interruptPin 震动开关pin
 * @param _interruptMode 中断类型
 * @param tc 温控对象
 */
void ShockStopEvent::init(uint8_t _interruptPin, uint8_t _interruptMode) {
    StopEvent::init(_interruptPin, _interruptMode);
    shockCount = 0;
}

void ShockStopEvent::stop() {
    // 不同停止事件不同判定结束条件 最终调用父类的stop函数。
    shockCount++;
    if (shockCount >= 5) {
        shockCount = 0;
        stopFlag = true;
    }
}


