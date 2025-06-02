#pragma once
#include <functional>
#include <Arduino.h>

extern bool mqttEnabled; // Um Sensordaten ohne WiFi auszugeben

void setupMQTT();
void mqttLoop();
void publishMessage(const char* topic, const char* message);
void subscribeToTopic(const char* topic, std::function<void(const String&)> handler);
void reconnectMQTT();