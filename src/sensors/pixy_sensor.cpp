#include "pixy_sensor.h"
#include <SPI.h>
#include "mqtt_client.h"

PixySensor::PixySensor(uint8_t ssPin, const char* publishTopic, const char* responseTopic)
    : _ssPin(ssPin), _publishTopic(publishTopic), _responseTopic(responseTopic) {}

void PixySensor::begin() {
  // SPI konfigurieren
  pinMode(_ssPin, OUTPUT);
  digitalWrite(_ssPin, HIGH);   // CS high (inaktiv)

  SPI.begin(); // D5=SCK, D6=MISO, D7=MOSI
  pixy.init();  // Pixy initialisieren (SPI)

  // In den Line-Modus wechseln
  if (pixy.changeProg("line") == 0) {
    Serial.println("🟢 Pixy2 bereit.");
  } else {
    Serial.println("❌ Fehler beider Initialisierung.");
  }
    
}

void PixySensor::loop() {
    digitalWrite(_ssPin, LOW); // Aktivieren
    pixy.line.getMainFeatures();

    if (pixy.line.numBarcodes > 0) {
        publishMessage(_publishTopic, String(pixy.line.barcodes[0].m_code).c_str());
    }

    digitalWrite(_ssPin, HIGH); // Deaktivieren
}

void PixySensor::handleAccessResponse(const String& message) {
    if (message == "granted") {
        Serial.println("Access granted");
        // z. B. LED an
    } else {
        Serial.println("Access denied");
        // z. B. Alarm o.Ä.
    }
}