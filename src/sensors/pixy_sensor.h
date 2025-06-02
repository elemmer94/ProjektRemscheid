#pragma once
#include "sensor_interface.h"
#include <Pixy2.h>

class PixySensor : public SensorInterface {
public:
    PixySensor(uint8_t ssPin, const char* publishTopic, const char* responseTopic);
    void begin() override;
    void loop() override;

private:
    uint8_t _ssPin;
    const char* _publishTopic;
    const char* _responseTopic;
    Pixy2 pixy;

    void handleAccessResponse(const String& message);
};
