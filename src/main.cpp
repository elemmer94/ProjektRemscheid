#include <Arduino.h>
#include "wifi_manager.h"
#include "mqtt_client.h"
#include "sensor_manager.h"
#include "parameter.h"

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
    reconnectWiFi();
    reconnectMQTT();
    sensorManager.loop();
    delay(1000);
}
