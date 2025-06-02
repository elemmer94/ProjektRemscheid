#include "rfid_sensor.h"
#include <MFRC522.h>
#include <SPI.h>
#include "mqtt_client.h"

RFIDSensor::RFIDSensor(uint8_t ssPin, uint8_t rstPin, const char* publishTopic, const char* responseTopic)
    : _ssPin(ssPin), _rstPin(rstPin), _publishTopic(publishTopic), _responseTopic(responseTopic), rfid(nullptr) {}

void RFIDSensor::begin() {
    SPI.begin();
    rfid = new MFRC522(_ssPin, _rstPin);
    rfid->PCD_Init();
    subscribeToTopic(_responseTopic, [this](const String& message) {
        handleAccessResponse(message);
    });
    Serial.println("🟢 RFID ready.");
}

void RFIDSensor::loop() {
    if (!rfid->PICC_IsNewCardPresent() || !rfid->PICC_ReadCardSerial()) return;

    String uid = "";
    for (byte i = 0; i < rfid->uid.size; i++) {
        uid += String(rfid->uid.uidByte[i] < 0x10 ? " 0" : " ");
        uid += String(rfid->uid.uidByte[i], HEX);
    }
    uid.toUpperCase();

    publishMessage(_publishTopic, uid.c_str());
    rfid->PICC_HaltA();
    rfid->PCD_StopCrypto1();
    delay(500);
}

void RFIDSensor::handleAccessResponse(const String& message) {
    if (message == "granted") {
        Serial.println("Access granted");
        // z. B. LED an
    } else {
        Serial.println("Access denied");
        // z. B. Alarm o.Ä.
    }
}