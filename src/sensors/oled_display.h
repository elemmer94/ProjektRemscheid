#pragma once
#include <Arduino.h>
#include "sensor_interface.h"
#include <U8g2lib.h>

class OLedDisplay : public SensorInterface
{
public:
    OLedDisplay(uint8_t sckPin, uint8_t sdaPin, const char* responseTopic);
    void begin() override;
    void loop() override;

private:
    uint8_t _sckPin;
    uint8_t _sdaPin;
    const char* _responseTopic;
    U8G2 *u8g2 = nullptr;

    void handleAccessResponse(const String& message);
};