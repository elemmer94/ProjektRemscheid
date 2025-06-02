#include "parameter.h"
#include "sensor_manager.h"
#include "sensors/pixy_sensor.h"
#include "sensors/rfid_sensor.h"
// ggf. weitere Sensoren

std::vector<SensorInterface*> sensors;

void SensorManager::begin() {
    // Anlegen der Sensorobjekte
    sensors.push_back(new RFIDSensor(RFID_SS, RFID_RST, RFID_SEND, RFID_RECEIVE));
    sensors.push_back(new PixySensor(PIXY_SS, PIXY_SEND, PIXY_RECEIVE));
    // ggf. weitere Sensoren
    

    // Initialisierung der Sensoren
    for (auto* s : sensors) {
        s->begin();
    }
}

void SensorManager::loop() {
    // Abfrage der Sensoren
    for (auto* s : sensors) {
        s->loop();
    }
}
