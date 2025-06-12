#include "rfid_sensor.h"
#include <MFRC522.h>
#include <SPI.h>
#include "mqtt_client.h"

RFIDSensor::RFIDSensor(uint8_t ssPin, const char *publishTopic)
    : _ssPin(ssPin), _publishTopic(publishTopic), rfid(nullptr) {}

void RFIDSensor::begin()
{
    // SPI konfigurieren
    pinMode(_ssPin, OUTPUT);
    digitalWrite(_ssPin, HIGH); // CS high (inaktiv)

    SPI.begin();
    rfid = new MFRC522(_ssPin);
    rfid->PCD_Init();
    Serial.println("🟢 RFID bereit.");
}

void RFIDSensor::loop()
{
    digitalWrite(_ssPin, LOW); // Aktivieren

    if (!rfid->PICC_IsNewCardPresent() || !rfid->PICC_ReadCardSerial())
        return;

    String uid = "";
    for (byte i = 0; i < rfid->uid.size; i++)
    {
        uid += String(rfid->uid.uidByte[i] < 0x10 ? " 0" : " ");
        uid += String(rfid->uid.uidByte[i], HEX);
    }
    uid.toUpperCase();

    publishMessage(_publishTopic, uid.c_str());
    rfid->PICC_HaltA();
    rfid->PCD_StopCrypto1();

    digitalWrite(_ssPin, HIGH); // Deaktivieren
}