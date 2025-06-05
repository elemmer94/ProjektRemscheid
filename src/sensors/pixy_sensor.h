#pragma once
#include <Arduino.h>
#include "sensor_interface.h"
#include <Pixy2.h>

class PixySensor : public SensorInterface
{
public:
    PixySensor(uint8_t ssPin, const char *publishTopic);
    void begin() override;
    void loop() override;

private:
    uint8_t _ssPin;
    const char *_publishTopic;
    Pixy2 pixy;
};
