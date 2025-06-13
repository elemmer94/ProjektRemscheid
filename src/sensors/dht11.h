#pragma once
#include <DHT.h>
#include <Arduino.h>
#include "sensor_interface.h"

class DHTSensor : public SensorInterface
{
public:
    DHTSensor(uint8_t pin, const char *publishTopic);
    void begin();
    void loop();

private:
    uint8_t _pin;
    const char *_publishTopic;
    DHT _dht;
};
