#include "wifi_manager.h"
#include "mqtt_client.h"
#include "parameter.h"
#include "timer.h"

extern unsigned long myTimer;

void setupWiFi()
{
    Serial.print("\n🔌 Connecting to WiFi: ");
    Serial.print(WIFI_SSID);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        publishMessage(ESP_IP, WiFi.localIP().toString().c_str());
    }
    else
    {
        Serial.println("\n❌ WLAN Verbindung fehlgeschlagen.");
    }
}

void reconnectWiFi()
{
    myTimer = 0;

    if (WiFi.status() != WL_CONNECTED)
    {
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

        while (WiFi.status() != WL_CONNECTED && timePassed(myTimer, INTERVALL))
        {
            delay(500);
            Serial.print(".");
        }

        if (WiFi.status() == WL_CONNECTED)
        {
            publishMessage(ESP_IP, WiFi.localIP().toString().c_str());
        }
        else
        {
            Serial.println("\n❌ WLAN Verbindung fehlgeschlagen.");
        }
    }
}