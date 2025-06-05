#include "digital_sensor.h"
#include "mqtt_client.h"

bool sensorState = false;

DigitalSensor::DigitalSensor(uint8_t inPin, const char *publishTopic)
    : _inPin(inPin), _publishTopic(publishTopic) {}

void DigitalSensor::begin()
{
    pinMode(_inPin, INPUT);
    Serial.println("🟢 Digitaler Sensor bereit.");
}

void DigitalSensor::loop()
{
    sensorState = digitalRead(_inPin);
    publishMessage(_publishTopic, String(sensorState).c_str());

    delay(5000);
}
