//
// Created by mdmbct on 10/4/22.
//

#include <Arduino.h>
#include "core/Core.h"
#include "impl/ShockDormancyEvent.h"
#include "impl/TwoButtonCtrl.h"
#include "impl/GS8551Measure.h"
#include "ui/Display.h"

#define TEMP_ADC_PIN 6
#define SCL_PIN 9
#define HEAT_PWM_PIN 10
#define PREVIOUS_BTU_PIN 11
#define NEXT_BTU_PIN 12
#define SDA_PIN 13
#define RESET_PIN 14
#define SHOCK_PIN 15
#define BUZZ_PIN 16

UIData uiData{};
ShockDormancyEvent *shockDormancyEvent = new ShockDormancyEvent(SHOCK_PIN, 0);
Ctrl *twoButtonCtrl = new TwoButtonCtrl(PREVIOUS_BTU_PIN, NEXT_BTU_PIN);
Core core = Core(BUZZ_PIN, HEAT_PWM_PIN,
                 twoButtonCtrl,
                 shockDormancyEvent,
                 new GS8551Measure(TEMP_ADC_PIN));
U8G2 u8g2 = screenDriver(SDA_PIN, SCL_PIN, RESET_PIN);

void setup() {
    noInterrupts();
    core.setup();
    screenDriverInit();
    interrupts();
}

void loop() {
    shockDormancyEvent->checkState();
    core.loop();
    refreshScreen(twoButtonCtrl->popCtrl());
}
