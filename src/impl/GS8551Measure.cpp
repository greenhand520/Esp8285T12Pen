//
// Created by mdmbct on 10/4/22.
//

#include "GS8551Measure.h"

GS8551Measure::GS8551Measure(uint8_t adcPin) : adcPin(adcPin) {
    pinMode(adcPin, INPUT);
}

uint16_t GS8551Measure::readTemp(uint8_t count) {
    // 测温前会停止加热 这里等待ADC电压稳定
    delayMicroseconds(500);
    // 读取ADC时禁止中断
    noInterrupts();


    return 0;
}

