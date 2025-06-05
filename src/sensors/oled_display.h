#pragma once
#include <Arduino.h>
#include "sensor_interface.h"

class OLedDisplay : public SensorInterface
{
public:
    OLedDisplay(uint8_t ssPin, const char* publishTopic, const char* responseTopic);
    void begin() override;
    void loop() override;

private:
    uint8_t _ssPin;
    const char* _publishTopic;
    const char* _responseTopic;

    void handleAccessResponse(const String& message);
};