#include "wifi_manager.h"
#include "mqtt_client.h"
#include "parameter.h"
#include "timer.h"

extern unsigned long myTimer;
extern IPAddress localIP;
extern String macAddress;

void setupWiFi()
{
    Serial.print("\n🔌 Connecting to WiFi: ");
    Serial.print(WIFI_SSID);

    WiFi.mode(WIFI_STA); // Station-Modus
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);

    while (WiFi.status() != WL_CONNECTED && !timePassed(myTimer, INTERVALL))
    {
        Serial.print(".");
        delay(500);
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("\n🟢 WLAN verbunden.");
    }
    else
    {
        Serial.println("\n❌ WLAN Verbindung fehlgeschlagen.");
        myTimer = millis(); // neuen Versuch merken
    }
}

void reconnectWiFi()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        WiFi.disconnect();
        Serial.print("\n🔌 Connecting to WiFi: ");
        Serial.print(WIFI_SSID);
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

        while (WiFi.status() != WL_CONNECTED && !timePassed(myTimer, INTERVALL))
        {
            Serial.print(".");
            delay(500);
        }

        if (WiFi.status() == WL_CONNECTED)
        {
            Serial.println("\n🟢 WLAN verbunden.");
        }
        else
        {
            Serial.println("\n❌ WLAN Verbindung fehlgeschlagen.");
            myTimer = millis(); // neuen Versuch merken
        }
    }
}