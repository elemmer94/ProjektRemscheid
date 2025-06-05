#include <map>
#include "mqtt_client.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include "parameter.h"
#include "timer.h"

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
    client.setServer(MQTT_SERVER, 1883);
    client.setCallback(callback);

    if (WiFi.status() == WL_CONNECTED)
    {
        if (client.connect(ESP_NAME))
        {
            for (const auto &entry : topicHandlers)
            {
                client.subscribe(entry.first.c_str());
            }
            Serial.println("🟢 MQTT verbunden.");
        }
        else
        {
            Serial.println("❌ MQTT Verbindung fehlgeschlagen.\nStatus: ");
            Serial.println(client.state());
        }
    }
    else
    {
        Serial.println("❌ MQTT überspringen: WLAN ist nicht verbunden.");
    }
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
    myTimer = 0;
    
    while (!client.connected() && timePassed(myTimer, INTERVALL))
    {
        if (client.connect(ESP_NAME))
        {
            Serial.println("✅ MQTT verbunden.");
            for (const auto &entry : topicHandlers)
            {
                client.subscribe(entry.first.c_str());
            }
        }
        else
        {
            Serial.print("❌ MQTT Verbindung fehlgeschlagen.\nStatus: ");
            Serial.println(client.state());
        }
    }
    if (client.connected())
    {
        client.loop();
    }
}