#pragma once
#include <Arduino.h>
#include "sensor_interface.h"

class AnalogSensor : public SensorInterface
{
public:
    AnalogSensor(uint8_t inPin, const char *publishTopic);
    void begin() override;
    void loop() override;

private:
    uint8_t _inPin;
    const char *_publishTopic;
    const char *_responseTopic;
};