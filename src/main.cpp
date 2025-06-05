#include <Arduino.h>
#include "wifi_manager.h"
#include "mqtt_client.h"
#include "sensor_manager.h"
#include "timer.h"
#include "parameter.h"

unsigned long myTimer = 0;

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
    if (timePassed(myTimer, INTERVALL))
    {
        reconnectWiFi();
        reconnectMQTT();
        sensorManager.loop();
    }
}
