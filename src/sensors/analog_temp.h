#pragma once
#include <Arduino.h>
#include "sensor_interface.h"
#include <math.h>

class AnalogTemp : public SensorInterface
{
public:
    AnalogTemp(uint8_t inPin, const char *publishTopic);
    void begin() override;
    void loop() override;

private:
    uint8_t _inPin;
    const char *_publishTopic;
};