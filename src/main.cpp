#include <Arduino.h>
#include "wifi_manager.h"
#include "mqtt_client.h"
#include "sensor_manager.h"
#include "timer.h"
#include "parameter.h"

extern unsigned long myTimer;

SensorManager sensorManager;

void setup()
{
    Serial.begin(115200);
    // Initialisierung von WLAN, MQTT und Sensoren
    setupWiFi();
    setupMQTT();
    sensorManager.begin();
}

void loop()
{
    if (timePassed(myTimer, 1000))
    {
        reconnectWiFi();
        reconnectMQTT();
        sensorManager.loop();
    }
}
