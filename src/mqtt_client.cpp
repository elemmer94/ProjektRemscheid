#include <map>
#include "mqtt_client.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

WiFiClient espClient;
PubSubClient client(espClient);
std::map<String, std::function<void(const String&)>> topicHandlers;

bool mqttEnabled = false;   // Ausgabe auf dem Seriellen Monitor

const char* mqtt_server = "192.168.0.100";  // z. B. IP des RPi

void callback(char* topic, byte* payload, unsigned int length) {
    String message;
    for (unsigned int i = 0; i < length; i++) {
        message += (char)payload[i];
    }
    String topicStr = String(topic);
    if (topicHandlers.count(topicStr)) {
        topicHandlers[topicStr](message);
    }
}

void setupMQTT() {
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);

    if (WiFi.status() == WL_CONNECTED) {
        if (client.connect("ESP8266Client")) {
            mqttEnabled = true;
            for (const auto& entry : topicHandlers) {
                client.subscribe(entry.first.c_str());
            }
            Serial.println("🟢 MQTT connected.");
        } else {
            Serial.println("❌ MQTT connection failed.");
        }
    } else {
        Serial.println("❌ Skipping MQTT setup: WiFi not connected.");
    }
}

void mqttLoop() {
    static unsigned long lastReconnectAttempt = 0;

    if (mqttEnabled) {
        if (!client.connected()) {
            unsigned long now = millis();
            if (now - lastReconnectAttempt > 15000) { // alle 10 Sekunden versuchen
                Serial.println("MQTT reconnect...");
                if (client.connect("ESP8266Client")) {
                    Serial.println("🟢 MQTT reconnected.");
                    for (const auto& entry : topicHandlers) {
                        client.subscribe(entry.first.c_str());
                    }
                } else {
                    Serial.println("❌ MQTT reconnect failed.");
                }
                lastReconnectAttempt = now;
            }
        } else {
            client.loop(); // nur, wenn verbunden
        }
    }
}

void publishMessage(const char* topic, const char* message) {
    if (mqttEnabled) {
        client.publish(topic, message);
    } else {
        Serial.print("[Offline] ");
        Serial.print(topic);
        Serial.print(": ");
        Serial.println(message);
    }
}

void subscribeToTopic(const char* topic, std::function<void(const String&)> handler) {
    topicHandlers[topic] = handler;
    client.subscribe(topic);
}

void reconnectMQTT() {
    if (!client.connected()) {
        Serial.println("🔁 MQTT disconnected – reconnect...");

        while (!client.connected()) {
            if (client.connect("ESP8266Client")) {
                Serial.println("✅ MQTT reconnected.");
                // Alle Abos neu registrieren:
                for (const auto& entry : topicHandlers) {
                    client.subscribe(entry.first.c_str());
                    Serial.print("🔔 Wiederabonniert: ");
                    Serial.println(entry.first);
                }
            } else {
                Serial.print("❌ MQTT Error: ");
                Serial.println(client.state());
                delay(5000);  // Warte vor erneutem Versuch
            }
        }
    }
}