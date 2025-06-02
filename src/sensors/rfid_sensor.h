#pragma once
#include "sensor_interface.h"

class MFRC522;

class RFIDSensor : public SensorInterface {
public:
    RFIDSensor(uint8_t ssPin, uint8_t rstPin, const char* publishTopic, const char* responseTopic);
    void begin() override;
    void loop() override;

private:
    uint8_t _ssPin, _rstPin;
    const char* _publishTopic;
    const char* _responseTopic;
    MFRC522* rfid;

    void handleAccessResponse(const String& message);
};