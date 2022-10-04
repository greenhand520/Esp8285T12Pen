//
// Created by mdmbct on 10/1/22.
//

#include <Arduino.h>
#include "Heat.h"
#include "stop/ShockStopEvent.h"
#include "ctrl/TwoButtonCtrl.h"

#define TEMP_ADC_PIN 6
#define SCL_PIN 9
#define HEAT_PWM_PIN 10
#define PREVIOUS_BTU_PIN 11
#define SDA_PIN 13
#define NEXT_BTU_PIN 14
#define SHOCK_PIN 15
#define BUZZ_PIN 16

ShockStopEvent shockStopEvent = ShockStopEvent(SHOCK_PIN, HIGH);
Buzz buzz = Buzz(BUZZ_PIN, 5);
TwoButtonCtrl twoButtonCtrl = TwoButtonCtrl(PREVIOUS_BTU_PIN, NEXT_BTU_PIN);
TempMeasure tempMeasure = TempMeasure();
Heat heat = Heat(HEAT_PWM_PIN, twoButtonCtrl, shockStopEvent, tempMeasure);

void setup() {

    heat.setBuzz(&buzz);
    // 别忘记添加中断
    attachInterrupt(digitalPinToInterrupt(SHOCK_PIN), []() {
        shockStopEvent.stop();
    }, LOW);
}

void loop() {

}