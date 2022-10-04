//
// Created by mdmbct on 10/4/22.
//

#include "Display.h"

Display::Display(bool isRotate, uint8_t brightness, uint8_t sdaPin, uint8_t sclPin, uint8_t resetPin) {
    if (isRotate) {
        driver = U8G2_SH1107_64X128_F_HW_I2C(U8G2_R2, resetPin, sclPin, sdaPin);
    } else {
        driver = U8G2_SH1107_64X128_F_HW_I2C(U8G2_R0, resetPin, sclPin, sdaPin);
    }
    setBrightness(brightness);
}

void Display::init(UIData uiData) {
    this->uiData = uiData;
    driver.begin();
    driver.setBusClock(921600);
    driver.enableUTF8Print();
    driver.setFontPosTop();
    driver.setFont(u8g2_font_wqy12_t_gb2312);
    driver.setDrawColor(1);
    driver.setFontMode(1);
}

void Display::setRotate(bool isRotate) {
    driver.setDisplayRotation(isRotate ? U8G2_R2 : U8G2_R0);
}

void Display::setBrightness(uint8_t _brightness) {
    driver.setContrast(constrain(_brightness, 1, 10) * 25);
}

void Display::refresh() {
    driver.clearBuffer();

    //todo:更新屏幕
}


