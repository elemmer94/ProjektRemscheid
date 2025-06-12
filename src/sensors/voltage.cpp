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
    sensorValue = (sensorValue / 1024) * 3.2;
    // Berechnung der Eingangsspannung
    sensorValue = sensorValue * ((12.0 + 30.0) / 12.0); // R2 + R1 / R2

    publishMessage(_publishTopic, String(sensorValue).c_str());
}
