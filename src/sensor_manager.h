#pragma once
#include <Arduino.h>
#include "sensors/sensor_interface.h"
#include <vector>
#include "sensors/rfid_sensor.h"
#include "sensors/pixy_sensor.h"

class SensorManager {
public:
    void begin();
    void loop();

private:
    std::vector<SensorInterface*> sensors;
};
