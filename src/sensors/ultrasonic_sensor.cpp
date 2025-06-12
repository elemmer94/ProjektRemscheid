#include "ultrasonic_sensor.h"
#include "mqtt_client.h"
#include "parameter.h"

Ultrasonic::Ultrasonic(uint8_t echoPin, uint8_t trigPin, const char *publishTopic)
    : _echoPin(echoPin), _trigPin(trigPin), _publishTopic(publishTopic) {}

void Ultrasonic::begin()
{
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
    pinMode(LED_PIN, OUTPUT);

    Serial.println("🟢 Ultraschalsensor bereit.");
}

void Ultrasonic::loop()
{
    
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    long duration = pulseIn(_echoPin, HIGH);
    double distance = duration / 58.2;

    // LED
    if(distance > 0.0 && distance <= 200.0)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }

    publishMessage(_publishTopic, String(distance).c_str());
}
