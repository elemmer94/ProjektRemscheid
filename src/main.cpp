#include <Arduino.h>
#include "wifi_manager.h"
#include "mqtt_client.h"
#include "sensor_manager.h"

SensorManager sensorManager;

void setup() {
    Serial.begin(115200);
    // Initialisierung von WLAN, MQTT und Sensoren
    setupWiFi();
    setupMQTT();
    sensorManager.begin();
}

void loop() {
    // Aktualisierung der MQTT-Nachrichten und der Sensorwerte
    sensorManager.loop();
    mqttLoop();
    delay(10);
}


// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <PubSubClient.h>

// const char* ssid2 = "Lemmer";
// const char* password2 = "80366569843992685706";
// const char* mqtt_server2 = "192.168.0.100";  // MQTT Broker IP

// WiFiClient espClient2;
// PubSubClient client2(espClient2);

// void setup_wifi() {
//   delay(10);
//   WiFi.begin(ssid2, password2);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//   }
//   Serial.println("WLAN verbunden!");
// }

// void reconnect() {
//   while (!client2.connected()) {
//     Serial.print("MQTT-Verbindungsversuch ... ");
//     if (client2.connect("ESP8266Client")) {
//       Serial.println("verbunden!");
//     } else {
//       Serial.print("fehlgeschlagen, rc=");
//       Serial.print(client2.state());
//       Serial.println(" -> neuer Versuch in 5 Sekunden");
//       delay(5000);
//     }
//   }
// }

// void setup() {
//   Serial.begin(115200);
//   setup_wifi();
//   client2.setServer(mqtt_server2, 1883);
// }

// void loop() {
//   if (!client2.connected()) {
//     reconnect();
//   }
//   client2.loop();
//   client2.publish("rfid/uid", "Hallo MQTT");
//   delay(5000);
// }
