#pragma once
#include <Arduino.h>
#include "sensor_interface.h"

class MFRC522;

class RFIDSensor : public SensorInterface {
public:
    RFIDSensor(uint8_t ssPin, const char* publishTopic);
    void begin() override;
    void loop() override;

private:
    uint8_t _ssPin;
    const char* _publishTopic;
    MFRC522* rfid;
};