//
// Created by mdmbct on 10/4/22.
//

#include "Display.h"

Display::Display(bool isRotate, uint8_t brightness, uint8_t sdaPin, uint8_t sclPin) {
    if (isRotate) {
        driver = U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C(U8G2_R2, sclPin, sdaPin);
    } else {
        driver = U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C(U8G2_R0, sclPin, sdaPin);
    }
//    this->rotate = isRotate;
    setBrightness(brightness);
}

void Display::init(UIData uiData) {
    this->uiData = uiData;
}

void Display::setRotate(bool isRotate) {
//    Display::rotate = isRotate;
    driver.setDisplayRotation(isRotate ? U8G2_R2 : U8G2_R0);
}

//bool Display::isRotate() const {
//    return rotate;
//}
//
//uint8_t Display::getBrightness() const {
//    return brightness;
//}

void Display::setBrightness(uint8_t _brightness) {
//    this->brightness = constrain(_brightness, 1, 10);
    driver.setContrast(constrain(_brightness, 1, 10) * 25);
}


