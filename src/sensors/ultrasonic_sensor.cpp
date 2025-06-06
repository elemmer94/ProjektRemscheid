#include "ultrasonic_sensor.h"
#include "mqtt_client.h"

Ultrasonic::Ultrasonic(uint8_t inPin, const char *publishTopic)
    : _inPin(inPin), _publishTopic(publishTopic) {}

void Ultrasonic::begin()
{
    pinMode(_inPin, INPUT);
    Serial.println("🟢 Ultraschalsensor bereit.");
}

void Ultrasonic::loop()
{
    double sensorValue = analogRead(_inPin);
    // Umrechnung in eine Spannung
    sensorValue = (sensorValue / 1024) * 3.3;
    // Berechnung der Eingangsspannung
    sensorValue = sensorValue * ((2.2 + 1.0) / 2.2); // R2 + R1 / R2

    publishMessage(_publishTopic, String(sensorValue).c_str());
}
