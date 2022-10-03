//
// 蜂鸣器
// Created by mdmbct on 10/1/22.
//

#ifndef ARDUINOESPHEATFARMWORK_BUZZ_H
#define ARDUINOESPHEATFARMWORK_BUZZ_H

#include <Arduino.h>

/**
 * 音符
 * 来自：https://docs.arduino.cc/built-in-examples/digital/toneMelody#hardware-required
 * 参考：https://www.zhihu.com/question/27166538/answer/35507740
 *      https://blog.csdn.net/fatway/article/details/118859714
 */
typedef enum {
    NOTE_NONE = 0,
    NOTE_C4 = 262,
    NOTE_CS4 = 277,
    NOTE_D4 = 294,
    NOTE_DS4 = 311,
    NOTE_E4 = 330,
    NOTE_F4 = 349,
    NOTE_FS4 = 370,
    NOTE_G4 = 392,
    NOTE_GS4 = 415,
    NOTE_A4 = 440,
    NOTE_AS4 = 466,
    NOTE_B4 = 494
} Note;

// 音效
struct Tone {
    Note note;
    int delay;
};

class Buzz {
private:
    // 音量 0 ～ 10
    uint8_t volume;
    // 蜂鸣器引脚 带pwm输出
    uint8_t pin;
    // 是否还在播放音效
    bool isPlaying = true;
    // 播放的音效
    Tone *playingMelody = nullptr;
    // 当前播放到的音符
    uint16_t playingIndex = 0;
    // 开机音效
    Tone *bootMeloy = nullptr;
    // 开始休眠音效
    Tone *dormancyMelody = nullptr;
    // 单击音效
    Tone *clickMelody = nullptr;
    // 双击音效
    Tone *doubleClickMelody = nullptr;
    // 长按音效
    Tone *longPressMelody = nullptr;

public:

    Buzz();

    void setBootMelody(Tone *bootMelody);

    void setDormancyMelody(Tone *dormancyMelody);

    void setClickMelody(Tone *clickMelody);

    void setDoubleClickMelody(Tone *doubleClickMelody);

    void setLongPressMelody(Tone *longPressMelody);

    void init(uint8_t volume, uint8_t pin);

    void setVolume(uint8_t volume);

    // 只设置音效。在loop函数中 循环调用play播放
    void setMelody(Tone melody[]);

    // 播放音效
    void IRAM_ATTR play();
};

extern Tone BootMelody[];
extern Tone DormancyMelody[];
extern Tone ClickMelody[];
extern Tone DoubleClickMelody[];
extern Tone LongPressMelody[];

#endif //ARDUINOESPHEATFARMWORK_BUZZ_H
