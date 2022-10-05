//
// Created by mdmbct on 10/4/22.
//

#include <Arduino.h>
#include "Heat.h"
#include "stop/ShockStopEvent.h"
#include "ctrl/TwoButtonCtrl.h"
#include "temp/GS8551Measure.h"

#define TEMP_ADC_PIN 6
#define SCL_PIN 9
#define HEAT_PWM_PIN 10
#define PREVIOUS_BTU_PIN 11
#define NEXT_BTU_PIN 12
#define SDA_PIN 13
#define RESET_PIN 14
#define SHOCK_PIN 15
#define BUZZ_PIN 16

StopEvent *shockStopEvent = new ShockStopEvent(SHOCK_PIN, 0);
Ctrl *twoButtonCtrl = new TwoButtonCtrl(PREVIOUS_BTU_PIN, NEXT_BTU_PIN);
Display display = Display(false, 5, SDA_PIN, SCL_PIN, RESET_PIN);
Heat heat = Heat(BUZZ_PIN, HEAT_PWM_PIN,
                 twoButtonCtrl,
                 shockStopEvent,
                 new GS8551Measure(TEMP_ADC_PIN), 5);

void setup() {
    noInterrupts();
    heat.setup();
    // 别忘记添加中断 低电平变高电平触发中断
    attachInterrupt(digitalPinToInterrupt(SHOCK_PIN), []() {
        shockStopEvent->stop();
    }, RISING);
    display.init(heat.getUiData());
    interrupts();
}

void loop() {
    heat.loop();
}
