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
    setupWiFi();
    setupMQTT();
    sensorManager.begin();
}

void loop()
{
    if (timePassed(myTimer, 2000))
    {
        reconnectWiFi();
        reconnectMQTT();
        sensorManager.loop();
    }
}
