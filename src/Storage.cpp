//
// Created by mdmbct on 10/1/22.
//

#include "Storage.h"

// 来自：https://github.com/esp8266/Arduino/issues/1539
void storeStruct(void *data_source, size_t size) {
    // 申请具体大小的ram内存空间并从flash中读取相应数据到内存
    EEPROM.begin(size * 2);
    for (size_t i = 0; i < size; i++) {
        char data = ((char *) data_source)[i];
        EEPROM.write(i, data);
    }
    EEPROM.end();
}

void loadStruct(void *data_dest, size_t size) {
    EEPROM.begin(size * 2);
    for (size_t i = 0; i < size; i++) {
        char data = EEPROM.read(i);
        ((char *) data_dest)[i] = data;
    }
}

void Storage::loadSettings() {
    EEPROM.begin(4);
    // 如果第一个字节存储的数据不是0，则继续加载设置数据
    uint8_t heatTime = EEPROM.read(0);
    if (heatTime != 0) {
        loadStruct(&settings, sizeof(settings));
    }
}

void Storage::saveSettings() {
    storeStruct(&settings, sizeof(settings));
}

void Storage::setVolume(uint8_t volume) {
    settings.volume = volume;
}

void Storage::setHeatTime(uint8_t heatTime) {
    settings.heatTime = heatTime;
}

void Storage::setDormancyTime(uint8_t dormancyTime) {
    settings.dormancyTime = dormancyTime;
}

void Storage::setDormancyTemp(uint16_t dormancyTemp) {
    settings.dormancyTemp = dormancyTemp;
}

void Storage::setInitTemp(uint16_t initTemp) {
    settings.initTemp = initTemp;
}

void Storage::setTempStep(uint8_t tempStep) {
    settings.tempStep = tempStep;
}

uint8_t Storage::getVolume() {
    return settings.volume;
}

// todo 时间分钟转换
uint8_t Storage::getHeatTime() {
    return settings.heatTime;
}

uint8_t Storage::getDormancyTime() {
    return settings.dormancyTime;
}

uint16_t Storage::getDormancyTemp() {
    return settings.dormancyTemp;
}

uint16_t Storage::getInitTemp() {
    return settings.initTemp;
}

uint8_t Storage::getTempStep() {
    return settings.tempStep;
}



