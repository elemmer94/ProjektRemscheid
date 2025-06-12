#include "analog_temp.h"
#include "mqtt_client.h"

AnalogTemp::AnalogTemp(uint8_t inPin, const char *publishTopic)
    : _inPin(inPin), _publishTopic(publishTopic) {}

void AnalogTemp::begin()
{
    pinMode(_inPin, INPUT);
    Serial.println("🟢 Analoger Temperatur Sensor bereit.");
}

void AnalogTemp::loop()
{
    double sensorValue = analogRead(_inPin);
    double fenya = (sensorValue / 1023) * 5;
    double r = (5 - fenya) / fenya * 4700;
    sensorValue = 1 / (log(r / 10000) / 3950 + 1 / (25 + 273.15)) - 273.15 + 4.0;

    publishMessage(_publishTopic, String(sensorValue).c_str());
}
