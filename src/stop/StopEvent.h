//
// 达到目标温度后 触发停止加热的事件
// Created by mdmbct on 10/2/22.
//

#ifndef ESP8285HEAT_STOPEVENT_H
#define ESP8285HEAT_STOPEVENT_H

#include <Arduino.h>

class StopEvent {
public:
    /**
     * 是否停止加热
     * @return
     */
    virtual bool isStop() = 0;

    /**
     * 被中断函数调用 根据情况修改stopFlag的值
     */
    virtual void stop() = 0;

};

#endif //ESP8285HEAT_STOPEVENT_H
