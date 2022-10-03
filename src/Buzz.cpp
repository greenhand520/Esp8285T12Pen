// 相关函数参考：https://arduino-esp8266.readthedocs.io/en/latest/reference.html#analog-output
// ESP8285没有硬件PWM，PWM接⼝口功能由软件实现 会占用CPU计算
// Created by mdmbct on 10/1/22.
//

#include "Buzz.h"


void Buzz::setMelody(Tone _melody[]) {
    this->playingMelody = _melody;
    this->playingIndex = 0;
}

void Buzz::setVolume(uint8_t _volume) {
    this->volume = constrain(_volume, 0, 10);
    if (volume == 0) {
        analogWrite(pin, 0);
        // analogWriteFreq(0);
    }
}

// 参考： https://www.esp32.com/viewtopic.php?t=4978
void IRAM_ATTR Buzz::play() {
    if (playingMelody == nullptr || volume == 0) {
        return;
    }

    if (playingMelody == nullptr || playingMelody[playingIndex].note == NOTE_NONE) {
        // 播放结束
        setMelody(nullptr);
    } else {
        analogWriteFreq(playingMelody[playingIndex].note);
        analogWrite(pin, volume);
        delay(playingMelody[playingIndex].delay);
        playingIndex++;
    }
}

void Buzz::init(uint8_t _volume, uint8_t _pin) {
    this->pin = _pin;
    setVolume(_volume);
    pinMode(_pin, OUTPUT);
    analogWrite(_pin, 0);
    analogWriteRange(this->volume * 10);

    setBootMelody(BootMelody);
    setDormancyMelody(DormancyMelody);
    setClickMelody(ClickMelody);
    setDoubleClickMelody(DoubleClickMelody);
    setLongPressMelody(longPressMelody);
}

// 额外修改音效
void Buzz::setBootMelody(Tone *bootMelody) {
    Buzz::bootMeloy = bootMelody;
}

void Buzz::setDormancyMelody(Tone *dormancyMelody) {
    Buzz::dormancyMelody = dormancyMelody;
}

void Buzz::setClickMelody(Tone *clickMelody) {
    Buzz::clickMelody = clickMelody;
}

void Buzz::setDoubleClickMelody(Tone *doubleClickMelody) {
    Buzz::doubleClickMelody = doubleClickMelody;
}

void Buzz::setLongPressMelody(Tone *longPressMelody) {
    Buzz::longPressMelody = longPressMelody;
}

Buzz::Buzz() {}

// 所有的音效最后一个音符都要是NOTE_NONE
Tone BootMelody[] = {
        {NOTE_D4,   230},
        {NOTE_D4,   230},
        {NOTE_D4,   215},
        {NOTE_D4,   215},
        {NOTE_NONE, 0},
};
// 开始休眠时的音效
Tone DormancyMelody[] = {
        {NOTE_C4,   50},
        {NOTE_D4,   50},
        {NOTE_C4,   50},
        {NOTE_D4,   50},
        {NOTE_NONE, 0},
};
// 单击音效
Tone ClickMelody[] = {
        {NOTE_E4,   100},
        {NOTE_NONE, 0},
};
// 双击音效
Tone DoubleClickMelody[] = {
        {NOTE_E4,   100},
        {NOTE_G4,   100},
        {NOTE_NONE, 0},
};

Tone LongPressMelody[] = {
        {NOTE_E4,   200},
        {NOTE_NONE, 0},
};




