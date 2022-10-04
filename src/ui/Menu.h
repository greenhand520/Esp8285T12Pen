//
// Created by mdmbct on 10/4/22.
//

#ifndef ESP8285HEAT_MENU_H

#include <Arduino.h>

struct Menu {
    uint8_t index;
//    uint8_t previousIndex;
//    uint8_t nextIndex;
    uint8_t confirmIndex;
    uint8_t menuIndex;
    char *name;
};

// 主界面 温度显示界面
Menu home = {0, 0, 1, "HOME"};
Menu setting = {1, 1, 1, "SETTING" };
Menu tipConfig = {2, 2, 2, "TIP CONFIG"};
Menu sysInfo = {3, 3, 3, "SYS INFO"};
Menu about = {4, 4, 4, "ABOUT"};

Menu volumeSet = {5, 4, 4, "Volume"};
Menu brightnessSet = {6, 4, 4, "Brightness"};
Menu tempSet = {7, 7, 7, "Temperature"};
Menu screenRotate = {8, 8, 8, "Screen rotate"};




#define ESP8285HEAT_MENU_H

#endif //ESP8285HEAT_MENU_H
