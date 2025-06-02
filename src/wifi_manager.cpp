#include "wifi_manager.h"
#include "secrets.h"


void setupWiFi() {
    Serial.print("\n🔌 Connecting to WiFi: ");
    Serial.print(WIFI_SSID);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);

    unsigned long startAttemptTime = millis();
    const unsigned long timeout = 15000; // 15 Sekunden Timeout

    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < timeout) {
        delay(500);
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.print("\n✅ WiFi connected.\nIP address: ");
        Serial.println(WiFi.localIP());
        Serial.print("MAC address: ");
        Serial.println(WiFi.macAddress());
    } else {
        Serial.println("\n❌ WiFi connection failed. Continuing in offline mode.");
    }
}

void reconnectWiFi() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("🔁 WiFi disconnected – reconnect...");
        WiFi.disconnect();
        WiFi.begin(ssid, password);
        int attempts = 0;
        while (WiFi.status() != WL_CONNECTED && attempts < 10) {
            delay(500);
            Serial.print(".");
            attempts++;
        }
        Serial.println();
        if (WiFi.status() == WL_CONNECTED) {
            Serial.println("✅ WiFi connected.");
        } else {
            Serial.println("❌ WiFi reconnect failed.");
        }
    }
}