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
    double raw = analogRead(_inPin);
    double v_out = (raw / 1023.0) * 3.3;     // Spannung an A0, max 3.3V
    // Spannungsteiler rückrechnen (R1 = 2.2k, R2 = 4.3k)
    double v_sensor = v_out * (2.2 + 4.3) / 4.3;
    // Berechnung des NTC-Widerstands (R2 = 4.7k Pullup)
    double r_ntc = (5.0 - v_sensor) / v_sensor * 4700.0;
    // Thermistor-Formel (B-Wert-Methode) + Offset Korrektur
    double temperatureC = 1.0 / (log(r_ntc / 10000.0) / 3950.0 + 1.0 / (25 + 273.15)) - 273.15 + 6;

    publishMessage(_publishTopic, String(temperatureC).c_str());
}
