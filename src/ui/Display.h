//
// Created by mdmbct on 10/4/22.
//

#ifndef ESP8285HEAT_DISPLAY_H
#define ESP8285HEAT_DISPLAY_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "UIData.h"

class Display {
private:
//    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C driver = nullptr;
    U8G2_SH1107_64X128_F_HW_I2C driver = nullptr;
    UIData uiData;

public:
    /**
     * 初始化
     * @param isRotate 是否旋转
     * @param brightness 亮度 1-10
     * @param sdaPin
     * @param sclPin
     */
    Display(bool isRotate, uint8_t brightness, uint8_t sdaPin, uint8_t sclPin, uint8_t resetPin);

    /**
     * 从UIdata中取数据更新屏幕
     * @param uiData
     */
    void init(UIData uiData);

    void setRotate(bool isRotate);

    void setBrightness(uint8_t brightness);

    /**
     * 刷新屏幕
     */
    void refresh();
};

#endif //ESP8285HEAT_DISPLAY_H
