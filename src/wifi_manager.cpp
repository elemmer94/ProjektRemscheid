#include "wifi_manager.h"
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

    while (WiFi.status() != WL_CONNECTED && timePassed(myTimer, INTERVALL))
    {
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.print("\n🟢 WLAN verbunden.\nIP Adresse: ");
        Serial.println(WiFi.localIP());
        Serial.print("MAC Adresse: ");
        Serial.println(WiFi.macAddress());
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
            Serial.print(".");
        }

        if (WiFi.status() == WL_CONNECTED)
        {
            Serial.println("\n🟢 WLAN verbunden.");
        }
        else
        {
            Serial.println("\n❌ WLAN Verbindung fehlgeschlagen.");
        }
    }
}