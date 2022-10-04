//
// Created by mdmbct on 10/4/22.
//

#ifndef ESP8285HEAT_GS8551MEASURE_H
#define ESP8285HEAT_GS8551MEASURE_H

#include "TempMeasure.h"

class GS8551Measure : public TempMeasure {
private:
    uint8_t adcPin;

public:
    GS8551Measure(uint8_t adcPin);

};


#endif //ESP8285HEAT_GS8551MEASURE_H
