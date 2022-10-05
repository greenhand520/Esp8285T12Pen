//
// Created by mdmbct on 10/4/22.
//

#ifndef ESP8285HEAT_MENU_H

#include <Arduino.h>


#define NO_MENU 255
// 确定操作 不进行界面切换
#define CONFIRM 254
struct Menu {
    uint8_t index;
//    uint8_t previousIndex;
    uint8_t confirmIndex;
    uint8_t nextIndex;
    char *name;

    void (*drawFun)();
};

// 用来临时存储翻过去的界面
#define MENU_STACK_MAX_SIZE 5
struct MenuStack {
    uint8_t indexs[MENU_STACK_MAX_SIZE];
    // 指向栈顶元素的下一个位置 （uint_8不能为-1）
    uint8_t top = 0;
};

MenuStack menuStack{};

bool pushMenu(uint8_t index) {
    if (menuStack.top <= MENU_STACK_MAX_SIZE - 1) {
        menuStack.indexs[menuStack.top] = index;
        menuStack.top++;
        return true;
    }
    return false;
}

uint8_t popMenu() {
    if (menuStack.top != 0) {
        uint8_t index = menuStack.indexs[menuStack.top];
        menuStack.top--;
        return index;
    }
    return NO_MENU;
}

// 界面切换
Menu homeSw = {0, 4, 1, "HOME"};
Menu settingsSw = {1, 5, 2, "SETTINGS"};
Menu aboutSw = {2, 6, 3, "ABOUT"};
Menu tipConfSw = {3, 7, 0, "TIP CONFIG"};

// 不同界面
Menu homeScr = {4, 4, NO_MENU, ""};
Menu settingsScr = {5, 11, NO_MENU, ""};
Menu aboutScr = {6, 3, NO_MENU, ""};
Menu tipConfigScr = {7, CONFIRM, NO_MENU, ""};
//Menu sysInfo = {7, 3, 3, "SYS INFO"};


// Home界面
// 当前温度
Menu currentTempInfo = {8, CONFIRM, 9, ""};
// 休眠
Menu dormancySw = {9, CONFIRM, 10, ""};
// 快速升温
Menu fastHeatSw = {10, CONFIRM, 8, ""};

// 设置界面中的菜单
Menu volumeSet = {11, CONFIRM, 12, "Volume: "};
Menu brightnessSet = {12, CONFIRM, 13, "Brightness: "};
Menu screenRotate = {13, CONFIRM, 14, "Screen Rotate: "};
Menu initTempSet = {14, CONFIRM, 15, "Init Temperature: "};
Menu tempStepSet = {15, CONFIRM, 16, "Temperature Step: "};
Menu dormancyTempSet = {16, CONFIRM, 17, "Dormancy Temperature: "};
Menu staticDormancySecsSet = {17, CONFIRM, 18, "Static Dormancy Secs: "};
Menu dormancyMinsSet = {18, CONFIRM, 19, "Dormancy Mins: "};


#define ESP8285HEAT_MENU_H

#endif //ESP8285HEAT_MENU_H
