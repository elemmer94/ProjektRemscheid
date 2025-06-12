#include "analog_sensor.h"
#include "mqtt_client.h"

AnalogSensor::AnalogSensor(uint8_t inPin, const char *publishTopic)
    : _inPin(inPin), _publishTopic(publishTopic) {}

void AnalogSensor::begin()
{
    pinMode(_inPin, INPUT);
    Serial.println("🟢 Analoger Sensor bereit.");
}

void AnalogSensor::loop()
{
    double sensorValue = analogRead(_inPin);
    sensorValue = (sensorValue * 100.0) / 890.0;

    publishMessage(_publishTopic, String(sensorValue).c_str());
}
