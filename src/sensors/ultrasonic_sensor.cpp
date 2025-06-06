#include "ultrasonic_sensor.h"
#include "mqtt_client.h"
#include "parameter.h"

Ultrasonic::Ultrasonic(uint8_t echoPin,uint8_t trigPin, const char *publishTopic)
    : _echoPin(echoPin), _trigPin(trigPin), _publishTopic(publishTopic) {}

void Ultrasonic::begin()
{
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);

    Serial.println("🟢 Ultraschalsensor bereit.");
}

void Ultrasonic::loop()
{
    long duration,distance;
    digitalWrite(ULTRA_TRIG, LOW); 
    delayMicroseconds(2);

    digitalWrite(ULTRA_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRA_TRIG, LOW);

    duration = pulseIn(ULTRA_ECHO, HIGH);
    
    //Calculate the distance (in cm) based on the speed of sound.
    distance = duration/58.2;

    publishMessage(_publishTopic, String(distance).c_str());
}
