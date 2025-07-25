#include "parameter.h"
#include "sensor_manager.h"
#include "sensors/pixy_sensor.h"
#include "sensors/rfid_sensor.h"
#include "sensors/digital_sensor.h"
#include "sensors/analog_sensor.h"
#include "sensors/oled_display.h"
#include "sensors/voltage.h"
#include "sensors/ultrasonic_sensor.h"
#include "sensors/analog_temp.h"
#include "sensors/ds18s20_sensor.h"
#include "sensors/dht11.h"

std::vector<SensorInterface *> sensors;

void SensorManager::begin()
{
    // Erstelle Sensoren abhängig vom ESP
    if (strcmp(ESP_NAME, "ESP_1") == 0)
    {
        // Authentifizierung
        sensors.push_back(new RFIDSensor(RFID_SS, RFID_SEND));
        sensors.push_back(new PixySensor(PIXY_SS, PIXY_SEND));
        sensors.push_back(new DigitalSensor(INFRARED_PIN, INFRARED_SEND));
        sensors.push_back(new OLedDisplay(DISPLAY_SCK, DISPLAY_SDA, RELAIS, DISPLAY_ACCESS));

        // Spannungsmessung
        sensors.push_back(new Voltage(VOLTAGE, VOLTAGE_SEND));
    }
    else if (strcmp(ESP_NAME, "ESP_2") == 0)
    {
        sensors.push_back(new AnalogTemp(TEMP1_PIN, TEMP1_SEND));
        sensors.push_back(new Ultrasonic(ULTRA_ECHO,ULTRA_TRIG,ULTRA_SEND));
    }
    else if (strcmp(ESP_NAME, "ESP_3") == 0)
    {
        sensors.push_back(new DigitalSensor(FLAME_PIN, FLAME_SEND));
        sensors.push_back(new DS18S20_TEMP(TEMP2_PIN, TEMP2_SEND));
        sensors.push_back(new AnalogSensor(GAS_PIN, GAS_SEND));
    }
    else
    {
        sensors.push_back(new DigitalSensor(PIR_PIN, PIR_SEND));
        sensors.push_back(new DHTSensor(TEMP_HUMIDITY_PIN, TEMP_HUMIDITY_SEND));
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
