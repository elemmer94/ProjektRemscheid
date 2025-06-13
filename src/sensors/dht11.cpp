#include "dht11.h"
#include "mqtt_client.h"

DHTSensor::DHTSensor(uint8_t pin, const char *publishTopic)
    : _pin(pin), _publishTopic(publishTopic), _dht(pin, DHT11) {}

void DHTSensor::begin()
{
    _dht.begin();
    Serial.println("🟢 DHT11 Sensor bereit.");
}

void DHTSensor::loop()
{
    float h = _dht.readHumidity();
    float t = _dht.readTemperature();

    String values = String(h) + "," + t;
    publishMessage(_publishTopic, values.c_str());
}
