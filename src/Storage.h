//
// Created by mdmbct on 10/1/22.
//

#ifndef OESPHEAT_SETTINGS_H
#define OESPHEAT_SETTINGS_H

#include <Arduino.h>
// Arduino for esp8266 中用的EEPROM其实是从外部flash中存储器最末尾开辟的4096字节空间，
// 每次操作写入的数据在4~4096字节之间（4字节对齐）；，所以，EEPROM可操作的地址为0~4095。

// ESP引入ESP_EEPROM读写EEPROM
#if (defined(ESP8266)) || (defined(ESP32))
    #include <ESP_EEPROM.h>
#else
    #include <EEPROM.h>
#endif


struct Settings {

    // 加热时间：即达到设定温度后且停止加热事件触发后维持温度的时间，之后会进入休眠状态 min 5 ～ 10min
    uint8_t heatTime = 5;
    // 休眠状态的时间 min 5 ～ 30
    uint8_t dormancyTime = 20;
    // 休眠温度 ℃ 0 ～ 100
    uint16_t dormancyTemp = 80;
    // 初始温度 比低温系膏熔点高几度 ℃
    uint16_t initTemp = 145;
    // 温度步进 ℃ 1 ～ 10
    uint8_t tempStep = 5;
    // 音量 0 ～ 10
    uint8_t volume = 5;
    // todo: 屏幕旋转
};

class Storage {
private:
    Settings settings;

public:
    void loadSettings();

    /**
     * 设置页中每修改一个数据调用对应的setXXX函数临时保存
     * 最后只在离开设置页面调用该函数写入epprom
     */
    void saveSettings();

    void setVolume(uint8_t volume);

    uint8_t getVolume();

    void setHeatTime(uint8_t heatTime);

    uint8_t getHeatTime();

    void setDormancyTime(uint8_t dormancyTime);

    uint8_t getDormancyTime();

    void setDormancyTemp(uint16_t dormancyTemp);

    uint16_t getDormancyTemp();

    void setInitTemp(uint16_t initTemp);

    uint16_t getInitTemp();

    void setTempStep(uint8_t tempStep);

    uint8_t getTempStep();
};

#endif //OESPHEAT_SETTINGS_H
