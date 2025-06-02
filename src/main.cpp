#include <Arduino.h>
#include "wifi_manager.h"
#include "mqtt_client.h"
#include "sensor_manager.h"

SensorManager sensorManager;

void setup() {
    Serial.begin(115200);
    // Initialisierung von WLAN, MQTT und Sensoren
    setupWiFi();
    setupMQTT();
    sensorManager.begin();
}

void loop() {
    // Aktualisierung der MQTT-Nachrichten und der Sensorwerte
    sensorManager.loop();
    mqttLoop();
    delay(10);
}
