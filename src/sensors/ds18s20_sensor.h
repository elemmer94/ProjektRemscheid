#pragma once
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "sensor_interface.h"

class DS18S20_TEMP : public SensorInterface
{
public:
    DS18S20_TEMP(uint8_t inPin, const char *publishTopic);
    void begin() override;
    void loop() override;

private:
    uint8_t _inPin;
    const char *_publishTopic;
    OneWire oneWire;
    DallasTemperature sensors;
};
