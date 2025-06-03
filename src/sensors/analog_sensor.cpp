#include "analog_sensor.h"
#include "mqtt_client.h"

double sensorValue = false;
double fenya;
double r;
String unit;

AnalogSensor::AnalogSensor(uint8_t inPin, const char *publishTopic)
    : _inPin(inPin), _publishTopic(publishTopic) {}

void AnalogSensor::begin()
{
    pinMode(_inPin, INPUT);
    Serial.println("🟢 Analoger Sensor bereit.");
}

void AnalogSensor::loop()
{
    sensorValue = analogRead(_inPin);

    sensorValue = (sensorValue * 100) / 1024;
    unit = "%";

    publishMessage(_publishTopic, (sensorValue + unit).c_str());

    delay(1000);
}
