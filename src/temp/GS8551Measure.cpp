//
// Created by mdmbct on 10/4/22.
//

#include "GS8551Measure.h"

GS8551Measure::GS8551Measure(uint8_t adcPin) : adcPin(adcPin) {
    pinMode(adcPin, INPUT);
}
