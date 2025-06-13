#include "voltage.h"
#include "mqtt_client.h"

Voltage::Voltage(uint8_t inPin, const char *publishTopic)
    : _inPin(inPin), _publishTopic(publishTopic) {}

void Voltage::begin()
{
    pinMode(_inPin, INPUT);
    Serial.println("🟢 Spannungsmessung bereit.");
}

void Voltage::loop()
{
    double sensorValue = analogRead(_inPin);
    // Umrechnung in eine Spannung
    sensorValue = (sensorValue / 970.0) * 3.28;

    publishMessage(_publishTopic, String(sensorValue).c_str());
}
