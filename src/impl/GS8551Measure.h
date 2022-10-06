//
// Created by mdmbct on 10/4/22.
//

#ifndef ESP8285HEAT_GS8551MEASURE_H
#define ESP8285HEAT_GS8551MEASURE_H

#include "core/TempMeasure.h"

class GS8551Measure : public TempMeasure {
private:
    uint8_t adcPin;

public:
    explicit GS8551Measure(uint8_t adcPin);

    uint16_t * getTemps(uint8_t count) override;
};


#endif //ESP8285HEAT_GS8551MEASURE_H
