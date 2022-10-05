//
// Created by mdmbct on 10/1/22.
//

#ifndef ESPHEAT_UIDATA_H
#define ESPHEAT_UIDATA_H

#include <Arduino.h>

struct Settings {

    /**
     * 休眠状态的时间 min 5 ～ 30
     */
    uint8_t dormancyMins = 20;

    /**
     * 休眠温度 ℃ 0 ～ 100
     */
    uint16_t dormancyTemp = 80;

    /**
     * 初始温度 比低温系膏熔点高几度 ℃
     */
    uint16_t initTemp = 145;

    /**
     * 温度步进 ℃ 1 ～ 10
     */
    uint8_t tempStep = 5;

    /**
     * 音量 0 ～ 10
     */
    uint8_t volume = 5;

    /**
     * 屏幕亮度
     */
    uint8_t brightness = 5;

    /**
     * 工作/休眠状态改变等待时间 第一次触发状态改变到确认状态改变的等待时间   0 ～ 30  0：关闭自动休眠
     */
    uint8_t stateChangeWaitSecs = 5;

    /**
     * 屏幕旋转
     */
    bool isRotate = false;
};

struct UIData {
    /**
     * 关闭屏幕
     */
    bool offScreen = false;
    /**
     * 展示休眠图标
     */
    bool showDormancyIco = false;

    /**
     * 当前温度
     */
    uint16_t currentTemp;

    /**
     * 目标温度
     */
    uint16_t targetTemp;

    Settings settings = {};

};

//extern UIData uiData = {};

#endif //ESPHEAT_UIDATA_H
