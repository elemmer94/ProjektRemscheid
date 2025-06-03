#include "wifi_manager.h"
#include "parameter.h"

void setupWiFi()
{
    Serial.print("\n🔌 Connecting to WiFi: ");
    Serial.print(WIFI_SSID);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.print("\n🟢 WLAN verbunden.\nIP Adresse: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC Adresse: ");
    Serial.println(WiFi.macAddress());
}

void reconnectWiFi()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("🔁 WLAN Verbindung getrennt – neu verbinden...");
        WiFi.disconnect();
        WiFi.begin(ssid, password);
        int attempts = 0;
        while (WiFi.status() != WL_CONNECTED && attempts < 10)
        {
            delay(500);
            Serial.print(".");
            attempts++;
        }
        Serial.println();
        if (WiFi.status() == WL_CONNECTED)
        {
            Serial.println("🟢 WLAN verbunden.");
        }
        else
        {
            Serial.println("❌ WLAN Verbindung fehlgeschlagen.");
        }
    }
}