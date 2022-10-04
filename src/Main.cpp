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
#define SDA_PIN 13
#define NEXT_BTU_PIN 14
#define SHOCK_PIN 15
#define BUZZ_PIN 16

StopEvent *shockStopEvent =  new ShockStopEvent(SHOCK_PIN, HIGH);
Ctrl *twoButtonCtrl = new TwoButtonCtrl(PREVIOUS_BTU_PIN, NEXT_BTU_PIN);
Heat heat = Heat(HEAT_PWM_PIN,
                 twoButtonCtrl,
                 shockStopEvent,
                 new GS8551Measure(TEMP_ADC_PIN),
                 new Buzz(BUZZ_PIN, 5));

void setup() {
    noInterrupts();
    heat.setup();
    // 别忘记添加中断
    attachInterrupt(digitalPinToInterrupt(SHOCK_PIN), []() {
        shockStopEvent->stop();
    }, LOW);
    interrupts();
}

void loop() {
    heat.loop();
}
