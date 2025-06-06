#pragma once
#include <ESP8266WiFi.h>

extern const char* ssid;
extern const char* password;

void setupWiFi();
void reconnectWiFi();