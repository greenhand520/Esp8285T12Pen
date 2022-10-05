//
// 达到目标温度后 触发休眠的事件
// Created by mdmbct on 10/2/22.
//

#ifndef ESP8285HEAT_DORMANCYEVENT_H
#define ESP8285HEAT_DORMANCYEVENT_H

#include <Arduino.h>

class DormancyEvent {
public:
    /**
     * 是否开始休眠
     * @return
     */
    virtual bool isStartDormancy() = 0;

    /**
     * 被中断函数调用
     */
    virtual void attach() = 0;

};

#endif //ESP8285HEAT_DORMANCYEVENT_H
