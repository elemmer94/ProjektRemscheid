#include "parameter.h"
#include "sensor_manager.h"
#include "sensors/pixy_sensor.h"
#include "sensors/rfid_sensor.h"
#include "sensors/digital_sensor.h"
#include "sensors/analog_sensor.h"

std::vector<SensorInterface *> sensors;

void SensorManager::begin()
{
    // Wähle Sensoren abhängig vom ESP
    if (strcmp(ESP_NAME, "ESP_1") == 0)
    {
        // Anlegen der Sensorobjekte
        sensors.push_back(new RFIDSensor(RFID_SS, RFID_RST, RFID_SEND, RFID_RECEIVE));
        sensors.push_back(new PixySensor(PIXY_SS, PIXY_SEND, PIXY_RECEIVE));
        sensors.push_back(new DigitalSensor(INFRARED_PIN, INFRARED_SEND));
        // Ultraschallsensor hinzufügen
    }
    else if (strcmp(ESP_NAME, "ESP_2") == 0)
    {
        sensors.push_back(new DigitalSensor(PIR_PIN, PIR_SEND));
        sensors.push_back(new AnalogSensor(TEMP1_PIN, TEMP1_SEND));
    }
    else if (strcmp(ESP_NAME, "ESP_3") == 0)
    {
        sensors.push_back(new DigitalSensor(FLAME_PIN, FLAME_SEND));
        // Temperatursensor 18B20 hinzufügen
        sensors.push_back(new AnalogSensor(GAS_PIN, GAS_SEND));
    }
    else
    {
        sensors.push_back(new DigitalSensor(TEMP_HUMIDITY_PIN, TEMP3_SEND));
        // Luftfeuchtigkeitssensor hinzufügen
        sensors.push_back(new AnalogSensor(VAPOR_PIN, VAPOR_SEND));
    }

    // Initialisierung der Sensoren
    for (auto *s : sensors)
    {
        s->begin();
    }
}

void SensorManager::loop()
{
    // Abfrage der Sensoren
    for (auto *s : sensors)
    {
        s->loop();
    }
}
