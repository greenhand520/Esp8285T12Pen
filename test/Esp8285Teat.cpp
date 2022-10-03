//
// Created by mdmbct on 10/1/22.
//

#include <Arduino.h>
#include "HeatFramework.h"
#include "stop/ShockStopEvent.h"
#include "ctrl/TwoButtonCtrl.h"

#define TEMP_ADC_PIN 6
#define SCL_PIN 9
#define HEAT_PWM_PIN 10
#define BACK_BTU_PIN 11
#define SDA_PIN 13
#define FORWARD_BTU_PIN 14
#define SHOCK_PIN 15
#define BUZZ_PIN 16

HeatFramework hf = HeatFramework();
ShockStopEvent shockStopEvent = ShockStopEvent();
Buzz buzz = Buzz();
TwoButtonCtrl twoButtonCtrl = TwoButtonCtrl();

void setup() {

    buzz.init(5, BUZZ_PIN);
    hf.init(HEAT_PWM_PIN);
    hf.setBuzz(&buzz);
    hf.setCtrl(&twoButtonCtrl);
    hf.setStopEvent(&shockStopEvent);
    // 别忘记添加中断
    attachInterrupt(digitalPinToInterrupt(SHOCK_PIN), []() {
        shockStopEvent.stop();
    }, LOW);
}

void loop() {

}