#include <map>
#include "mqtt_client.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include "parameter.h"
#include "timer.h"

bool initialize = false;

extern unsigned long myTimer;

WiFiClient espClient;
PubSubClient client(espClient);
std::map<String, std::function<void(const String &)>> topicHandlers;

void callback(char *topic, byte *payload, unsigned int length)
{
    String message;
    for (unsigned int i = 0; i < length; i++)
    {
        message += (char)payload[i];
    }
    String topicStr = String(topic);
    if (topicHandlers.count(topicStr))
    {
        topicHandlers[topicStr](message);
    }
}

void setupMQTT()
{
    client.setServer(RASPI_IP, 1883);
    client.setCallback(callback);

    reconnectMQTT();
}

void publishMessage(const char *topic, const char *message)
{
    client.publish(topic, message);

    Serial.print(topic);
    Serial.print(": ");
    Serial.println(message);
}

void subscribeToTopic(const char *topic, std::function<void(const String &)> handler)
{
    topicHandlers[topic] = handler;
    client.subscribe(topic);
}

void reconnectMQTT()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("❌ MQTT überspringen: WLAN nicht verbunden.");
        return;
    }

    if (client.connected())
    {
        client.loop();
        if (!initialize)
        {
            publishMessage(ESP_IP, WiFi.localIP().toString().c_str());
            publishMessage(ESP_MAC, WiFi.macAddress().c_str());
            initialize = true;
        }
        return;
    }

    if (!timePassed(myTimer, INTERVALL))
        return; // Schon verbunden oder noch nicht Zeit für neuen Versuch

    myTimer = millis(); // neuen Versuch merken

    if (client.connect(ESP_NAME, MQTT_USER, MQTT_PASS, ESP_LASTWILL, 1, true, "false"))
    {
        Serial.println("🟢 MQTT verbunden.");
        // Alle Topics neu abonnieren
        for (const auto &entry : topicHandlers)
        {
            client.subscribe(entry.first.c_str());
        }
        // Sobald verbunden: "online" senden
        client.publish(ESP_LASTWILL, "true", true); // Retained
    }
    else
    {
        Serial.print("❌ MQTT Verbindung fehlgeschlagen. Status: ");
        Serial.println(client.state());
    }
}