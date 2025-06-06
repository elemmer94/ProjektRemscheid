#pragma once
#include <Arduino.h>
#include "sensor_interface.h"

class Ultrasonic : public SensorInterface
{
public:
    Ultrasonic(uint8_t _echoPin, uint8_t _trigPin, const char *publishTopic);
    void begin() override;
    void loop() override;

private:
    uint8_t _echoPin;
    uint8_t _trigPin;
    const char *_publishTopic;
};