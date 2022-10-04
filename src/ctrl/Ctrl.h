//
// 操控
// Created by mdmbct on 10/1/22.
//

#ifndef ARDUINOESPHEAT_CTRL_H
#define ARDUINOESPHEAT_CTRL_H

#include <Arduino.h>
#include <OneButton.h>

#define MAX_FIFO_QUEUE_SIZE 10


typedef enum {
//  无操作        上一个、减      下一个、加     确认       菜单、设置    返回
    NO_CTRL = 0, PREVIOUS = 1, NEXT = 2, CONFIRM = 3, MENU = 4, BACK = 5
} CtrlType;

// 从队列末尾拿元素操作
struct CtrlTypeFIFOQueue {
    // 操作类型
    CtrlType data[MAX_FIFO_QUEUE_SIZE];
    // 队列头尾指针
    // 这里队尾指针指向最后一个元素
    int front, rear;
};

class Ctrl {

protected:
    // 存储操作的先进先出队列
    CtrlTypeFIFOQueue ctrlQueue{};

public:
    Ctrl();

    void pushCtrl(CtrlType ct);

    CtrlType popCtrl();

    void clearCtrlQueue();

    /**
     * 添加中断
     */
    virtual void attachButtonInterrupt();
};

#endif //ARDUINOESPHEAT_CTRL_H
