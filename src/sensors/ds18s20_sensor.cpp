#include "ds18s20_sensor.h"
#include <Arduino.h>
#include "mqtt_client.h"

DS18S20_TEMP::DS18S20_TEMP(uint8_t inPin, const char *publishTopic)
    : _inPin(inPin), _publishTopic(publishTopic), oneWire(inPin), sensors(&oneWire) {}

void DS18S20_TEMP::begin()
{
    sensors.begin();
    Serial.println("🟢 DS18S20-Temperatur Sensor bereit.");
}

void DS18S20_TEMP::loop()
{
    sensors.requestTemperatures();
    float temperature = sensors.getTempCByIndex(0);

    if (temperature != DEVICE_DISCONNECTED_C)
    {
        publishMessage(_publishTopic, String(temperature - 2).c_str());
    }
}
