#include "parameter.h"
#include "sensor_manager.h"
#include "sensors/pixy_sensor.h"
#include "sensors/rfid_sensor.h"
// ggf. weitere Sensoren

std::vector<SensorInterface*> sensors;


void SensorManager::begin() {
    sensors.push_back(new RFIDSensor(RFID_SS, RFID_RST, "rfid/uid", "rfid/access"));  // D2 = SS, D1 = RST
    sensors.push_back(new PixySensor(PIXY_SS, "pixy/barcode", "pixy/access"));  // D8 = SS
    for (auto* s : sensors) {
        s->begin();
    }
}

void SensorManager::loop() {
    for (auto* s : sensors) {
        s->loop();
    }
}
